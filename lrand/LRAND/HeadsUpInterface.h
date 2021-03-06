/*
 * HeadsUpInterface.h
 *
 *  Created on: Jan 10, 2017
 *      Author: greg
 */

#ifndef LRAND_LRAND_HEADSUPINTERFACE_H_
#define LRAND_LRAND_HEADSUPINTERFACE_H_

class HeadsUpInterface
{
public:
				HeadsUpInterface();

	void		start_stuff(void);
	void		draw(void);
	void		makeActiveTask(HeadsUpTask* t);

	void		addWaypoint(HeadsUpWaypoint*);
	void		removeWaypoint(HeadsUpWaypoint*);
	void		addWaypoints(std::vector<HeadsUpWaypoint*>);
	std::vector<HeadsUpWaypoint*> waypoints;

	void		updateGL(void);
	void		updateX(void);

	std::string getTasksFolder(){
		return local_tasks_folder;
	}
	void setTasksFolder(std::string);

	std::string getSourceFolder(){
		return remote_tasks_folder;
	}
	void setSourceFolder(std::string);

	std::string getHost(){
		return remote_host;
	}
	std::string getUserName(){
		return remote_username;
	}

	int getActiveTask(void);
	void setActiveTask(int);

	HeadsUpTask	getTask(void);
	HeadsUpTask getLastTask(void);

	void 		push_changes(void);
	void		pull_updates(void);

	void		changeColours(void);

	void 				setColour(int R,int G,int B,int A)	{ colour.set(R,G,B,A); changeColours();}
	void 				setColour(LRAND::Colour c)			{ colour = c; changeColours();}

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

	static std::string				remote_tasks_folder;
	static std::string				remote_username;
	static std::string				remote_password;
	static std::string				remote_host;
	static std::string				local_tasks_folder;

	Device 	_da;
	LANAccess 		_la;
};



#endif /* LRAND_LRAND_HEADSUPINTERFACE_H_ */
