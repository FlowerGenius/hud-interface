/*
 * HeadsUpObjective.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */

#include <lrand/lrand.h>

extern int height, width;
extern double m_latitude,m_longitude, m_altitude;

std::string	o_persistent_optional_string;
std::string o_persistent_completed_string;
std::string o_persistent_location_string;


void setStringAttribute(
        rapidxml::xml_document<>& doc, rapidxml::xml_node<>* node,
        const std::string& attributeName, const std::string& attributeValue)
{
    // allocate memory assigned to document for attribute value
    char* rapidAttributeValue = doc.allocate_string(attributeValue.c_str());
    // search for the attribute at the given node
    rapidxml::xml_attribute<>* attr = node->first_attribute(attributeName.c_str());
    if (attr != 0) { // attribute already exists
        // only change value of existing attribute
        attr->value(rapidAttributeValue);
    } else { // attribute does not exist
        // allocate memory assigned to document for attribute name
        char* rapidAttributeName = doc.allocate_string(attributeName.c_str());
        // create new a new attribute with the given name and value
        attr = doc.allocate_attribute(rapidAttributeName, rapidAttributeValue);
        // append attribute to node
        node->append_attribute(attr);
    }
}

HeadsUpObjective::HeadsUpObjective(){
	name 				= 	"";
	active_stage 		= 	0;
	completed 			= 	false;
	failed				= 	false;
	remove_on_complete	= 	true;
	state_changed 		= 	true;
	optional			= 	false;
	remove_on_complete	= 	true;
	file_node			=	NULL;
	source				=	NULL;
}

HeadsUpObjective::HeadsUpObjective(std::string n,int i,bool optio,bool comple,rapidxml::xml_node<> *x_node,HeadsUpTask *t) : HeadsUpObjective() {
	name 				= 	n;
	active_stage 		= 	i;
	file_node			=	x_node;

	if(optio)  { optional  = true; }
	if(comple) { completed = true; }

	if(optional){
		colour.set(0,255,255,255);
	} else {
		colour.set(255,255,255,255);
	}

	obj_text.setColour(colour);

	source = t;
}

void HeadsUpObjective::draw(int position) {
	checkState();

	const int x = width - RIGHT_MARGIN - 20;
	const int y = 50 + TOP_MARGIN + MAP_HEIGHT + (position * 30) + (OBJECTIVE_TEXT_HEIGHT/2);
	const float bw = 0.15;

	glViewport(x, height-y, 20,20);
	//glViewport(300,300, 200,200);
	glPushMatrix();  //Make sure our transformations don't affect any other transformations in other code

		colour.bind();
		glBegin(GL_POLYGON);   //We want to draw a quad, i.e. shape with four sides
		glVertex2f(-1, 1);
		glVertex2f(1, 1);
		glVertex2f(1, -0.5);
		glVertex2f(0.5, -1);
		glVertex2f(-1, -1);
		glEnd();

		glBegin(GL_POLYGON);   //We want to draw a quad, i.e. shape with four sides
		(colour - 100).bind();
		glVertex2f(-1+bw, 1.0-bw);
		glVertex2f(1-bw, 1-bw);
		glVertex2f(1-bw, -0.5+bw);
		glVertex2f(0.5-bw, -1+bw);
		glVertex2f(-1+bw, -1+bw);
		glEnd();


		if(completed){
			glBegin(GL_POLYGON);   //We want to draw a quad, i.e. shape with four sides
			LRAND::Colour::YELLOW.bind();
			//glVertex2f(-0.8, -0.4);
			glVertex2f(-0.2, -0.8);
			glVertex2f(0.8, 0.2);
			glVertex2f(0.75, 0.8);
			glVertex2f(-0.2, -0.2);
			glVertex2f(-0.7, 0.2);
			glVertex2f(-0.8, -0.4);
			glEnd();
		}
	glPopMatrix();


	obj_text.setText(getName());
	obj_text.rdraw(RIGHT_MARGIN + 30,
			height - (60 + TOP_MARGIN + MAP_HEIGHT + (position * 30)), 1.1,
			OBJECTIVE_TEXT_HEIGHT);
}

void HeadsUpObjective::write(){

}

void HeadsUpObjective::deactivate(){
	std::fprintf(stderr,"You Fucked up, implement this");
}

void HeadsUpObjective::checkState(){
	std::fprintf(stderr,"You Fucked up, implement this");
}

//================================================================================================================================
// setter methods
//================================================================================================================================

void HeadsUpObjective::setCompleted(bool b){
	file_node->remove_attribute(file_node->first_attribute("completed"));
	o_persistent_completed_string = b ? "true" : "false";
	file_node->append_attribute(source->doc->allocate_attribute("completed",o_persistent_completed_string.c_str()));
	completed = b;
}

void HeadsUpObjective::setLocation(gps::Point p){
	file_node->remove_attribute(file_node->first_attribute("location"));
	o_persistent_location_string = p.to_string();
	file_node->append_attribute(source->doc->allocate_attribute("location",o_persistent_location_string.c_str()));
	location = p;
}

void HeadsUpObjective::setName(std::string n){
	file_node->remove_attribute(file_node->first_attribute("title"));
	file_node->append_attribute(source->doc->allocate_attribute("title",n.c_str()));
	name = n;
}

void HeadsUpObjective::setOptional(bool b){
	file_node->remove_attribute(file_node->first_attribute("optional"));
	o_persistent_optional_string = b ? "true" : "false";
	file_node->append_attribute(source->doc->allocate_attribute("optional",o_persistent_optional_string.c_str()));
	optional = b;
}

//===========================================
// Objective For Fixed Specific Location
//===========================================

void SpecificLocationObjective::initWaypoint(){
	HeadsUpWaypoint::addWaypoint(&waypoint);
}
void SpecificLocationObjective::deactivate(){
	obj_text.setColour(colour - 100);
	setColour(colour - 100);
	HeadsUpWaypoint::removeWaypoint(&waypoint);
}
void SpecificLocationObjective::checkState(){

	if (m_latitude - 0.0003 <= location.latitude and m_latitude + 0.0003 >= location.latitude and
			m_longitude - 0.0003 <= location.longitude and m_longitude + 0.0003 >= location.longitude and
				m_altitude - 0.0003 <= location.altitude and m_altitude + 0.0003 >= location.altitude){
		setCompleted(true);
		if (remove_on_complete){
			write();
		    remove_on_complete = false;
		}
	}
}

//============================================
// Objective For Fixed Area Location
//============================================

void AreaLocationObjective::initWaypoint(){
	HeadsUpWaypoint::addWaypoint(&waypoint);
}
void AreaLocationObjective::deactivate(){
	obj_text.setColour(colour - 100);
	setColour(colour - 100);
	HeadsUpWaypoint::removeWaypoint(&waypoint);
}
void AreaLocationObjective::checkState(){
	if (m_latitude - (double)radius/111111.0 <= location.latitude and m_latitude + (double)radius/111111.0 >= location.latitude and
			m_longitude - (double)radius/111111.0 <= location.longitude and m_longitude + (double)radius/111111.0 >= location.longitude){
		setCompleted(true);
		if (remove_on_complete){
			write();
			remove_on_complete = false;
		}
	}
}



HeadsUpObjective::~HeadsUpObjective(){
	HeadsUpWaypoint::removeWaypoint(&waypoint);

}
