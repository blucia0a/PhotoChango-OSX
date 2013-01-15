#include "WaveChango.h"
#include "Wave.h"
#include "tones.h"


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

void WaveChango::tune(long which, float freq){

    ((Wave*)this->srcs[which])->setFreqVal( freq );
    
}

void WaveChango::update(float *vals){

  for( int i = 0; i < NUM_WAVES; i++ ){

    this->srcs[i]->setAmpVal( vals[i] );

  }
  
}
