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

	void 				setColour(int R,int G,int B,int A)	{ colour.set(R,G,B,A); }
	void 				setColour(LRAND::Colour c)			{ colour = c; }
private:
	LRAND::Colour		colour;
	TileBuilder tiles;

};



#endif /* HEADSUPMAP_H_ */
