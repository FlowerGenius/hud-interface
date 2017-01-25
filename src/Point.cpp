/*
 * Point.cpp
 *
 *  Created on: Jan 22, 2017
 *      Author: erin
 */

#include <header.h>
#include <Point.h>
#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

namespace gps {

cv::Point2d gps2tile(gps::Point,int zoom){

}

double deg2rad(double deg) {
  return (deg * (pi / 180));
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * (180 / pi));
}

double pixel2metre(int pixels){
	double lat;
	return pixels*(earthRadiusKm*1000.0*cos(lat)/(2^(17+8)));
}

double metre2pixel(int metres, double lat){
	return metres/1.193;
}

double distance(gps::Point a,gps::Point b){
	  double lat1r, lon1r, lat2r, lon2r, u, v;
	  lat1r = deg2rad(a.latitude);
	  lon1r = deg2rad(a.longitude);
	  lat2r = deg2rad(b.latitude);
	  lon2r = deg2rad(b.longitude);
	  u = sin((lat2r - lat1r)/2);
	  v = sin((lon2r - lon1r)/2);
	  return 1000.0 * 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));

}

/*
 * Note: This function is part of the LRAND proprietary coordinate and direction
 * system. And as such a full explanation is included in the GPS.hpp file.
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
  const auto longitudeDifferenceRadians = deg2rad(b.longitude - a.longitude);
  auto latitude1Radian = deg2rad(a.latitude),
       latitude2Radian = deg2rad(b.latitude);

  const auto x = cos(latitude1Radian) * sin(latitude2Radian) -
                 sin(latitude1Radian) * cos(latitude2Radian) *
                 cos(longitudeDifferenceRadians);
  const auto y = sin(longitudeDifferenceRadians) * cos(latitude2Radian);


  return rad2deg(atan2(y, x));
}


/*
 * Note: This function is part of the LRAND proprietary coordinate and direction
 * system. And as such a full explanation is included in the GPS.hpp file.
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
	double polar;
	if (-180 <= current_bearing and current_bearing < -90){
		if (target_bearing < 0){
			polar =  (target_bearing/90) - (current_bearing/90);
		} else {
			polar =  ((target_bearing-360)/90) - (current_bearing/90);
		}
	} else
	if ( -90 <= current_bearing and current_bearing <= 90){
		polar =  (target_bearing/90) - (current_bearing/90);
	} else
	if ( 90  < current_bearing and current_bearing <= 180){
		if (target_bearing > 0){
			polar =  (target_bearing/90) - (current_bearing/90);
		} else {
			polar =  ((target_bearing+360)/90) - (current_bearing/90);
		}
	}
	return polar;
}

double elevation(gps::Point a, gps::Point b){
	return b.altitude - a.altitude;
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

Point::~Point() {
	// TODO Auto-generated destructor stub
}

Vector::Vector() {
	// TODO Auto-generated constructor stub
	distance = 0.0;
	bearing = 0.0;
	elevation = 0.0;
}

Vector::Vector(Point p1,Point p2) {
	// TODO Auto-generated constructor stub
	distance 	= gps::distance(p1,p2);
	bearing	 	= gps::bearing(p1,p2);
	elevation 	= gps::elevation(p1,p2);
}

Vector::Vector(double lat1, double lon1, double lat2, double lon2){
	distance 	= gps::distance(gps::Point(lat1,lon1),gps::Point(lat2,lon2));
	bearing	 	= gps::bearing(gps::Point(lat1,lon1),gps::Point(lat2,lon2));
	elevation 	= 0.0;
}
Vector::Vector(double lat1, double lon1, double alt1, double lat2, double lon2, double alt2){
	distance 	= gps::distance(gps::Point(lat1,lon1),gps::Point(lat2,lon2));
	bearing	 	= gps::bearing(gps::Point(lat1,lon1),gps::Point(lat2,lon2));
	elevation 	= gps::elevation(gps::Point(lat1,lon1,alt1),gps::Point(lat2,lon2,alt2));
}

Vector::~Vector() {
	// TODO Auto-generated destructor stub
}

} /* namespace gps */
