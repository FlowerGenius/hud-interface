/*
 * header.hpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */

#ifndef HEADER_H_
#define HEADER_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glxext.h>

#include <X11/Xatom.h>
#include <X11/extensions/Xrender.h>
#include <X11/Xutil.h>
#include <X11/Xlibint.h>
#include <X11/keysym.h>

#include <curl/curl.h>

#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include "opencv2/core.hpp"
#include "opencv2/core/opengl.hpp"
#include "opencv2/core/ocl.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <highgui.h>

#include <memory>

#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>
#include <signal.h>

#include <Xm/MwmUtil.h>

#include <iostream>
#include <list>
#include <vector>
#include <thread>         // std::thread

#define USE_CHOOSE_FBCONFIG
#define MAP_FG 0.0,0.6,0.6,0.9
#define MAP_BG 0.0,0.3,0.6,0.3
#define COCK_HEIGHT


extern int height,width;
#define OBJECTIVE_TEXT_HEIGHT 	20
#define MAP_HEIGHT			  	(height / 5  )
#define MAP_WIDTH				MAP_HEIGHT*1.3

#define BAT_WIDTH				(width  / 20)
#define BAT_HEIGHT				BAT_WIDTH*0.4

#define CLOCK_FONT_SIZE			45

#define TOP_MARGIN				(height / 30)
#define RIGHT_MARGIN			(width  / 70)
#define TASK_TEXT_HEIGHT		25

#include "ScalableVectorString.h"

#endif /* HEADER_H_ */
