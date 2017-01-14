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
	virtual ~HeadsUpWaypoint();
	void	changeText();
	void 	changeColour();
	void	setPos();
	void	getPos();
protected:
	//std::string text;
	int r,g,b,a;
};


#endif /* HEADSUPWAYPOINT_H_ */
