/*
 * HeadsUpCompass.cpp
 *
 *  Created on: Jan 23, 2017
 *      Author: erin
 */

#include <header.h>
#include "DeviceAccess.h"
#include <HeadsUpCompass.h>

extern std::atomic<double> m_direction;
extern int width,height;

namespace gps {
	extern double polarBearing(double,double);
}

#define COMPASS_FONT_SIZE 45
#define COL 0,160,255,255

void HeadsUpCompass::draw(){

	view = {viewN,viewNNE,viewNE,viewENE,
			viewE,viewESE,viewSE,viewSSE,
			viewS,viewSSW,viewSW,viewWSW,
			viewW,viewWNW,viewNW,viewNNW};

	double viewd;

	glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	{
		for(size_t j = 0; j < view.size();j++){
				viewd = gps::polarBearing(m_direction,-view[j]);
				if ( -0.333 <= viewd and viewd <= 0){
					card[j].ldraw(((viewd*width/2) + (width/2)),height - TOP_MARGIN - (CLOCK_FONT_SIZE + COMPASS_FONT_SIZE - fabs(viewd)*80)/2 , 1, COMPASS_FONT_SIZE - fabs(viewd)*130);
				} else
				if ( 0 <= viewd and viewd <= 0.333){
					card[j].ldraw(((viewd*width/2) + (width/2)),height - TOP_MARGIN - (CLOCK_FONT_SIZE + COMPASS_FONT_SIZE - fabs(viewd)*80)/2 , 1, COMPASS_FONT_SIZE - fabs(viewd)*130);
				}

			}
		glViewport(width/3,height - TOP_MARGIN - CLOCK_FONT_SIZE, width/3, CLOCK_FONT_SIZE);

		glColor4f(0.0, 0.0, 1.0, 1.0);

		glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
		glVertex2f(-1.0,1.0);
		glVertex2f(-0.99,1.0);
		glVertex2f(-0.99,-1.0);
		glVertex2f(-1.0,-1.0);
		glEnd();

		glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
		glVertex2f(1.0,1.0);
		glVertex2f(0.99,1.0);
		glVertex2f(0.99,-1.0);
		glVertex2f(1.0,-1.0);
		glEnd();
	}
	glPopAttrib();
}


HeadsUpCompass::HeadsUpCompass() {

	N.setText("N");
	NNE.setText("NNE",-4);
	NE.setText("NE",-2);
	ENE.setText("ENE",-4);
	E.setText("E");
	ESE.setText("ESE",-4);
	SE.setText("SE",-2);
	SSE.setText("SSE",-4);
	S.setText("S");
	SSW.setText("SSW",-4);
	SW.setText("SW",-2);
	WSW.setText("WSW",-4);
	W.setText("W");
	WNW.setText("WNW",-4);
	NW.setText("NW",-2);
	NNW.setText("NNW",-4);

	N.setColour(COL);
	NNE.setColour(COL);
	NE.setColour(COL);
	ENE.setColour(COL);
	E.setColour(COL);
	ESE.setColour(COL);
	SE.setColour(COL);
	SSE.setColour(COL);
	S.setColour(COL);
	SSW.setColour(COL);
	SW.setColour(COL);
	WSW.setColour(COL);
	W.setColour(COL);
	WNW.setColour(COL);
	NW.setColour(COL);
	NNW.setColour(COL);

	viewN 	= 0.0;
	viewNNE = -22.5;
	viewNE 	= -45.0;
	viewENE	= -67.50;

	viewE 	= -90.0;
	viewESE = -112.5;
	viewSE 	= -135.0;
	viewSSE = -157.5;

	viewS 	= -180.0;
	viewSSW = 157.5;
	viewSW 	= 135.0;
	viewWSW = 112.5;

	viewW 	= 90.0;
	viewWNW = 67.5;
	viewNW 	= 45.0;
	viewNNW = 22.5;

	card = {	N,NNE,NE,ENE,
				E,ESE,SE,SSE,
				S,SSW,SW,WSW,
				W,WNW,NW,NNW};
}

HeadsUpCompass::~HeadsUpCompass() {
	// TODO Auto-generated destructor stub
}

