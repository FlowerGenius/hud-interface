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

double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
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

Point::Point() {
	// TODO Auto-generated constructor stub
	latitude 	= 0.0;
	longitude 	= 0.0;
}

Point::Point(double lat, double lon){
	latitude 	= lat;
	longitude 	= lon;
}

Point::~Point() {
	// TODO Auto-generated destructor stub
}

Vector::Vector() {
	// TODO Auto-generated constructor stub
	distance = 0.0;
	bearing = 0.0;
}

Vector::Vector(Point,Point) {
	// TODO Auto-generated constructor stub
	distance = 0.0;
	bearing = 0.0;
}

Vector::Vector(double lat1, double lon1, double lat2, double lon2){
	distance = 0.0;
	bearing = 0.0;
// 	latitude 	= lat;
// 	longitude 	= lon;
}

Vector::~Vector() {
	// TODO Auto-generated destructor stub
}

} /* namespace gps */
