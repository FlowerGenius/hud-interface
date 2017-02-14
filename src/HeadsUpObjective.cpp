/*
 * HeadsUpObjective.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */

#include <lrand/lrand.h>

extern HeadsUpInterface interface;
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

	if(optio) {optional = true;}
	if(comple) {completed = true;}

	if(optional){
		colour.set(0,255,255,255);
	} else {
		colour.set(255,255,255,255);
	}

	check.setColour(colour);
	obj_text.setColour(colour);

	if(completed){
		deactivate();
	}

	source = t;
}

void HeadsUpObjective::draw(int position) {
	checkState();
	check.draw(completed, width - RIGHT_MARGIN - 20,
			50 + TOP_MARGIN + MAP_HEIGHT + (position * 30));
	obj_text.setText(getName());
	obj_text.rdraw(RIGHT_MARGIN + 30,
			height - (60 + TOP_MARGIN + MAP_HEIGHT + (position * 30)), 1.1,
			OBJECTIVE_TEXT_HEIGHT);
}

void HeadsUpObjective::deactivate(){
	obj_text.setColour(colour - 100);
	check.setColour(colour - 100);
	interface.removeWaypoint(&waypoint);
}

void HeadsUpObjective::write(){

}

void HeadsUpObjective::checkState(){
	//Virtual Method
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
	interface.addWaypoint(&waypoint);
}
void SpecificLocationObjective::remove(){
	obj_text.setColour(colour - 100);
	check.setColour(colour - 100);
	interface.removeWaypoint(&waypoint);
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
	interface.addWaypoint(&waypoint);
}
void AreaLocationObjective::remove(){
	obj_text.setColour(colour - 100);
	check.setColour(colour - 100);
	interface.removeWaypoint(&waypoint);
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
	interface.removeWaypoint(&waypoint);

}
