/*
 * HeadsUpObjective.cpp
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

extern HeadsUpInterface interface;
extern int height, width;
extern double m_latitude,m_longitude, m_altitude;

Objective::~Objective(){

}

HeadsUpObjective::HeadsUpObjective(){
	name 				= 	"";
	active_stage 		= 	0;
	completed 			= 	false;
	remove_on_complete	= 	true;
	state_changed 		= 	true;

	a=255,r=255,b=255,g=255;
}

HeadsUpObjective::HeadsUpObjective(std::string n,int i){
	name 				= 	n;
	active_stage 		= 	i;
	completed 			= 	false;
	remove_on_complete	= 	true;
	state_changed 		= 	true;
	a=255,r=255,b=255,g=255;
}

HeadsUpObjective::HeadsUpObjective(std::string n, int i,gps::Point loc) : HeadsUpObjective(n,i) {
	location = loc;
}

void HeadsUpObjective::drawGL(int position) {
	checkState();
	check.draw(completed, width - RIGHT_MARGIN - 20,
			50 + TOP_MARGIN + MAP_HEIGHT + (position * 30));
	obj_text.setText(getName());
	obj_text.setColour(r, g, b, a);
	obj_text.rdraw(RIGHT_MARGIN + 30,
			height - (60 + TOP_MARGIN + MAP_HEIGHT + (position * 30)), 1.1,
			OBJECTIVE_TEXT_HEIGHT);
	state_changed = false;
}

std::string HeadsUpObjective::getName() {
	return name;
}

void HeadsUpObjective::toggle() {
	if (completed)
		completed = false;
	else
		completed = true;
}

int HeadsUpObjective::getStage() {
	return active_stage;
}

void HeadsUpObjective::checkState(){
	//Virtual Method
}

void SpecificLocationObjective::checkState(){
	if (m_latitude - 0.0003 <= location.latitude and m_latitude + 0.0003 >= location.latitude and
			m_longitude - 0.0003 <= location.longitude and m_longitude + 0.0003 >= location.longitude and
				m_altitude - 0.0003 <= location.altitude and m_altitude + 0.0003 >= location.altitude){
		completed=true;
		if (remove_on_complete){
			setColour(100,100,100,a);
			interface.removeWaypoint(&waypoint);
		}
	}
}

void AreaLocationObjective::checkState(){
	if (m_latitude - (double)radius/111111.0 <= location.latitude and m_latitude + (double)radius/111111.0 >= location.latitude and
			m_longitude - (double)radius/111111.0 <= location.longitude and m_longitude + (double)radius/111111.0 >= location.longitude){
		completed=true;
		if (remove_on_complete){
			setColour(100,100,100,a);
			interface.removeWaypoint(&waypoint);
		}
	}
}

void SpecificLocationObjective::initWaypoint(){
	interface.addWaypoint(&waypoint);
}
void AreaLocationObjective::initWaypoint(){
	interface.addWaypoint(&waypoint);
}


HeadsUpObjective::~HeadsUpObjective(){

}
