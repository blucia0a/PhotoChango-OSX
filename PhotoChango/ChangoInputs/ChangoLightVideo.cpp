#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <cassert>
#include <iostream>
#include "Pixelator.h"
#include "ChangoInput.h"
#include "mahalo.h"
#include "ChangoGlobal.h"
#include "ChangoGenerator.h"
#include "ChangoLightVideo.h"

extern CvCapture *camera;

void ChangoLightVideo::highlight(CvPoint p1, CvPoint p2){

}

extern unsigned long SCREEN_WIDTH;
extern unsigned long SCREEN_HEIGHT;
extern bool fullScreen;

ChangoLightVideo::ChangoLightVideo(ChangoGenerator *chan, Mahalo *M) 
{
      this->m = M;
      this->chango = chan; 
      this->retVal = 0; //Default is quit and end

      IplImage *  test_frame = cvCreateImage(cvSize (480, 240), IPL_DEPTH_8U, 1);

      CvSize fsize;  
      fsize.height = test_frame->height;  
      fsize.width = test_frame->width;
    
      //CvVideoWriter *writer = cvCreateVideoWriter("./vcout.mp4",CV_FOURCC('a','v','c','1'),10.0,fsize);

      if (! camera)
        abort ();


      // get an initial frame and duplicate it for later work
      IplImage *  fcurrent_frame = cvQueryFrame (camera);

      IplImage *  tframe = cvCreateImage(cvSize (fcurrent_frame->width, fcurrent_frame->height), IPL_DEPTH_8U, 1);

      IplImage *  current_frame = cvCreateImage(cvSize (test_frame->width, test_frame->height), IPL_DEPTH_8U, 1);; 

      IplImage *  gray_image    = cvCreateImage(cvSize (current_frame->width, current_frame->height), IPL_DEPTH_8U, 1);

      IplImage *  gray_image2    = cvCreateImage(cvSize (current_frame->width, current_frame->height), IPL_DEPTH_8U, 1);
    
      IplImage * img_fs = cvCreateImage(cvSize((int)SCREEN_WIDTH,(int)SCREEN_HEIGHT), IPL_DEPTH_8U, 1);
    

      assert (current_frame && gray_image);
      
      // as long as there are images ...
      while ((fcurrent_frame = cvQueryFrame (camera)))
      {

        cvCvtColor (fcurrent_frame, tframe, CV_BGR2GRAY);
        cvResize(tframe,gray_image);
    	
        // convert to gray and downsize
        //cvCvtColor (current_frame, gray_image, CV_BGR2GRAY);
        cvConvert( gray_image, gray_image2);
            
        float vals[NUM_WAVES];
        pixelate(gray_image,vals);
        this->chango->update(vals);
    
        // just show the image
        cvAddWeighted( gray_image2, 0.5, gray_image, 0.5, 0.5, gray_image);
          
        if(fullScreen){
            cvResize(gray_image, img_fs);
            cvShowImage ( WINDOW_NAME_STR, img_fs);
        }else{
            cvShowImage ( WINDOW_NAME_STR, gray_image);
        }


        int keyRet = handleKey();
        if( keyRet != 0 ){
          break;
        }
          /*usleep(3000);*/

      }

    return;
}

ChangoLightVideo::~ChangoLightVideo(){
    
    
}


