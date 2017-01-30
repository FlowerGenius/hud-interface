/*
 * HeadsUpCompass.h
 *
 *  Created on: Jan 23, 2017
 *      Author: erin
 */

#ifndef LRAND_LRAND_HEADSUPCOMPASS_H_
#define LRAND_LRAND_HEADSUPCOMPASS_H_

class HeadsUpCompass {
public:
					HeadsUpCompass();
					HeadsUpCompass(int,int,int,int);
	virtual 		~HeadsUpCompass();
	int				render(void);
	void			draw(void);

	void 			setColour(int R,int G,int B,int A){
						colour.set(R,G,B,A);
					}

	void 			setColour(LRAND::Colour c){
						colour = c;
					}
private:
	LRAND::Colour colour;
	ScalableVectorString 	N,NNE,NE,ENE,
							E,ESE,SE,SSE,
							S,SSW,SW,WSW,
							W,WNW,NW,NNW;
	std::vector<ScalableVectorString> card;
	double 	viewd;
	std::vector<double> view;


};

#endif /* LRAND_LRAND_HEADSUPCOMPASS_H_ */
