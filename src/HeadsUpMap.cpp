/*
 * HeadsUpMap.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */

#include "header.h"
#include "HeadsUpMap.h"


HeadsUpMap::HeadsUpMap(){
		h = MAP_HEIGHT;
		w = MAP_HEIGHT*1.3;
		x = width-w-RIGHT_MARGIN;
		y = TOP_MARGIN;
	}

	void HeadsUpMap::transform(int new_height, int new_width, int new_x, int new_y){
		h = new_height;
		w = new_width;
		x = new_x;
		y = new_y;
	}

	void HeadsUpMap::draw(){
		glViewport(width-w-RIGHT_MARGIN-MAP_HEIGHT*1.3, height-MAP_HEIGHT-TOP_MARGIN,  MAP_HEIGHT*1.3, MAP_HEIGHT);

		glPushMatrix();  //Make sure our transformations don't affect any other transformations in other code
		//glTranslateF(pRect->x, pRect->y);  //Translate rectangle to its assigned x and y position
		//Put other transformations here
		glBegin(GL_POLYGON);   //We want to draw a quad, i.e. shape with four sides
		glColor4f(0.0, 0.6, 0.6, 0.9);
		glVertex2f(-1, 0.8);
		glVertex2f(-0.8, 1);
		glVertex2f(1, 1);
		glVertex2f(1, -0.8);
		glVertex2f(0.8, -1);
		glVertex2f(-1, -1);
		glEnd();

		float bw = 0.03;

		glBegin(GL_POLYGON);   //We want to draw a quad, i.e. shape with four sides
		glColor4f(0.0, 0.3, 0.6, 0.3);
		glVertex2f(-1+bw, 0.8-bw);
		glVertex2f(-0.8+bw, 1-bw);
		glVertex2f(1-bw, 1-bw);
		glVertex2f(1-bw, -0.8+bw);
		glVertex2f(0.8-bw, -1+bw);
		glVertex2f(-1+bw, -1+bw);
		glEnd();
		glPopMatrix();

	}


