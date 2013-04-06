#include "CameraAndWindow.h"
#include "ChangoGlobal.h"



CameraAndWindow::CameraAndWindow(){

  cvNamedWindow (WINDOW_NAME_STR, CV_WINDOW_AUTOSIZE);
  //this->camera = cvCreateCameraCapture (CV_CAP_ANY);
  //this->storage = cvCreateMemStorage(0);

}
