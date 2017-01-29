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
	ScalableVectorString();
	virtual ~ScalableVectorString();
	void	ldraw(int x,int y, int,float);
	void 	rdraw(int nx, int y, int,float);
	void 	setText(std::string,float size=-1);
	void 	setColour(int,int,int,int);
	void	setColour(LRAND::GlColour);
	void	setColour(LRAND::Colour);
	LRAND::Colour		getColour()							{ return colour; }
	std::u32string bytes;
	unsigned int getHeight();
	unsigned int getLength();
	unsigned int length;
private:
	LRAND::GlColour colour;
	LRAND::GlColour	br_colour;
	void vectorize(char32_t chr,int,int,LRAND::GlColour);
	std::string text;
	int xx;
	unsigned int i;
	float ht;
	float hw,vw;
	int h, w;
};

#endif /* SCALABLEVECTORSTRING_H_ */
