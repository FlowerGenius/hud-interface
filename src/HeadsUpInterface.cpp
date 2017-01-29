/*
 * HeadsUpInterface.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */



#include "header.h"
#include "DeviceAccess.h"
#include "HeadsUpCompass.h"
#include "HeadsUpBatteryInfo.h"
#include "HeadsUpDigitalClock.h"
#include "TileBuilder.h"
#include "HeadsUpWaypoint.h"
#include "HeadsUpMap.h"
#include "HeadsUpCheckBox.h"
#include "HeadsUpWaypoint.h"
#include "HeadsUpObjective.h"
#include "HeadsUpTask.h"
#include "Timer.hpp"
#include "HeadsUpInterface.h"

extern std::atomic<bool>	direction_changed;
extern std::atomic<bool>	location_changed;

bool m_shutdown        = 		false;
bool m_use_buffer      = 		false;
bool m_demo_processing = 		true;
MODE m_mode            = 		MODE_CPU;

bool use_buffer()        		{ return m_use_buffer; }
void toggle_buffer()     		{ m_use_buffer = !m_use_buffer; }
MODE get_mode()          		{ return m_mode; }
void set_mode(MODE mode) 		{ m_mode = mode; }

extern cv::VideoCapture 		m_cap;
extern cv::Mat           		m_frame_bgr, m_frame_rgba,frame_gray;
extern cv::String         		m_oclDevName;
extern int 						height, width;

extern cv::CascadeClassifier 	face_cascade;

std::vector<cv::Rect> 			faces;
std::vector<cv::Rect> 			eyes;

Timer        					m_timer;


void drawCompass(HeadsUpCompass c){
		c.draw();
	}

	void drawClock(HeadsUpDigitalClock c){
		c.draw(MAP_WIDTH + BAT_WIDTH + RIGHT_MARGIN*4, height - 100);
	}

	void drawBat(HeadsUpBatteryInfo b){
		b.render();
		b.draw();
	}

	void drawMap(HeadsUpMap m){
		m.render();
		m.draw();
	}

	void drawTask(HeadsUpTask* t){
		t->drawGL();
	}

	HeadsUpInterface::HeadsUpInterface()
	{
		cam_mode = MODE_CPU;
		cam_do_buffer = false;
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_DEPTH_TEST);
		glViewport(0, 0, width, height);
		if (cv::ocl::haveOpenCL())
		{
			(void) cv::ogl::ocl::initializeContextFromGL();
		}

		m_oclDevName = cv::ocl::useOpenCL() ?
				cv::ocl::Context::getDefault().device(0).name() :
				(char*) "No OpenCL device";

}

	void detectEyes(size_t i, size_t j){
		cv::Point eye_center( faces[i].x + eyes[j].x + eyes[j].width/2, faces[i].y + eyes[j].y + eyes[j].height/2 );
		int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
		circle( m_frame_bgr, eye_center, radius, cv::Scalar( 255, 0, 0 ), 4, 8, 0 );
	}

	void detectFaces(size_t i){
		ellipse( m_frame_bgr,cv::Point( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 ), cv::Size( faces[i].width/2, faces[i].height/1.5 ), 0, 0, 360, cv::Scalar( 255, 167, 0 ), 4, 8, 0 );
//
//		cv::Mat faceROI = frame_gray( faces[i] );
//
//		//-- In each face, detect eyes
//		eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30) );
//
//		std::vector<std::thread> threads;
//		for ( size_t j = 0; j < eyes.size(); j++ )
//		{
//			threads.push_back(std::thread(detectEyes,i,j));
//		}
//		for (auto& th : threads) th.join();
	}



	int HeadsUpInterface::get_frame(cv::ogl::Texture2D& texture, cv::ogl::Buffer& buffer, bool do_buffer)
	{
		if (!m_cap.read(m_frame_bgr))
			return -1;


//		cv::cvtColor( m_frame_bgr, frame_gray, cv::COLOR_BGR2GRAY );
//		equalizeHist( frame_gray, frame_gray );
//		//-- Detect faces
//		face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30) );
//		std::vector<std::thread> threads;
//
//		for ( size_t i = 0; i < faces.size(); i++ )
//		{
//			threads.push_back(std::thread(detectFaces,i));
////			detectFaces(i);
//		}
//		for (auto& th : threads) th.join();

		cv::cvtColor(m_frame_bgr, m_frame_rgba, CV_RGB2RGBA);

		if (do_buffer)
			buffer.copyFrom(m_frame_rgba, cv::ogl::Buffer::PIXEL_UNPACK_BUFFER, true);
		else
			texture.copyFrom(m_frame_rgba, true);

		return 0;
	}

	void HeadsUpInterface::processFrameCPU(cv::ogl::Texture2D& texture, cv::ogl::Buffer& buffer, bool do_buffer)
	{
		cv::Mat m(height, width, CV_8UC4);

		m_timer.start();

		if (do_buffer)
			buffer.copyTo(m);
		else
			texture.copyTo(m);

		if (do_buffer)
			buffer.copyFrom(m, cv::ogl::Buffer::PIXEL_UNPACK_BUFFER, true);
		else
			texture.copyFrom(m, true);

		m_timer.stop();
	}

	void HeadsUpInterface::processFrameGPU(cv::ogl::Texture2D& texture, cv::ogl::Buffer& buffer, bool do_buffer)
	{
		cv::UMat u;

		m_timer.start();

		if (do_buffer)
			u = cv::ogl::mapGLBuffer(buffer);
		else
			cv::ogl::convertFromGLTexture2D(texture, u);

		if (m_demo_processing)
		{
			// blur texture image with OpenCV on GPU with OpenCL
			cv::blur(u, u, cv::Size(15, 15), cv::Point(-7, -7));
		}

		if (do_buffer)
			cv::ogl::unmapGLBuffer(u);
		else
			cv::ogl::convertToGLTexture2D(u, texture);

		m_timer.stop();
	}

	void HeadsUpInterface::changeColours(void)
	{
		compass.setColour(colour);
		map.setColour(colour);
		batinfo.setColour(colour);
		clockk.setColour(colour);
	}

	void HeadsUpInterface::updateGL(void)
	{
		drawGLComponents();
	}
	void HeadsUpInterface::updateX(void)
	{
		//getActiveTask().drawX();
	}

	void HeadsUpInterface::addTask(HeadsUpTask* t)
	{
		t->setColour(colour);
		tasks.push_back(t);
		if (tasks.size()==1){
			makeActiveTask(t);
		}
	}

	void HeadsUpInterface::addTasks(std::vector<HeadsUpTask*> tks){
		for (auto& tsk : tks) addTask(tsk);
	}

	void HeadsUpInterface::addWaypoint(HeadsUpWaypoint* w){
		waypoints.push_back(w);
	}

	void HeadsUpInterface::removeWaypoint(HeadsUpWaypoint* w){
		int i = 0;
		for (auto& wp : waypoints){
			if (wp == w){
				waypoints.erase(waypoints.begin()+i);
			}
			i++;
		}
	}

	void HeadsUpInterface::addWaypoints(std::vector<HeadsUpWaypoint*> wps){
		for (auto& wp : wps) addWaypoint(wp);
	}

	void HeadsUpInterface::makeActiveTask(HeadsUpTask* t)
	{
		tasks.remove(t);
		tasks.push_front(t);
	}



	void HeadsUpInterface::draw()
	{
		cam_texture.setAutoRelease(true);
		cam_buffer.setAutoRelease(true);

		cam_mode = get_mode();
		cam_do_buffer = use_buffer();

		if (get_frame(cam_texture, cam_buffer, cam_do_buffer) != 0)
		{

		}

		switch (cam_mode)
		{
		case MODE_CPU: // process frame on CPU
			processFrameCPU(cam_texture, cam_buffer, cam_do_buffer);
			break;

		case MODE_GPU: // process frame on GPU
			processFrameGPU(cam_texture, cam_buffer, cam_do_buffer);
			break;
		} // switch

		if (cam_do_buffer) // buffer -> texture
		{
			cv::Mat m(height, width, CV_8UC4);
			cam_buffer.copyTo(m);
			cam_texture.copyFrom(m, true);
		}

		glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		{
			glColor4f(0.5, 0.5, 0.5, 0.9);
			glLoadIdentity();

			glEnable(GL_TEXTURE_2D);
			cam_texture.bind();

			glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 0.1f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, 0.1f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, -1.0f, 0.1f);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 0.1f);
			glEnd();

			glDisable(GL_TEXTURE_2D);
		}
		glPopAttrib();

	}

	void HeadsUpInterface::drawGLComponents()
	{

		if (tasks.front()->isComplete()){
			tasks.pop_front();
		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glFlush();

		draw();
		drawClock(clockk);
		drawBat(batinfo);
		drawMap(map);
		drawCompass(compass);
		drawTask(tasks.front());

	}



