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
	void 	draw();
	//std::pair<double,double> coords;
	void setCoords();

private:
	std::vector<std::string> 		getTileUrls();
	std::string	dsource;
	std::string getTileUrl();
	std::string url;

	int z;
};

#endif /* TILEBUILDER_H_ */
