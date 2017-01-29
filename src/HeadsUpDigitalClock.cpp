/*
 * HeadsUpDigitalClock.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */
#include "header.h"
#include "HeadsUpDigitalClock.h"

/* */

time_t rawtime;
struct tm * timeinfo;
bool time_format;
std::string timestring;
extern std::atomic<bool> EXIT_THREADS;

void getTime() {
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	char* buffer = (char*) malloc(sizeof(char) * 80);
	strftime(buffer, 80, "%I:%M:%S%p", timeinfo);
	timestring = std::string(buffer);
	free(buffer);
}

void computerGetLocalTime() {
	while (!EXIT_THREADS) {
		getTime();
	}
	puts("Computer Local Time Thread Exited Successfully");
}

HeadsUpDigitalClock::HeadsUpDigitalClock() {
	time_format = true;
	y = 0, x = 0;
	getTime();
}

int HeadsUpDigitalClock::draw(int ax, int ay) {
	time_text.setText(timestring);
	time_text.setColour(colour);
	time_text.rdraw(ax, height - TOP_MARGIN - CLOCK_FONT_SIZE, 4.0,
			CLOCK_FONT_SIZE);
	return 0;
}

HeadsUpDigitalClock::~HeadsUpDigitalClock(){

}
