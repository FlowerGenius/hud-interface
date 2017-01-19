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
	void						draw(void);
protected:
	int							setIcon(void);
	int							set(std::pair<double,double>);
	std::pair<double,double>	get(void);
	std::string 				getText(void);
private:
	int r,g,b,a;
	std::pair<double,double>   	gps_coordinates;
	std::string text;
	//uchar*		icon;
};


#endif /* HEADSUPWAYPOINT_H_ */
