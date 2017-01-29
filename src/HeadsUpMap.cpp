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
extern std::atomic<double>	m_direction, m_pitch;
extern std::atomic<bool>	direction_changed;
extern std::atomic<bool>	location_changed;

extern void					getCoords();
extern void					getDirection();

extern std::atomic<bool> 	EXIT_THREADS;
std::atomic<bool> 			coordschanged (true);


HeadsUpMap::HeadsUpMap(){
	if (m_latitude == (double)0.0){
		getCoords();
	}
	getDirection();
}

int	HeadsUpMap::render(){
	getCoords();
	getDirection();
	tiles.render();
	for (auto& wp : interface.waypoints) wp->render();
	return 0;
}

	void HeadsUpMap::draw(){
		glViewport(width-RIGHT_MARGIN-MAP_WIDTH, height-MAP_HEIGHT-TOP_MARGIN,  MAP_WIDTH, MAP_HEIGHT);

		glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		{
			glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
			colour.bind();
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
		glRotatef(-m_pitch, 1, 0, 0);

		glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		{
			glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
			colour.bind();
			glVertex2f(0.0,0.0);
			glVertex2f(0.1,-0.1);
			glVertex2f(0.0,+0.1);
			glVertex2f(-0.1,-0.1);


			glEnd();
		}
		glPopAttrib();
		glPopMatrix();

	}

HeadsUpMap::~HeadsUpMap(){

}



