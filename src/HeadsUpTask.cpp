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
extern std::string exec(const char*);

HeadsUpTask* HeadsUpTask::active_task = new HeadsUpTask();
std::list<HeadsUpTask*> HeadsUpTask::tasks = {};

	HeadsUpTask::HeadsUpTask(){
		title 		= "default";
		completed	= false;
		id			= 0;
		stage		= 0;
	}

/*
 * Initialize with the file location of the task, not the name
 */
	HeadsUpTask::HeadsUpTask(std::string t,rapidxml::xml_node<> *no,rapidxml::xml_node<>* ni,std::string nm,int ident,int sta,bool com)
	{
		title 		= nm;
		completed 	= com;
		id 			= ident;
		stage 		= sta;
		filename 	= t;
		file_node 	= ni;


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
			bool op				= std::string(obj_n->first_attribute("optional")->value()) == std::string("true") ?  true : false;
			bool comm			= std::string(obj_n->first_attribute("completed")->value()) == std::string("true") ?  true : false;
			int stage			= std::atoi(obj_n->first_attribute("stage")->value());


			if (std::string("SpecificLocationObjective") == std::string(obj_n->name())){
				SpecificLocationObjective* o = new SpecificLocationObjective(name,stage,loc,op,comm,obj_n,this);
				addObjective(o);
			} else if (std::string("AreaLocationObjective") == std::string(obj_n->name())){
				int radius = std::atoi(obj_n->first_attribute("radius")->value());
				AreaLocationObjective* o = new AreaLocationObjective(name,stage,loc,radius,op,comm,obj_n,this);
				addObjective(o);
			}
			obj_n = obj_n->next_sibling();
		}

		state_changed = true;
		indexx 		  = 0;
	}

	std::string persistent_stage_string;
	std::string	persistent_id_string;
	std::string persistent_completed_string;

	void HeadsUpTask::confirmObjective(int position){
		objectives.at(position)->setCompleted(true);
	}

	void HeadsUpTask::setTitle(std::string s){
		file_node->remove_attribute(file_node->first_attribute("name"));
		file_node->append_attribute(HeadsUpDisplay::interface.doc->allocate_attribute("name",s.c_str()));
		title = s;
	}

	void HeadsUpTask::setCompleted(bool b){
		file_node->remove_attribute(file_node->first_attribute("completed"));
		persistent_completed_string = b ? "true" : "false";
		file_node->append_attribute(HeadsUpDisplay::interface.doc->allocate_attribute("completed",persistent_completed_string.c_str()));
		completed = b;
	}

	void HeadsUpTask::setId(int Id){
		file_node->remove_attribute(file_node->first_attribute("id"));
		persistent_id_string 	= std::to_string(Id);
		file_node->append_attribute(HeadsUpDisplay::interface.doc->allocate_attribute("id", persistent_id_string.c_str()));
		id = Id;
	}
	void HeadsUpTask::setStage(int sstage){
		file_node->remove_attribute(file_node->first_attribute("stage"));
		persistent_stage_string = std::to_string(sstage);
		file_node->append_attribute(HeadsUpDisplay::interface.doc->allocate_attribute("stage",persistent_stage_string.c_str()));
		stage = sstage;
	}

	void HeadsUpTask::update(void){

	}

	void HeadsUpTask::drawGL(void)
	{

		indexx = 0;
		total_complete_flag = true;
		incomplete_flag = false;

		for (auto& current : objectives) {

				if (current->getStage() == getStage()){

					current->draw(indexx);
					if (!current->getCompleted() && !current->getOptional()){
						incomplete_flag = true;
					}

					indexx++;
				} else if (current->getStage() < getStage() and current->source->getId() == getId()){
					current->deactivate();
				}

				if (!current->getCompleted() && !current->getOptional()){
					total_complete_flag = false;
				}

		}

		if (!incomplete_flag){
			setStage(stage+1);
		}

		if (total_complete_flag){
			setCompleted(true);
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

	void HeadsUpTask::push_changes(){
//		std::cout << *interface.doc << filename << std::endl;
//
//		std::ofstream fil;
//		fil.open(filename);
//		fil << *doc << std::endl;
//		fil.close();
//
//		fil.open(LOCAL_TASKS);
//		fil << *interface.doc << std::endl;
//		fil.close();
//
//		try {
//			exec(std::string("scp "+filename+" "+interface.getUserName()+"@"+interface.getHost()+":"+interface.getSourceFolder()).c_str());
//		} catch(std::runtime_error *e){
//			std::fprintf(stderr,"Error executing push command (fatal)");
//		}
	}

	void HeadsUpTask::makeActiveTask(HeadsUpTask* t)
	{
		//setActiveTask(t->getId());
		HeadsUpTask::active_task = t;
	}

	void HeadsUpTask::addTask(HeadsUpTask* t)
	{
		t->setColour(colour);
		tasks.push_back(t);
		if (tasks.size()==1){
			makeActiveTask(t);
		}
	}

	void HeadsUpTask::addTasks(std::vector<HeadsUpTask*> tks){
		for (auto& tsk : tks) addTask(tsk);
	}


	std::list<std::string> HeadsUpTask::displayObjectives(void)
	{
		return names;
	}

	void HeadsUpTask::deactivate(){
		for (auto& current : objectives) {
			current->deactivate();
		}
	}

	HeadsUpTask::~HeadsUpTask(){
	}



