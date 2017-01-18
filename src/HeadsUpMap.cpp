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

extern void doGetCoords(TileBuilder);


HeadsUpMap::HeadsUpMap(){
		h = MAP_HEIGHT;
		w = MAP_WIDTH;
		x = width-w-RIGHT_MARGIN;
		y = TOP_MARGIN;
		tiles = TileBuilder();
		std::thread _t(doGetCoords, tiles);
		_t.detach();
		//coords = getCoords();
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


//		int hh = MAP_HEIGHT;
//		int ww = MAP_HEIGHT*1.3;
//
//		//std::vector<std::string> str = getTileUrls();
//		std::string str = getTileUrl(datsource);
//
//			glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//			{
//				glColor4f(0.5, 0.5, 0.5, 0.9);
//
//				glEnable(GL_TEXTURE_2D);
//				// Create Texture
//				glGenTextures(1, &tex);
//				glBindTexture(GL_TEXTURE_2D, tex); // 2d texture (x and y size)
//
//				glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
//				glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture
//
//				if (str != tilesource){
//					m_image =  curlImg(str.c_str());
//					tilesource = str;
//				}
//				glTexImage2D(GL_TEXTURE_2D, 0, 3, m_image.cols, m_image.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, m_image.data);
//
//				glBindTexture(GL_TEXTURE_2D, tex); // choose the texture to use.
//				glBegin(GL_QUADS);
//				glTexCoord2f (0.0, 0.0);
//				glVertex3f (-1.0,1.0, 0.1);
//				glTexCoord2f (1.0, 0.0);
//				glVertex3f (1.0, 1.0, 0.1);
//				glTexCoord2f (1.0, 1.0);
//				glVertex3f (1.0, -1.0, 0.1);
//				glTexCoord2f (0.0, 1.0);
//				glVertex3f (-1.0, -1.0, 0.1);
//
//				glEnd();
//				glDisable(GL_TEXTURE_2D);
//
//			}
//			glPopAttrib();

		tiles.draw();

	}



