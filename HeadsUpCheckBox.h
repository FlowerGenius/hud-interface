/*
 * HeadsUpCheckbox.h
 *
 *  Created on: Jan 10, 2017
 *      Author: greg
 */

#ifndef HEADSUPCHECKBOX_H_
#define HEADSUPCHECKBOX_H_

class HeadsUpCheckBox
{
public:
					HeadsUpCheckBox();
	void			setChecked(bool state);
	void 			getState(void);
	void			draw(bool c, int x, int y);
private:
	XColor 			background_colour;
	XColor			border_colour;
	XColor			check_colour;

};



#endif /* HEADSUPCHECKBOX_H_ */
