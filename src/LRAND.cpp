/*
 * LRAND.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: erin
 */

#include <lrand/lrand.h>

namespace LRAND {
	Colour  Colour::YELLOW = Colour(255,255,0,255);
	Colour  Colour::RED = Colour(255,0,0,255);
	Colour  Colour::GREEN = Colour(0,255,0,255);
	Colour  Colour::BLUE = Colour(0,0,255,255);

	GlColour GlColour::YELLOW = GlColour(255,255,9,255);
	GlColour GlColour::RED = GlColour(255,0,0,255);
	GlColour GlColour::GREEN = GlColour(0,255,0,255);
	GlColour GlColour::BLUE = GlColour(0,0,255,255);


} /* namespace LRAND */
