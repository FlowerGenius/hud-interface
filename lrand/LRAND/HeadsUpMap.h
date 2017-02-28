/*
 * HeadsUpMap.h
 *
 *  Created on: Jan 10, 2017
 *      Author: greg
 */

#ifndef LRAND_LRAND_HEADSUPMAP_H_
#define LRAND_LRAND_HEADSUPMAP_H_

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

	ScalableVectorString s1;
	ScalableVectorString s2;
	ScalableVectorString 	N,NNE,NE,ENE,
							E,ESE,SE,SSE,
							S,SSW,SW,WSW,
							W,WNW,NW,NNW;
	std::vector<ScalableVectorString> card;
	double 	viewd;
	std::vector<double> view;

};



#endif /* LRAND_LRAND_HEADSUPMAP_H_ */
