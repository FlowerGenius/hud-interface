/*
 * HeadsUpObjective.h
 *
 *  Created on: Jan 10, 2017
 *      Author: greg
 */

#ifndef LRAND_LRAND_HEADSUPOBJECTIVE_H_
#define LRAND_LRAND_HEADSUPOBJECTIVE_H_

class HeadsUpObjective
{
public:
							HeadsUpObjective();
							HeadsUpObjective(std::string,int,bool,bool,rapidxml::xml_node<> *x_node,HeadsUpTask *t);
							HeadsUpObjective(std::string n, int i,gps::Point loc,bool optio,bool comple,rapidxml::xml_node<> *x_node,HeadsUpTask *t) : HeadsUpObjective(n,i,optio,comple,x_node,t) {
								location = loc;
							}
	virtual 				~HeadsUpObjective();

	HeadsUpTask				*source;

	virtual int				getStage(void){ return active_stage; }
	void					setStage(int);

	virtual bool			getCompleted(void){ return completed; }
	void					setCompleted(bool);

	virtual bool			getRemoveOnComplete(void){ return remove_on_complete; }
	void					setRemoveOnComplete(bool);

	virtual bool			getOptional(void){ return optional; }
	void					setOptional(bool);

	virtual gps::Point		getLocation(void){ return location; }
	void					setLocation(gps::Point);

	virtual std::string		getName(void){ return name; }
	void					setName(std::string);

	virtual void 			setColour(int R,int G,int B,int A)	{ waypoint.setColour(R,G,B,A);}
	virtual void 			setColour(LRAND::Colour c)			{ waypoint.setColour(c);}

	virtual HeadsUpWaypoint* 	getWaypoint(void) { return &waypoint;}

	virtual void				checkState();
	virtual void				write();
	virtual void				draw(int position);
	virtual void				deactivate();

	bool operator == (const HeadsUpObjective& s) const 		{ return name == s.name && completed == s.completed && state_changed == s.state_changed;}
	bool operator != (const HeadsUpObjective& s) const 		{ return !operator==(s); }

protected:
	LRAND::Colour			colour;
	LRAND::Colour			wp_colour;
	ScalableVectorString 	obj_text;
	HeadsUpCheckBox 		check;
	std::string 			name;
	gps::Point				location;
	int						radius = -1;
	int						active_stage;
	bool 					completed;
	bool					remove_on_complete;
	bool					state_changed;
	bool					optional;
	rapidxml::xml_node<> 	*file_node;
private:
	HeadsUpWaypoint			waypoint = HeadsUpWaypoint(this);

};


/*
 *
 */
class SpecificLocationObjective : public HeadsUpObjective
{
public:
	SpecificLocationObjective(std::string n, int stage, gps::Point loc,bool op,bool com,rapidxml::xml_node<> *x_node,HeadsUpTask *t) :
		HeadsUpObjective(n, stage, loc, op, com,x_node,t)
	{
			remove_on_complete = true;
			waypoint.set(location);
			waypoint.setText(n);
			waypoint.setColour(wp_colour);
			initWaypoint();
			radius = -1;


			if(completed){
				deactivate();
			}

	}

	virtual void 				checkState(void);
	virtual void 				setColour(int R,int G,int B,int A)	{ waypoint.setColour(R,G,B,A);}
	virtual void 				setColour(LRAND::Colour c)			{ waypoint.setColour(c);}
	virtual HeadsUpWaypoint* 	getWaypoint(void) 					{ return &waypoint;}
	virtual void				deactivate();


private:
	HeadsUpWaypoint 			waypoint = HeadsUpWaypoint(this);
	virtual void				initWaypoint(void);

};

/*
 * An objective
 */
class AreaLocationObjective : public HeadsUpObjective
{
public:
	AreaLocationObjective(std::string n, int stage, gps::Point loc,int r,bool op,bool com,rapidxml::xml_node<> *x_node,HeadsUpTask *t) :
		HeadsUpObjective(n, stage, loc, op, com,x_node, t)
	{
			radius = r;
			remove_on_complete = true;
			waypoint.set(location);
			waypoint.setText("Area");
			waypoint.setSize(radius);
			waypoint.setFill(true);
			waypoint.setColour(wp_colour);
			initWaypoint();


			if(completed){
				deactivate();
			}


	}
	int							getRadius() { return radius; }
	void						setRadius(int);

	virtual void 				checkState(void);
	virtual void 				setColour(int R,int G,int B,int A)	{ waypoint.setColour(R,G,B,A);}
	virtual void 				setColour(LRAND::Colour c)			{ waypoint.setColour(c);}
	virtual HeadsUpWaypoint* 	getWaypoint(void) { return &waypoint;}
	virtual void				deactivate();

private:
	HeadsUpWaypoint 			waypoint = HeadsUpWaypoint(this);
	virtual void				initWaypoint(void);
};

/*
 * An objective where a specific action must be done, once it is
 * done the objective is complete.
 */
class ActionObjective : public HeadsUpObjective
{
public:

					ActionObjective(std::string n, int stage,bool op,bool com,rapidxml::xml_node<> *x_node,HeadsUpTask *t) :
						HeadsUpObjective(n,stage,op,com,x_node,t)
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


#endif /* LRAND_LRAND_HEADSUPOBJECTIVE_H_ */
