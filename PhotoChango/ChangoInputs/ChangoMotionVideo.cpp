#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <cassert>
#include <iostream>
#include "Pixelator.h"
#include "ChangoInput.h"
#include "mahalo.h"
#include "ChangoGlobal.h"
#include "ChangoGenerator.h"
#include "ChangoMotionVideo.h"

extern CvCapture *camera;
extern unsigned long SCREEN_HEIGHT;
extern unsigned long SCREEN_WIDTH;
extern bool fullScreen;
void ChangoMotionVideo::highlight(CvPoint p1, CvPoint p2){

}

ChangoMotionVideo::ChangoMotionVideo(ChangoGenerator *chan, Mahalo *M) 
{
    this->m = M;
    this->chango = chan; 
    this->retVal = 0;
    // create all necessary instances
    IplImage *  test_frame = cvCreateImage(cvSize (480, 240), IPL_DEPTH_8U, 1);


    CvSize fsize;  
    fsize.height = test_frame->height;  
    fsize.width = test_frame->width;
    
    //CvVideoWriter *writer = cvCreateVideoWriter("./vcout.mp4",CV_FOURCC('a','v','c','1'),10.0,fsize);

    if (! camera)
        abort ();


    IplImage *  fcurrent_frame = cvQueryFrame (camera);
    IplImage *  tframe = cvCreateImage(cvSize (fcurrent_frame->width, fcurrent_frame->height), IPL_DEPTH_8U, 1);
    IplImage *  current_frame = cvCreateImage(cvSize (test_frame->width, test_frame->height), IPL_DEPTH_8U, 1);

    cvCvtColor (fcurrent_frame, tframe, CV_BGR2GRAY);
    cvResize(tframe,current_frame);

    IplImage *  gray_image    = cvCreateImage(cvSize (current_frame->width, current_frame->height), IPL_DEPTH_8U, 1);
    IplImage *  avg_img = cvCreateImage(cvSize (current_frame->width, current_frame->height), IPL_DEPTH_32F, 1);
    IplImage *  gavg_img = cvCreateImage(cvSize (current_frame->width, current_frame->height), IPL_DEPTH_8U, 1);
    IplImage *  diff_img = cvCreateImage(cvSize (current_frame->width, current_frame->height), IPL_DEPTH_8U, 1);
    IplImage *  diff_img2 = cvCreateImage(cvSize (current_frame->width, current_frame->height), IPL_DEPTH_8U, 1);
/*    IplImage *  diff_img3 = cvCreateImage(cvSize (current_frame->width, current_frame->height), IPL_DEPTH_8U, 1);*/
    IplImage * diff_img_fs = cvCreateImage(cvSize((int)SCREEN_WIDTH,(int)SCREEN_HEIGHT), IPL_DEPTH_8U, 1);
    
    // as long as there are images ...
    while (fcurrent_frame = cvQueryFrame (camera))
    {
        cvCvtColor (fcurrent_frame, tframe, CV_BGR2GRAY);
        cvResize(tframe,gray_image);

        cvSmooth( gray_image, gray_image);
        
        cvRunningAvg( gray_image, avg_img, .250, NULL);

        cvConvert( avg_img, gavg_img );

        cvAbsDiff( gray_image, gavg_img, diff_img );    
     
        cvConvert( diff_img, diff_img2 );

	  float vals[NUM_WAVES];
        pixelate(diff_img,vals);
        this->chango->update(vals);
	  //this->sg->setAmplitudes(vals);

        cvAddWeighted( diff_img, 0.5, diff_img2, 0.5, 0.5, diff_img);
        
        if(fullScreen){
            cvResize(diff_img, diff_img_fs);
            cvShowImage ( WINDOW_NAME, diff_img_fs);
        }else{
            cvShowImage ( WINDOW_NAME, diff_img);
        }
        //cvWriteFrame(writer, diff_img);

        if( handleKey() != 0 ){
          break;
        }
        /*usleep(3000);*/

    }

    //cvReleaseVideoWriter(&writer);
    // be nice and return no error
    return;
}
