/*
 * WorldObject.h
 *
 *  Created on: Feb 14, 2017
 *      Author: erin
 */

#ifndef LRAND_LRAND_WORLDOBJECT_H_
#define LRAND_LRAND_WORLDOBJECT_H_

class WorldObject {
public:
	WorldObject();
	virtual ~WorldObject();
	static std::list<WorldObject*> world_object_collection;
	static int k;
	void draw();
};

#endif /* LRAND_LRAND_WORLDOBJECT_H_ */
