/*
 * ScalableVectorString.h
 *
 *  Created on: Jan 11, 2017
 *      Author: erin
 */

#ifndef SCALABLEVECTORSTRING_H_
#define SCALABLEVECTORSTRING_H_

class ScalableVectorString {
public:
	ScalableVectorString(std::string s,int r,int g,int b,int a, int h);
	virtual ~ScalableVectorString();
	void	ldraw(int x,int y, int);
	void 	rdraw(int nx, int y, int);
	void 	changeText(std::string);
	void 	changeColour(int,int,int);
	unsigned int getLength();
	unsigned int length;
private:
	void vectorize(char c,int,int,float,float,float,float);
	std::string text;
	float a,r,g,b;
	int xx;
	float ht;
	const char* bytes;
};

#endif /* SCALABLEVECTORSTRING_H_ */
