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
	std::pair<double,double> coords;
	std::pair<double,double> getCoords(int timeout);
	void setCoords();

private:
	std::vector<std::string> 		getTileUrls();
	std::string	dsource;
	std::string getTileUrl();
	std::string leftbound;
	std::string coordsep;
	std::string rightbound;
	std::string sub1,coordstring,longstring,latstring;
	size_t pos=0;

	int z;
};

#endif /* TILEBUILDER_H_ */
