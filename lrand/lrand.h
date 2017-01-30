/*
 * header.hpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */

#ifndef LRAND_LRAND_H_
#define LRAND_LRAND_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <codecvt>
#include <locale>
#include <errno.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <list>
#include <fstream>
#include <mutex>
#include <atomic>
#include <vector>
#include <thread>

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



#define USE_CHOOSE_FBCONFIG
#define MAP_FG 0.0,0.6,0.6,0.9
#define MAP_BG 0.0,0.3,0.6,0.3
#define COCK_HEIGHT

extern int height, width;
#define OBJECTIVE_TEXT_HEIGHT 	20
#define MAP_HEIGHT			  	(height / 5  )
#define MAP_WIDTH				MAP_HEIGHT
#define BAT_WIDTH				(width  / 20)
#define BAT_HEIGHT				BAT_WIDTH*0.4

#define CLOCK_FONT_SIZE			45

#define TOP_MARGIN				(height / 30)
#define RIGHT_MARGIN			(width  / 70)
#define TASK_TEXT_HEIGHT		25

enum MODE
{
	MODE_CPU = 0,
	MODE_GPU
};

#define LASTNAME	"lee/"
#define MIDDLENAME	"penelope/"
#define	FIRSTNAME	"erin/"

#define DOM			"https://"

#define LAN			"192.168.000.027/"
#define WAN 		"000.000.000.000/"
#define SRV			"leeresearchdev.ca/"
#define LOCAL_TASKS "/home/erin/workspace/HUD2/Tasks.xml"

#define EID			std::string(LASTNAME)+std::string(MIDDLENAME)+std::string(FIRSTNAME)

#define FIL			"tasks.xml"

#define COMPASS_FONT_SIZE 25
#define COL 0,200,255,255

class LANAccess;
class DeviceAccess;
class HeadsUpTask;
class HeadsUpWaypoint;
class HeadsUpObjective;
class HeadsUpTask;
class HeadsUpBatteryInfo;
class HeadsUpCheckBox;
class HeadsUpCompass;
class TileBuilder;
class HeadsUpMap;
class HeadsUpDigitalClock;
class HeadsUpInterface;
class ScalableVectorString;


#include <lrand/LRAND/LRAND.h>
#include <lrand/rapidxml-1.13/rapidxml.hpp>
#include <lrand/glstring/ScalableVectorString.h>
#include <lrand/GPS/GPS.h>
#include <lrand/LRAND/DeviceAccess.h>
#include <lrand/LRAND/LANAccess.h>
#include <lrand/LRAND/Timer.hpp>
#include <lrand/LRAND/HeadsUpWaypoint.h>
#include <lrand/LRAND/HeadsUpCheckBox.h>
#include <lrand/LRAND/HeadsUpObjective.h>
#include <lrand/LRAND/HeadsUpTask.h>
#include <lrand/LRAND/HeadsUpBatteryInfo.h>
#include <lrand/LRAND/HeadsUpCompass.h>
#include <lrand/LRAND/TileBuilder.h>
#include <lrand/LRAND/HeadsUpMap.h>
#include <lrand/LRAND/HeadsUpDigitalClock.h>
#include <lrand/LRAND/HeadsUpInterface.h>



#endif /* LRAND_LRAND_H_ */
