/*
 * HeadsUpWaypoint.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: erin
 */

#include "header.h"
#include "HeadsUpWaypoint.h"

HeadsUpWaypoint::HeadsUpWaypoint() {
	// TODO Auto-generated constructor stub
	r=0,b=0,g=0,a=0;
	text="";
	//icon;

}

HeadsUpWaypoint::~HeadsUpWaypoint() {
	// TODO Auto-generated destructor stub
}

int HeadsUpWaypoint::setColour(int R,int G,int B, int A){
	return 0;
}

int HeadsUpWaypoint::setIcon(){
	return 0;
}

int HeadsUpWaypoint::setText(std::string s){
	return 0;
}

std::string HeadsUpWaypoint::getText(){
	return text;
}

int HeadsUpWaypoint::set(std::pair<double,double> coordinates){
	return 0;
}

std::pair<double,double> HeadsUpWaypoint::get(){
	return gps_coordinates;
}

void HeadsUpWaypoint::draw(){

}

