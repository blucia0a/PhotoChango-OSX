#include <opencv/cv.h>
#include <opencv/highgui.h>
class CameraAndWindow{


public:
      // create all necessary instances
      CvCapture * camera;
      CvMemStorage* storage;
      CameraAndWindow();

};
