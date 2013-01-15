#ifndef _WAVECHANGO_H_
#define _WAVECHANGO_H_
#include "ChangoGenerator.h"
#include "Wave.h"
class WaveChango : public ChangoGenerator{

  public:

    WaveChango(Mahalo *M);
    /*Will have NUM_SRCS entries*/
    virtual void update(float vals[]);
    virtual void tune(long which, float freq);
};
#endif
