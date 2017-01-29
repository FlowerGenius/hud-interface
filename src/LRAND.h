/*
 * LRAND.h
 *
 *  Created on: Jan 28, 2017
 *      Author: erin
 */

#ifndef LRAND_H_
#define LRAND_H_

namespace LRAND {


class generic_error: public std::exception
{

public:

	//! Constructs parse error
	generic_error(const char *what)
		: m_what(what)
	{
	}

	//! Gets human readable description of error.
	//! \return Pointer to null terminated description of the error.
	virtual const char *what() const throw()
	{
		return m_what;
	}

private:
	const char *m_what;
};

class Colour {
public:
	virtual void set(int Red, int Green, int Blue, int Alpha){
		if (0 <= Red and Red <= 255 and
			0 <= Green and Green <= 255 and
			0 <= Blue and Blue <= 255 and
			0 <= Alpha and Alpha <= 255){
			R=Red,G=Green,B=Blue,A=Alpha;
		} else {
			throw generic_error("Colour index out of range");
		}
		R=Red,G=Green,B=Blue,A=Alpha;
		BGR = cv::Scalar((float)B,(float)G,(float)R);
	}
	virtual void set(float Red, float Green, float Blue, float Alpha){
		if (0 <= Red and Red <= 255 and
			0 <= Green and Green <= 255 and
			0 <= Blue and Blue <= 255 and
			0 <= Alpha and Alpha <= 255){
			R=Red,G=Green,B=Blue,A=Alpha;
		} else {
			throw generic_error("Colour index out of range");
		}
		R=Red,G=Green,B=Blue,A=Alpha;
		BGR = cv::Scalar(B,G,R);
	}

	Colour(){
		set(255,255,255,255);
	}

	Colour(int Red, int Green, int Blue, int Alpha){
		if (0 <= Red and Red <= 255 and
			0 <= Green and Green <= 255 and
			0 <= Blue and Blue <= 255 and
			0 <= Alpha and Alpha <= 255){
			R=Red,G=Green,B=Blue,A=Alpha;
		} else {
			throw generic_error("Colour index out of range");
		}
	}


	virtual ~Colour() {
		// TODO Auto-generated destructor stub
	}
	LRAND::Colour operator- (const int i) const 		{ return Colour(std::max(R-i,0),std::max(G-i,0),std::max(B-i,0),std::max(A-i,0)); }
	LRAND::Colour operator+ (const int i) const 		{ return Colour(std::min(R+i,255),std::min(R+i,255),std::min(R+i,255),std::min(R+i,255)); }

	std::vector<double> polar(){
		return {(float)R/255.0,(float)G/255.0,(float)B/255.0,(float)A/255.0};
	}

	virtual void bind(){
		glColor4f((float)R/255.0,(float)G/255.0,(float)B/255.0,(float)A/255.0);
	}

	cv::Scalar_<int> 	BGR;
	cv::Scalar_<int>	RGB;


private:
	int R,G,B,A;
};

class GlColour : public Colour
{
public:

	virtual void set(float Red, float Green, float Blue, float Alpha){
		if (0 <= Red and Red <= 255 and
			0 <= Green and Green <= 255 and
			0 <= Blue and Blue <= 255 and
			0 <= Alpha and Alpha <= 255){
			R=Red,G=Green,B=Blue,A=Alpha;
		} else {
			throw generic_error("Colour index out of range");
		}
		R=Red,G=Green,B=Blue,A=Alpha;
		BGR = cv::Scalar(B,G,R);
	}

	GlColour(){
		set(255.0f,255.0f,255.0f,255.0f);
	}

	GlColour(int Red,int Green,int Blue,int Alpha){
		set((float)Red/255.0,(float)Green/255.0,(float)Blue/255.0,(float)Alpha/255.0);
	}

	GlColour(float Red,float Green,float Blue,float Alpha){
		set(Red,Green,Blue,Alpha);
	}

	GlColour(LRAND::Colour& c){
		std::vector<double> f = c.polar();
		set(f.at(0),f.at(1),f.at(2),f.at(3));
	}

	virtual void bind(){
		glColor4f(R,G,B,A);
	}

	virtual ~GlColour(){

	}


private:
	float R,G,B,A;
};

class Drawable {
public:
					Drawable(){

					}

	virtual			~Drawable() {

	}
	virtual int 	render(void);
	virtual	void	draw(void);

	virtual void 	setColour(int R,int G,int B,int A);
	virtual void 	setColour(LRAND::Colour c);

protected:
	LRAND::Colour colour;
};


} /* namespace LRAND */

#endif /* LRAND_H_ */
