/*
 * HeadsUpObjective.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */

#include "header.h"
#include "HeadsUpWaypoint.h"
#include "HeadsUpCheckBox.h"
#include "HeadsUpObjective.h"
extern int height, width;
extern std::vector<HeadsUpWaypoint> waypoints;
extern double m_latitude,m_longitude;

Objective::~Objective(){

}

HeadsUpObjective::HeadsUpObjective(){
	puts("new objective");
	name = "";
	active_stage = 0;
	completed = false;
	state_changed = true;
}

HeadsUpObjective::HeadsUpObjective(std::string n,int i){
	puts("new objective");
	name = n;
	active_stage = i;
	completed = false;
	state_changed = true;
}

HeadsUpObjective::HeadsUpObjective(std::string n, int i,gps::Point loc) : HeadsUpObjective(n,i) {
	location = loc;
}

void HeadsUpObjective::drawGL(int position) {
	checkState();
	check.draw(completed, width - RIGHT_MARGIN - 20,
			50 + TOP_MARGIN + MAP_HEIGHT + (position * 30));
	obj_text.setText(getName());
	obj_text.setColour(255, 255, 255, 200);
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
			m_longitude - 0.0003 <= location.longitude and m_longitude + 0.0003 >= location.longitude){
		completed=true;
	}
}

void AreaLocationObjective::checkState(){
	if (m_latitude - radius <= location.latitude and m_latitude + radius >= location.latitude and
			m_longitude - radius <= location.longitude and m_longitude + radius >= location.longitude){
		completed=true;
	}
}

void HeadsUpObjective::initWaypoint(){
	waypoints.push_back(waypoint);
}

HeadsUpObjective::~HeadsUpObjective(){

}
