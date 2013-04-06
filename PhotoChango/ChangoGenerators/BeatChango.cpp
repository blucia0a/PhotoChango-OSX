#include "BeatChango.h"
#include "BeatWave.h"
#include "tones.h"

#define FULL_PERIOD 1000000
#define FULL_DURATION 1000000

static double tones[NUM_WAVES] = { C3, C3, A3, A3, F4, F4, D5, D5, B5, B5,
    C3, C3, A3, A3, F4, F4, D5, D5, B5, B5,
    D3, D3, B3, B3, G4};

BeatChango::BeatChango(Mahalo *M){

  this->m = M;

  SampleMixer *s = new SampleMixer();

  for ( int i = 0; i < NUM_WAVES; i++ ){

    BeatWave *b = new BeatWave(tones[i], this->m->getRate(), 0.0); 

    this->srcs[i] = b;
    s->Add(b);

  }
  
  m->setSampleSource(s); 

}

BeatChango::~BeatChango(){
    
    
}

BeatChango::BeatChango(BeatWave **ws, Mahalo *M){

  for ( int i = 0; i < NUM_WAVES; i++ ){
    this->srcs[i] = ws[i];
  }
  this->m = M;

}

void BeatChango::tune(long which, float freq){
    
}

void BeatChango::update(float *vals){

  BeatWave **bs = (BeatWave **)this->srcs;
  for( int i = 0; i < NUM_WAVES; i++ ){

    this->srcs[i]->setAmpVal( vals[i] );

    if( vals[i] < .2 ){

      bs[i]->setPeriod( FULL_PERIOD ); 
      bs[i]->setDuration( FULL_DURATION ); 
      

    }else if( vals[i] < .6 ){

      bs[i]->setPeriod( FULL_PERIOD / 8); 
      bs[i]->setDuration( FULL_DURATION / 8); 


    }else{

      bs[i]->setPeriod( FULL_PERIOD / 16); 
      bs[i]->setDuration( FULL_DURATION / 16); 

    }
    //bs[i]->setPeriod((1.0 - vals[i]) * MAX_PERIOD);
    //bs[i]->setDuration((1.0 - vals[i]) * MAX_DURATION);
  }
  
}
