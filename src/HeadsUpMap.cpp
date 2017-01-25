/*
 * HeadsUpMap.cpp
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

extern HeadsUpInterface 	interface;

extern std::atomic<double> 	m_latitude;
extern std::atomic<double> 	m_longitude;
extern std::atomic<double>	m_direction;

extern void					getCoords();
extern void					getDirection();

extern std::atomic<bool> 	EXIT_THREADS;
std::atomic<bool> 			coordschanged (true);

void computerGetGeoLocation(){
	while(!EXIT_THREADS){
		getCoords();
	}
	puts("Geolocation Thread Exited Successfully");
}

void computerGetDirection(){
	while(!EXIT_THREADS){
		getDirection();
	}
	puts("Direction Thread Exited Successfully");
}

HeadsUpMap::HeadsUpMap(){
	if (m_latitude == (double)0.0){
		getCoords();
	}
	getDirection();
}

	void HeadsUpMap::draw(){
		//		if (m_direction < 180){
		//				m_direction = m_direction + 1;
		//		} else { m_direction = -180;}

		//m_direction = -90;
		glViewport(width-RIGHT_MARGIN-MAP_WIDTH, height-MAP_HEIGHT-TOP_MARGIN,  MAP_WIDTH, MAP_HEIGHT);

		glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		{
			glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
			//glColor4f(0.0, 0.6, 0.6, 0.9);
			glVertex2f(-1, 0.8);
			glVertex2f(-0.8, 1);
			glVertex2f(1, 1);
			glVertex2f(1, -0.8);
			glVertex2f(0.8, -1);
			glVertex2f(-1, -1);
			glEnd();
		}
		glPopAttrib();
		glViewport(width-RIGHT_MARGIN-MAP_WIDTH+2, height-MAP_HEIGHT-TOP_MARGIN+2,  MAP_WIDTH-4, MAP_HEIGHT-4);

		tiles.draw();

		glPushMatrix();
		glRotatef(-m_direction, 0, 0, 1);
		glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		{
			glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
			glColor4f(0.0, 0.0, 1.0, 1.0);
			glVertex2f(0.0,0.0);
			glVertex2f(0.1,-0.1);
			glVertex2f(0.0,+0.1);
			glVertex2f(-0.1,-0.1);


			glEnd();
		}
		glPopAttrib();
		glPopMatrix();

		for (auto& wp : interface.waypoints) wp->render();


	}



