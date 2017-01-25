/*
 * HeadsUpTask.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */


#include "header.h"
#include "HeadsUpCheckBox.h"
#include "HeadsUpWaypoint.h"
#include "HeadsUpObjective.h"
#include "HeadsUpTask.h"

extern int height,width;
bool total_complete_flag;
bool incomplete_flag;
extern double m_latitude,m_longitude;

	HeadsUpTask::HeadsUpTask(std::string t)
	{

		title = t;
		state_changed = true;
		current_stage = 0;
		completed = false;
		indexx = 0;
	}

	void HeadsUpTask::confirmObjective(int position){
		objectives.at(position)->completed = true;
	}

	bool HeadsUpTask::isComplete(void){
		return completed;
	}

	void HeadsUpTask::drawGL(void)
	{
		indexx = 0;
		total_complete_flag = true;
		incomplete_flag = false;
		for (auto& current : objectives) {


				if (current->getStage() == current_stage){

					current->drawGL(indexx);
					if (!current->completed){
						incomplete_flag = true;
					}
					indexx++;
				}
				if (!current->completed){
					total_complete_flag = false;
				}

		}
		if (!incomplete_flag){
			current_stage++;
		}
		if (total_complete_flag){
			completed = true;
		}

		tit_text.setText(getTitle());
		tit_text.setColour(76,200,255,200);
		tit_text.rdraw(RIGHT_MARGIN,height-(30+TOP_MARGIN+MAP_HEIGHT),1.5,TASK_TEXT_HEIGHT);


		state_changed = false;


	}

	void HeadsUpTask::addObjective(HeadsUpObjective* o)
	{
		objectives.push_back(o);
		state_changed = true;
		names.clear();
		for (auto& current : objectives) {
			names.push_back(current->getName());
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


