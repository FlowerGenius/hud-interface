/*
 * HeadsUpTask.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */


#include "header.h"
#include "HeadsUpObjective.h"
#include "HeadsUpTask.h"

extern int height,width;

	HeadsUpTask::HeadsUpTask(std::string t)
	{
		title = t;
		state_changed = true;
		current_stage = 0;
		completed = false;
		index = 0;
	}

	void HeadsUpTask::confirmObjective(int position){
		objectives.at(position).completed = true;
	}

	bool HeadsUpTask::isComplete(void){
		return completed;
	}

	void HeadsUpTask::drawGL(void)
	{
		index = 0;
		bool total_complete_flag = true;
		bool incomplete_flag = false;
		for (std::vector<HeadsUpObjective>::const_iterator iterator = objectives.begin(), end = objectives.end(); iterator != end; ++iterator) {
				HeadsUpObjective current = *iterator;
				if (current.getStage() == current_stage){
					current.drawGL(index);
					if (!current.completed){
						incomplete_flag = true;
					}
					index++;
				}
				if (!current.completed){
					total_complete_flag = false;
				}

		}
		if (!incomplete_flag){
			current_stage++;
		}
		if (total_complete_flag){
			completed = true;
		}

		float bw=1.5;
		ScalableVectorString s = ScalableVectorString(getTitle(),76,200,255,200,20);
		s.rdraw(RIGHT_MARGIN,height-(30+TOP_MARGIN+MAP_HEIGHT),bw);


		state_changed = false;


	}

	void HeadsUpTask::addObjective(HeadsUpObjective o)
	{
		objectives.push_back(o);
		state_changed = true;
		names.clear();
		for (std::vector<HeadsUpObjective>::const_iterator iterator = objectives.begin(), end = objectives.end(); iterator != end; ++iterator) {
			HeadsUpObjective current = *iterator;
			names.push_back(current.getName());
		}
	}

	std::string HeadsUpTask::getTitle(void)
	{
		return title;
	}

	std::list<std::string> HeadsUpTask::displayObjectives(void)
	{

		return names;
	}


