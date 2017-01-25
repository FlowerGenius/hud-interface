/*
 * HeadsUpObjective.h
 *
 *  Created on: Jan 10, 2017
 *      Author: greg
 */

#ifndef HEADSUPOBJECTIVE_H_
#define HEADSUPOBJECTIVE_H_

class Objective
{
public:
	virtual void			checkState() = 0;
	virtual ~Objective();
};


class HeadsUpObjective
{
public:
							HeadsUpObjective();
							HeadsUpObjective(std::string,int);
							HeadsUpObjective(std::string,int,gps::Point);



	virtual int				getStage(void);
	virtual std::string		getName(void);

	virtual void					checkState();
	bool 					completed;

	bool					state_changed;
	void					toggle(void);
	bool operator == (const HeadsUpObjective& s) const { return name == s.name && completed == s.completed && state_changed == s.state_changed;}
	bool operator != (const HeadsUpObjective& s) const { return !operator==(s); }
	virtual 				~HeadsUpObjective();
	virtual void			drawGL(int position);
	gps::Point				location;
	int						radius = -1;
protected:
	ScalableVectorString 	obj_text;
	HeadsUpCheckBox 		check;
private:
	std::string 			name;
	int						active_stage;
};


/*
 *
 */
class SpecificLocationObjective : public HeadsUpObjective
{
public:
					SpecificLocationObjective(std::string n, int stage, gps::Point loc) :
						HeadsUpObjective(n, stage, loc)
					{
							location = loc;
							waypoint.set(location);
							waypoint.setText(n);
							waypoint.setColour(100,255,100,255);
							initWaypoint();
							radius = -1;
					}
					virtual void checkState(void);
private:
	virtual void			initWaypoint(void);
	HeadsUpWaypoint			waypoint;

};

/*
 * An objective
 */
class AreaLocationObjective : public HeadsUpObjective
{
public:
					AreaLocationObjective(std::string n, int stage, gps::Point loc,int r) :
						HeadsUpObjective(n, stage, loc)
					{
							radius = r;
							waypoint.set(location);
							waypoint.setText("Area");
							waypoint.setSize(radius);
							waypoint.setFill(true);
							waypoint.setColour(0,160,255,126);
							initWaypoint();

					}
					virtual void checkState(void);
private:
	HeadsUpWaypoint 		waypoint;
	virtual void			initWaypoint(void);
};

/*
 * An objective where a specific action must be done, once it is
 * done the objective is complete.
 */
class ActionObjective : public HeadsUpObjective
{
public:

					ActionObjective(std::string n, int stage) : HeadsUpObjective(n,stage)
					{

					}

};

/*
 * An objective where there is a counter for the number of times
 * the specified action is done. Objective is complete once the
 * counter reaches the target.
 */
class RepeatedActionObjective : public ActionObjective
{

};


#endif /* HEADSUPOBJECTIVE_H_ */
