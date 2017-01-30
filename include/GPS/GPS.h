/*
 * Point.h
 *
 *  Created on: Jan 22, 2017
 *      Author: erin
 */

#ifndef INCLUDE_GPS_GPS_H_
#define INCLUDE_GPS_GPS_H_

namespace gps {

class Point {
public:
	Point();
	Point(double,double);
	Point(cv::Point2d);
	Point(double,double,double);
	Point(cv::Point3d);
	Point(std::string);
	virtual ~Point();
	double latitude;
	double longitude;
	double altitude;
};

class Vector {
public:
	Vector();
	Vector(Point,Point);
	Vector(double,double,double,double);
	Vector(double,double,double,double,double,double);
	virtual ~Vector();
	double distance;
	double bearing;
	double elevation;
};
} /* namespace gps */

#endif /* INCLUDE_GPS_GPS_H_ */
