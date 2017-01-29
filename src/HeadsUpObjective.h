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
							HeadsUpObjective(std::string,int,bool);
							HeadsUpObjective(std::string,int,gps::Point,bool);
	virtual 				~HeadsUpObjective();



	virtual int				getStage(void);
	virtual std::string		getName(void);

	virtual void			checkState();
	bool 					completed;
	bool					remove_on_complete;
	bool					state_changed;
	bool					optional;

	void					toggle(void);
	virtual void			drawGL(int position);
	gps::Point				location;
	int						radius = -1;


	bool operator == (const HeadsUpObjective& s) const 		{ return name == s.name && completed == s.completed && state_changed == s.state_changed;}
	bool operator != (const HeadsUpObjective& s) const 		{ return !operator==(s); }
	virtual void 				setColour(int R,int G,int B,int A)	{ waypoint.setColour(R,G,B,A);}
	virtual void 				setColour(LRAND::Colour c)			{ waypoint.setColour(c);}
	virtual HeadsUpWaypoint* getWaypoint(void) { return &waypoint;}
	virtual void					remove();
protected:
	LRAND::Colour			colour;
	LRAND::Colour			wp_colour;
	ScalableVectorString 	obj_text;
	HeadsUpCheckBox 		check;
private:
	std::string 			name;
	int						active_stage;
	HeadsUpWaypoint			waypoint;
};


/*
 *
 */
class SpecificLocationObjective : public HeadsUpObjective
{
public:
					SpecificLocationObjective(std::string n, int stage, gps::Point loc,bool op) :
						HeadsUpObjective(n, stage, loc, op)
					{
							location = loc;
							obj_text.setColour(colour);
							check.setColour(colour);
							waypoint.set(location);
							waypoint.setText(n);
							waypoint.setColour(wp_colour);
							initWaypoint();
							radius = -1;
					}
					virtual void checkState(void);
					virtual void 				setColour(int R,int G,int B,int A)	{ waypoint.setColour(R,G,B,A);}
					virtual void 				setColour(LRAND::Colour c)			{ waypoint.setColour(c);}
					virtual HeadsUpWaypoint* getWaypoint(void) { return &waypoint;}
					virtual void					remove();


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
					AreaLocationObjective(std::string n, int stage, gps::Point loc,int r,bool op) :
						HeadsUpObjective(n, stage, loc, op)
					{
							radius = r;
							remove_on_complete = false;
							obj_text.setColour(colour);
							check.setColour(colour);
							waypoint.set(location);
							waypoint.setText("Area");
							waypoint.setSize(radius);
							waypoint.setFill(true);
							waypoint.setColour(wp_colour);
							initWaypoint();

					}
					virtual void checkState(void);
					virtual void 				setColour(int R,int G,int B,int A)	{ waypoint.setColour(R,G,B,A);}
					virtual void 				setColour(LRAND::Colour c)			{ waypoint.setColour(c);}
					virtual HeadsUpWaypoint* getWaypoint(void) { return &waypoint;}
					virtual void					remove();

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

					ActionObjective(std::string n, int stage,bool op) :
						HeadsUpObjective(n,stage,op)
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
