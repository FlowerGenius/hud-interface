/*
 * HeadsUpCheckBox.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */

#include "header.h"
#include "HeadsUpCheckBox.h"

extern int height;

HeadsUpCheckBox::HeadsUpCheckBox(){

}

void HeadsUpCheckBox::draw(bool c, int x, int y)
	{
		bool checked=c;
		y+=(OBJECTIVE_TEXT_HEIGHT/2);

		glViewport(x, height-y, 20,20);
		//glViewport(300,300, 200,200);
		glPushMatrix();  //Make sure our transformations don't affect any other transformations in other code
		glBegin(GL_POLYGON);   //We want to draw a quad, i.e. shape with four sides
		glColor4f(0.0, 0.6, 0.6, 0.9);
		glVertex2f(-1, 1);
		glVertex2f(1, 1);
		glVertex2f(1, -0.5);
		glVertex2f(0.5, -1);
		glVertex2f(-1, -1);
		glEnd();

		float bw = 0.15;

		glBegin(GL_POLYGON);   //We want to draw a quad, i.e. shape with four sides
		glColor4f(0.0, 0.3, 0.6, 0.3);
		glVertex2f(-1+bw, 1.0-bw);
		glVertex2f(1-bw, 1-bw);
		glVertex2f(1-bw, -0.5+bw);
		glVertex2f(0.5-bw, -1+bw);
		glVertex2f(-1+bw, -1+bw);
		glEnd();


		if(checked){
			glBegin(GL_POLYGON);   //We want to draw a quad, i.e. shape with four sides
			glColor4f(1.0, 1.0, 0.0, 0.9);
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


