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
#define TASKPATH(a) std::string(LOCAL_TASKS)+std::string(a)

HeadsUpTask* HeadsUpTask::active_task = new HeadsUpTask();
std::list<HeadsUpTask*> HeadsUpTask::tasks = {};

	HeadsUpTask::HeadsUpTask(){
		title 		= "default";
		filename 	= "config";
		completed	= false;
		id			= 0;
		stage		= 0;
		stages 		= 0;
		stage_name	= "stagename";
	}

/*
 * Initialize with the file location of the task, not the name
 */
	extern std::vector<std::string> readConfigurationFile(std::string,int);
	HeadsUpTask::HeadsUpTask(std::string nm)
	{
		filename = nm;
		std::vector<std::string> config_vector = readConfigurationFile(filename+"/config",4);

		title = nm.substr(nm.rfind("/")+1,nm.length());
		std::replace(title.begin(),title.end(),'_',' ');
		id 			= std::atoi(config_vector[0].c_str());
		stages 		= std::atoi(config_vector[1].c_str());
		stage 		= std::atoi(config_vector[2].c_str());
		completed 	= std::atoi(config_vector[3].c_str()) == 0 ? true : false;

		if (stages > 0){
			std::vector<std::string> stage_vector  = readConfigurationFile(filename+"/."+std::to_string(stage),2);
			stage_name 	= stage_vector[0];
		}

		const boost::filesystem::path & dir_path = filename;
		if ( exists( dir_path ) )
		{
			boost::filesystem::directory_iterator end_itr; // default construction yields past-the-end
			for ( boost::filesystem::directory_iterator itr( dir_path );
				  itr != end_itr;
				  ++itr )
			{
				std::string file = itr->path().string();
				if ( (file.substr(file.length()-7) != "/config") and file.substr(file.rfind('/')+1)[0] != '.'){
					std::vector<std::string> ne_vector = readConfigurationFile(file,5);
					if (ne_vector[1] == "SpecificLocationObjective"){
						objectives.push_back(new SpecificLocationObjective(file,this));
					} else if (ne_vector[1] == "AreaLocationObjective"){
						objectives.push_back(new AreaLocationObjective(file,this));
					} else if (ne_vector[1] == "ActionObjective"){
						objectives.push_back(new ActionObjective(file,this));
					}
				}
			}
		}

		indexx 		= 0;
	}

	void HeadsUpTask::confirmObjective(int position){
		objectives.at(position)->setCompleted(true);
	}

	void HeadsUpTask::setTitle(std::string s){
		title = s;
	}

	void HeadsUpTask::setCompleted(bool b){
		completed = b;
	}

	void HeadsUpTask::setId(int Id){
		id = Id;
	}

	void HeadsUpTask::setStage(int sstage){
		std::vector<std::string> stage_vector  = readConfigurationFile(filename+"/."+std::to_string(stage),2);
		stage_name 	= stage_vector[0];
		stage = sstage;
	}

	void HeadsUpTask::setActiveTask(int task){
		for (auto& tsk : HeadsUpTask::tasks) {
			if (tsk->getId() == task){
				HeadsUpTask::active_task = tsk;
			}
		}
	}

	void HeadsUpTask::makeActiveTask(HeadsUpTask* task){
		HeadsUpTask::active_task = task;
	}


	void HeadsUpTask::update(void){
		std::ofstream ofile(filename+"/config");
		if(ofile.is_open()){
			ofile << id << '\t' << stages << '\t' << stage << '\t' <<completed;
		}
	}

	void HeadsUpTask::drawGL(void)
	{

		indexx = 0;
		total_complete_flag = true;
		incomplete_flag = false;

	//	std::fprintf(stderr,"%s",objectives.front()->getName().c_str());


		for (auto& current : objectives) {

				//if (current->getStage() == getStage()){

					current->draw(indexx);
//					if (!current->getCompleted() && !current->getOptional()){
//						incomplete_flag = true;
//					}
//
//					indexx++;
//				} else if (current->getStage() < getStage() and current->source->getId() == getId()){
//					current->deactivate();
//				}
//
//				if (!current->getCompleted() && !current->getOptional()){
//					total_complete_flag = false;
//				}
//
//		}
//
//		if (!incomplete_flag){
//			//setStage(stage+1);
//		}
//
//		if (total_complete_flag){
//			setCompleted(true);
//		}
				//}
		}
		tit_text.setText(title+": "+stage_name);
		tit_text.setColour(colour);
		tit_text.rdraw(RIGHT_MARGIN,height-(30+TOP_MARGIN+MAP_HEIGHT),1.5,TASK_TEXT_HEIGHT);
	}

	void HeadsUpTask::addObjective(HeadsUpObjective* o)
	{
		objectives.push_back(o);
		names.clear();
		for (auto& current : objectives) {
			names.push_back(current->getName());
		}
	}

	void HeadsUpTask::push_changes(){
//		for (auto& current : objectives) {
//			current->push_changes();
//		}
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



