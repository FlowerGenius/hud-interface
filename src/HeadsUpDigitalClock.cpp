/*
 * HeadsUpDigitalClock.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */
#include "header.h"
#include "HeadsUpDigitalClock.h"

/* */


HeadsUpDigitalClock::HeadsUpDigitalClock(){
	time_format = true;
	y=0,x=0;
	getTime();
}

void HeadsUpDigitalClock::getTime(){
	time (&rawtime);
	timeinfo = localtime (&rawtime);
	char buffer[80];
	strftime (buffer,80,"%I:%M:%S%p",timeinfo);
	timestring = std::string(buffer);}


int	HeadsUpDigitalClock::draw(int ax, int ay){
	getTime();
	ScalableVectorString l = ScalableVectorString(timestring,0,167,167,200,CLOCK_FONT_SIZE);
	l.rdraw(ax,height - TOP_MARGIN - CLOCK_FONT_SIZE,4.0);
	return 0;
}



