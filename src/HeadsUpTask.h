/*
 * HeadsUpTask.h
 *
 *  Created on: Jan 10, 2017
 *      Author: greg
 */

#ifndef HEADSUPTASK_H_
#define HEADSUPTASK_H_

class HeadsUpTask
{
public:
							HeadsUpTask(std::string t);

    void					drawGL(void);
    void					drawX(void);
	std::string 			getTitle(void);
	std::list<std::string> 	displayObjectives(void);
	bool					isComplete(void);
	bool					state_changed;
	void					addObjective(HeadsUpObjective*);

	void					confirmObjective(int);

	std::vector<HeadsUpObjective*> objectives;

	bool operator == (const HeadsUpTask& s) const { return title == s.title && objectives == s.objectives; }
	bool operator != (const HeadsUpTask& s) const { return !operator==(s); }

private:
	std::list<std::string> names;
	int indexx = 0;
	int						current_stage;
	bool					completed;
	void					deleteObjective(HeadsUpObjective);
	std::string 			title;
	ScalableVectorString 	tit_text;

};



#endif /* HEADSUPTASK_H_ */
