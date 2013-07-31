/*
 *  PhotoChango.cpp
 *  Sin
 *
 *  Created by blucia0a on 8/25/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <opencv/cv.h>
#include <opencv2/highgui/highgui_c.h>
#include "mahalo.h"
#include "ChangoInput.h"
#include "ChangoLightVideo.h"
#include "ChangoMotionVideo.h"
#include "BeatChango.h"
#include "WaveChango.h"
#include "MIDIChango.h"
#include "tones.h"
#include <pthread.h>
#include <unistd.h>

#define NUM_TONE_SETS 11 //10 for user + 1 for MIDI

CvCapture *camera;

bool useMIDI = false;
bool useMotion = false; 
bool useBeat = false;
bool fullScreen = false;
bool done = false;


float amplitude_threshold = 0.2f;

extern "C" {
    
  unsigned long SCREEN_HEIGHT = 0;
  unsigned long SCREEN_WIDTH = 0;

}

float toneSets[NUM_WAVES][NUM_TONE_SETS];
bool validToneSet[NUM_TONE_SETS] = {false, false, false, false, false, false, false, false, false, false, false};

float getToneFromToneSet(int set, int tone){
  
  return toneSets[tone][set];
  
}

void setToneInToneSet(int set, int tone, float f){
  
  toneSets[tone][set] = f;
  
}



void processToneFileOpen(const char *string, int index){

    fprintf(stderr,"Hi baby.  Setting %d to %s\n",index, string);
    FILE *f = fopen(string, "r");
    float toneVal;
    int i = 0;
    while( fscanf(f,"%f\n", &toneVal) != EOF && i < NUM_WAVES ){
        

        toneSets[i][index] = toneVal;
        fprintf(stderr,"toneSets[%d][%d] = <%f>\n", i, index, toneSets[i][index]);
        i++;
      
    }
    fclose(f);
    validToneSet[index] = true;
    
}

void processToneFileSave(const char *string, int index){
 
    FILE *f = fopen(string, "w");
    
    for( int i = 0; i < NUM_WAVES; i++){
        
        fprintf(f,"%f\n",toneSets[i][index]);
        
    }
    fclose(f);
    
}

void setAmplitudeThreshold(float newthresh){
  
  if( amplitude_threshold >= 0.0f && amplitude_threshold <= 1.0f){
    amplitude_threshold = newthresh;
  }
  
}

void tune(int which, float freq);
void tuneToToneSet(int which){

    if( validToneSet[which] == true ){
        
        for( int i = 0; i < NUM_WAVES; i++){
            fprintf(stderr,"tonesets[%d][%d] = %f\n",i,which,toneSets[i][which]);
            tune(i,toneSets[i][which]);
            
        }
        
    }

}

void handleCameraSelection(int cameraNumber){
  
  if (!done ){ return; } //Only change cameras while paused
  CvCapture *newCam = cvCreateCameraCapture (cameraNumber);
  if( newCam ){
    CvCapture *oldCam = camera;
    camera = newCam;
    cvReleaseCapture(&oldCam);
  }else{
    fprintf(stderr,"There is no Camera %d\n",cameraNumber);
  }
  
}

void handleFullScreen(){
  
    if(fullScreen){
        
        fprintf(stderr,"going regular screen!\n");
        fullScreen = false;
        cvSetWindowProperty(WINDOW_NAME_STR, CV_WND_PROP_FULLSCREEN, CV_WINDOW_NORMAL);
        cvSetWindowProperty(WINDOW_NAME_STR, CV_WND_PROP_ASPECTRATIO, CV_WINDOW_KEEPRATIO);
        
        
    }else{
        
        fprintf(stderr,"going fullscreen!\n");
        fullScreen = true;
        cvSetWindowProperty(WINDOW_NAME_STR, CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN);
        cvSetWindowProperty(WINDOW_NAME_STR, CV_WND_PROP_ASPECTRATIO, CV_WINDOW_FREERATIO);
    }


}


int handleKey(){

        int key = cvWaitKey (30);
        if (key == 'p' || key == 'P'){
           
            if( !done ){
                
                done = true;
                return -1;
            
            }else{
                
                done = false;
                return -1;
            }
            
        }

        if (key == 'm'){
          useMotion = true;
          return 1;
        }

        if (key == 'l'){
          useMotion = false;
          return 1;
        }

        if (key == 'b'){
          useBeat = true;
          return 1;
        }
        if (key == 'w'){
          useBeat = false;
          return 1;
        }
  
        if (key == '1'){

          handleCameraSelection(1);

        }

        if (key == '0'){

          handleCameraSelection(0);

        }

        if (key == 'f'){
          handleFullScreen();
        }
    
   
    
        return NULL;

}

#define WINDOW_IMG_WIDTH 480
#define WINDOW_IMG_HEIGHT 240
void onMouse(int event, int x, int y, int flags, void *n){

  ChangoInput *ci = (ChangoInput *)n;
  if( event == CV_EVENT_LBUTTONDOWN ){
    
    fprintf(stderr,"%d %d\n",x,y);
  
    IplImage *img = cvCreateImage(cvSize(480, 240), IPL_DEPTH_8U, 3);
    //Determine which square we're in...
    int xbox = x / (WINDOW_IMG_WIDTH / 10);
    int ybox = y / (WINDOW_IMG_HEIGHT / 10);
    CvPoint p1,p2;
    p1.x = xbox;
    p1.y = ybox;
    p2.x = xbox + 47;
    p2.y = ybox + 23;
    cvShowImage(WINDOW_NAME_STR, img);
    ci->highlight(p1, p2);

  }

}

ChangoGenerator *c;


void tune(int which, float freq){
    if(c != NULL){
        c->tune(which,freq);
        
    }
}

int Changomain(int argc, char *argv[],int width, int height){
	
    SCREEN_HEIGHT = height;
    SCREEN_WIDTH = width;
    
	fprintf(stderr,"PhotoChango - Brandon Lucia 2011 - Audiolyze the world! [http://cs.washington.edu/homes/blucia0a]\n");
        if( argc >= 2 ){
          useMotion = true;
        }
	
	Mahalo *m = new Mahalo();

	m->setup();
  m->sstart();
        
  camera = cvCreateCameraCapture (CV_CAP_ANY);
  cvNamedWindow(WINDOW_NAME_STR,CV_WINDOW_NORMAL);
 
        /*clv should be loaded from a factory that can be specified on the command line*/ 
        ChangoInput *ci;
	
    while( true ){
        
    
        while( !done ){

          fprintf(stderr,"Creating a new chango input!\n");
          fprintf(stderr,"done %s motion %s!\n", done ? "true" : "false", useMotion ? "true" : "false");

          if( useMIDI ){
            useBeat = false;
            c = new MIDIChango(m);
          }else{

            if( useBeat ){
              c = new BeatChango(m);
            }else{
              c = new WaveChango(m);
            }
          }

          if( !useMotion ){
              
            ci = new ChangoLightVideo(c,m);
          
          }else{
          
              ci = new ChangoMotionVideo(c,m);
          
          }

          delete ci;
          m->src = NULL;
          delete c;
      
        }
    
    
        handleKey();
    
    }
    
    return 0;
}

