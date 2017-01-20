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
	void	ldraw(int x,int y, int,int);
	void 	rdraw(int nx, int y, int,int);
	void 	setText(std::string);
	void 	setColour(int,int,int,int);
	unsigned int getLength();
	unsigned int length;
private:
	void vectorize(char c,int,int,float,float,float,float);
	std::string text;
	float a,r,g,b;
	int xx;
	unsigned int i;
	float br,bg,bb,ba;
	float ht;
	const char* bytes;
	float hw,vw;
	int h, w;
	enum {
				SPACE=32,
				EXCLAMATION,
				DOUBLE_QUOTES,
				HASHTAG,
				DOLLAR,
				PERCENT,
				AMPERSAND,
				SINGLE_QUOTE,
				OPEN_PAREN,
				CLOSE_PAREN,
				ASTERISK,
				PLUS,
				COMMA,
				HYPHEN,
				FULL_STOP,
				SLASH,
				ZERO,
				ONE,
				TWO,
				THREE,
				FOUR,
				FIVE,
				SIX,
				SEVEN,
				EIGHT,
				NINE,
				COLON,
				SEMI_COLON,
				LESS_THAN,
				EQUAL,
				GRTR_THAN,
				QUESTION,
				AT,
				OPEN_BRACKET=91,
				BACKSLASH,
				CLOSE_BRACKET,
				CARET,
				UNDERSCORE,
				ACCT_GRAVE,
				OPEN_BRACE=123,
				VERT_BAR,
				CLOSE_BRACE,
				TILDE,
				DELETE,
			};
};

#endif /* SCALABLEVECTORSTRING_H_ */
