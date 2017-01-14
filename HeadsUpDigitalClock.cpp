/*
 * HeadsUpDigitalClock.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */
#include "header.h"
#include "HeadsUpDigitalClock.h"

#include "header.h"

	HeadsUpDigitalClock::HeadsUpDigitalClock(){
		time_format = true;
		x=0;
		y = 0;
	}

	void HeadsUpDigitalClock::draw(int ax, int ay){
		time_t rawtime;
		struct tm * timeinfo;
		char buffer [80];
		x = ax;
		y = ay;
		time (&rawtime);
		timeinfo = localtime (&rawtime);

		strftime (buffer,80,"%I:%M:%S%p",timeinfo);
		//std::string k;
		ScalableVectorString l = ScalableVectorString(buffer,255,0,0,200,100);
		l.rdraw(x,y,4.0);
	}

	void HeadsUpDigitalClock::update(){

	}



