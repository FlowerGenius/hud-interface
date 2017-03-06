/*
a * HeadsUpMap.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */

#include <lrand/lrand.h>

extern std::atomic<bool>	direction_changed;
extern std::atomic<bool>	location_changed;

extern void					getCoords();
extern void					getDirection();

extern std::atomic<bool> 	EXIT_THREADS;
std::atomic<bool> 			coordschanged (true);

extern Shader interfaceShader;
namespace gps {
	extern double polarBearing(double,double);
}
HeadsUpMap::HeadsUpMap(){
	if (User::m_latitude == (double)0.0){
		getCoords();
	}
	getDirection();

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

	card = {	N,NNE,NE,ENE,
				E,ESE,SE,SSE,
				S,SSW,SW,WSW,
				W,WNW,NW,NNW};

	for (auto& lo : card) lo.setColour(colour);

	view = {0.0,22.5,45.0,67.50,90.0,112.5,135.0,157.5,180.0, -157.5,-135.0,-112.5,-90,-67.5,-45.0,-22.5};
	viewd = 0.0;
}

int	HeadsUpMap::render(){
	getCoords();
	getDirection();
	tiles.render();
	for (auto& wp : HeadsUpWaypoint::waypoints) wp->render();
	return 0;
}

	void HeadsUpMap::draw(){
#ifdef MODERN_OPENGL
		interfaceShader.Use();
#endif
		glViewport(width-RIGHT_MARGIN-MAP_WIDTH, height-MAP_HEIGHT-TOP_MARGIN,  MAP_WIDTH, MAP_HEIGHT);

		glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		{
			glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
			colour.bind();
			glVertex2f(-1, 0.8);
			glVertex2f(-0.8, 1);
			glVertex2f(1, 1);
			glVertex2f(1, -0.8);
			glVertex2f(0.8, -1);
			glVertex2f(-1, -1);
			glEnd();
		}
		glPopAttrib();
		glViewport(width-RIGHT_MARGIN-MAP_WIDTH+2, height-MAP_HEIGHT-TOP_MARGIN+2,  MAP_WIDTH-4, MAP_HEIGHT-4);

		tiles.draw();

		glPushMatrix();
		glRotatef(-User::m_direction, 0, 0, 1);
		glRotatef(-User::m_pitch, 1, 0, 0);

		glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		{
			glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
			colour.bind();
			glVertex2f(0.0,0.0);
			glVertex2f(0.1,-0.1);
			glVertex2f(0.0,+0.1);
			glVertex2f(-0.1,-0.1);


			glEnd();
		}
		glPopAttrib();
		glPopMatrix();
		glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			{
				glViewport(width/3,height - TOP_MARGIN - CLOCK_FONT_SIZE, width/3, CLOCK_FONT_SIZE);


				glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
				colour.bind();
				glVertex2f(-1.0,0.1);
				glVertex2f(1.0,0.1);
				glVertex2f(1.0,-0.1);
				glVertex2f(-1.0,-0.1);
				glEnd();
				glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
				(colour - 100).bind();
				glVertex2f(-1.0,0.01);
				glVertex2f(1.0,0.01);
				glVertex2f(1.0,-0.01);
				glVertex2f(-1.0,-0.01);
				glEnd();

				for(size_t j = 0; j < view.size();j++){
						viewd = gps::polarBearing(view[j],User::m_direction);
						double font_difference;

						if ((j+1) % 2 == 0){ 			//
							font_difference = COMPASS_FONT_SIZE/2;
						} else if ((j+1) == 0 or (j+1) == 5 or (j+1) == 9 or (j+1) == 13){		//N,S,E,W
							font_difference = (double)COMPASS_FONT_SIZE;
						} else {					//NW,SW,NW,SW
							font_difference = (double)COMPASS_FONT_SIZE/1.5;
						}

						if ( -0.3 <= viewd and viewd <= 0){

							card[j].rdraw(((viewd*width/2) + (width/2)),height - TOP_MARGIN - (CLOCK_FONT_SIZE + font_difference)/2, 1, COMPASS_FONT_SIZE);
						} else
						if ( 0 <= viewd and viewd <= 0.3){
							card[j].rdraw(((viewd*width/2) + (width/2)),height - TOP_MARGIN - (CLOCK_FONT_SIZE + font_difference)/2, 1, COMPASS_FONT_SIZE);
						}
					}
				glViewport(width/3,height - TOP_MARGIN - CLOCK_FONT_SIZE, width/3, CLOCK_FONT_SIZE);

				colour.bind();

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

				s1.setText("Alt== "+std::to_string(User::m_altitude)+'m');
				s2.setText("Pitch "+std::to_string(User::m_pitch)+"°");
				s1.ldraw(0,TOP_MARGIN + CLOCK_FONT_SIZE/2, 1, CLOCK_FONT_SIZE/2);
				s2.ldraw(0,TOP_MARGIN + CLOCK_FONT_SIZE, 1, CLOCK_FONT_SIZE/2);

			}
			glPopAttrib();

	}

HeadsUpMap::~HeadsUpMap(){

}



