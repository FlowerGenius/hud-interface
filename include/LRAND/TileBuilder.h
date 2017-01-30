/*
 * TileBuilder.h
 *
 *  Created on: Jan 16, 2017
 *      Author: erin
 */

#ifndef TILEBUILDER_H_
#define TILEBUILDER_H_

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

#endif /* TILEBUILDER_H_ */