/*
 * HeadsUpTask.h
 *
 *  Created on: Jan 10, 2017
 *      Author: greg
 */

#ifndef INCLUDE_LRAND_HEADSUPTASK_H_
#define INCLUDE_LRAND_HEADSUPTASK_H_

class HeadsUpTask
{
public:
							HeadsUpTask(std::string t,std::string nm,int,int,bool);
	virtual					~HeadsUpTask();
    void					drawGL(void);
    void					drawX(void);
	std::list<std::string> 	displayObjectives(void);

	void					deactivate(void);

	std::string 			getTitle(void);
	void					setTitle(std::string);

	bool					getCompleted(void);
	void					setCompleted(bool);

	int						getId(void);
	void					setId(int);

	int 					getStage(void);
	void					setStage(int);

	bool					state_changed;

	void					addObjective(HeadsUpObjective*);
	void					confirmObjective(int);

	void					update();

	std::vector<HeadsUpObjective*> objectives;

	bool operator == (const HeadsUpTask& s) const 			{ return objectives == s.objectives; }
	bool operator != (const HeadsUpTask& s) const 			{ return !operator==(s); }
	void 				setColour(int R,int G,int B,int A)	{ colour.set(R,G,B,A);}
	void 				setColour(LRAND::Colour c)			{ colour = c; for (auto& wp : objectives) wp->setColour(colour); }
private:
	LRAND::Colour			colour;
	std::list<std::string> 	names;
	int indexx = 0;

	std::string				loaded_doc;

	void					deleteObjective(HeadsUpObjective);
	ScalableVectorString 	tit_text;

	std::string				title;
	bool					completed;
	int						stage;
	int 					id;

	rapidxml::xml_document<> 	*doc;
	rapidxml::xml_node<>		*taskfile_node;


};



#endif /* INCLUDE_LRAND_HEADSUPTASK_H_ */
