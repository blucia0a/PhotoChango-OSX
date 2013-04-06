#ifndef _BEATCHANGO_H_
#define _BEATCHANGO_H_
#include "ChangoGenerator.h"
#include "BeatWave.h"
class BeatChango : public ChangoGenerator{

  public:

    BeatChango(BeatWave **ws, Mahalo *M);
    BeatChango(Mahalo *M);
    /*Will have NUM_SRCS entries*/
    virtual void update(float vals[]);
    virtual void tune(long which, float freq);
    virtual ~BeatChango();
};
#endif
