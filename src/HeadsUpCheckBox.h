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

	void 				setColour(int R,int G,int B,int A)	{ colour.set(R,G,B,A); }
	void 				setColour(LRAND::Colour c)			{ colour = c; }

private:
	bool			checked;
	float 			bw;
	LRAND::Colour	colour;

};



#endif /* HEADSUPCHECKBOX_H_ */
