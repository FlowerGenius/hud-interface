/*
 * HeadsUpBatteryInfo.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */
#include "header.h"
#include "HeadsUpBatteryInfo.h"

// From helper functions
extern std::string exec(const char*);

// From main object
extern std::atomic<double> battery_life;
extern std::atomic<double> dev_battery_life;
extern std::string battery_state;
extern std::string dev_battery_state;

extern std::atomic<bool> is_charging;
extern std::atomic<bool> dev_is_charging;

//extern std::atomic<bool> dev_is_connected;
extern std::atomic<bool> EXIT_THREADS;

// Temp variables
std::string pinf;

namespace LRAND{
	extern LRAND::Colour YELLOW;
	extern LRAND::Colour RED;
	extern LRAND::Colour GREEN;
}
void getPCBatteryInformation() {
	try {
		pinf = exec("upower -i `upower -e | grep 'BAT'` | grep 'percentage\\|state'");
	} catch(std::runtime_error *e){
		std::fprintf(stderr,"Error executing upower command (fatal)");
	}

	battery_state	= pinf.substr(pinf.find("charging")-3,11);
	battery_life 	= atof(pinf.substr(pinf.find('%') - 3).c_str());

	if (battery_state == "discharging")
		is_charging = false;
	else if (battery_state == "   charging")
		is_charging = true;
	if (dev_battery_state == "discharging")
			dev_is_charging = false;
	else if (dev_battery_state == "charging")
		dev_is_charging = true;
}

void computerGetBatteryInformation() {
	int i = 0;
	while (!EXIT_THREADS) {
		if (i > 10){
			getPCBatteryInformation();
			i = 0;
		} else {
			i++;
		}
	}
	puts("Computer Battery Information Thread Exited Successfully");
}

HeadsUpBatteryInfo::HeadsUpBatteryInfo() {
	getPCBatteryInformation();
}

/*@method:	render(void);
 *		Processes all the information necessary to update the module.
 */
int HeadsUpBatteryInfo::render(){
	comp_text.setText(std::to_string(battery_life).erase(5));
		comp_text.setColour(text_colour);

	dev_text.setText(std::to_string(dev_battery_life).erase(5));
		dev_text.setColour(text_colour);

	return 0;
}

/*@method:	draw(void);
 *		Draws the module to the window using OpenGL.
 */
void HeadsUpBatteryInfo::draw() {

	// Computer Battery Monitor
	glViewport(width - (MAP_WIDTH + BAT_WIDTH + RIGHT_MARGIN*2), height - TOP_MARGIN - BAT_HEIGHT, BAT_WIDTH,
	BAT_HEIGHT);
	glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	{
		glBegin(GL_POLYGON); //We want to draw a map, i.e. shape with four bevel sides
		colour.bind();
		glVertex2f(-1.0, -1.0);
		glVertex2f(-1.0, 1.0);
		glVertex2f(0.8, 1.0);
		glVertex2f(0.8, 0.4);
		glVertex2f(1.0, 0.4);
		glVertex2f(1.0, -0.4);
		glVertex2f(0.8, -0.4);
		glVertex2f(0.8, -1.0);
		glEnd();
	}
	{
		glBegin(GL_POLYGON); //We want to draw a map, i.e. shape with four bevel sides
		if (battery_life <= 10.0)
			LRAND::RED.bind();
		else if (battery_life <= 20.0)
			LRAND::YELLOW.bind();
		else
			LRAND::GREEN.bind();
		glVertex2f(-0.9, -0.8);
		glVertex2f(-0.9, 0.8);
		glVertex2f(((battery_life / 125.0) * 2.0 - 0.9), 0.8);
		glVertex2f(((battery_life / 125.0) * 2.0 - 0.9), -0.8);
		glEnd();
	}
	comp_text.ldraw(width - (MAP_WIDTH + BAT_WIDTH + RIGHT_MARGIN*2) + (BAT_WIDTH / 6),
			height - TOP_MARGIN - BAT_HEIGHT * 0.8, 0, BAT_HEIGHT / 2);

	// Device Battery Monitor
	glViewport(width - (MAP_WIDTH + BAT_WIDTH + RIGHT_MARGIN*2), height - TOP_MARGIN - BAT_HEIGHT * 2 - height / 70,
	BAT_WIDTH, BAT_HEIGHT);
	{
		glBegin(GL_POLYGON); //We want to draw a map, i.e. shape with four bevel sides
		colour.bind();
		glVertex2f(-1.0, -1.0);
		glVertex2f(-1.0, 1.0);
		glVertex2f(0.8, 1.0);
		glVertex2f(0.8, 0.4);
		glVertex2f(1.0, 0.4);
		glVertex2f(1.0, -0.4);
		glVertex2f(0.8, -0.4);
		glVertex2f(0.8, -1.0);
		glEnd();
	}
	{
		glBegin(GL_POLYGON); //We want to draw a map, i.e. shape with four bevel sides
		if (dev_battery_life <= 10.0)
			LRAND::RED.bind();
		else if (dev_battery_life <= 20.0)
			LRAND::YELLOW.bind();
		else
			LRAND::GREEN.bind();
		glVertex2f(-0.9, -0.8);
		glVertex2f(-0.9, 0.8);
		glVertex2f(((dev_battery_life / 125.0) * 2.0 - 0.9), 0.8);
		glVertex2f(((dev_battery_life / 125.0) * 2.0 - 0.9), -0.8);
		glEnd();
	}
	dev_text.ldraw(width - (MAP_WIDTH + BAT_WIDTH + RIGHT_MARGIN*2) + (BAT_WIDTH / 6),
			height - TOP_MARGIN - BAT_HEIGHT * 2 - height / 70
					+ (BAT_HEIGHT * 0.2), 0, BAT_HEIGHT / 2);

	// Computer icon
	glViewport(width - (MAP_WIDTH + BAT_WIDTH + RIGHT_MARGIN*2) - RIGHT_MARGIN - 10, height - TOP_MARGIN - BAT_HEIGHT,
			30, BAT_HEIGHT);
	{
		glBegin(GL_POLYGON); //We want to draw a map, i.e. shape with four bevel sides
		colour.bind();
		glVertex2f(-0.7, 0.7);
		glVertex2f(-0.7, 0.0);
		glVertex2f(0.7, 0.0);
		glVertex2f(0.7, 0.7);
		glEnd();
	}
	{
		glBegin(GL_POLYGON); //We want to draw a map, i.e. shape with four bevel sides
		(colour - 50).bind();
		glVertex2f(-0.6, 0.6);
		glVertex2f(-0.6, 0.1);
		glVertex2f(0.6, 0.1);
		glVertex2f(0.6, 0.6);

		glEnd();
	}
	{
		glBegin(GL_POLYGON); //We want to draw a map, i.e. shape with four bevel sides
		colour.bind();
		glVertex2f(-0.8, -0.35);
		glVertex2f(-0.7, 0.0);
		glVertex2f(0.7, 0.0);
		glVertex2f(0.8, -0.35);

		glEnd();
	}
	if (is_charging) {
		glBegin(GL_POLYGON); //We want to draw a map, i.e. shape with four bevel sides
		LRAND::YELLOW.bind();
		glVertex2f(0.0, 0.4);
		glVertex2f(0.0, 0.9);
		glVertex2f(-0.2, 0.2);
		glVertex2f(0.0, 0.2);
		glVertex2f(0.0, -0.2);
		glVertex2f(0.2, 0.4);

		glEnd();
	}
	// Device Icon
	glViewport(width - (MAP_WIDTH + BAT_WIDTH + RIGHT_MARGIN*2) - RIGHT_MARGIN - 10,
			height - TOP_MARGIN - BAT_HEIGHT * 2 - height / 70, 30, BAT_HEIGHT);
	glColor4f(0.0, 0.67, 1.0, 0.9);
	{
		glBegin(GL_POLYGON); //We want to draw a map, i.e. shape with four bevel sides
		glVertex2f(-0.8, -0.8);
		glVertex2f(-0.2, 0.8);
		glVertex2f(0.0, 0.6);
		glEnd();
	}
	{
		glBegin(GL_POLYGON); //We want to draw a map, i.e. shape with four bevel sides
		glVertex2f(0.8, -0.8);
		glVertex2f(0.2, 0.8);
		glVertex2f(0.0, 0.6);
		glEnd();
	}
	if (dev_is_charging) {
		glBegin(GL_POLYGON); //We want to draw a map, i.e. shape with four bevel sides
		LRAND::YELLOW.bind();
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 0.5);
		glVertex2f(-0.2, -0.2);
		glVertex2f(0.0, -0.2);
		glVertex2f(0.0, -0.6);
		glVertex2f(0.2, 0.0);

		glEnd();
	}
	glPopAttrib();
}
