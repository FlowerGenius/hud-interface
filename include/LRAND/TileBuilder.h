/*
 * TileBuilder.h
 *
 *  Created on: Jan 16, 2017
 *      Author: erin
 */

#ifndef INCLUDE_LRAND_TILEBUILDER_H_
#define INCLUDE_LRAND_TILEBUILDER_H_

class HeadsUpInterface;

class TileBuilder {
public:
	TileBuilder();
	virtual ~TileBuilder();

	int render(void);
	void draw(void);

	void setCoords();
private:
	std::string dsource;
	std::string url;
	int z;
};

#endif /* INCLUDE_LRAND_TILEBUILDER_H_ */
