/*
 * HeadsUpObjective.h
 *
 *  Created on: Jan 10, 2017
 *      Author: greg
 */

#ifndef HEADSUPOBJECTIVE_H_
#define HEADSUPOBJECTIVE_H_

class HeadsUpObjective
{
public:
					HeadsUpObjective(std::string n, int stage);
	void			drawGL(int position);
	int				getStage(void);
	std::string		getName(void);
	bool			state_changed;
	bool 			completed;
	void			toggle(void);
	bool operator == (const HeadsUpObjective& s) const { return name == s.name && completed == s.completed && state_changed == s.state_changed;}
	bool operator != (const HeadsUpObjective& s) const { return !operator==(s); }
private:
	std::string 	name;
	int		active_stage;

};



#endif /* HEADSUPOBJECTIVE_H_ */
