#ifndef _CHANGO_H_
#define _CHANGO_H_

#include "mahalo.h"
#include "SampleSource.h"
#include "ChangoGlobal.h"
class ChangoGenerator{

  protected:
    Mahalo *m;
    SampleSource *srcs[NUM_WAVES];

  public:
    /*Will have NUM_SRCS entries*/
    virtual void update(float *vals) = 0;
    virtual void tune(long which, float freq) = 0;
  
};
#endif
