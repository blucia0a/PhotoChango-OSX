#include "WaveChango.h"
#include "Wave.h"
#include "tones.h"

static double tones[NUM_WAVES] = { C3, C3, A3, A3, F4, F4, D5, D5, B5, B5,
    C3, C3, A3, A3, F4, F4, D5, D5, B5, B5,
    D3, D3, B3, B3, G4};

extern float amplitude_threshold;

WaveChango::WaveChango(Mahalo *M){

  this->m = M;

  SampleMixer *s = new SampleMixer();

  for ( int i = 0; i < NUM_WAVES; i++ ){

    Wave *b = new Wave(tones[i], this->m->getRate(), 0.0); 

    this->srcs[i] = b;
    s->Add(b);

  }
  
  m->setSampleSource(s); 

}

WaveChango::~WaveChango(){
    
}


void WaveChango::tune(long which, float freq){

    ((Wave*)this->srcs[which])->setFreqVal( freq );
    
}

void WaveChango::update(float *vals){

  for( int i = 0; i < NUM_WAVES; i++ ){
   
    if( vals[i] > amplitude_threshold ){
      this->srcs[i]->setAmpVal( vals[i] );
    }else{
      this->srcs[i]->setAmpVal( 0.0f );
    }
  }
  
}
