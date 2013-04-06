/*
 *  Wave.cpp
 *  Sin
 *
 *  Created by blucia0a on 8/25/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
#include "BeatWave.h"
#include <math.h>
#include <stdlib.h>
BeatWave::BeatWave(double frq, double srate, double amp = 0.5){
	
    //Sample rate is passed in from the HAL deviceInfo structure
    this->srate = srate;
    this->sampleLenIn_us = 1.0f / (float)this->srate * 1000000;
    this->elapsedSamples = 0;
    this->playing = true;
	
    // initialize phase and de-zipper filters.
    phase = 0.0;
    this->freqz = this->freq = frq * 2. * 3.14159265459 / srate; 
    this->ampz = this->amp = amp;
    this->callback = NULL;

}

void BeatWave::reset(){
  this->elapsedSamples = 0;
  this->playing = true;
}

void BeatWave::setCallback(void (*f)(BeatWave *, void *), void *cbd){

  this->callback = f;
  this->cbdata = cbd;

}

double BeatWave::getRate(){

  return this->srate;

}

void BeatWave::getNextSample(float *out){

  float wave = (float)sin(this->phase);
  this->elapsedSamples++;

  if( this->playing ){

    if( this->elapsedSamples > this->duration){
      this->elapsedSamples = 0;
      this->playing = false;      
    }
    wave *= (float)this->ampz;

  }else{

    if( this->elapsedSamples > this->period ){
      this->elapsedSamples = 0;
      this->playing = true;      
    }
    wave = 0;  

  }
  this->phase = this->phase + this->freqz;  // increment phase
  
  // write output
  out[0] = wave;	// left channel
  out[1] = wave;	// right channel
  
  // de-zipper controls
  this->ampz  = 0.001 * this->amp  + 0.999 * this->ampz;
  this->freqz = 0.001 * this->freq + 0.999 * this->freqz;	

  if(this->callback != NULL){

    this->callback(this, this->cbdata);

  }

}

void BeatWave::setAmpVal(float val){
    this->amp = val;
}

void BeatWave::setFreqVal(double val){
    this->freq = val * 2. * 3.14159265359 / this->srate;
}

void BeatWave::setPeriod(unsigned val){

  /*Val is the period in us. Set this->period to the val in samples*/
  //There are this->rate samples per second
  //Each sample lasts 1/this->rate seconds = (1/this->rate)*1000000 us = ru
  //If the period is p us, it takes (p / ru) samples to make a period
  this->period = ((float)val) / this->sampleLenIn_us;
  this->elapsedSamples = this->elapsedSamples % this->period;
/*
  if( !this->playing ){

    if( this->elapsedSamples > this->period ){
      this->elapsedSamples = 0;
      this->playing = true;      
    }

  }*/

}

void BeatWave::setDuration(unsigned val){

  this->duration = ((float)val) / this->sampleLenIn_us;
  this->elapsedSamples = this->elapsedSamples % this->duration;
  /*if( this->playing ){

    if( this->elapsedSamples > this->duration ){
      this->elapsedSamples = 0;
      this->playing = false;      
    }

  }*/

}

double BeatWave::getAmpVal(){

    return this->amp;

}

double BeatWave::getFreqVal(){

    return this->freq / 2. / 3.141592653589 * this->srate;

}

unsigned BeatWave::getPeriod(){

    return this->period;

}

unsigned BeatWave::getDuration(){

    return this->duration;

}

unsigned BeatWave::getElapsed(){

    return this->elapsedSamples;

}

void BeatWave::setElapsed(unsigned v){

    this->elapsedSamples = v;

}
