/*
 * HeadsUpWaypoint.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: erin
 */

#include "header.h"
#include "HeadsUpWaypoint.h"

extern int tiley,tilex;
extern cv::Mat resultImg;
extern double m_latitude,m_longitude;

extern float long2tilex(double lon, int z);
extern float lat2tiley(double lat, int z);
extern float rotation;

namespace gps {
	extern double distance(gps::Point,gps::Point);
	extern double bearing(gps::Point,gps::Point);
	extern double metre2pixel(int,double);
}

double sightLine(){
	return 1000.0;
}

HeadsUpWaypoint::HeadsUpWaypoint() {
	// Null Colour initialization
	r = 0, g = 0, b = 0;
	a = 1.0;
	// Null text initialization
	text = "";
	// Null icon initialization
	//icon;
	size = 10;
	animation = 10;
	filled = 1;

}

int HeadsUpWaypoint::setColour(int R, int G, int B, int A) {
	r = R, g = G, b = B;
	a = (double)(A/255.0);
	label.setColour(r,g,b,255);
	distance.setColour(r,g,b,255);
	return 0;
}

int HeadsUpWaypoint::setFill(bool b){
	if (b)
		filled = -1;
	else
		filled = 1;
}

int HeadsUpWaypoint::setIcon() {
	return 0;
}



int HeadsUpWaypoint::setSize(int radius_in_metres) {
	size = gps::metre2pixel(radius_in_metres,location.latitude);
	return 0;
}

int HeadsUpWaypoint::setText(std::string s) {
	text = s;
	label.setText(text);
	return 0;
}

std::string HeadsUpWaypoint::getText() {
	return text;
}

int HeadsUpWaypoint::set(double longitude, double latitude){
	location.longitude = longitude;
	location.latitude = latitude;
	return 0;
}

int HeadsUpWaypoint::set(gps::Point p){
	location = p;
	return 0;
}

gps::Point HeadsUpWaypoint::get() {
	return location;
}

void HeadsUpWaypoint::draw() {
	int z = 17;

	int x = ((int) (floor(long2tilex(location.longitude, z))));
	int y = ((int) (floor(lat2tiley(location.latitude, z))));

	float map_x = long2tilex(location.longitude, z);
	float map_y = lat2tiley(location.latitude, z);
	cv::Mat overlay;
	resultImg.copyTo(overlay);

	if ( x == tilex-1){
		if ( y == tiley-1){
			cv::Point waypoint_map_location(256*(map_x-x),256*(map_y-y));
			circle( overlay, waypoint_map_location, size, cv::Scalar( r, g, b), filled*4, 8, 0 );

		} else if ( y == tiley){
			cv::Point waypoint_map_location(256*(map_x-x),256 + 256*(map_y-y));
			circle( overlay, waypoint_map_location, size, cv::Scalar( r, g, b), filled*4, 8, 0 );

		} else if ( y == tiley+1){
			cv::Point waypoint_map_location(256*(map_x-x),256*2 + 256*(map_y-y));
			circle( overlay, waypoint_map_location, size, cv::Scalar( r, g, b), filled*4, 8, 0 );

		}
	} else if ( x == tilex){
		if ( y == tiley-1){
			cv::Point waypoint_map_location(256 + 256*(map_x-x),256*(map_y-y));
			circle( overlay, waypoint_map_location, size, cv::Scalar( b, g, r), filled*4, 8, 0 );

		} else if ( y == tiley){
			cv::Point waypoint_map_location(256 + 256*(map_x-x),256 + 256*(map_y-y));
			circle( overlay, waypoint_map_location, size, cv::Scalar( b, g, r), filled*4, 8, 0 );

		} else if ( y == tiley+1){
			cv::Point waypoint_map_location(256 + 256*(map_x-x),256*2+256*(map_y-y));
			circle( overlay, waypoint_map_location, size, cv::Scalar( b, g, r), filled*4, 8, 0 );

		}
	} else if ( x == tilex+1){
		if ( y == tiley-1){
			cv::Point waypoint_map_location(256*2 + 256*(map_x-x),256*(map_y-y));
			circle( overlay, waypoint_map_location, size, cv::Scalar( b, g, r), filled*4, 8, 0 );

		} else if ( y == tiley){
			cv::Point waypoint_map_location(256*2 + 256*(map_x-x),256 + 256*(map_y-y));
			circle( overlay, waypoint_map_location, size, cv::Scalar( b, g, r), filled*4, 8, 0 );

		} else if ( y == tiley+1){
			cv::Point waypoint_map_location(256*2 + 256*(map_x-x),256*2+256*(map_y-y));
			circle( overlay, waypoint_map_location, size, cv::Scalar( b, g, r), filled*4, 8, 0 );

		}
	}
	cv::addWeighted(overlay,a,resultImg,1-a,0,resultImg);


}
double d,angle,viewd;

void gpsGetWaypointVector(){

}


void HeadsUpWaypoint::render(){
	d = scalarDistance();
	angle = -getBearing();
	viewd = -(angle/90) + (rotation/90);
	if (angle > 0){
		angle = 180-angle;
	} else {
		angle = -(180+angle);
	}

	if (d <= sightLine()){

		distance.setText(std::to_string(d).erase(5)+"m");

		if (-1.0 <= viewd and viewd <= 1.0 ){
			label.ldraw((int)((viewd*width/2) + (width/2)),height/2, 0.1, 100 - log2(d+0.1)*10);
			distance.ldraw((int)((viewd*width/2) + (width/2)),height/2 - (52 - log2(d+0.1)*5), 0.1, 50 - log2(d+0.1)*5);

		}
	}

}

double HeadsUpWaypoint::scalarDistance(){
	return 	gps::distance(gps::Point(m_latitude,m_longitude),location);
}
double HeadsUpWaypoint::getBearing(){
	return 	gps::bearing(gps::Point(m_latitude,m_longitude), location);
}
gps::Vector HeadsUpWaypoint::getVector(){
	return 	gps::Vector(gps::Point(m_latitude,m_longitude), location);
}

HeadsUpWaypoint::~HeadsUpWaypoint() {
	// TODO Auto-generated destructor stub
}

