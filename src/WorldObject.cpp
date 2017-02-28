/*
 * WorldObject.cpp
 *
 *  Created on: Feb 14, 2017
 *      Author: erin
 */

#include <lrand/lrand.h>

int WorldObject::k = 0;
std::list<WorldObject*> WorldObject::world_object_collection = {};

WorldObject::WorldObject() {

}

void WorldObject::draw(){

	std::fprintf(stderr,"%d",(int)WorldObject::world_object_collection.size());
}

WorldObject::~WorldObject() {
	// TODO Auto-generated destructor stub
}

