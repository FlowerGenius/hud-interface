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

	void		draw(void);
	void		makeActiveTask(HeadsUpTask t);

	void		addTask(HeadsUpTask t);
	void		updateGL(void);
	void		updateX(void);
	HeadsUpTask	getTask(void);
	HeadsUpTask getLastTask(void);
	void		initialize(void);
protected:
	int 		get_frame(cv::ogl::Texture2D& texture, cv::ogl::Buffer& buffer, bool do_buffer);
	void		processFrameCPU(cv::ogl::Texture2D& texture, cv::ogl::Buffer& buffer, bool do_buffer);
	void		processFrameGPU(cv::ogl::Texture2D& texture, cv::ogl::Buffer& buffer, bool do_buffer);
private:
	int			tasksFontSize;
	int			objectivesFontSize;
	int			batteryLife;
	int			waypointFontSize;

	std::list<HeadsUpTask> taskQueue;


	void		drawXComponents(void);
	void		drawGLComponents(void);
	int			queryBatteryLife(void);
	HeadsUpMap	map;
	HeadsUpDigitalClock clock;
	HeadsUpBatteryInfo batinfo;
};



#endif /* HEADSUPINTERFACE_H_ */
