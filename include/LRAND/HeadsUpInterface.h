/*
 * HeadsUpInterface.h
 *
 *  Created on: Jan 10, 2017
 *      Author: greg
 */

#ifndef HEADSUPINTERFACE_H_
#define HEADSUPINTERFACE_H_

class HeadsUpInterface
{
public:
				HeadsUpInterface();

	void		start_stuff(void);
	void		draw(void);
	void		makeActiveTask(HeadsUpTask* t);

	void		addTask(HeadsUpTask* t);
	void		addTasks(std::vector<HeadsUpTask*>);
	std::list<HeadsUpTask*> 	tasks;

	void		addWaypoint(HeadsUpWaypoint*);
	void		removeWaypoint(HeadsUpWaypoint*);
	void		addWaypoints(std::vector<HeadsUpWaypoint*>);
	std::vector<HeadsUpWaypoint*> waypoints;

	void		updateGL(void);
	void		updateX(void);

	std::string getTasksFolder(void);
	void setTasksFolder(std::string);

	int getActiveTask(void);
	void setActiveTask(int);

	HeadsUpTask	getTask(void);
	HeadsUpTask getLastTask(void);

	void		changeColours(void);

	void 				setColour(int R,int G,int B,int A)	{ colour.set(R,G,B,A); changeColours();}
	void 				setColour(LRAND::Colour c)			{ colour = c; changeColours();}
	HeadsUpTask*				 active_task;

private:
	LRAND::Colour 	colour;
	int 		get_frame(cv::ogl::Texture2D& texture, cv::ogl::Buffer& buffer, bool do_buffer);
	void		processFrameCPU(cv::ogl::Texture2D& texture, cv::ogl::Buffer& buffer, bool do_buffer);
	void		processFrameGPU(cv::ogl::Texture2D& texture, cv::ogl::Buffer& buffer, bool do_buffer);

	cv::ogl::Texture2D 		cam_texture;
	cv::ogl::Buffer 		cam_buffer;
	MODE					cam_mode;
	bool					cam_do_buffer;
	std::list<HeadsUpTask> 	taskQueue;

	void		drawXComponents(void);
	void		drawGLComponents(void);
	int			queryBatteryLife(void);

	HeadsUpMap	map;
	HeadsUpDigitalClock clockk;
	HeadsUpBatteryInfo batinfo;
	HeadsUpCompass compass;

	std::string				loaded_doc;
	std::string				tasks_folder;


	rapidxml::xml_document<> 	*doc;
	rapidxml::xml_node<>		*taskfile_node;

	DeviceAccess 	_da;
	LANAccess 		_la;
};



#endif /* HEADSUPINTERFACE_H_ */