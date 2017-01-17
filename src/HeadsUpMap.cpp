/*
 * HeadsUpMap.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */

#include "header.h"
#include "TileBuilder.h"

#include "HeadsUpMap.h"

#define LONGITUDE	-79.397433
#define LATITUDE	43.662314

double m_latitude =LATITUDE;
double m_longitude = LONGITUDE;


std::string dsource = "http://a.tile.openstreetmap.org";
TileBuilder tiles = TileBuilder(dsource,18);


HeadsUpMap::HeadsUpMap(){
		h = MAP_HEIGHT;
		w = MAP_WIDTH;
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

		glViewport(width-w-RIGHT_MARGIN-MAP_WIDTH, height-MAP_HEIGHT-TOP_MARGIN,  MAP_WIDTH, MAP_HEIGHT);

		glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		{
			glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
			glColor4f(0.0, 0.6, 0.6, 0.9);
			glVertex2f(-1, 0.8);
			glVertex2f(-0.8, 1);
			glVertex2f(1, 1);
			glVertex2f(1, -0.8);
			glVertex2f(0.8, -1);
			glVertex2f(-1, -1);
			glEnd();
		}
		glPopAttrib();


		float bw = 0.03;



		//fprintf(stderr,"%s",str.c_str());



	}


