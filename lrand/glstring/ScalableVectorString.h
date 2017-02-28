/*
 * ScalableVectorString.h
 *
 *  Created on: Jan 11, 2017
 *      Author: erin
 */

#ifndef LRAND_GLSTRING_SCALABLEVECTORSTRING_H_
#define LRAND_GLSTRING_SCALABLEVECTORSTRING_H_

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
#define			SLASH_ZERO			U'\u00F8'
#define			POUND_STERLING		U'\u00A3'
#define			SLASH_BIGZERO		U'\u00D8'
#define			MULTIPLICATION		U'\u00D7'
#define			FUNCTION			U'\u0192'
#define			ANGLE_QUOTES_OPEN	U'\u00AB'
#define			ANGLE_QUOTES_CLOSE	U'\u00BB'
#define			STIPPLE1			U'\u2591'
#define			STIPPLE2			U'\u2592'
#define			STIPPLE3			U'\u2593'
#define			CENT				U'\u00A2'
#define			YEN					U'\u00A5'
#define			CURRENCY_SYMBOL		U'\u00A4'
#define			BLOCK				U'\u2588'
#define			BOTTOM_BLOCK		U'\u2584'
#define			TOP_BLOCK			U'\u2580'
#define			MACRON_SYMBOL		U'\u00AF'
#define			TRIPLE_HYPHEN		U'\u2261'
#define			PLUSMINUS			U'\u00B1'
#define			DOUBLE_UNDERSCORE	U'\u007E'
#define			SECTION_SIGN		U'\u00F7'
#define			DIVISION_SIGN		U'\u00F7'
#define			CEDILLA				U'\u00B8'
#define			DEGREE				U'\u00B0'
#define			DIAERESIS			U'\u00A8'
#define			SPACE_DOT			U'\u00B7'
#define			SUPER_1			U'\u00B9'
#define			SUPER_3			U'\u00B3'
#define			SUPER_2			U'\u00B2'
#define			SQUARE			U'\u25A0'
#define			NBSP			U'\u00A0'


#ifdef MODERN_OPENGL
#include <lrand/glstring/fonts/modern_kombat.hpp>
#define FONT_SHADER_INIT(VS,IS)  glBufferData(GL_ARRAY_BUFFER, sizeof(VS), VS, GL_STATIC_DRAW); 	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(IS), IS, GL_STATIC_DRAW);	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (GLvoid*)0); glEnableVertexAttribArray(0); glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat))); glEnableVertexAttribArray(1); verts = sizeof(IS);
#define fontbuilder(y)	 modern_kombat ## _ ## y
#else
#include <lrand/glstring/fonts/kombat.hpp>
#define fontbuilder(y)	 kombat ## _ ## y
#endif

extern Shader interfaceShader;

class ScalableVectorString {
public:

	ScalableVectorString() {
		br_colour.set(0.0,0.0,0.0,1.0);
		text = "";
		xx=0,x1=0,x2=0,x3=0,x4=0;
		length=0;
		i=0;
		h=0;
		w=0;
		hw=0;
		vw=0;
		ht=-1;
		bw=0;
		verts=3;
	}

	virtual ~ScalableVectorString(){

	}

	void ldraw(int x, int y, int border,float font_size){

		if (ht < 0){
			ht = font_size;
		}

		bw = border;
		length = getLength();
		xx=x;
		x1=x+border;
		x2=x-border;
		for (auto& ch : bytes){
			if(border>0){
				vectorize(ch, x+border, y-border, br_colour,x1);
				x1=vectorize(ch, x+border, y+border, br_colour,x1);
				vectorize(ch, x-border, y-border, br_colour,x2);
				x2=vectorize(ch, x-border, y+border, br_colour,x2);
			}
			xx=vectorize(ch, x, y, colour,xx);
		}
		length = xx-x;
	}

	void rdraw(int x, int y, int border, float font_size){


		if (ht < 0){
			ht = font_size;
		}

		length = getLength();
		bw = border;
		xx=width-x-length;
		x1=width-x+border-length;
		x2=width-x-border-length;
		for (auto& ch : bytes){
			if(border>0){
				vectorize(ch, x-border, y+border, br_colour,x1);
				x1=vectorize(ch, x-border, y-border, br_colour,x1);
				vectorize(ch, x+border, y+border, br_colour,x2);
				x2=vectorize(ch, x+border, y-border, br_colour,x2);
			}
			xx=vectorize(ch, width-x, y, colour,xx);
		}
	}



	void setText(std::string s,float size=-1){
		text = s;
		bytes = std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t>{}.from_bytes(text);
		if (size > 0){
			ht = size;
		}


	}

	void setColour(int red, int green, int blue,int alpha){
		colour = LRAND::GlColour((float)red/255,(float)green/255,(float)blue/255,(float)alpha/255);
	}
	void setColour(LRAND::GlColour c){
		colour = c;
	}
	void setColour(LRAND::Colour c){
		colour = LRAND::GlColour(c);
	}


	LRAND::Colour		getColour()		{ return colour; }
	std::u32string bytes;

	unsigned int getLength(){
		xx=0;
		for (auto& ch : bytes){
			xx=vectorize(ch, width, height, br_colour,xx);
		}
		return xx;
	}

	unsigned int getHeight(){
		return ht;
	}

	unsigned int length;
private:
	Shader textShader;
	LRAND::GlColour colour;
	LRAND::GlColour	br_colour;
	uint verts;
	GLuint VBO, VAO, EBO;
	float a,r,g,b;


	int vectorize(char32_t chr, int x, int y,LRAND::GlColour co,int pos)
	{

		hw=MAX(2,bw);
		vw = 0.0;


#ifdef MODERN_OPENGL
		a = co.A, r = co.R, g = co.G, b = co.B;
		verts = 3;

		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);
		// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

		for(;;)
		{
			if (  SPACE ==chr) fontbuilder(SPACE)
			else if (  EXCLAMATION ==chr) fontbuilder(EXCLAMATION)
			else if (  DOUBLE_QUOTES ==chr) fontbuilder(DOUBLE_QUOTES)
			else if (  HASHTAG ==chr) fontbuilder(HASHTAG)
			else if (  DOLLAR ==chr) fontbuilder(DOLLAR)
			else if (  PERCENT ==chr) fontbuilder(PERCENT)
			else if (  AMPERSAND ==chr) fontbuilder(AMPERSAND)
			else if (  SINGLE_QUOTE ==chr) fontbuilder(SINGLE_QUOTE)
			else if (  OPEN_PAREN ==chr) fontbuilder(OPEN_PAREN)
			else if (  CLOSE_PAREN ==chr) fontbuilder(CLOSE_PAREN)
			else if (  ASTERISK ==chr) fontbuilder(ASTERISK)
			else if (  PLUS ==chr) fontbuilder(PLUS)
			else if (  COMMA ==chr) fontbuilder(COMMA)
			else if (  HYPHEN ==chr) fontbuilder(HYPHEN)
			else if (  FULL_STOP ==chr) fontbuilder(FULL_STOP)
			else if (  SLASH ==chr) fontbuilder(SLASH)
			else if (  ZERO ==chr) fontbuilder(ZERO)
			else if (  ONE ==chr) fontbuilder(ONE)
			else if (  TWO ==chr) fontbuilder(TWO)
			else if (  THREE ==chr) fontbuilder(THREE)
			else if (  FOUR ==chr) fontbuilder(FOUR)
			else if (  FIVE ==chr) fontbuilder(FIVE)
			else if (  SIX ==chr) fontbuilder(SIX)
			else if (  SEVEN ==chr) fontbuilder(SEVEN)
			else if (  EIGHT ==chr) fontbuilder(EIGHT)
			else if (  NINE ==chr) fontbuilder(NINE)
			else if (  COLON ==chr) fontbuilder(COLON)
			else if (  SEMI_COLON ==chr) fontbuilder(SEMI_COLON)
			else if (  LESS_THAN ==chr) fontbuilder(LESS_THAN)
			else if (  EQUAL ==chr) fontbuilder(EQUAL)
			else if (  GRTR_THAN ==chr) fontbuilder(GRTR_THAN)
			else if (  QUESTION ==chr) fontbuilder(QUESTION)
			else if (  AT ==chr) fontbuilder(AT)
			else if ( U'A' ==chr) fontbuilder(A)
			else if ( U'B' ==chr) fontbuilder(B)
			else if ( U'C' ==chr) fontbuilder(C)
			else if ( U'D' ==chr) fontbuilder(D)
			else if ( U'E' ==chr) fontbuilder(E)
			else if ( U'F' ==chr) fontbuilder(F)
			else if ( U'G' ==chr) fontbuilder(G)
			else if ( U'H' ==chr) fontbuilder(H)
			else if ( U'I' ==chr) fontbuilder(I)
			else if ( U'J' ==chr) fontbuilder(J)
			else if ( U'K' ==chr) fontbuilder(K)
			else if ( U'L' ==chr) fontbuilder(L)
			else if ( U'M' ==chr) fontbuilder(M)
			else if ( U'N' ==chr) fontbuilder(N)
			else if ( U'O' ==chr) fontbuilder(O)
			else if ( U'P' ==chr) fontbuilder(P)
			else if ( U'Q' ==chr) fontbuilder(Q)
			else if ( U'R' ==chr) fontbuilder(R)
			else if ( U'S' ==chr) fontbuilder(S)
			else if ( U'T' ==chr) fontbuilder(T)
			else if ( U'U' ==chr) fontbuilder(U)
			else if ( U'V' ==chr) fontbuilder(V)
			else if ( U'W' ==chr) fontbuilder(W)
			else if ( U'X' ==chr) fontbuilder(X)
			else if ( U'Y' ==chr) fontbuilder(Y)
			else if ( U'Z' ==chr) fontbuilder(Z)
			else if (  BACKSLASH ==chr) fontbuilder(BACKSLASH)
			else if (  UNDERSCORE ==chr) fontbuilder(UNDERSCORE)
			else if ( U'a' ==chr) fontbuilder(a)
			else if ( U'b' ==chr) fontbuilder(b)
			else if ( U'c' ==chr) fontbuilder(c)
			else if ( U'd' ==chr) fontbuilder(d)
			else if ( U'e' ==chr) fontbuilder(e)
			else if ( U'f' ==chr) fontbuilder(f)
			else if ( U'g' ==chr) fontbuilder(g)
			else if ( U'h' ==chr) fontbuilder(h)
			else if ( U'i' ==chr) fontbuilder(i)
			else if ( U'j' ==chr) fontbuilder(j)
			else if ( U'k' ==chr) fontbuilder(k)
			else if ( U'l' ==chr) fontbuilder(l)
			else if ( U'm' ==chr) fontbuilder(m)
			else if ( U'n' ==chr) fontbuilder(n)
			else if ( U'o' ==chr) fontbuilder(o)
			else if ( U'p' ==chr) fontbuilder(p)
			else if ( U'q' ==chr) fontbuilder(q)
			else if ( U'r' ==chr) fontbuilder(r)
			else if ( U's' ==chr) fontbuilder(s)
			else if ( U't' ==chr) fontbuilder(t)
			else if ( U'u' ==chr) fontbuilder(u)
			else if ( U'v' ==chr) fontbuilder(v)
			else if ( U'w' ==chr) fontbuilder(w)
			else if ( U'x' ==chr) fontbuilder(x)
			else if (U'y' ==chr) fontbuilder(y)
			else if (U'z' == chr ) fontbuilder(z)
			else if ( DEGREE == chr) fontbuilder(DEGREE)
			else {
				pos+=17*(ht/40)+hw;
			}
			//glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glBindVertexArray(0); // Unbind VAO
			interfaceShader.Use();
			glBindVertexArray(VAO);
			glDrawElements(GL_TRIANGLES, verts, GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);

			//glPopAttrib();
			break;
		}
#else
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

			pos+=17*(ht/40)+hw;
			break;
		}
		glPopAttrib();
		glPopMatrix();
#endif


		return pos;
	}

	std::string text;
	int xx,x1,x2,x3,x4;
	unsigned int i;
	float ht;
	float hw,vw;
	int h, w;
	float bw;
};

#undef			SPACE
#undef			EXCLAMATION
#undef			DOUBLE_QUOTES
#undef			HASHTAG
#undef			DOLLAR
#undef			PERCENT
#undef			AMPERSAND
#undef			SINGLE_QUOTE
#undef			OPEN_PAREN
#undef			CLOSE_PAREN
#undef			ASTERISK
#undef			PLUS
#undef			COMMA
#undef			HYPHEN
#undef			FULL_STOP
#undef			SLASH
#undef			ZERO
#undef			ONE
#undef			TWO
#undef			THREE
#undef			FOUR
#undef			FIVE
#undef			SIX
#undef			SEVEN
#undef			EIGHT
#undef			NINE
#undef			COLON
#undef			SEMI_COLON
#undef			LESS_THAN
#undef			EQUAL
#undef			GRTR_THAN
#undef			QUESTION
#undef			AT
//Capital Letters
#undef			OPEN_BRACKET
#undef			BACKSLASH
#undef			CLOSE_BRACKET
#undef			CARET
#undef			UNDERSCORE
#undef			ACCT_GRAVE
//Minor letters
#undef			OPEN_BRACE
#undef			VERT_BAR
#undef			CLOSE_BRACE
#undef			TILDE
//				DELETE
#undef			SLASH_ZERO
#undef			POUND_STERLING
#undef			SLASH_BIGZERO
#undef			MULTIPLICATION
#undef			FUNCTION
#undef			ANGLE_QUOTES_OPEN
#undef			ANGLE_QUOTES_CLOSE
#undef			STIPPLE1
#undef			STIPPLE2
#undef			STIPPLE3
#undef			CENT
#undef			YEN
#undef			CURRENCY_SYMBOL
#undef			BLOCK
#undef			BOTTOM_BLOCK
#undef			TOP_BLOCK
#undef			MACRON_SYMBOL
#undef			TRIPLE_HYPHEN
#undef			PLUSMINUS
#undef			DOUBLE_UNDERSCORE
#undef			SECTION_SIGN
#undef			DIVISION_SIGN
#undef			CEDILLA
#undef			DEGREE
#undef			DIAERESIS
#undef			SPACE_DOT
#undef			SUPER_1
#undef			SUPER_3
#undef			SUPER_2
#undef			SQUARE
#undef			NBSP
#undef			fontbuilder

#endif /* LRAND_GLSTRING_SCALABLEVECTORSTRING_H_ */
