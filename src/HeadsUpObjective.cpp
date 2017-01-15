/*
 * HeadsUpObjective.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */



#include "header.h"
#include "HeadsUpCheckBox.h"
#include "HeadsUpObjective.h"
extern int height,width;

	HeadsUpObjective::HeadsUpObjective(std::string n, int i)
	{
		name = n;
		completed = false;
		state_changed = true;
		active_stage = i;

	}

	void HeadsUpObjective::drawGL(int position)
	{
		int ay = 50+TOP_MARGIN+MAP_HEIGHT+(position*30);
		int ax =  width-RIGHT_MARGIN-20;
		HeadsUpCheckBox check = HeadsUpCheckBox();
		check.draw(completed,ax,ay);

		float bw=1.1;
		ScalableVectorString s = ScalableVectorString(getName(),255,255,255,200,20);
		s.rdraw(RIGHT_MARGIN+30,height-(60+TOP_MARGIN+MAP_HEIGHT+(position*30)),bw);

		state_changed = false;
	}

	std::string HeadsUpObjective::getName()
	{
		return name;
	}

	void HeadsUpObjective::toggle(){
		if (completed)
			completed  = false;
		else
			completed = true;
	}

	int HeadsUpObjective::getStage(){
		return active_stage;
	}


