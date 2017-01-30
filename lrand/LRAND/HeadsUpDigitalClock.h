/*
 * HeadsUpDigitalClock.h
 *
 *  Created on: Jan 10, 2017
 *      Author: greg
 */

#ifndef LRAND_LRAND_HEADSUPDIGITALCLOCK_H_
#define LRAND_LRAND_HEADSUPDIGITALCLOCK_H_

class HeadsUpDigitalClock
{
public:
					HeadsUpDigitalClock();
	virtual			~HeadsUpDigitalClock();
	int				draw(int ax, int ay);
	void 			setColour(int R,int G,int B,int A){
						colour.set(R,G,B,A);
					}

	void 			setColour(LRAND::Colour c){
						colour = c;
					}

private:
	LRAND::Colour			colour;
	ScalableVectorString 	time_text;
	int						x;
	int						y;
};



#endif /* LRAND_LRAND_HEADSUPDIGITALCLOCK_H_ */
