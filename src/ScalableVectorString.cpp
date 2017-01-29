/*
 * ScalableVectorString.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */
#include "header.h"
#include "fonts/kombat.hpp"
#include <codecvt>
#include <locale>

#define			SPACE 			U'\u0020'
#define			EXCLAMATION 	U'\u0021'
#define			DOUBLE_QUOTES 	U'\u0022'
#define			HASHTAG			U'\u0023'
#define			DOLLAR			U'\u0024'
#define			PERCENT			U'\u0025'
#define			AMPERSAND	 	U'\u0026'
#define			SINGLE_QUOTE	U'\u0027'
#define			OPEN_PAREN		U'\u0028'
#define			CLOSE_PAREN		U'\u0029'
#define			ASTERISK		U'\u002A'
#define			PLUS			U'\u002B'
#define			COMMA			U'\u002C'
#define			HYPHEN			U'\u002D'
#define			FULL_STOP		U'\u002E'
#define			SLASH			U'\u002F'
#define			ZERO			U'\u0030'
#define			ONE				U'\u0031'
#define			TWO				U'\u0032'
#define			THREE			U'\u0033'
#define			FOUR			U'\u0034'
#define			FIVE			U'\u0035'
#define			SIX				U'\u0036'
#define			SEVEN			U'\u0037'
#define			EIGHT			U'\u0038'
#define			NINE			U'\u0039'
#define			COLON			U'\u003A'
#define			SEMI_COLON		U'\u003B'
#define			LESS_THAN		U'\u003C'
#define			EQUAL			U'\u003D'
#define			GRTR_THAN		U'\u003E'
#define			QUESTION		U'\u003F'
#define			AT				U'\u0040'
//TODO Capital Letters
#define			OPEN_BRACKET	U'\u005B'
#define			BACKSLASH		U'\u005C'
#define			CLOSE_BRACKET	U'\u005D'
#define			CARET			U'\u005E'
#define			UNDERSCORE		U'\u005F'
#define			ACCT_GRAVE		U'\u0060'
//TODO Minor letters
#define			OPEN_BRACE		U'\u007B'
#define			VERT_BAR		U'\u007C'
#define			CLOSE_BRACE		U'\u007D'
#define			TILDE			U'\u007E'
//#define			DELETE
#define			SLASH_ZERO			U'\u007E'
#define			POUND_STERLING		U'\u00A3'
#define			SLASH_BIGZERO		U'\u007E'
#define			MULTIPLICATION		U'\u007E'
#define			FUNCTION			U'\u007E'
#define			ANGLE_QUOTES_OPEN	U'\u00AB'
#define			ANGLE_QUOTES_CLOSE	U'\u00BB'
#define			STIPPLE1			U'\u007E'
#define			STIPPLE2			U'\u007E'
#define			STIPPLE3			U'\u007E'
#define			CENT				U'\u00A2'
#define			YEN					U'\u00A5'
#define			CURRENCY_SYMBOL		U'\u00A4'
#define			BLOCK				U'\u007E'
#define			BOTTOM_BLOCK		U'\u007E'
#define			TOP_BLOCK			U'\u007E'
#define			MACRON_SYMBOL		U'\u00AF'
#define			TRIPLE_HYPHEN		U'\u007E'
#define			PLUSMINUS			U'\u00B1'
#define			DOUBLE_UNDERSCORE	U'\u007E'
#define			SECTION_SIGN		U'\u00A7'
#define			DIVISION_SIGN		U'\u007E'
#define			CEDILLA				U'\u00B8'
#define			DEGREE				U'\u00B0'
#define			DIAERESIS			U'\u00A8'
#define			SPACE_DOT			U'\u00B7'
#define			SUPER_1			U'\u00B9'
#define			SUPER_3			U'\u00B3'
#define			SUPER_2			U'\u00B2'
#define			SQUARE			U'\u007E'
#define			NBSP			U'\u007E'



#define fontbuilder(y)	 kombat ## _ ## y
extern int width, height;
	ScalableVectorString::ScalableVectorString() {
		// TODO Auto-generated constructor stub
		br_colour.set(0.0,0.0,0.0,1.0);
		text = "";
		xx=0;
		length=0;
		i=0;
		h=0;
		w=0;
		hw=0;
		vw=0;
		ht=-1;
	}

	void ScalableVectorString::ldraw(int x, int y, int border,float font_size){

		if (ht < 0){
			ht = font_size;
		}
		std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;

		i=0;
		if(border>0){

			xx=x+border;

			for (auto& ch : bytes){
				vectorize(ch, x+border, y-border, br_colour);
			}
			xx=width-x+border-getLength();

			for (auto& ch : bytes){
				vectorize(ch, x+border, y+border, br_colour);
			}
			xx=width-x-border-getLength();

			for (auto& ch : bytes){
				vectorize(ch, x-border, y-border, br_colour);
			}
			xx=width-x-border-getLength();

			for (auto& ch : bytes){
				vectorize(ch, x-border, y+border, br_colour);
			}
		}
		xx=x;
		for (auto& ch : bytes){
			vectorize(ch, x, y, colour);
		}
		length = xx-x;
	}

	unsigned int ScalableVectorString::getLength(){

		xx=0;
		for (auto& ch : bytes){
			vectorize(ch, width, height, br_colour);
		}
		return xx;
	}

	unsigned int ScalableVectorString::getHeight(){
		return ht;
	}

	void ScalableVectorString::rdraw(int x, int y, int border, float font_size){

			if (ht < 0){
				ht = font_size;
			}	i = 0;
			if(border>0){
				xx=width-x+border-getLength();

				for (auto& ch : bytes){
					vectorize(ch, x+border, y-border, br_colour);
				}
				xx=width-x+border-getLength();

				for (auto& ch : bytes){
					vectorize(ch, x+border, y+border, br_colour);
				}
				xx=width-x-border-getLength();

				for (auto& ch : bytes){
					vectorize(ch, x-border, y-border, br_colour);
				}
				xx=width-x-border-getLength();

				for (auto& ch : bytes){
					vectorize(ch, x-border, y+border, br_colour);
				}
			}
			xx=width-x-getLength();
			for (auto& ch : bytes){
				vectorize(ch, width-x, y, colour);
			}
		}

	void ScalableVectorString::setText(std::string s,float size){
		text = s;
		bytes = std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t>{}.from_bytes(text);
		if (size > 0){
			ht = size;
		}
	}

	void ScalableVectorString::setColour(int red, int green, int blue,int alpha){
		colour = LRAND::GlColour((float)red/255,(float)green/255,(float)blue/255,(float)alpha/255);
	}
	void ScalableVectorString::setColour(LRAND::GlColour c){
		colour = c;
	}
	void ScalableVectorString::setColour(LRAND::Colour c){
		colour = LRAND::GlColour(c);
	}

	void ScalableVectorString::vectorize(char32_t chr, int x, int y,LRAND::GlColour co)
	{

		hw=2;
		vw = 0.0;
		glPushMatrix();
		glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		co.bind();

		for(;;)
		{
			if (  SPACE ==chr) fontbuilder(SPACE);
			if (  EXCLAMATION ==chr) fontbuilder(EXCLAMATION);
			if (  DOUBLE_QUOTES ==chr) fontbuilder(DOUBLE_QUOTES);
			if (  HASHTAG ==chr) fontbuilder(HASHTAG);
			if (  DOLLAR ==chr) fontbuilder(DOLLAR);
			if (  PERCENT ==chr) fontbuilder(PERCENT);
			if (  AMPERSAND ==chr) fontbuilder(AMPERSAND);
			if (  SINGLE_QUOTE ==chr) fontbuilder(SINGLE_QUOTE);
			if (  OPEN_PAREN ==chr) fontbuilder(OPEN_PAREN);
			if (  CLOSE_PAREN ==chr) fontbuilder(CLOSE_PAREN);
			if (  ASTERISK ==chr) fontbuilder(ASTERISK);
			if (  PLUS ==chr) fontbuilder(PLUS);
			if (  COMMA ==chr) fontbuilder(COMMA);
			if (  HYPHEN ==chr) fontbuilder(HYPHEN);
			if (  FULL_STOP ==chr) fontbuilder(FULL_STOP);
			if (  SLASH ==chr) fontbuilder(SLASH);
			if (  ZERO ==chr) fontbuilder(ZERO);
			if (  ONE ==chr) fontbuilder(ONE);
			if (  TWO ==chr) fontbuilder(TWO);
			if (  THREE ==chr) fontbuilder(THREE);
			if (  FOUR ==chr) fontbuilder(FOUR);
			if (  FIVE ==chr) fontbuilder(FIVE);
			if (  SIX ==chr) fontbuilder(SIX);
			if (  SEVEN ==chr) fontbuilder(SEVEN);
			if (  EIGHT ==chr) fontbuilder(EIGHT);
			if (  NINE ==chr) fontbuilder(NINE);
			if (  COLON ==chr) fontbuilder(COLON);
			if (  SEMI_COLON ==chr) fontbuilder(SEMI_COLON);
			if (  LESS_THAN ==chr) fontbuilder(LESS_THAN);
			if (  EQUAL ==chr) fontbuilder(EQUAL);
			if (  GRTR_THAN ==chr) fontbuilder(GRTR_THAN);
			if (  QUESTION ==chr) fontbuilder(QUESTION);
			if (  AT ==chr) fontbuilder(AT);
			if ( U'A' ==chr) fontbuilder(A);
			if ( U'B' ==chr) fontbuilder(B);
			if ( U'C' ==chr) fontbuilder(C);
			if ( U'D' ==chr) fontbuilder(D);
			if ( U'E' ==chr) fontbuilder(E);
			if ( U'F' ==chr) fontbuilder(F);
			if ( U'G' ==chr) fontbuilder(G);
			if ( U'H' ==chr) fontbuilder(H);
			if ( U'I' ==chr) fontbuilder(I);
			if ( U'J' ==chr) fontbuilder(J);
			if ( U'K' ==chr) fontbuilder(K);
			if ( U'L' ==chr) fontbuilder(L);
			if ( U'M' ==chr) fontbuilder(M);
			if ( U'N' ==chr) fontbuilder(N);
			if ( U'O' ==chr) fontbuilder(O);
			if ( U'P' ==chr) fontbuilder(P);
			if ( U'Q' ==chr) fontbuilder(Q);
			if ( U'R' ==chr) fontbuilder(R);
			if ( U'S' ==chr) fontbuilder(S);
			if ( U'T' ==chr) fontbuilder(T);
			if ( U'U' ==chr) fontbuilder(U);
			if ( U'V' ==chr) fontbuilder(V);
			if ( U'W' ==chr) fontbuilder(W);
			if ( U'X' ==chr) fontbuilder(X);
			if ( U'Y' ==chr) fontbuilder(Y);
			if ( U'Z' ==chr) fontbuilder(Z);
			if (  BACKSLASH ==chr) fontbuilder(BACKSLASH);
			if (  UNDERSCORE ==chr) fontbuilder(UNDERSCORE);
			if ( U'a' ==chr) fontbuilder(a);
			if ( U'b' ==chr) fontbuilder(b);
			if ( U'c' ==chr) fontbuilder(c);
			if ( U'd' ==chr) fontbuilder(d);
			if ( U'e' ==chr) fontbuilder(e);
			if ( U'f' ==chr) fontbuilder(f);
			if ( U'g' ==chr) fontbuilder(g);
			if ( U'h' ==chr) fontbuilder(h);
			if ( U'i' ==chr) fontbuilder(i);
			if ( U'j' ==chr) fontbuilder(j);
			if ( U'k' ==chr) fontbuilder(k);
			if ( U'l' ==chr) fontbuilder(l);
			if ( U'm' ==chr) fontbuilder(m);
			if ( U'n' ==chr) fontbuilder(n);
			if ( U'o' ==chr) fontbuilder(o);
			if ( U'p' ==chr) fontbuilder(p);
			if ( U'q' ==chr) fontbuilder(q);
			if ( U'r' ==chr) fontbuilder(r);
			if ( U's' ==chr) fontbuilder(s);
			if ( U't' ==chr) fontbuilder(t);
			if ( U'u' ==chr) fontbuilder(u);
			if ( U'v' ==chr) fontbuilder(v);
			if ( U'w' ==chr) fontbuilder(w);
			if ( U'x' ==chr) fontbuilder(x);
			if (U'y' ==chr) fontbuilder(y);
			if (U'z' == chr ) fontbuilder(z);
			if ( DEGREE == chr) fontbuilder(DEGREE);

			xx+=17*(ht/40)+hw;
			break;
		}
		glPopAttrib();
		glPopMatrix();

	}

	ScalableVectorString::~ScalableVectorString() {
		// TODO Auto-generated destructor stub
	}





