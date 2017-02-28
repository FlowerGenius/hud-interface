/*
 * header.hpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */

#ifndef LRAND_LRAND_H_
#define LRAND_LRAND_H_


#if defined(unix) || defined(__unix__) || defined(__unix)
	#define OS_UNIX
#else
	#define NOUNIX
#endif

#if defined(linux) || defined(__linux) || defined(__linux__)
	#define OS_LINUX
	#if defined(__gnu_linux__)
		#define OS_GNU_LINUX
	#else
		#define NOGNU
	#endif
#else
	#define NOLINUX
#endif

#if defined(__NetBSD__)
	#define OS_NETBSD
#elif defined(__FreeBSD__)
	#define OS_FREEBSD
#elif defined(__OpenBSD__)
	#define OS_OPENBSD
#elif defined(__bsdi__)
	#define OS_BSDI
#elif defined(__DragonFly__)
	#define OS_DRAGONFLY
#else
	#define NOBSD
#endif

#include <lrand/rapidxml-1.13/rapidxml_print.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <codecvt>
#include <errno.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <locale>
#include <sstream>

#include <list>
#include <fstream>
#include <mutex>
#include <atomic>
#include <vector>
#include <thread>

#include <lrand/glad/glad.h>
#include <GLFW/glfw3.h>
#include "linmath.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <SOIL.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

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

#ifdef OS_LINUX
#include <Xm/MwmUtil.h>
#endif


#define USE_CHOOSE_FBCONFIG
#define MAP_FG 0.0,0.6,0.6,0.9
#define MAP_BG 0.0,0.3,0.6,0.3
#define CLOCK_HEIGHT

extern int height, width;
#define OBJECTIVE_TEXT_HEIGHT 	20
#define MAP_HEIGHT			  	(height / 5  )
#define MAP_WIDTH				(height / 5  )

#define BAT_WIDTH				(width  / 20 )
#define BAT_HEIGHT				BAT_WIDTH*0.4
#define BAT_FONT_SIZE			BAT_HEIGHT / 2

#define CLOCK_FONT_SIZE			BAT_HEIGHT

#define TOP_MARGIN				(height / 30)
#define RIGHT_MARGIN			(width  / 70)
#define TASK_TEXT_HEIGHT		25

enum MODE
{
	MODE_CPU = 0,
	MODE_GPU
};

#define FIRSTNAME  ""
#define LASTNAME   ""
#define MIDDLENAME ""

#define DOM			"https://"

#define LAN			"192.168.000.027/"
#define WAN 		"000.000.000.000/"
#define SRV			"leeresearchdev.ca/"
#define LOCAL_TASKS "/home/erin/.lrand/HUD/Tasks.xml"

#define EID			"data/worker/"+std::string(LASTNAME)+std::string(MIDDLENAME)+std::string(FIRSTNAME)

#define FIL			"tasks.xml"
#define	URL(x)		std::string(DOM)+std::string( x )+std::string(EID)+std::string(FIL)

#define COMPASS_FONT_SIZE 25
#define COL 0,200,255,255
//#define MODERN_OPENGL


class LANAccess;
class DeviceAccess;
class HeadsUpTask;
class WorldObject;
class HeadsUpWaypoint;
class HeadsUpObjective;
class HeadsUpTask;
class HeadsUpDisplay;
class HeadsUpBatteryInfo;
class Mesh;
class Model;
class Texture;
class TileBuilder;
class HeadsUpMap;
class HeadsUpDigitalClock;
class HeadsUpInterface;
class ScalableVectorString;


#include <lrand/LRAND/LRAND.h>
#include <lrand/LRAND/Shader.h>
#include <lrand/LRAND/Mesh.h>
//#include <lrand/LRAND/Texture.h>
#include <lrand/LRAND/Model.h>

#include <lrand/glstring/ScalableVectorString.h>
#include <lrand/GPS/GPS.h>
#include <lrand/LRAND/DeviceAccess.h>
#include <lrand/HeadsUpDisplay.h>
#include <lrand/LRAND/LANAccess.h>
#include <lrand/LRAND/Timer.hpp>
#include <lrand/LRAND/HeadsUpWaypoint.h>
#include <lrand/LRAND/HeadsUpObjective.h>
#include <lrand/LRAND/HeadsUpTask.h>
#include <lrand/LRAND/WorldObject.h>
#include <lrand/LRAND/HeadsUpBatteryInfo.h>
#include <lrand/LRAND/Tile.h>
#include <lrand/LRAND/TileBuilder.h>
#include <lrand/LRAND/HeadsUpMap.h>
#include <lrand/LRAND/HeadsUpDigitalClock.h>
#include <lrand/LRAND/HeadsUpInterface.h>



#endif /* LRAND_LRAND_H_ */
