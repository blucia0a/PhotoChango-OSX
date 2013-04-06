/*
 *  FrameAcquirer.h
 *  Sin
 *
 *  Created by blucia0a on 8/6/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
#include "mahalo.h"
#include "ChangoGenerator.h"
#include <opencv/cv.h>
class ChangoInput{

protected:
	Mahalo *m;
	ChangoGenerator *chango;
public:
    /*Constructor should run the input handler and return to end main()*/
    int retVal;
    ChangoInput();
    virtual ~ChangoInput(){}
    virtual void highlight(CvPoint p1, CvPoint p2) = 0;
};
