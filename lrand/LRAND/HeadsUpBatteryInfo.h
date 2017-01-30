/*
 * HeadsUpBatteryInfo.h
 *
 *  Created on: Jan 10, 2017
 *      Author: greg
 */

#ifndef LRAND_LRAND_HEADSUPBATTERYINFO_H_
#define LRAND_LRAND_HEADSUPBATTERYINFO_H_

/*
 * Battery Information Module for LRANDD Heads Up Display
 * ======================================================
 *@usage:	HeadsUpBatteryInfo(void);
 *		Initializes the Battery Information module.
 */
class HeadsUpBatteryInfo
{
public: HeadsUpBatteryInfo();


	int 				render(void);
	void				draw(void);


	void 				setColour(int R,int G,int B,int A)	{ colour.set(R,G,B,A); }
	void 				setColour(LRAND::Colour c)			{ colour = c; }
private:
	LRAND::Colour 			colour;
	LRAND::Colour			text_colour;

	ScalableVectorString 	comp_text;
	ScalableVectorString 	dev_text;
};



#endif /* LRAND_LRAND_HEADSUPBATTERYINFO_H_ */
