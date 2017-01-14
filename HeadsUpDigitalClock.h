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
	void			draw(int ax, int ay);
	void			update(void);
private:
	bool			time_format;
	int				x;
	int				y;
};



#endif /* HEADSUPDIGITALCLOCK_H_ */
