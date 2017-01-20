/*
 * HeadsUpDigitalClock.h
 *
 *  Created on: Jan 10, 2017
 *      Author: greg
 */

#ifndef HEADSUPDIGITALCLOCK_H_
#define HEADSUPDIGITALCLOCK_H_

class HeadsUpDigitalClock
{
public:
					HeadsUpDigitalClock();
	int				draw(int ax, int ay);


private:
	ScalableVectorString time_text;
	int				x;
	int				y;
};



#endif /* HEADSUPDIGITALCLOCK_H_ */
