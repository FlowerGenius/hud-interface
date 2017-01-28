/*
 * helper_functions.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: erin
 */

#include "header.h"

bool any(std::list<bool> L){
	for (std::list<bool>::const_iterator iterator =L.begin(), end = L.end(); iterator != end; ++iterator) {
				bool current = *iterator;
				if (current)
					return true;
			}
	return false;
}


bool all(std::list<bool> L){
	for (std::list<bool>::const_iterator iterator = L.begin(), end = L.end(); iterator != end; ++iterator) {
				bool current = *iterator;
				if (current)
					return false;
			}
	return true;

}

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != NULL)
            result += buffer.data();
    }
    return result;
}

float long2tilex(double lon, int z)
{
	return (lon + 180.0) / 360.0 * pow(2.0, z);
}


float lat2tiley(double lat, int z)
{
	return (1.0 - log( tan(lat * M_PI/180.0) + 1.0 / cos(lat * M_PI/180.0)) / M_PI) / 2.0 * pow(2.0, z);
}


double tilex2long(int x, int z)
{
	return x / pow(2.0, z) * 360.0 - 180;
}


double tiley2lat(int y, int z)
{
	double n = M_PI - 2.0 * M_PI * y / pow(2.0, z);
	return 180.0 / M_PI * atan(0.5 * (exp(n) - exp(-n)));
}


void BindCVMat2GLTexture(cv::Mat& image, GLuint& imageTexture)
{
   if(image.empty()){
      std::cout << "image empty" << std::endl;
  }else{
      glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    //  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
      glGenTextures(1, &imageTexture);
      glBindTexture(GL_TEXTURE_2D, imageTexture);

      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        // Set texture clamping method
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

      cv::cvtColor(image, image, CV_RGB2BGR);

      glTexImage2D(GL_TEXTURE_2D,         // Type of texture
                     	0,                   // Pyramid level (for mip-mapping) - 0 is the top level
			GL_RGB,              // Internal colour format to convert to
                     	image.cols,          // Image width  i.e. 640 for Kinect in standard mode
                     	image.rows,          // Image height i.e. 480 for Kinect in standard mode
                     	0,                   // Border width in pixels (can either be 1 or 0)
			GL_RGB,              // Input image format (i.e. GL_RGB, GL_RGBA, GL_BGR etc.)
			GL_UNSIGNED_BYTE,    // Image data type
			image.ptr());        // The actual image data itself
	}
}
