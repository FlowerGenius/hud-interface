/*
 * HeadsUpWaypoint.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: erin
 */

#include <lrand/lrand.h>

extern int tiley,tilex;
extern cv::Mat resultImg;
extern std::atomic<double> 	User::m_latitude;
extern std::atomic<double> 	User::m_longitude;
extern std::atomic<double>	User::m_direction;
extern std::atomic<double> 	User::m_pitch;
extern std::atomic<double>	User::m_roll;
extern std::atomic<double>	User::m_altitude;

extern float long2tilex(double lon, int z);
extern float lat2tiley(double lat, int z);
extern double sightLine();

namespace gps {
	extern double distance(gps::Point,gps::Point);
	extern double bearing(gps::Point,gps::Point);
	extern double metre2pixel(int,double);
	extern double polarBearing(double,double);
	extern double pitch(gps::Point,gps::Point);
	extern double polarPitch(double,double);
}

std::vector<HeadsUpWaypoint*> HeadsUpWaypoint::waypoints = {};

HeadsUpWaypoint::HeadsUpWaypoint(){
	// Null Colour initialization
	k = 0, j = 0;
	a = 1.0;
	// Null text initialization
	text 		= "";
	// Null icon initialization

	size 		= 10;
	filled 		= 1;

	viewd 		= 0.0;
	viewp		= 0.0;

	distance_to = 0.0;

	tile_x 		= 0;
	tile_y		= 0;
	map_x		= 0;
	map_y		= 0;
	tile_z 		= 17;

	active = false;
	draw_fov 	= false;
	icon 		= {};
}

HeadsUpWaypoint::HeadsUpWaypoint(HeadsUpObjective *o) : HeadsUpWaypoint() {
	source = o;
}

int HeadsUpWaypoint::setFill(bool b){
	if (b)
		filled = -1;
	else
		filled = 1;
	return filled;
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
	return 0;
}

std::string HeadsUpWaypoint::getText() {
	return text;
}

int HeadsUpWaypoint::set(double longitude, double latitude, double altitude){
	location.longitude = longitude;
	location.latitude = latitude;
	location.altitude = altitude;
	return 0;
}

int HeadsUpWaypoint::set(gps::Point p){
	location = p;
	tile_x 		= ((int) (floor(long2tilex(location.longitude, tile_z))));
	tile_y 		= ((int) (floor(lat2tiley(location.latitude, tile_z))));

	map_x 		= long2tilex(location.longitude, tile_z);
	map_y 		= lat2tiley(location.latitude, tile_z);

	return 0;
}

gps::Point HeadsUpWaypoint::get() {
	return location;
}

void HeadsUpWaypoint::draw() {

	if (distance_to <= sightLine()){
		if(-1.0 <= viewd and 1.0 >= viewd){
			distance.ldraw((int)((viewd*width/2) + (width/2)),
								((viewp)*height/2) + height/2 - (50.0f-log2(distance_to+0.1)*5.0f),
								0.1,50);
			label.ldraw((int)((viewd*width/2) + (width/2)), ((viewp)*height/2) + height/2,0.1,50);
			glViewport((int)((viewd*width/2) + (width/2)), ((viewp)*height/2) + height/2 - 2*(50.0f-log2(distance_to+0.1)*5.0f),15,15);

			glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
			colour.bind();
			glVertex2f(0.0,-1.0);
			glVertex2f(1.0,1.0);
			glVertex2f(-1.0,1.0);
			glEnd();

		} else if (viewd < -1.0 and viewd > -1.8) {
			label.ldraw((int)16, ((viewp)*height/2) + height/2,0.1,50);

			glViewport((int)0,((viewp)*height/2) + height/2,15,15);
			glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			{
				glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
				colour.bind();
				glVertex2f(1.0,1.0);
				glVertex2f(-1.0,0.0);
				glVertex2f(1.0,-1.0);
				glEnd();
			}
			glPopAttrib();
		} else if (viewd > 1.0 and viewd < 1.8){
			label.rdraw(16, ((viewp)*height/2) + height/2,0.1,50);

			glViewport(width - 15, ((viewp)*height/2) + height/2,15,15);
			glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			{
				glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
				colour.bind();
				glVertex2f(-1.0,1.0);
				glVertex2f(1.0,0.0);
				glVertex2f(-1.0,-1.0);
				glEnd();
			}glPopAttrib();
		} else {
			label.ldraw(-(int)(((viewd)*width/2) + (width/2)),16,0.1,50);
			glViewport(-(int)(((viewd)*width/2) + (width/2)),0,15,15);
			glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			{
				glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
				colour.bind();
				glVertex2f(0.0,-1.0);
				glVertex2f(1.0,1.0);
				glVertex2f(-1.0,1.0);
				glEnd();
			}
			glPopAttrib();
		}
	} else {
	if(-0.3 <= viewd and 0.3 >= viewd){

		glViewport((int)((viewd*width/2) + (width/2)) -12.5,height - TOP_MARGIN - CLOCK_FONT_SIZE,25,50);
		glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		{
		glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
		colour.bind();
		glVertex2f(0.0,0.4);
		glVertex2f(0.8,0.0);
		glVertex2f(0.0,-0.4);
		glVertex2f(-0.8,0.0);
		glEnd();
		}
		glPopAttrib();

	}
	}
	if ((j>=0) and (k>=0)){
		resultImg.copyTo(map_overlay);
		circle( map_overlay, cv::Point(256*k + 256*(map_x-tile_x),256*j + 256*(map_y-tile_y)), size, colour.BGR , filled*4, 8, 0 );
		cv::addWeighted(map_overlay,a,resultImg,1-a,0,resultImg);
	}
}

int HeadsUpWaypoint::render(){
	distance_to = scalarDistance();
	viewd = getPolarBearing(getBearing());
	viewp = getPolarPitch(getPitch());
	distance.setText(std::to_string(distance_to).erase(5)+"m",50.0f-log2(distance_to+0.1)*5.0f);
	label.setText(getText(), 100.0f-log2(distance_to+0.1)*10.0f);

	if ( tile_y == tiley-1){
		j=0;
	} else if ( tile_y == tiley){
		j=1;
	} else if ( tile_y == tiley+1){
		j=2;
	} else {
		j=-1;
	}

	if ( tile_x == tilex-1){
		k=0;
	} else if ( tile_x == tilex){
		k=1;
	} else if ( tile_x == tilex+1){
		k=2;
	} else {
		k=-1;
	}

	return 0;

}

void HeadsUpWaypoint::addWaypoint(HeadsUpWaypoint* w){
	HeadsUpWaypoint::waypoints.push_back(w);
}

void HeadsUpWaypoint::removeWaypoint(HeadsUpWaypoint* w){
	int i=0;
	for (auto& wp : waypoints){
		if (wp == w){
			waypoints.erase(waypoints.begin()+i);
		}
		i++;
	}
}

void HeadsUpWaypoint::addWaypoints(std::vector<HeadsUpWaypoint*> wps){
	for (auto& wp : wps) addWaypoint(wp);
}

double HeadsUpWaypoint::scalarDistance(){
	return 	gps::distance(gps::Point(User::m_latitude,User::m_longitude,User::m_altitude),location);
}
double HeadsUpWaypoint::getBearing(){
	return 	gps::bearing(gps::Point(User::m_latitude,User::m_longitude,User::m_altitude), location);
}
double HeadsUpWaypoint::getPolarBearing(double theta){
	return	gps::polarBearing(User::m_direction,theta);
}
double HeadsUpWaypoint::getPitch(){
	return	gps::pitch(gps::Point(User::m_latitude,User::m_longitude,User::m_altitude), location);
}
double HeadsUpWaypoint::getPolarPitch(double theta){
	return	gps::polarPitch(User::m_pitch,theta);
}

gps::Vector HeadsUpWaypoint::getVector(){
	return 	gps::Vector(gps::Point(User::m_latitude,User::m_longitude,User::m_altitude), location);
}

HeadsUpWaypoint::~HeadsUpWaypoint() {
	// TODO Auto-generated destructor stub
}

