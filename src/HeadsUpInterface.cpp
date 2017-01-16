/*
 * HeadsUpInterface.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */



#include "header.h"
#include "HeadsUpBatteryInfo.h"
#include "HeadsUpDigitalClock.h"
#include "HeadsUpMap.h"
#include "HeadsUpCheckBox.h"
#include "HeadsUpObjective.h"
#include "HeadsUpTask.h"
#include "Timer.hpp"
#include "HeadsUpInterface.h"

enum MODE
{
	MODE_CPU = 0,
	MODE_GPU
};


bool m_shutdown        = false;
bool m_use_buffer      = false;
bool m_demo_processing = true;
MODE m_mode            = MODE_CPU;
bool use_buffer()        { return m_use_buffer; }
void toggle_buffer()     { m_use_buffer = !m_use_buffer; }
MODE get_mode()          { return m_mode; }
void set_mode(MODE mode) { m_mode = mode; }
std::list<HeadsUpTask> tasks;
std::list<HeadsUpObjective> current_objectives;
extern cv::VideoCapture m_cap;
extern cv::Mat            m_frame_bgr;
extern cv::Mat            m_frame_rgba;
extern cv::String         m_oclDevName;
extern int height,width;
extern Display *Xdisplay;
extern Window window_handle;

Timer        m_timer;


	HeadsUpInterface::HeadsUpInterface()
	{
		batteryLife = queryBatteryLife();
		waypointFontSize = 6;
	}

	int HeadsUpInterface::get_frame(cv::ogl::Texture2D& texture, cv::ogl::Buffer& buffer, bool do_buffer)
	{
		if (!m_cap.read(m_frame_bgr))
			return -1;

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

		//        if (m_demo_processing)
		//        {
		//            // blur texture image with OpenCV on CPU
		//            cv::blur(m, m, cv::Size(15, 15), cv::Point(-7, -7));
		//        }

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

	void HeadsUpInterface::initialize(void)
	{
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
		batinfo = HeadsUpBatteryInfo();
		clock = HeadsUpDigitalClock();
		map = HeadsUpMap();
	}

	void HeadsUpInterface::updateGL(void)
	{
		drawGLComponents();
	}
	void HeadsUpInterface::updateX(void)
	{
		//getActiveTask().drawX();

	}

	void HeadsUpInterface::addTask(HeadsUpTask t)
	{
		tasks.push_back(t);
		if (tasks.size()==1){
			makeActiveTask(t);
		}
	}

	void HeadsUpInterface::makeActiveTask(HeadsUpTask t)
	{

		tasks.remove(t);
		tasks.push_front(t);
		//current_objectives = t.objectives;
	}



	void HeadsUpInterface::drawXComponents()
	{

	}

	void HeadsUpInterface::drawGLComponents()
	{

		int r;
		cv::ogl::Texture2D texture;
		cv::ogl::Buffer buffer;

		texture.setAutoRelease(true);
		buffer.setAutoRelease(true);

		MODE mode = get_mode();
		bool do_buffer = use_buffer();

		r = get_frame(texture, buffer, do_buffer);
		if (r != 0)
		{

		}

		switch (mode)
		{
		case MODE_CPU: // process frame on CPU
			processFrameCPU(texture, buffer, do_buffer);
			break;

		case MODE_GPU: // process frame on GPU
			processFrameGPU(texture, buffer, do_buffer);
			break;
		} // switch

		if (do_buffer) // buffer -> texture
		{
			cv::Mat m(height, width, CV_8UC4);
			buffer.copyTo(m);
			texture.copyFrom(m, true);
		}

		XWindowAttributes window_attributes;
		XGetWindowAttributes(Xdisplay, window_handle, &window_attributes);
		glViewport(0, 0, window_attributes.width, window_attributes.height);

		glPushMatrix();

		glColor4f(0.5, 0.5, 0.5, 0.9);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

		glEnable(GL_TEXTURE_2D);
		//texture.bind();

		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 0.1f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, 0.1f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, -1.0f, 0.1f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 0.1f);
		glEnd();



		glDisable(GL_TEXTURE_2D);


		glPopMatrix();

		clock.draw(width - 650 ,height - 150);
		if (!tasks.front().isComplete()){
			tasks.front().drawGL();
		} else {
			tasks.pop_front();
			tasks.front().drawGL();
		}
		map.draw();


	}

	int HeadsUpInterface::queryBatteryLife()
	{
		return 100;
	}



