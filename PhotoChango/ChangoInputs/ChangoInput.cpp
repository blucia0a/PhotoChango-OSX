#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "ChangoInput.h"
extern void onMouse(int event, int x, int y, int flags, void *n);

ChangoInput::ChangoInput(){
  cvSetMouseCallback(WINDOW_NAME,onMouse,this);
}

