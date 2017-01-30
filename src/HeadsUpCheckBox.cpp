/*
 * HeadsUpCheckBox.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */

#include <lrand.h>

extern int height;

namespace LRAND{
	extern LRAND::Colour YELLOW;
}
HeadsUpCheckBox::HeadsUpCheckBox(){
	bw = 0.15;
	checked=false;
}

void HeadsUpCheckBox::draw(bool c, int x, int y)
	{
		checked=c;
		y+=(OBJECTIVE_TEXT_HEIGHT/2);

		glViewport(x, height-y, 20,20);
		//glViewport(300,300, 200,200);
		glPushMatrix();  //Make sure our transformations don't affect any other transformations in other code
		glBegin(GL_POLYGON);   //We want to draw a quad, i.e. shape with four sides
		colour.bind();
		glVertex2f(-1, 1);
		glVertex2f(1, 1);
		glVertex2f(1, -0.5);
		glVertex2f(0.5, -1);
		glVertex2f(-1, -1);
		glEnd();

		glBegin(GL_POLYGON);   //We want to draw a quad, i.e. shape with four sides
		(colour - 100).bind();
		glVertex2f(-1+bw, 1.0-bw);
		glVertex2f(1-bw, 1-bw);
		glVertex2f(1-bw, -0.5+bw);
		glVertex2f(0.5-bw, -1+bw);
		glVertex2f(-1+bw, -1+bw);
		glEnd();


		if(checked){
			glBegin(GL_POLYGON);   //We want to draw a quad, i.e. shape with four sides
			LRAND::YELLOW.bind();
			//glVertex2f(-0.8, -0.4);
			glVertex2f(-0.2, -0.8);
			glVertex2f(0.8, 0.2);
			glVertex2f(0.75, 0.8);
			glVertex2f(-0.2, -0.2);
			glVertex2f(-0.7, 0.2);
			glVertex2f(-0.8, -0.4);
			glEnd();
		}
		glPopMatrix();
	}


