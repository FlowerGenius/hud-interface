/*
 * TileBuilder.cpp
 *
 *  Created on: Jan 16, 2017
 *      Author: erin
 */
 
#include "header.h"
#include "TileBuilder.h"
#include "png.h"

std::vector<std::string> tilesource;
GLuint tex;

extern std::pair<double,double> coords;
float bw = 0.03;
extern float long2tilex(double lon,int z);
extern float lat2tiley(double lat,int z);
extern double m_longitude;
extern double m_latitude;
std::pair<float,float> map_location;

float zoom = 0.3333;
float rotation;

cv::Mat m_image;
cv::Mat m1_image;

std::string datsource = "http://a.tile.openstreetmap.org";

cv::Mat resultImg;
cv::Mat al,bl,cl,dl,ar,br,cr,dr,top,mid,bottom,c0_image,c1_image,c2_image,c3_image,c4_image,c5_image,c6_image,c7_image,c8_image,c9_image,c10_image,c11_image,c12_image,c13_image,c14_image,c15_image;
std::vector<std::string> vstr;
float mmx,mmy;

size_t write_data(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    std::vector<uchar> *stream = (std::vector<uchar>*)userdata;
    size_t count = size * nmemb;
    stream->insert(stream->end(), ptr, ptr + count);
    return count;
}

//function to retrieve the image as cv::Mat data type
cv::Mat curlImg(const char *img_url, int timeout=10)
{
    std::vector<uchar> stream;
    CURL *curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, img_url); //the img url
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data); // pass the writefunction
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &stream); // pass the stream ptr to the writefunction
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout); // timeout if curl_easy hangs,
    CURLcode res = curl_easy_perform(curl); // start curl
    curl_easy_cleanup(curl); // cleanup
    return cv::imdecode(stream, -1); // 'keep-as-is'
}


TileBuilder::~TileBuilder() {
	// TODO Auto-generated destructor stub
}


TileBuilder::TileBuilder() {
	dsource = datsource;
		z = 17;
}
int tilex;
int tiley;
 std::vector<std::string> TileBuilder::getTileUrls(){

	 tilex = ((int)(floor(long2tilex(m_longitude,z))));
	 tiley = ((int)(floor(lat2tiley(m_latitude,z))));
	 map_location.first = (long2tilex(m_longitude,z)-tilex);
	 map_location.second = (lat2tiley(m_latitude,z)-tiley);


 	return {
//			dsource+"/"+std::to_string(z)+"/"+std::to_string( ((int)(floor(long2tilex(m_longitude,z)))-1)+"/"+yp1_str+".png",
 			dsource+"/"+std::to_string(z)+"/"+std::to_string(tilex-1)+"/"+std::to_string(tiley+1)+".png",
			dsource+"/"+std::to_string(z)+"/"+std::to_string(tilex)+"/"+std::to_string(tiley+1)+".png",
			dsource+"/"+std::to_string(z)+"/"+std::to_string(tilex+1)+"/"+std::to_string(tiley+1)+".png",

// 			dsource+"/"+std::to_string(z)+"/"+std::to_string( x-2)+"/"+y_str+".png",
			dsource+"/"+std::to_string(z)+"/"+std::to_string(tilex-1)+"/"+std::to_string(tiley)+".png",
			dsource+"/"+std::to_string(z)+"/"+std::to_string(tilex)+"/"+std::to_string(tiley)+".png",
			dsource+"/"+std::to_string(z)+"/"+std::to_string(tilex+1)+"/"+std::to_string(tiley)+".png",

// 			dsource+"/"+std::to_string(z)+"/"+std::to_string( x-2)+"/"+ym1_str+".png",
			dsource+"/"+std::to_string(z)+"/"+std::to_string(tilex-1)+"/"+std::to_string(tiley-1)+".png",
			dsource+"/"+std::to_string(z)+"/"+std::to_string(tilex)+"/"+std::to_string(tiley-1)+".png",
			dsource+"/"+std::to_string(z)+"/"+std::to_string(tilex+1)+"/"+std::to_string(tiley-1)+".png",

 	};
 }


std::string TileBuilder::getTileUrl(){
	return dsource+"/"+std::to_string(z)+"/"+std::to_string(long2tilex(m_longitude,z))+"/"+std::to_string((int)(floor(lat2tiley(m_latitude,z))))+".png";
}


void TileBuilder::draw(){
		dsource = datsource;
		z = 17;
		vstr = getTileUrls();
		mmx = ((map_location.first*2)-1)/2;
		mmy = ((map_location.second*2)-1)/2;

		if (vstr != tilesource){

			c0_image = curlImg(vstr[0].c_str());
			c1_image = curlImg(vstr[1].c_str());
			c2_image = curlImg(vstr[2].c_str());
			cv::hconcat(std::vector<cv::Mat>({c0_image,c1_image,c2_image}),top);

			c4_image = curlImg(vstr[3].c_str());
			c5_image = curlImg(vstr[4].c_str());
			c6_image = curlImg(vstr[5].c_str());
			cv::hconcat(std::vector<cv::Mat>({c4_image,c5_image,c6_image}),mid);

			c8_image = curlImg(vstr[6].c_str());
			c9_image = curlImg(vstr[7].c_str());
			c10_image = curlImg(vstr[8].c_str());
			cv::hconcat(std::vector<cv::Mat>({c8_image,c9_image,c10_image}),bottom);

			cv::vconcat(std::vector<cv::Mat>({bottom,mid,top}),resultImg);

			tilesource = vstr;
		}
		if (rotation < 360){
			rotation+=1;
		} else { rotation = 0;}
			glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			{

				glColor4f(0.3, 0.5, 0.8, 0.98);
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
			glPushMatrix();
			glRotatef(rotation, 0, 0, 1);
			glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			{
				glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
				glColor4f(0.0, 0.0, 1.0, 1.0);
				glVertex2f(0.0,0.0);
				glVertex2f(0.1,-0.1);
				glVertex2f(0.0,+0.1);
				glVertex2f(-0.1,-0.1);


				glEnd();
			}
			glPopAttrib();
			glPopMatrix();

}




