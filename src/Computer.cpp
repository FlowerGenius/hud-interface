/*
 * Computer.cpp
 *
 *  Created on: Mar 5, 2017
 *      Author: erin
 */

#include <lrand/lrand.h>

std::atomic<double> 	Computer::battery_life;
std::atomic<bool> 		Computer::is_charging;
std::string 			Computer::battery_state;

Computer::Computer() {
	// TODO Auto-generated constructor stub

}

Computer::~Computer() {
	// TODO Auto-generated destructor stub
}

