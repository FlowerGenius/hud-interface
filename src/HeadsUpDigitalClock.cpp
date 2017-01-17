/*
 * HeadsUpDigitalClock.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */
#include "header.h"
#include "HeadsUpDigitalClock.h"

#include "header.h"


/* */
//void updateClock(HeadsUpDigitalClock clk){
//	clk.draw();
//}

HeadsUpDigitalClock::HeadsUpDigitalClock(){
	time_format = true;
	y=0,x=0;
}

void HeadsUpDigitalClock::init(){

}

int	HeadsUpDigitalClock::draw(int ax, int ay){
	y= height - TOP_MARGIN - CLOCK_FONT_SIZE;
	x=ax;
	time_t rawtime;
	struct tm * timeinfo;
	char buffer [80];
	time (&rawtime);
	timeinfo = localtime (&rawtime);
	strftime (buffer,80,"%I:%M:%S%p",timeinfo);
	ScalableVectorString l = ScalableVectorString(buffer,255,0,0,200,CLOCK_FONT_SIZE);
	l.rdraw(x,y,4.0);
	return 0;
}

void HeadsUpDigitalClock::update(){

}



