#ifndef _BEATWAVE_H_
#define _BEATWAVE_H_

#include "SampleSource.h"
class BeatWave : public SampleSource{

  double freq, amp;		// controls
  double freqz, ampz;	    // for dezipper filter

  double phase;			// oscillator phase in radians
  double srate;

  unsigned period;
  unsigned duration;
  unsigned sampleLenIn_us;
  unsigned elapsedSamples;
  bool playing;

  void *cbdata;
  void (*callback)(BeatWave *self, void *d);

public:	
  BeatWave(double frq, double rate, double ampl);
  void reset();
  void setAmpVal(float val);
  double getAmpVal();
  void setFreqVal(double val);
  double getFreqVal();
  double getRate();
  
  void setElapsed(unsigned v);
  unsigned getElapsed();

  void setPeriod(unsigned val);
  unsigned getPeriod();
  void setDuration(unsigned val);
  unsigned getDuration();

  void setCallback(void (*f)(BeatWave *self, void *d), void *cbd);
  virtual void getNextSample(float *out);
  
};
#endif
