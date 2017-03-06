/*
 * Planet.h
 *
 *  Created on: Mar 5, 2017
 *      Author: erin
 */

#ifndef LRAND_MPSPS_PLANET_H_
#define LRAND_MPSPS_PLANET_H_


class Planet {
public:
	Planet();
	virtual ~Planet();

//== Physical Planetary Attributes ====

	/*
	 * Get the planetary radius
	 */
	long double getRadius() { return radius; }

	/*
	 * Get the planetary mass
	 */
	long double getMass() { return mass; }

//== Given Planetary Attributes =======

	/*
	 * Get the name of the planet
	 */
	std::string getName() { return name; }

//== Derived Planetary Attributes =====

	/*
	 * Get the force of gravity at the current altitude for this planet
	 */
	long double getForceOfGravity(){
		;
	}

protected:
	const long double radius   = 0;
	const long double mass	   = 0;

	const std::string name     = "PlanetX";
};

class Earth : Planet{
public:
	Earth();
	virtual ~Earth();
protected:
	const long double radius 	= 6371.0;
	const long double mass   	= 5.972e24;

	const std::string name	 	= "Earth";
};

#endif /* LRAND_MPSPS_PLANET_H_ */
