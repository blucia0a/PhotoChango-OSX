/*
 *  PhotoChango.cpp
 *  Sin
 *
 *  Created by blucia0a on 8/25/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
//#include <OpenCV/OpenCV.h>
#include <opencv/cv.h>
//#include <opencv/highgui.h>
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

CvCapture *camera;

bool useMIDI = false;
bool useMotion = false; 
bool useBeat = false;
bool fullScreen = false;
bool done = false;
extern "C" {
    
unsigned long SCREEN_HEIGHT;
unsigned long SCREEN_WIDTH;

}

float toneSets[NUM_WAVES][10];
bool validToneSet[10] = {false, false, false, false, false, false, false, false, false, false};
void processToneFileOpen(const char *string, int index){

    fprintf(stderr,"Hi baby.  Setting %d to %s\n",index, string);
    FILE *f = fopen(string, "r");
    float toneVal;
    int i = 0;
    while( fscanf(f,"%f\n", &toneVal) != EOF && i < NUM_WAVES ){
        
        fprintf(stderr,"the thing was <%f>\n", toneVal);
        toneSets[i++][index] = toneVal;
        
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


void tune(int which, float freq);
void tuneToToneSet(int which){

    if( validToneSet[which] == true ){
        
        for( int i = 0; i < NUM_WAVES; i++){
            
            tune(i,toneSets[i][which]);
            
        }
        
    }

}

void handleFullScreen(){
  
    if(fullScreen){
        
        fprintf(stderr,"going regular screen!\n");
        fullScreen = false;
        cvSetWindowProperty(WINDOW_NAME, CV_WND_PROP_FULLSCREEN, CV_WINDOW_NORMAL);
        cvSetWindowProperty(WINDOW_NAME, CV_WND_PROP_ASPECTRATIO, CV_WINDOW_KEEPRATIO);
        
        
    }else{
        
        fprintf(stderr,"going fullscreen!\n");
        fullScreen = true;
        cvSetWindowProperty(WINDOW_NAME, CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN);
        cvSetWindowProperty(WINDOW_NAME, CV_WND_PROP_ASPECTRATIO, CV_WINDOW_FREERATIO);
    }


}


float DbLydian[] = {
                     Csharp2, Csharp2, Dsharp2, Dsharp2, F2, F2,  G2, G2,  Gsharp2, Gsharp2,
                     Csharp2, Csharp2, Dsharp2, Dsharp2, F2, F2,  G2, G2,  Gsharp2, Gsharp2,
                     Asharp2, Asharp2, C2, C2, Csharp3, Csharp3,  Dsharp3, Dsharp3, F3, F3,
                     Asharp2, Asharp2, C2, C2, Csharp3, Csharp3,  Dsharp3, Dsharp3, F3, F3,
                     G3, G3, Gsharp3, Gsharp3, Asharp3, Asharp3, C3, C3, Csharp4, Csharp4,
                     G3, G3, Gsharp3, Gsharp3, Asharp3, Asharp3, C3, C3, Csharp4, Csharp4,
                     Dsharp4, Dsharp4, F4, F4, G4, G4, Gsharp4, Gsharp4, Asharp4, Asharp4,
                     Dsharp4, Dsharp4, F4, F4, G4, G4, Gsharp4, Gsharp4, Asharp4, Asharp4,
                     C4, C4, Csharp5, Csharp5, Dsharp5, Dsharp5, F5, F5, G5, G5
                    };


float CMajor[] = { C2, C2,  D2, D2,  E2, E2,  F2, F2, G2, G2,
                   C2, C2,  D2, D2,  E2, E2,  F2, F2, G2, G2,
                   A2, A2, B2, B2, C3, C3, D3, D3, E3, E3,
                   A2, A2, B2, B2, C3, C3, D3, D3, E3, E3,
                   F3, F3, G3, G3, A3, A3, B3, B3, C4, C4,
                   F3, F3, G3, G3, A3, A3, B3, B3, C4, C4,
                   D4, D4, E4, E4, F4, F4, G4, G4, A4, A4,
                   D4, D4, E4, E4, F4, F4, G4, G4, A4, A4,
                   B4, B4, C5, C5, D5, D5, E5, E5, G5, G5,
                   B4, B4, C5, C5, D5, D5, E5, E5, G5, G5
};


void tuneFromFile(int which, float freq){
    

}


void setDbLydian(){
    
    for( int i = 0; i < NUM_WAVES; i++){
        
        tune(i,DbLydian[i]);
        
    }
    
}

void setCMajor(){
    
    for( int i = 0; i < NUM_WAVES; i++){
        
        tune(i,CMajor[i]);
        
    }
    
}

int handleKey(){

        int key = cvWaitKey (30);
        if (key == 'q' || key == 'Q'){
          done = true;
          return -1;
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

    if (key == 'f'){

        handleFullScreen();
    }
    
    if (key == 'd'){
        
        setDbLydian();
        
    }
    
    if (key == 'c'){
        
        setCMajor();
        
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
    cvShowImage(WINDOW_NAME, img);
    ci->highlight(p1, p2);

  }

}

ChangoGenerator *c;

extern void doRetune(int who, float tone);

void tune(int which, float freq){
    if(c != NULL){
        c->tune(which,freq);
        int col = which / 5;
        int row = which % 5;
        doRetune(col * 5 + row, freq);
    }
}

int Changomain(int argc, char *argv[]){
	
	fprintf(stderr,"PhotoChango - Brandon Lucia 2011 - Audiolyze the world! [http://cs.washington.edu/homes/blucia0a]\n");
        if( argc >= 2 ){
          useMotion = true;
        }
	
	Mahalo *m = new Mahalo();

	m->setup();
    m->sstart();
        
        camera = cvCreateCameraCapture (CV_CAP_ANY);
        //camera = cvCreateCameraCapture (10);
        cvNamedWindow(WINDOW_NAME,CV_WINDOW_NORMAL);
 
        /*clv should be loaded from a factory that can be specified on the command line*/ 
        ChangoInput *ci;
	

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
 
}

