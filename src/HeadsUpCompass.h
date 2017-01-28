/*
 * HeadsUpCompass.h
 *
 *  Created on: Jan 23, 2017
 *      Author: erin
 */

#ifndef HEADSUPCOMPASS_H_
#define HEADSUPCOMPASS_H_

class HeadsUpCompass {
public:
					HeadsUpCompass();
	virtual 		~HeadsUpCompass();
	void			draw();
private:
	ScalableVectorString 	N,NNE,NE,ENE,
							E,ESE,SE,SSE,
							S,SSW,SW,WSW,
							W,WNW,NW,NNW;
	std::vector<ScalableVectorString> card;
	double 	viewW,viewWNW,viewNW,viewNNW,
			viewN,viewNNE,viewNE,viewENE,
			viewE,viewESE,viewSE,viewSSE,
			viewS,viewSSW,viewSW,viewWSW;
	std::vector<double> view;
	double viewd;


};

#endif /* HEADSUPCOMPASS_H_ */
