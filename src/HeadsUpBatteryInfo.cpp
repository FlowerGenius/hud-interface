/*
 * HeadsUpBatteryInfo.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */
#include "header.h"
#include "HeadsUpBatteryInfo.h"

extern std::string exec(const char*);

extern std::atomic<double> battery_life;
extern std::atomic<double> dev_battery_life;

extern std::string battery_state;

extern std::atomic<bool> is_charging;
extern std::atomic<bool> dev_is_charging;
extern std::atomic<bool> dev_is_connected;

std::string pinf;
std::string ssinf;

void computerGetBatteryInformation(){
		pinf = exec("upower -i `upower -e | grep 'BAT'` | grep percentage");
		ssinf = exec("upower -i `upower -e | grep 'BAT'` | grep state");

		battery_life = atof(pinf.substr(pinf.find('%')-3).c_str());
		battery_state = ssinf.substr(ssinf.find(':')+1);

		while (battery_state.substr(0,1) == " ")
			battery_state = battery_state.substr(1);

		while (battery_state.substr(battery_state.size()-1)==" " or battery_state.substr(battery_state.size()-1)=="\n")
			battery_state = battery_state.substr(0,battery_state.size()-1);

		if(battery_state == "discharging")
			is_charging = false;
		else if (battery_state == "charging")
			is_charging = true;
	}

	HeadsUpBatteryInfo::HeadsUpBatteryInfo(){

	}

void HeadsUpBatteryInfo::draw(int ax,int ay){

		// Computer Battery Monitor
		glViewport(width-ax, height-TOP_MARGIN-BAT_HEIGHT,  BAT_WIDTH, BAT_HEIGHT);
		glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		{
			glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
			glColor4f(0.0, 0.6, 0.6, 0.9);

			glVertex2f(-1.0,-1.0);
			glVertex2f(-1.0,1.0);
			glVertex2f(0.8,1.0);
			glVertex2f(0.8,0.4);
			glVertex2f(1.0,0.4);
			glVertex2f(1.0,-0.4);
			glVertex2f(0.8,-0.4);
			glVertex2f(0.8,-1.0);
			glEnd();
		}
		{
			glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
			if (battery_life <= 10.0)
				glColor4f(1.0, 0.0, 0.0, 0.9);
			else if (battery_life <= 20.0)
				glColor4f(1.0, 1.0, 0.0, 0.9);
			else
				glColor4f(0.0, 1.0, 0.0, 0.9);
			glVertex2f(-0.9,-0.8);
			glVertex2f(-0.9,0.8);
			glVertex2f( ((battery_life/125.0)*2.0 - 0.9),0.8);
			glVertex2f( ((battery_life/125.0)*2.0 - 0.9),-0.8);
			glEnd();
		}
		ScalableVectorString l = ScalableVectorString(std::to_string(battery_life).erase(5),167,167,255,200,BAT_HEIGHT/2);
		l.ldraw(width-ax+(BAT_WIDTH/6),height-TOP_MARGIN-BAT_HEIGHT*0.8,0);


		// Device Battery Monitor
		glViewport(width-ax, height-TOP_MARGIN-BAT_HEIGHT*2 - height/70, BAT_WIDTH, BAT_HEIGHT);
		{
			glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
			glColor4f(0.0, 0.6, 0.6, 0.9);

			glVertex2f(-1.0,-1.0);
			glVertex2f(-1.0,1.0);
			glVertex2f(0.8,1.0);
			glVertex2f(0.8,0.4);
			glVertex2f(1.0,0.4);
			glVertex2f(1.0,-0.4);
			glVertex2f(0.8,-0.4);
			glVertex2f(0.8,-1.0);
			glEnd();
		}
		{
			glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
			if (dev_battery_life <= 10.0)
				glColor4f(1.0, 0.0, 0.0, 0.9);
			else if (dev_battery_life <= 20.0)
				glColor4f(1.0, 1.0, 0.0, 0.9);
			else
				glColor4f(0.0, 1.0, 0.0, 0.9);
			glVertex2f(-0.9,-0.8);
			glVertex2f(-0.9,0.8);
			glVertex2f( ((dev_battery_life/125.0)*2.0 - 0.9),0.8);
			glVertex2f( ((dev_battery_life/125.0)*2.0 - 0.9),-0.8);
			glEnd();
		}
		ScalableVectorString o = ScalableVectorString(std::to_string(dev_battery_life).erase(5),167,167,255,200,BAT_HEIGHT/2);
		o.ldraw(width-ax+(BAT_WIDTH/6),height-TOP_MARGIN-BAT_HEIGHT*2 - height/70 +BAT_HEIGHT*0.2,0);


		// Computer icon
		glViewport(width-ax-RIGHT_MARGIN-10, height-TOP_MARGIN-BAT_HEIGHT,  30, BAT_HEIGHT);
		{
			glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
			glColor4f(0.0, 0.6, 0.6, 0.9);

			glVertex2f(-0.7,0.7);
			glVertex2f(-0.7,0.0);
			glVertex2f(0.7,0.0);
			glVertex2f(0.7,0.7);

			glEnd();
		}
		{
			glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
			glColor4f(0.6, 0.6, 0.6, 0.9);

			glVertex2f(-0.6,0.6);
			glVertex2f(-0.6,0.1);
			glVertex2f(0.6,0.1);
			glVertex2f(0.6,0.6);

			glEnd();
		}
		{
			glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
			glColor4f(0.0, 0.6, 0.6, 0.9);

			glVertex2f(-0.8,-0.35);
			glVertex2f(-0.7,0.0);
			glVertex2f(0.7,0.0);
			glVertex2f(0.8,-0.35);

			glEnd();
		}
		if(is_charging)
		{
			glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
			glColor4f(1.0, 1.0, 0.0, 0.9);
			glVertex2f(0.0,0.4);
			glVertex2f(0.0,0.9);
			glVertex2f(-0.2,0.2);
			glVertex2f(0.0,0.2);
			glVertex2f(0.0,-0.2);
			glVertex2f(0.2,0.4);


			glEnd();
		}
		// Device Icon
		glViewport(width-ax-RIGHT_MARGIN-10, height-TOP_MARGIN-BAT_HEIGHT*2 - height/70,  30, BAT_HEIGHT);
		{
			glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
			glColor4f(0.0, 0.6, 0.6, 0.9);

			glVertex2f(-0.8,-0.8);
			glVertex2f(-0.2,0.8);
			glVertex2f(0.0,0.6);

			glEnd();
		}
		{
			glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides

			glColor4f(0.0, 0.6, 0.6, 0.9);

			glVertex2f(0.8,-0.8);
			glVertex2f(0.2,0.8);
			glVertex2f(0.0,0.6);

			glEnd();
		}
		if(dev_is_charging)
		{
			glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
			glColor4f(1.0, 1.0, 0.0, 0.9);
			glVertex2f(0.0,0.0);
			glVertex2f(0.0,0.5);
			glVertex2f(-0.2,-0.2);
			glVertex2f(0.0,-0.2);
			glVertex2f(0.0,-0.6);
			glVertex2f(0.2,0.0);

			glEnd();
		}
		glPopAttrib();
	}
