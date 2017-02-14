/*
 * HeadsUpWaypoint.h
 *
 *  Created on: Jan 14, 2017
 *      Author: erin
 */

#ifndef LRAND_LRAND_HEADSUPWAYPOINT_H_
#define LRAND_LRAND_HEADSUPWAYPOINT_H_

class HeadsUpObjective;

class HeadsUpWaypoint {
public:
								HeadsUpWaypoint();
								HeadsUpWaypoint(HeadsUpObjective* o);
	virtual 					~HeadsUpWaypoint();

	int							setText(std::string);
	std::string 				getText(void);

	int							set(double,double,double alt = 0.0);
	int							set(gps::Point);

	int							setSize(int);
	int							setFill(bool);

	int							render(void);
	void						draw(void);

	HeadsUpObjective			*source;

	bool						active;

	double						scalarDistance();
	double						getBearing();
	gps::Vector					getVector();
	double						getPolarBearing(double target_bearing);
	double						getPolarPitch(double target_pitch);

	double 						getPitch();

	void 						setColour(int R,int G,int B,int A)	{ colour.set(R,G,B,A); label.setColour(colour); distance.setColour(colour); }
	void 						setColour(LRAND::Colour c)			{ colour = c;label.setColour(colour); distance.setColour(colour); }
protected:
	int							setIcon(void);

	gps::Point					get(void);
private:
	LRAND::Colour				colour;

	double 						distance_to, viewd, viewp;
	int 						k,j;
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


#endif /* LRAND_LRAND_HEADSUPWAYPOINT_H_ */
