/*
 * HeadsUpMap.h
 *
 *  Created on: Jan 10, 2017
 *      Author: greg
 */

#ifndef HEADSUPMAP_H_
#define HEADSUPMAP_H_

class HeadsUpMap
{
public:
				HeadsUpMap();
	void		draw(void);
	void		transform(int,int,int,int);
private:
	int x,y,w,h;

};



#endif /* HEADSUPMAP_H_ */
