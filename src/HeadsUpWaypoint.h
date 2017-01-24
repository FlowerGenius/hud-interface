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
	int 						setColour(int,int,int,int);
	int							set(double,double);
	int							set(gps::Point);
	int							setSize(int);
	int							setFill(bool);
	void						draw(void);
	void						render(void);
	double						scalarDistance();
	double						getBearing();
	gps::Vector					getVector();
protected:
	int							setIcon(void);

	gps::Point					get(void);

	std::string 				getText(void);
private:
	int 						r,g,b;
	double						a;
	std::pair<double,double>	gps_coordinates;
	int							size;
	std::string 				text;
	int filled;
	ScalableVectorString 		label;
	ScalableVectorString 		distance;
	int 						animation;
	gps::Point 					location;
	//uchar*					icon;
};


#endif /* HEADSUPWAYPOINT_H_ */
