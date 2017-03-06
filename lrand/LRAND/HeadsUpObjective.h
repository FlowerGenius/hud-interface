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
							HeadsUpObjective(std::string,HeadsUpTask *t);

	virtual 				~HeadsUpObjective();

	HeadsUpTask				*source;

	virtual int				getStage(void){ return stage; }
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
	std::string 			name;
	gps::Point				location;
	int						radius = -1;
	int stage;
	int						active_stage;
	bool 					completed;
	bool					failed;
	bool					remove_on_complete;
	bool					state_changed;
	bool					optional;
private:
	HeadsUpWaypoint			waypoint = HeadsUpWaypoint(this);

};


/*
 *
 */
class SpecificLocationObjective : public HeadsUpObjective
{
public:
	SpecificLocationObjective(std::string n,HeadsUpTask *t) :
		HeadsUpObjective(n,t)
	{
			remove_on_complete = true;
			waypoint.set(location);
			waypoint.setText(n);
			waypoint.setColour(colour);
			initWaypoint();
			radius = -1;


			if(completed){
				deactivate();
			}

	}

	virtual void 				checkState(void);
	virtual void 				setColour(int R,int G,int B,int A)	{ waypoint.setColour(R,G,B,A); colour = LRAND::Colour(R,G,B,A);}
	virtual void 				setColour(LRAND::Colour c)			{ waypoint.setColour(c); colour = c;}
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
	AreaLocationObjective(std::string n,HeadsUpTask *t) :
		HeadsUpObjective(n, t)
	{
			radius = 10;
			remove_on_complete = true;
			waypoint.set(location);
			waypoint.setText("Area");
			waypoint.setSize(radius);
			waypoint.setFill(true);
			waypoint.setColour(colour);
			initWaypoint();


			if(completed){
				deactivate();
			}


	}
	int							getRadius() { return radius; }
	void						setRadius(int);

	virtual void 				checkState(void);
	virtual void 				setColour(int R,int G,int B,int A)	{ waypoint.setColour(R,G,B,A); colour = LRAND::Colour(R,G,B,A);}
	virtual void 				setColour(LRAND::Colour c)			{ waypoint.setColour(c); colour = c;}
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

					ActionObjective(std::string n,HeadsUpTask *t) :
						HeadsUpObjective(n,t)
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
