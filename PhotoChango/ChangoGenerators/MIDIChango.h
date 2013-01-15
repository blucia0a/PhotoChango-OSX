#ifndef _MIDICHANGO_H_
#define _MIDICHANGO_H_
#include "ChangoGenerator.h"
class MIDIChango : public ChangoGenerator{

  public:

    MIDIChango(Mahalo *M);
    /*Will have NUM_SRCS entries*/
    virtual void update(float vals[]);
    virtual void tune(long which, float freq);
  
};
#endif
