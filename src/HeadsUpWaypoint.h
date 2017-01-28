/*
 * HeadsUpWaypoint.h
 *
 *  Created on: Jan 14, 2017
 *      Author: erin
 */

#ifndef HEADSUPWAYPOINT_H_
#define HEADSUPWAYPOINT_H_

class HeadsUpWaypoint {
public:
								HeadsUpWaypoint();
	virtual 					~HeadsUpWaypoint();

	int							setText(std::string);
	std::string 				getText(void);

	int 						setColour(int,int,int,int);


	int							set(double,double,double alt = 0.0);
	int							set(gps::Point);

	int							setSize(int);
	int							setFill(bool);

	int							render(void);
	void						draw(void);

	double						scalarDistance();
	double						getBearing();
	gps::Vector					getVector();
	double						getPolarBearing(double target_bearing);
	double 						getVerticalBearing();
protected:
	int							setIcon(void);

	gps::Point					get(void);
private:
	double 						distance_to, viewd;
	int 						r,g,b,k,j;
	double						a;
	int							size;
	std::string 				text;
	int filled;

	ScalableVectorString 		label;
	ScalableVectorString 		distance;

	gps::Point 					location;
	uchar*						icon;

	cv::Mat 					map_overlay;

	float						map_x,map_y;
	int							tile_x,tile_y,tile_z;

	bool						draw_fov;


};


#endif /* HEADSUPWAYPOINT_H_ */
