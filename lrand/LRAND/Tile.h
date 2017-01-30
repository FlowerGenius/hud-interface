/*
 * Tile.h
 *
 *  Created on: Jan 21, 2017
 *      Author: erin
 */

#ifndef LRAND_LRAND_TILE_H_
#define LRAND_LRAND_TILE_H_

#include <opencv2/core/mat.hpp>

namespace cv {

class Tile: public Mat {
public:
	Tile();
	Tile(Mat,int,int,int);
	virtual ~Tile();
};

} /* namespace cv */

#endif /* LRAND_LRAND_TILE_H_ */
