/*
 * TileBuilder.cpp
 *
 *  Created on: Jan 16, 2017
 *      Author: erin
 */
 
#include "header.h"
#include "DeviceAccess.h"
#include "HeadsUpCompass.h"
#include "png.h"
#include "HeadsUpBatteryInfo.h"
#include "HeadsUpDigitalClock.h"
#include "TileBuilder.h"
#include "HeadsUpWaypoint.h"
#include "HeadsUpMap.h"
#include "HeadsUpCheckBox.h"
#include "HeadsUpWaypoint.h"
#include "HeadsUpObjective.h"
#include "HeadsUpTask.h"
#include "Timer.hpp"
#include "HeadsUpInterface.h"

extern HeadsUpInterface interface;


std::vector<std::string> tilesource;
GLuint tex;

extern float long2tilex(double lon,int z);
extern float lat2tiley(double lat,int z);
extern double m_longitude;
extern double m_latitude;
std::pair<float,float> map_location;

float bw = 0.03;
float zoom = 0.3333;

cv::Mat m_image;
cv::Mat m1_image;

std::string datsource = "http://a.tile.openstreetmap.org";

cv::Mat resultImg;
cv::Mat top,mid,bottom;
std::vector<std::string> vstr;
float mmx,mmy;

int tilex;
int tiley;
int k = 0;

int previous_tilex,previous_tiley;

extern std::vector<cv::Mat> tiles;

size_t write_data(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    std::vector<uchar> *stream = (std::vector<uchar>*)userdata;
    size_t count = size * nmemb;
    stream->insert(stream->end(), ptr, ptr + count);
    return count;
}

//function to retrieve the image as cv::Mat data type
cv::Mat curlImg(std::string img_url, int timeout=10)
{
    std::vector<uchar> stream;
    CURL *curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, img_url.c_str()); //the img url
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data); // pass the writefunction
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &stream); // pass the stream ptr to the writefunction
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout); // timeout if curl_easy hangs,
    curl_easy_perform(curl); // start curl
    curl_easy_cleanup(curl); // cleanup
    return cv::imdecode(stream, -1); // 'keep-as-is'
}

TileBuilder::TileBuilder() {
	dsource = datsource;
	z = 17;
}

cv::Mat getTile(int tilexyx, int tileyxy, int zoom){
	return curlImg(datsource+"/"+std::to_string(zoom)+"/"+std::to_string(tilexyx)+"/"+std::to_string(tileyxy)+".png");
}

void assignTile(int i,int tilexx, int tileyy, int zoom){

	if (k % 3) {k=0;}

	switch(k){
	case 0:
		datsource = "http://a.tile.openstreetmap.org";
		k++;
		break;
	case 1:
		datsource = "http://b.tile.openstreetmap.org";
		k++;
		break;
	case 2:
		datsource = "http://c.tile.openstreetmap.org";
		k++;
		break;
	default:
		datsource = "http://a.tile.openstreetmap.org";
		k = 0;
		break;
	};

	tiles[i] = getTile(tilexx,tileyy,zoom);
}

void assignTiles(int tilex, int tileyy, int zoom){
	std::vector<std::thread> threads;
	if (tilex == previous_tilex-1){
			if (tileyy == previous_tiley-1){
				tiles[8] = tiles[4];
				tiles[7] = tiles[3];
				threads.push_back(std::thread(assignTile,6,tilex-1,tileyy+1,zoom));

				tiles[5] = tiles[1];
				tiles[4] = tiles[0];
				threads.push_back(std::thread(assignTile,3,tilex-1,tileyy,zoom));

				threads.push_back(std::thread(assignTile,2,tilex+1,tileyy-1,zoom));
				threads.push_back(std::thread(assignTile,1,tilex,tileyy-1,zoom));
				threads.push_back(std::thread(assignTile,0,tilex-1,tileyy-1,zoom));
			}
			else if (tileyy == previous_tiley){

				tiles[2] = tiles[1];
				tiles[1] = tiles[0];
				threads.push_back(std::thread(assignTile,0,tilex-1,tileyy-1,zoom));

				tiles[5] = tiles[4];
				tiles[4] = tiles[3];
				threads.push_back(std::thread(assignTile,3,tilex-1,tileyy,zoom));

				tiles[8] = tiles[7];
				tiles[7] = tiles[6];
				threads.push_back(std::thread(assignTile,6,tilex-1,tileyy+1,zoom));

			}
			else if (tileyy == previous_tiley+1){

				tiles[2] = tiles[4];
				tiles[1] = tiles[3];
				threads.push_back(std::thread(assignTile,0,tilex-1,tileyy-1,zoom));

				tiles[5] = tiles[7];
				tiles[4] = tiles[6];
				threads.push_back(std::thread(assignTile,3,tilex-1,tileyy,zoom));

				threads.push_back(std::thread(assignTile,8,tilex+1,tileyy+1,zoom));
				threads.push_back(std::thread(assignTile,7,tilex,tileyy+1,zoom));
				threads.push_back(std::thread(assignTile,6,tilex-1,tileyy+1,zoom));

			}
		}
		else if (tilex == previous_tilex){
			if (tileyy == previous_tiley-1){

				tiles[8] = tiles[5];
				tiles[7] = tiles[4];
				tiles[6] = tiles[3];

				tiles[5] = tiles[2];
				tiles[4] = tiles[1];
				tiles[3] = tiles[0];

				threads.push_back(std::thread(assignTile,2,tilex+1,tileyy-1,zoom));
				threads.push_back(std::thread(assignTile,1,tilex,tileyy-1,zoom));
				threads.push_back(std::thread(assignTile,0,tilex-1,tileyy-1,zoom));
			}
			else if (tileyy == previous_tiley){

				//Do nothing because the context has not changed
			}
			else if (tileyy == previous_tiley+1){
				tiles[0] = tiles[3];
				tiles[1] = tiles[4];
				tiles[2] = tiles[5];

				tiles[5] = tiles[8];
				tiles[4] = tiles[7];
				tiles[3] = tiles[6];

				threads.push_back(std::thread(assignTile,8,tilex+1,tileyy+1,zoom));
				threads.push_back(std::thread(assignTile,7,tilex,tileyy+1,zoom));
				threads.push_back(std::thread(assignTile,6,tilex-1,tileyy+1,zoom));
			}
		}
		else if (tilex == previous_tilex+1){
			if (tileyy == previous_tiley-1){
				tiles[6] = tiles[4];
				tiles[7] = tiles[5];
				threads.push_back(std::thread(assignTile,8,tilex+1,tileyy+1,zoom));

				tiles[3] = tiles[1];
				tiles[4] = tiles[2];
				threads.push_back(std::thread(assignTile,5,tilex+1,tileyy,zoom));

				threads.push_back(std::thread(assignTile,0,tilex-1,tileyy-1,zoom));
				threads.push_back(std::thread(assignTile,1,tilex,tileyy-1,zoom));
				threads.push_back(std::thread(assignTile,2,tilex+1,tileyy-1,zoom));

			}
			else if (tileyy == previous_tiley){
				tiles[0] = tiles[1];
				tiles[1] = tiles[2];
				threads.push_back(std::thread(assignTile,2,tilex+1,tileyy-1,zoom));

				tiles[3] = tiles[4];
				tiles[4] = tiles[5];
				threads.push_back(std::thread(assignTile,5,tilex+1,tileyy,zoom));

				tiles[6] = tiles[7];
				tiles[7] = tiles[8];
				threads.push_back(std::thread(assignTile,8,tilex+1,tileyy+1,zoom));
			}
			else if (tileyy == previous_tiley+1){
				tiles[0] = tiles[4];
				tiles[1] = tiles[5];
				threads.push_back(std::thread(assignTile,2,tilex+1,tileyy-1,zoom));

				tiles[3] = tiles[7];
				tiles[4] = tiles[8];
				threads.push_back(std::thread(assignTile,5,tilex+1,tileyy,zoom));

				threads.push_back(std::thread(assignTile,6,tilex-1,tileyy+1,zoom));
				threads.push_back(std::thread(assignTile,7,tilex,tileyy+1,zoom));
				threads.push_back(std::thread(assignTile,8,tilex+1,tileyy+1,zoom));
			}
		}
		else {
			threads.push_back(std::thread(assignTile,8,tilex+1,tileyy+1,zoom));
			threads.push_back(std::thread(assignTile,7,tilex,tileyy+1,zoom));
			threads.push_back(std::thread(assignTile,6,tilex-1,tileyy+1,zoom));

			threads.push_back(std::thread(assignTile,5,tilex+1,tileyy,zoom));
			threads.push_back(std::thread(assignTile,4,tilex,tileyy,zoom));
			threads.push_back(std::thread(assignTile,3,tilex-1,tileyy,zoom));

			threads.push_back(std::thread(assignTile,2,tilex+1,tileyy-1,zoom));
			threads.push_back(std::thread(assignTile,1,tilex,tileyy-1,zoom));
			threads.push_back(std::thread(assignTile,0,tilex-1,tileyy-1,zoom));
		}

	for (auto& th : threads) th.join();

	cv::hconcat(std::vector<cv::Mat>({tiles[0],tiles[1],tiles[2]}), top);
	cv::hconcat(std::vector<cv::Mat>({tiles[3],tiles[4],tiles[5]}), mid);
	cv::hconcat(std::vector<cv::Mat>({tiles[6],tiles[7],tiles[8]}), bottom);

	cv::vconcat(std::vector<cv::Mat>({top,mid,bottom}),resultImg);

	for (auto& wp : interface.waypoints) {wp->draw();}

}

void TileBuilder::draw(){
		dsource = datsource;
		z = 17;
		tilex = ((int)(floor(long2tilex(m_longitude,z))));
	 	tiley = ((int)(floor(lat2tiley(m_latitude,z))));
	 	map_location.first = (long2tilex(m_longitude,z)-tilex);
	 	map_location.second = (lat2tiley(m_latitude,z)-tiley);
		mmx = ((map_location.first*2)-1)/2;
		mmy = ((map_location.second*2)-1)/2;

		assignTiles(tilex,tiley,z);

		previous_tiley = tiley;
		previous_tilex = tilex;


			glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			{

				glColor4f(0.5, 0.5, 0.5, 0.98);
				glEnable(GL_TEXTURE_2D);
				// Create Texture
				glGenTextures(1, &tex);
				glBindTexture(GL_TEXTURE_2D, tex); // 2d texture (x and y size)

				glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
				glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture




				glTexImage2D(GL_TEXTURE_2D, 0, 3, resultImg.cols, resultImg.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, resultImg.data);

				glBindTexture(GL_TEXTURE_2D, tex); // choose the texture to use.
				glBegin(GL_POLYGON);



				glTexCoord2f (0.0*zoom + 0.3333 + mmx*zoom, 0.1*zoom + 0.3333 + mmy*zoom);
				glVertex2f(-1+bw, 0.8-bw);
				glTexCoord2f (0.1*zoom + 0.3333 + mmx*zoom, 0.0*zoom + 0.3333 + mmy*zoom);
				glVertex2f(-0.8+bw, 1-bw);

				glTexCoord2f (1.0*zoom + 0.3333 + mmx*zoom, 0.0*zoom + 0.3333 + mmy*zoom);
				glVertex2f(1-bw, 1-bw);

				glTexCoord2f (1.0*zoom + 0.3333 + mmx*zoom, 0.9*zoom + 0.3333 + mmy*zoom);
				glVertex2f(1-bw, -0.8+bw);
				glTexCoord2f (0.9*zoom + 0.3333 + mmx*zoom, 1.0*zoom + 0.3333 + mmy*zoom);
				glVertex2f(0.8-bw, -1+bw);

				glTexCoord2f (0.0*zoom + 0.3333 + mmx*zoom, 1.0*zoom + 0.3333 + mmy*zoom);
				glVertex2f(-1+bw, -1+bw);


				glEnd();


				glDisable(GL_TEXTURE_2D);



			}
			glPopAttrib();


}

TileBuilder::~TileBuilder() {
	// TODO Auto-generated destructor stub
}




