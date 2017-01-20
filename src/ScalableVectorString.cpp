/*
 * ScalableVectorString.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */
#include "header.h"
#include "fonts/kombat.hpp"

extern int width, height;
	ScalableVectorString::ScalableVectorString() {
		// TODO Auto-generated constructor stub
		text = "";
		bytes = text.c_str();
		r=255;g=255,b=255,a=1.0;
		xx=0;
		length=0;
		i=0;
		bb=0;
		br=0;
		bg=0;
		ba=0;
		h=0;
		w=0;
		hw=0;
		vw=0;
		ht=0;
	}

	void ScalableVectorString::ldraw(int x, int y, int border,int font_size){
		ht = font_size;

		i=0;
		if(border>0){

			br=(float)0/255;bg=(float)0/255,bb=(float)0/255,ba=1.0;
			xx=x+border;

			for (i=0;i<text.length();i++){
				vectorize(bytes[i], x+border, y-border, br,bg,bb,ba);
			}
			xx=x+border;

			for (i=0;i<text.length();i++){
				vectorize(bytes[i], x+border, y+border, br,bg,bb,ba);
			}
			xx=x-border;

			for (i=0;i<text.length();i++){
				vectorize(bytes[i], x-border, y-border, br,bg,bb,ba);
			}
			xx=x-border;

			for (i=0;i<text.length();i++){
				vectorize(bytes[i], x-border, y+border, br,bg,bb,ba);
			}
		}
		xx=x;
		for (i=0;i<text.length();i++){
			vectorize(bytes[i], x, y, r,g,b,a);
		}
		length = xx-x;
	}

	unsigned int ScalableVectorString::getLength(){

		br=(float)0/255;bg=(float)0/255,bb=(float)0/255,ba=0.0;
		xx=0;
		for (i=0;i<text.length();i++){
			vectorize(bytes[i], width, height, br,bg,bb,ba);
		}
		return xx;
	}

	void ScalableVectorString::rdraw(int x, int y, int border, int font_size){
			ht = font_size;
			i = 0;
			if(border>0){
				float br,bg,bb,ba;


				br=(float)0/255;bg=(float)0/255,bb=(float)0/255,ba=1.0;
				xx=width-x+border-getLength();

				for (i=0;i<text.length();i++){
					vectorize(bytes[i], x+border, y-border, br,bg,bb,ba);
				}
				xx=width-x+border-getLength();

				for (i=0;i<text.length();i++){
					vectorize(bytes[i], x+border, y+border, br,bg,bb,ba);
				}
				xx=width-x-border-getLength();

				for (i=0;i<text.length();i++){
					vectorize(bytes[i], x-border, y-border, br,bg,bb,ba);
				}
				xx=width-x-border-getLength();

				for (i=0;i<text.length();i++){
					vectorize(bytes[i], x-border, y+border, br,bg,bb,ba);
				}
			}
			xx=width-x-getLength();
			for (i=0;i<text.length();i++){
				vectorize(bytes[i], width-x, y, r,g,b,a);
			}
		}

	void ScalableVectorString::setText(std::string s){
		text = s;
		bytes = text.c_str();
	}

	void ScalableVectorString::setColour(int red, int green, int blue,int alpha){
		r=(float)red/255;g=(float)green/255,b=(float)blue/255,a=(float)alpha/255;
	}

	void ScalableVectorString::vectorize(char c, int x, int y,float red,float green,float blue,float alpha)
	{



		hw=2;
		vw = 0.0;



		glPushMatrix();
		glColor4f(red,green,blue,alpha);
		switch(c)
		{
			case  SPACE: kombat_SPACE
			case  EXCLAMATION: kombat_EXCLAMATION
			case  DOUBLE_QUOTES: kombat_DOUBLE_QUOTES
			case  HASHTAG: kombat_HASHTAG
			case  DOLLAR: kombat_DOLLAR
			case  PERCENT: kombat_PERCENT
			case  AMPERSAND: kombat_AMPERSAND
			case  SINGLE_QUOTE: kombat_SINGLE_QUOTE
			case  OPEN_PAREN: kombat_OPEN_PAREN
			case  CLOSE_PAREN: kombat_CLOSE_PAREN
			case  ASTERISK: kombat_ASTERISK
			case  PLUS: kombat_PLUS
			case  COMMA: kombat_COMMA
			case  HYPHEN: kombat_HYPHEN
			case  FULL_STOP: kombat_FULL_STOP
			case  SLASH: kombat_SLASH
			case  ZERO: kombat_ZERO
			case  ONE: kombat_ONE
			case  TWO: kombat_TWO
			case  THREE: kombat_THREE
			case  FOUR: kombat_FOUR
			case  FIVE: kombat_FIVE
			case  SIX: kombat_SIX
			case  SEVEN: kombat_SEVEN
			case  EIGHT: kombat_EIGHT
			case  NINE: kombat_NINE
			case  COLON: kombat_COLON
			case  SEMI_COLON: kombat_SEMI_COLON
			case  LESS_THAN: kombat_LESS_THAN
			case  EQUAL: kombat_EQUAL
			case  GRTR_THAN: kombat_GRTR_THAN
			case  QUESTION: kombat_QUESTION
			case  AT: kombat_AT
			case  'A': kombat_A
			case  'B': kombat_B
			case  'C': kombat_C
			case  'D': kombat_D
			case  'E': kombat_E
			case  'F': kombat_F
			case  'G': kombat_G
			case  'H': kombat_H
			case  'I': kombat_I
			case  'J': kombat_J
			case  'K': kombat_K
			case  'L': kombat_L
			case  'M': kombat_M
			case  'N': kombat_N
			case  'O': kombat_O
			case  'P': kombat_P
			case  'Q': kombat_Q
			case  'R': kombat_R
			case  'S': kombat_S
			case  'T': kombat_T
			case  'U': kombat_U
			case  'V': kombat_V
			case  'W': kombat_W
			case  'X': kombat_X
			case  'Y': kombat_Y
			case  'Z': kombat_Z
			case  BACKSLASH: kombat_BACKSLASH
			case  UNDERSCORE: kombat_UNDERSCORE
			case  'a': kombat_a
			case  'b': kombat_b
			case  'c': kombat_c
			case  'd': kombat_d
			case  'e': kombat_e
			case  'f': kombat_f
			case  'g': kombat_g
			case  'h': kombat_h
			case  'i': kombat_i
			case  'j': kombat_j
			case  'k': kombat_k
			case  'l': kombat_l
			case  'm': kombat_m
			case  'n': kombat_n
			case  'o': kombat_o
			case  'p': kombat_p
			case  'q': kombat_q
			case  'r': kombat_r
			case  's': kombat_s
			case  't': kombat_t
			case  'u': kombat_u
			case  'v': kombat_v
			case  'w': kombat_w
			case  'x': kombat_x
			case  'y': kombat_y
			case  'z': kombat_z
			default:xx+=17*(ht/40)+hw;break;
		}

		glPopMatrix();

	}

	ScalableVectorString::~ScalableVectorString() {
		// TODO Auto-generated destructor stub
	}





