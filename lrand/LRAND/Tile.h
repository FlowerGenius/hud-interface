/*
 * Tile.h
 *
 *  Created on: Jan 21, 2017
 *      Author: erin
 */

#ifndef LRAND_LRAND_TILE_H_
#define LRAND_LRAND_TILE_H_

class Tile
{
public:
	Tile();
	Tile(int,int,int);
	virtual ~Tile();
	void fetch(int,int,int);
private:
	cv::Mat _data;
};


#endif /* LRAND_LRAND_TILE_H_ */
