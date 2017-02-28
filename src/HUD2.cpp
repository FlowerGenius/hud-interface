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

GLuint VBO, VAO, EBO;

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

    if (key == GLFW_KEY_S && action == GLFW_PRESS)
    	m_latitude = m_latitude - 0.00003;

    if (key == GLFW_KEY_W && action == GLFW_PRESS)
		m_latitude = m_latitude + 0.00003;

    if (key == GLFW_KEY_A && action == GLFW_PRESS)
		m_longitude = m_longitude - 0.00003;

	if (key == GLFW_KEY_D && action == GLFW_PRESS)
		m_longitude = m_longitude + 0.00003;

    if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
    	m_direction = m_direction + 1;

    if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
    	m_direction = m_direction - 1;

    if (key == GLFW_KEY_DOWN && action == GLFW_PRESS){
    	m_pitch = m_pitch - 1;
    }

	if (key == GLFW_KEY_UP && action == GLFW_PRESS){
		m_pitch = m_pitch + 1;
	}

}
static void createTheWindow() {
	 glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		exit(EXIT_FAILURE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	window = glfwCreateWindow(1920, 1080, "LRAND Heads Up Display Program v0.1a",  glfwGetPrimaryMonitor(), NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

}

Model ourModel;
Shader ourShader;

static void createTheRenderContext() {
	glfwSetKeyCallback(window, key_callback);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
	Shader().loadStaticShaders();
//    glEnable(GL_DEPTH_TEST);
//	ourShader = Shader("/home/erin/workspace/HUD2/lrand/shaders/model_loading.vs", "/home/erin/workspace/HUD2/lrand/shaders/model_loading.frag");
//    ourModel = Model("/home/erin/untitled.obj");

}

static void redrawTheWindow() {
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    glClearColor(0.0f,0.0f,0.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//	ourShader.Use();

	HeadsUpDisplay::interface.updateGL();

//	glm::mat4 model;
//	model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f)); // Translate it down a bit so it's at the center of the scene
//	model = glm::scale(model, glm::vec3(0.02f, 0.0002f, 0.0002f));	// It's a bit too big for our scene, so scale it down
//	glUniformMatrix4fv(glGetUniformLocation(ourShader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
//	ourModel.Draw(ourShader);
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
	HeadsUpDisplay::interface.setColour(0,167,255,200);

	createTheWindow();
	createTheRenderContext();

//	cv::VideoCapture cap;
//
//	if( !face_cascade.load( face_cascade_name ) ){ fprintf(stderr,"--(!)Error loading face cascade\n"); return -1; };
//	if( !eyes_cascade.load( eyes_cascade_name ) ){ fprintf(stderr,"--(!)Error loading eyes cascade\n"); return -1; };
//
//	cap.open(0);
//
//	if (!cap.isOpened()) {
//		fprintf(stderr,"can not open camera or video file\n");
//		return -1;
//	}
//	m_cap = cap;

	HeadsUpDisplay::interface.start_stuff();

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
