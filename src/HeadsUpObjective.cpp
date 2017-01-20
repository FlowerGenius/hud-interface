/*
 * HeadsUpObjective.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */

#include "header.h"
#include "HeadsUpCheckBox.h"
#include "HeadsUpObjective.h"
extern int height, width;

HeadsUpObjective::HeadsUpObjective(std::string n, int i) {
	name = n;
	completed = false;
	state_changed = true;
	active_stage = i;

}

void HeadsUpObjective::drawGL(int position) {
	check.draw(completed, width - RIGHT_MARGIN - 20,
			50 + TOP_MARGIN + MAP_HEIGHT + (position * 30));
	obj_text.setText(getName());
	obj_text.setColour(255, 255, 255, 200);
	obj_text.rdraw(RIGHT_MARGIN + 30,
			height - (60 + TOP_MARGIN + MAP_HEIGHT + (position * 30)), 1.1,
			OBJECTIVE_TEXT_HEIGHT);
	state_changed = false;
}

std::string HeadsUpObjective::getName() {
	return name;
}

void HeadsUpObjective::toggle() {
	if (completed)
		completed = false;
	else
		completed = true;
}

int HeadsUpObjective::getStage() {
	return active_stage;
}

