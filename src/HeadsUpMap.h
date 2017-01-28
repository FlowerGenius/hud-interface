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
	virtual		~HeadsUpMap();

	int			render(void);
	void		draw(void);
private:
	TileBuilder tiles;

};



#endif /* HEADSUPMAP_H_ */
