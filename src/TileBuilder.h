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
	TileBuilder(std::string datasource,int zoom=18);
	virtual ~TileBuilder();
	void 	draw(void);
private:
	std::pair<double,double>	getCoords(int timeout=10);
	std::list<std::string> 		getTileUrls();
	std::string	dsource;
	int z;
};

#endif /* TILEBUILDER_H_ */
