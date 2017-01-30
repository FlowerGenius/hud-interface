/*
 * HeadsUpTask.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */


#include <lrand/lrand.h>

#define LONGITUDE	-79.395293
#define LATITUDE	43.661802
extern int height,width;
bool total_complete_flag;
bool incomplete_flag;
extern double m_latitude,m_longitude;

/*
 * Initialize with the file location of the task, not the name
 */
	HeadsUpTask::HeadsUpTask(std::string t,std::string nm,int ident,int sta,bool com)
	{
		title 		= nm;
		completed 	= com;
		id 			= ident;
		stage 		= sta;

		rapidxml::xml_document<> d;
		doc = &d;

		std::string buf;
		std::ifstream handle;
		handle.open(t);

		if (handle.is_open()){
		while(!handle.eof()){
			getline(handle,buf);
			loaded_doc += buf;
			}
		}
		handle.close();

		doc->parse<0>((char *)loaded_doc.c_str());
		taskfile_node = doc->first_node("objectives");



		int num_of_objectives	= std::atoi(taskfile_node->first_attribute("objectives")->value());
		rapidxml::xml_node<> *obj_n = taskfile_node->first_node();

		for (int q=1;q<num_of_objectives+1;q++){
			std::string name 	= std::string(obj_n->first_attribute("title")->value());
			gps::Point  loc		= gps::Point(obj_n->first_attribute("location")->value());
			bool op				= std::string(obj_n->first_attribute("optional")->value()) == std::string("false") ?  false : true;
			int stage			= std::atoi(obj_n->first_attribute("stage")->value());


			if (std::string("SpecificLocationObjective") == std::string(obj_n->name())){
				SpecificLocationObjective* o = new SpecificLocationObjective(name,stage,loc,op,this);
				addObjective(o);
			} else if (std::string("AreaLocationObjective") == std::string(obj_n->name())){
				int radius = std::atoi(obj_n->first_attribute("radius")->value());
				AreaLocationObjective* o = new AreaLocationObjective(name,stage,loc,radius,op,this);
				addObjective(o);
			}
			obj_n = obj_n->next_sibling();
		}

		state_changed = true;
		indexx 		  = 0;
	}

	void HeadsUpTask::confirmObjective(int position){
		objectives.at(position)->completed = true;
	}


	std::string HeadsUpTask::getTitle(void)
	{
		return title;
	}
//	void HeadsUpTask::setTitle(std::string s){
//		title = s;
//		rapidxml::xml_attribute<> *attr = doc->allocate_attribute("title",s.c_str());
//		doc->first_node("objectives")->append_attribute(attr);
//	}

	bool HeadsUpTask::getCompleted(void){
		return completed;
	}
//	void HeadsUpTask::setCompleted(bool b){
//		completed = b;
//		std::string s = std::to_string(b);
//		rapidxml::xml_attribute<> *attr = doc->allocate_attribute("completed",s.c_str());
//		doc->first_node("objectives")->append_attribute(attr);
//	}

	int HeadsUpTask::getId(){
		return id;
	}
//	void HeadsUpTask::setId(int Id){
//		id = Id;
//		rapidxml::xml_attribute<> *attr = doc->allocate_attribute("id",std::to_string(Id).c_str());
//		doc->first_node("objectives")->append_attribute(attr);
//	}

	int HeadsUpTask::getStage(){
		return stage;
	}
//	void HeadsUpTask::setStage(int sstage){
//		stage = sstage;
//		rapidxml::xml_attribute<> *attr = doc->allocate_attribute("current_stage",std::to_string(sstage).c_str());
//		doc->first_node("objectives")->append_attribute(attr);
//	}

	void HeadsUpTask::update(void){

	}

	void HeadsUpTask::drawGL(void)
	{
		indexx = 0;
		total_complete_flag = true;
		incomplete_flag = false;
		for (auto& current : objectives) {


				if (current->getStage() == stage){

					current->drawGL(indexx);
					if (!current->completed && !current->optional){
						incomplete_flag = true;
					}

					indexx++;
				} else if (current->getStage() < stage and current->source->getId() == getId()){
					current->remove();
				}

				if (!current->completed && !current->optional){
					total_complete_flag = false;
				}



		}
		if (!incomplete_flag){
			stage+=1;
		}

		if (total_complete_flag){
			completed = true;
		}

		tit_text.setText(title);
		tit_text.setColour(colour);
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

	std::list<std::string> HeadsUpTask::displayObjectives(void)
	{

		return names;
	}

	void HeadsUpTask::deactivate(){

	}

	HeadsUpTask::~HeadsUpTask(){
	}



