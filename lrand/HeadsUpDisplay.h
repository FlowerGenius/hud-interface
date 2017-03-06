/*
 * HeadsUpDisplay.h
 *
 *  Created on: Feb 27, 2017
 *      Author: erin
 */

#ifndef LRAND_HEADSUPDISPLAY_H_
#define LRAND_HEADSUPDISPLAY_H_

class HeadsUpDisplay {
public:
	HeadsUpDisplay();
	virtual ~HeadsUpDisplay();

	//TODO Task Module

	//TODO Battery Module

	//TODO Clock Module

	//TODO Map + Compass + Waypoint Module

	//TODO Background Tasks and Daemons Module

	//


	/* The height (in pixels) of the current display context */
	static int height;

	/* The width (in pixels) of the current display context */
	static int width;

	static std::vector<HeadsUpWaypoint*> waypoints;

	//Interface Proper main system
	static HeadsUpInterface interface;



};

#endif /* LRAND_HEADSUPDISPLAY_H_ */
