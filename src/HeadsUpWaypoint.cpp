/*
 * HeadsUpWaypoint.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: erin
 */

#include "header.h"
#include "HeadsUpWaypoint.h"

extern double m_longitude;
extern double m_latitude;

extern float mmx, mmy;

extern float long2tilex(double lon, int z);
extern float lat2tiley(double lat, int z);
extern std::pair<float, float> map_location;
std::pair<float, float> my_map_location;

HeadsUpWaypoint::HeadsUpWaypoint() {
	// TODO Auto-generated constructor stub
	r = 0, b = 0, g = 0, a = 0;
	text = "";
	//icon;

}

HeadsUpWaypoint::~HeadsUpWaypoint() {
	// TODO Auto-generated destructor stub
}

int HeadsUpWaypoint::setColour(int R, int G, int B, int A) {
	r = R, g = G, b = B, a = A;
	return 0;
}

int HeadsUpWaypoint::setIcon() {
	return 0;
}

int HeadsUpWaypoint::setText(std::string s) {
	text = s;
	return 0;
}

std::string HeadsUpWaypoint::getText() {
	return text;
}

int HeadsUpWaypoint::set(std::pair<double, double> coordinates) {
	gps_coordinates = coordinates;
	return 0;
}

std::pair<double, double> HeadsUpWaypoint::get() {
	return gps_coordinates;
}

void HeadsUpWaypoint::draw() {
	int z = 17;
	int x = ((int) (floor(long2tilex(gps_coordinates.first, z))));
	int y = ((int) (floor(lat2tiley(gps_coordinates.second, z))));
	my_map_location.first = (long2tilex(gps_coordinates.first, z) - x);
	my_map_location.second = (lat2tiley(gps_coordinates.second, z) - y);
	float mx = ((my_map_location.first * 2) - 1);
	float my = ((my_map_location.second * 2) - 1);
	fprintf(stderr, "%f %f\n", my_map_location.first, my_map_location.second);
//		if(std::fabs((float)gps_coordinates.first - (float)m_latitude) <= 0.002){ 					//If latitude is within the map window
//		if(std::fabs((float)gps_coordinates.second - (float)m_longitude) <= 0.002){				//If longitude is within the map window
	glPopAttrib();
	glViewport(width - RIGHT_MARGIN - MAP_WIDTH,
			height - MAP_HEIGHT - TOP_MARGIN, MAP_WIDTH, MAP_HEIGHT);

	glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	{
		glBegin(GL_POLYGON); //We want to draw a map, i.e. shape with four bevel sides
		glColor4f(1.0, 0.0, 1.0, 1.0);
		glVertex2f(mx - mmx + 0.0, mmy - my + 0.0);
		glVertex2f(mx - mmx + 0.1, mmy - my - 0.1);
		glVertex2f(mx - mmx + 0.0, mmy - my + 0.1);
		glVertex2f(mx - mmx - 0.1, mmy - my - 0.1);

		glEnd();
	}
	glPopAttrib();
//		}
//	}

}

