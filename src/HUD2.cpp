/*
 ============================================================================
 Name        : HUD.cpp
 Author      : Erin Lee
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C++,
 ============================================================================
 */

#include <lrand/lrand.h>



#define LONGITUDE	-79.395293
#define LATITUDE	43.661802
int width, height;

GLFWwindow* window;
int mkk;



cv::Mat m_frame_bgr, m_frame_rgba, frame_gray;
cv::VideoCapture m_cap;
cv::String m_oclDevName;

cv::String face_cascade_name = "src/haarcascades/haarcascade_frontalface_alt.xml";
cv::String eyes_cascade_name = "src/haarcascades/haarcascade_eye_tree_eyeglasses.xml";
cv::CascadeClassifier face_cascade;
cv::CascadeClassifier eyes_cascade;

//Device Interaction
extern void getInformation();

//Compile time configuration settings

//Interface Proper main system
HeadsUpInterface interface;
std::vector<HeadsUpWaypoint*> waypoints;

//Threading management
std::atomic<bool> EXIT_THREADS;

//Task Management Subsystem


//Time Subsystem
extern void computerGetLocalTime();

//Power Management Subsystem
std::string 		battery_state;
std::string 		dev_battery_state;

std::atomic<double> battery_life;
std::atomic<double> dev_battery_life;
std::atomic<bool> 	is_charging;
std::atomic<bool> 	dev_is_charging;
std::atomic<bool> 	dev_is_connected;
extern void computerGetBatteryInformation();

//Map Subsystem
gps::Point			coords;
std::atomic<double> m_latitude;
std::atomic<double> m_longitude;
std::atomic<double> m_altitude;

std::atomic<double>	m_direction;
std::atomic<double> m_pitch;
std::atomic<double> m_roll;

std::atomic<bool>	direction_changed;
std::atomic<bool>	location_changed;

cv::Mat c0_image,c1_image,c2_image,
		c3_image,c4_image,c5_image,
		c6_image,c7_image,c8_image;
std::vector<cv::Mat> tiles = {
		c0_image,c1_image,c2_image,
		c3_image,c4_image,c5_image,
		c6_image,c7_image,c8_image
};


#if COMPUTER_GPS_ENABLED
void computerGetGeoLocation(){
	while(!EXIT_THREADS){
		getCoords();
	}
	puts("Geolocation Thread Exited Successfully");
}
#endif

#if COMPUTER_GYRO_ENABLED
void computerGetDirection(){
	while(!EXIT_THREADS){
		getDirection();
	}
	puts("Direction Thread Exited Successfully");
}
#endif

void deviceGetInformation(){
	while(!EXIT_THREADS){
		getInformation();
	}
	puts("Information Thread Exited Successfully");
}

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}
static void createTheWindow() {
	 glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		exit(EXIT_FAILURE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

}

static void createTheRenderContext() {
	glfwSetKeyCallback(window, key_callback);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
}


static void redrawTheWindow() {
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glFlush();
	interface.updateGL();
	glfwSwapBuffers(window);
	glfwPollEvents();

}

int main(int argc, char *argv[]) {

	char *loc;

	if (NULL != (loc = setlocale(LC_CTYPE, NULL)) )
	{
	printf("locale changed from '%s', ", loc);
	}

	if (NULL != (loc = setlocale(LC_CTYPE, "")) )
	{
	printf("to: '%s'\n", loc);
	}
	EXIT_THREADS = false;
	std::thread _bat_th(computerGetBatteryInformation);
	std::thread _clk_th(computerGetLocalTime);

//	dev_is_connected = true;
#if COMPUTER_GPS_ENABLED || COMPUTER_GYRO_ENABLED
	if (!dev_is_connected){
#if COMPUTER_GPS_ENABLED
		std::thread _geo_th(computerGetGeoLocation);
#endif
#if COMPUTER_GYRO_ENABLED
		std::thread _dir_th(computerGetDirection);
#endif
	} else {
#endif
		std::thread _get_di(deviceGetInformation);
#if COMPUTER_GPS_ENABLED || COMPUTER_GYRO_ENABLED
	}
#endif
	interface.setColour(0,167,255,200);

	createTheWindow();
	createTheRenderContext();

	cv::VideoCapture cap;

	if( !face_cascade.load( face_cascade_name ) ){ fprintf(stderr,"--(!)Error loading face cascade\n"); return -1; };
	if( !eyes_cascade.load( eyes_cascade_name ) ){ fprintf(stderr,"--(!)Error loading eyes cascade\n"); return -1; };

	cap.open(0);

	if (!cap.isOpened()) {
		fprintf(stderr,"can not open camera or video file\n");
		return -1;
	}
	m_cap = cap;


	interface.start_stuff();
	while (!glfwWindowShouldClose(window)) {
		redrawTheWindow();
	}

	EXIT_THREADS = true;
	if (_clk_th.joinable())
		_clk_th.join();
	if (_bat_th.joinable())
		_bat_th.join();

#if COMPUTER_GPS_ENABLED || COMPUTER_GYRO_ENABLED
	if (!dev_is_connected){
#if COMPUTER_GPS_ENABLED
		if (_geo_th.joinable())
			_geo_th.join();
#endif
#if COMPUTER_GYRO_ENABLED
		if (_dir_th.joinable())
			_dir_th.join();
#endif
	} else {
#endif
		if (_get_di.joinable())
			_get_di.join();
#if COMPUTER_GPS_ENABLED || COMPUTER_GYRO_ENABLED
	}
#endif
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
	return 0;
}
