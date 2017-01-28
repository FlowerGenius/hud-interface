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

#define COMPASS_FONT_SIZE 25
#define COL 0,200,255,255

void HeadsUpCompass::draw(){

	glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	{
		glViewport(width/3,height - TOP_MARGIN - CLOCK_FONT_SIZE, width/3, CLOCK_FONT_SIZE);


		glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
		glColor4f(0.0, 0.37, 0.7, 0.2);
		glVertex2f(-1.0,0.1);
		glVertex2f(1.0,0.1);
		glVertex2f(1.0,-0.1);
		glVertex2f(-1.0,-0.1);
		glEnd();
		glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
		glColor4f(0.0, 0.27, 0.6, 0.9);
		glVertex2f(-1.0,0.01);
		glVertex2f(1.0,0.01);
		glVertex2f(1.0,-0.01);
		glVertex2f(-1.0,-0.01);
		glEnd();

		for(size_t j = 0; j < view.size();j++){
				viewd = gps::polarBearing(view[j],m_direction);
				if ( -0.3 <= viewd and viewd <= 0){
					card[j].rdraw(((viewd*width/2) + (width/2)),height - TOP_MARGIN - (CLOCK_FONT_SIZE + COMPASS_FONT_SIZE-card[j].getHeight())/2 , 1, COMPASS_FONT_SIZE);
				} else
				if ( 0 <= viewd and viewd <= 0.3){
					card[j].rdraw(((viewd*width/2) + (width/2)),height - TOP_MARGIN - (CLOCK_FONT_SIZE + COMPASS_FONT_SIZE-card[j].getHeight())/2 , 1, COMPASS_FONT_SIZE);
				}
			}
		glViewport(width/3,height - TOP_MARGIN - CLOCK_FONT_SIZE, width/3, CLOCK_FONT_SIZE);

		glColor4f(0.0, 0.67, 1.0, 0.5);

		glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
		glVertex2f(-1.0,1.0);
		glVertex2f(-0.95,1.0);
		glVertex2f(-0.9,0.0);
		glVertex2f(-0.95,-1.0);
		glVertex2f(-1.0,-1.0);
		glEnd();

		glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
		glVertex2f(1.0,1.0);
		glVertex2f(0.95,1.0);
		glVertex2f(0.9,0.0);
		glVertex2f(0.95,-1.0);
		glVertex2f(1.0,-1.0);
		glEnd();


	}
	glPopAttrib();
}


HeadsUpCompass::HeadsUpCompass() {

	N.setText("N");
	NNE.setText("NNE",COMPASS_FONT_SIZE/2);
	NE.setText("NE",COMPASS_FONT_SIZE/1.5);
	ENE.setText("ENE",COMPASS_FONT_SIZE/2);
	E.setText("E");
	ESE.setText("ESE",COMPASS_FONT_SIZE/2);
	SE.setText("SE",COMPASS_FONT_SIZE/1.5);
	SSE.setText("SSE",COMPASS_FONT_SIZE/2);
	S.setText("S");
	SSW.setText("SSW",COMPASS_FONT_SIZE/2);
	SW.setText("SW",COMPASS_FONT_SIZE/1.5);
	WSW.setText("WSW",COMPASS_FONT_SIZE/2);
	W.setText("W");
	WNW.setText("WNW",COMPASS_FONT_SIZE/2);
	NW.setText("NW",COMPASS_FONT_SIZE/1.5);
	NNW.setText("NNW",COMPASS_FONT_SIZE/2);

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
	viewNNE = 22.5;
	viewNE 	= 45.0;
	viewENE	= 67.50;

	viewE 	= 90.0;
	viewESE = 112.5;
	viewSE 	= 135.0;
	viewSSE = 157.5;

	viewS 	= 180.0;
	viewSSW = -157.5;
	viewSW 	= -135.0;
	viewWSW = -112.5;

	viewW 	= -90.0;
	viewWNW = -67.5;
	viewNW 	= -45.0;
	viewNNW = -22.5;

	card = {	N,NNE,NE,ENE,
				E,ESE,SE,SSE,
				S,SSW,SW,WSW,
				W,WNW,NW,NNW};

	view = {viewN,viewNNE,viewNE,viewENE,
			viewE,viewESE,viewSE,viewSSE,
			viewS,viewSSW,viewSW,viewWSW,
			viewW,viewWNW,viewNW,viewNNW};

	viewd = 0.0;
}

HeadsUpCompass::~HeadsUpCompass() {
	// TODO Auto-generated destructor stub
}

