/*
 * Point.cpp
 *
 *  Created on: Jan 22, 2017
 *      Author: erin
 */

#include <lrand/lrand.h>

extern double lat2tiley(double,int);
extern double long2tilex(double,int);

#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

namespace gps {

double u,v;

cv::Point2d gps2tile(gps::Point p,int zoom){
	return cv::Point2d(long2tilex(p.longitude, zoom),lat2tiley(p.latitude, zoom));
}

double deg2rad(double deg) {
  return (deg * (pi / 180));
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * (180 / pi));
}

double pixel2metre(int pixels,double lat){
	return pixels*(earthRadiusKm*1000.0*cos(lat)/(2^(17+8)));
}

double metre2pixel(int metres, double lat){
	return metres/1.193;
}

double elevation(gps::Point a, gps::Point b){
	return b.altitude - a.altitude;
}


double distance(gps::Point a,gps::Point b){
	  u = sin((deg2rad(b.latitude) - deg2rad(a.latitude))/2);
	  v = sin((deg2rad(b.longitude) - deg2rad(a.longitude))/2);
	  return sqrt(pow((1000.0 * 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(deg2rad(a.latitude)) * cos(deg2rad(b.latitude)) * v * v))),2.0) + pow(elevation(a,b),2.0));
}

double pitch(gps::Point a, gps::Point b){
	return rad2deg(asin(elevation(a,b) / distance(a,b)));
}


/*
 * Note: This function is part of the LRAND proprietary coordinate and direction
 * system. And as such a full explanation is included in the GPS.h file.
 *
 * Return a fixed direction bearing, the definition of which follows:
 *
 * 		A bearing of 	0 	degrees indicates NORTH
 * 		A bearing of   45	degrees indicates NORTH EAST
 * 		A bearing of   90	degrees indicates EAST
 * 		A bearing of  135	degrees indicates SOUTH EAST
 * 		A bearing of  180   degrees indicates SOUTH
 *
 *		A bearing of    0   degrees indicates NORTH
 *		A bearing of  -45   degrees indicates NORTH WEST
 *		A bearing of  -90	degrees indicates WEST
 *		A bearing of -135	degrees indicates SOUTH WEST
 *		A bearing of -180   degrees indicates SOUTH
 *
 */
double bearing (gps::Point a, gps::Point b)
{
  u = cos(deg2rad(a.latitude)) * sin(deg2rad(b.latitude)) -
                 sin(deg2rad(a.latitude)) * cos(deg2rad(b.latitude)) *
                 cos(deg2rad(b.longitude - a.longitude));
  v = sin(deg2rad(b.longitude - a.longitude)) * cos(deg2rad(b.latitude));
  return rad2deg(atan2(v, u));
}


/*
 * Note: This function is part of the LRAND proprietary coordinate and direction
 * system. And as such a full explanation is included in the GPS.h file.
 *
 * Return a relative direction bearing, the definition of which is as follows:
 *
 * 		A bearing of 0.0 indicates the direction FORWARD or exact middle of the FOV
 * 		A bearing of 1.0 indicates the far RIGHT of the 180 degree FOV
 *		A bearing of -1.0 indicates the far LEFT of the 180 degree FOV
 *
 * The FOV (field of view) measures 90 degrees to left and right of the current
 * bearing.
 *
 *
 */
double polarBearing(double current_bearing, double target_bearing)
{
	if (-180 <= current_bearing and current_bearing < -90){
		if (target_bearing < 0){
			u =  (target_bearing/90) - (current_bearing/90);
		} else {
			u =  ((target_bearing-360)/90) - (current_bearing/90);
		}
	} else
	if ( -90 <= current_bearing and current_bearing <= 90){
			u =  (target_bearing/90) - (current_bearing/90);
	} else
	if ( 90  < current_bearing and current_bearing <= 180){
		if (target_bearing > 0){
			u =  (target_bearing/90) - (current_bearing/90);
		} else {
			u =  ((target_bearing+360)/90) - (current_bearing/90);
		}
	}
	return u;
}

double polarPitch(double current_pitch, double target_pitch)
{
	if (-180 <= current_pitch and current_pitch < -90){
		if (target_pitch < 0){
			u =  (target_pitch/90) - (current_pitch/90);
		} else {
			u =  ((target_pitch-360)/90) - (current_pitch/90);
		}
	} else
	if ( -90 <= current_pitch and current_pitch <= 90){
			u =  (target_pitch/90) - (current_pitch/90);
	} else
	if ( 90  < current_pitch and current_pitch <= 180){
		if (target_pitch > 0){
			u =  (target_pitch/90) - (current_pitch/90);
		} else {
			u =  ((target_pitch+360)/90) - (current_pitch/90);
		}
	}
	return u;
}



Point::Point() {
	latitude 	= 0.0;
	longitude 	= 0.0;
	altitude	= 0.0;
}

Point::Point(double lat, double lon){
	latitude 	= lat;
	longitude 	= lon;
	altitude	= 0.0;
}

Point::Point(cv::Point2d p){
	latitude 	= p.x;
	longitude 	= p.y;
	altitude	= 0.0;
}

Point::Point(double lat, double lon, double alt){
	latitude 	= lat;
	longitude 	= lon;
	altitude	= alt;
}

Point::Point(cv::Point3d p){
	latitude 	= p.x;
	longitude 	= p.y;
	altitude	= p.z;
}

Point::Point(std::string s){
	longitude	= std::atof(s.substr(0,s.substr(0).find('@')).c_str());
	latitude 	= std::atof(s.substr(s.substr(0).find('@')+1,s.substr(s.substr(0).find('@')+1).find('@')).c_str());
	altitude 	= std::atof(s.substr(s.rfind('@')+1).c_str());
}

Point::~Point() {
}

Vector::Vector() {
	distance = 0.0;
	bearing = 0.0;
	elevation = 0.0;
}

Vector::Vector(Point p1,Point p2) {
	distance 	= gps::distance(p1,p2);
	bearing	 	= gps::bearing(p1,p2);
	elevation 	= gps::pitch(p1,p2);
}

Vector::Vector(double lat1, double lon1, double lat2, double lon2){
	distance 	= gps::distance(gps::Point(lat1,lon1),gps::Point(lat2,lon2));
	bearing	 	= gps::bearing(gps::Point(lat1,lon1),gps::Point(lat2,lon2));
	elevation 	= 0.0;
}
Vector::Vector(double lat1, double lon1, double alt1, double lat2, double lon2, double alt2){
	distance 	= gps::distance(gps::Point(lat1,lon1),gps::Point(lat2,lon2));
	bearing	 	= gps::bearing(gps::Point(lat1,lon1),gps::Point(lat2,lon2));
	elevation 	= gps::pitch(gps::Point(lat1,lon1,alt1),gps::Point(lat2,lon2,alt2));
}

Vector::~Vector() {
}

} /* namespace gps */
