/*
 * HeadsUpTask.h
 *
 *  Created on: Jan 10, 2017
 *      Author: greg
 */

#ifndef LRAND_LRAND_HEADSUPTASK_H_
#define LRAND_LRAND_HEADSUPTASK_H_

class HeadsUpTask
{
public:
							HeadsUpTask(std::string nm);
	virtual					~HeadsUpTask();
    void					drawGL(void);
    void					drawX(void);
	std::list<std::string> 	displayObjectives(void);

							HeadsUpTask();

	void					deactivate(void);

	std::string getTitle(void)
	{
		return title;
	}
	void					setTitle(std::string);

	bool getCompleted(void){
		return completed;
	}
	void					setCompleted(bool);

	int getId(){
		return id;
	}
	void					setId(int);

	int getStage(){
		return stage;
	}
	void					setStage(int);

	HeadsUpTask*			getActiveTask(){
		return active_task;
	}
	void					setActiveTask(int t);
	void					makeActiveTask(HeadsUpTask* t);



	void					push_changes(void);
	void					addObjective(HeadsUpObjective*);
	void					confirmObjective(int);
	void					update();

	void					addTask(HeadsUpTask* t);
	void					addTasks(std::vector<HeadsUpTask*>);

	static std::list<HeadsUpTask*> tasks;
	static HeadsUpTask*			active_task;

	std::vector<HeadsUpObjective*> 	objectives;

	bool operator == (const HeadsUpTask& s) const 			{ return objectives == s.objectives; }
	bool operator != (const HeadsUpTask& s) const 			{ return !operator==(s); }
	void 				setColour(int R,int G,int B,int A)	{ colour.set(R,G,B,A);}
	void 				setColour(LRAND::Colour c)			{ colour = c; for (auto& wp : objectives) wp->setColour(colour); }
private:

	void					deleteObjective(HeadsUpObjective);

	LRAND::Colour			colour;
	std::list<std::string> 	names;
	int indexx = 0;

	ScalableVectorString 	tit_text;

	std::string				title;
	bool					completed;
	int						stage;
	int						stages;
	std::string				stage_name;
	int 					id;
	std::string				filename;
};



#endif /* LRAND_LRAND_HEADSUPTASK_H_ */
