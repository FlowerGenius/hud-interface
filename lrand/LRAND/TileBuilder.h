/*
 * TileBuilder.h
 *
 *  Created on: Jan 16, 2017
 *      Author: erin
 */

#ifndef LRAND_LRAND_TILEBUILDER_H_
#define LRAND_LRAND_TILEBUILDER_H_

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

#endif /* LRAND_LRAND_TILEBUILDER_H_ */
