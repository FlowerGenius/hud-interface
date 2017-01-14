/*
 * helper_functions.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: erin
 */

#include "header.h"

bool any(std::list<bool> L){
	for (std::list<bool>::const_iterator iterator =L.begin(), end = L.end(); iterator != end; ++iterator) {
				bool current = *iterator;
				if (current)
					return true;
			}
	return false;
}



bool all(std::list<bool> L){
	for (std::list<bool>::const_iterator iterator = L.begin(), end = L.end(); iterator != end; ++iterator) {
				bool current = *iterator;
				if (current)
					return false;
			}
	return true;

}
