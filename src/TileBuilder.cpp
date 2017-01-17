/*
 * TileBuilder.cpp
 *
 *  Created on: Jan 16, 2017
 *      Author: erin
 */
#include "header.h"
#include "TileBuilder.h"
#include "png.h"


std::string tilesource = "";
GLuint tex;
cv::Mat m_image;
std::string data;

extern cv::Mat BindCVMat2GLTexture(cv::Mat& image, GLuint& imageTexture);
extern int long2tilex(double lon,int z);
extern int lat2tiley(double lat,int z);
//extern double tilex2long(int x, int z);
//extern double tiley2lat(int y, int z);


TileBuilder::TileBuilder(std::string datasource, int zoom) {
	dsource = datasource;
	z = zoom;
}

TileBuilder::~TileBuilder() {
	// TODO Auto-generated destructor stub
}

size_t write_data(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    std::vector<uchar> *stream = (std::vector<uchar>*)userdata;
    size_t count = size * nmemb;
    stream->insert(stream->end(), ptr, ptr + count);
    return count;
}

size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up)
{ //callback must have this declaration
    //buf is a pointer to the data that curl has for us
    //size*nmemb is the size of the buffer

    for (int c = 0; c<size*nmemb; c++)
    {
        data.push_back(buf[c]);
    }
    return size*nmemb; //tell curl how many bytes we handled
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


std::pair<double,double> TileBuilder::getCoords(int timeout)
{
    std::vector<uchar> stream;
    CURL *curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "http://whatismycountry.com/1"); //the img url
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &writeCallback);
	curl_easy_setopt(curl, CURLOPT_VERBOSE, 0); //tell curl to output its progress

	curl_easy_perform(curl);

	std::string leftbound 	= "<p>Coordinates ";
	std::string coordsep 	= " ";
	std::string rightbound	= "</p>";
	std::string sub1,coordstring,longstring,latstring;

	size_t pos=0;

	sub1		= data.substr(data.find(leftbound)+leftbound.size());
	coordstring	= sub1.substr(0,sub1.find(rightbound));

	pos 		= coordstring.find(coordsep);

	latstring=coordstring.substr(0,pos);
	longstring=coordstring.substr(pos+1);

	curl_easy_cleanup(curl);
	curl_global_cleanup();

	std::pair<double,double> tup = {std::atof(latstring.c_str()),std::atof(longstring.c_str())};
	return tup;
}

std::list<std::string> TileBuilder::getTileUrls(){
	std::pair<double,double> coords = getCoords();
	std::string str = dsource;

	int x = long2tilex(coords.second,z);
	int y = lat2tiley(coords.first,z);

	std::string z_str =std::to_string(z);
	std::string x_str = std::to_string(x);
	std::string xp1_str = std::to_string(x+1);
	std::string xm1_str = std::to_string(x-1);



	std::string y_str  = std::to_string(y);
	std::string yp1_str  = std::to_string(y+1);
	std::string ym1_str  = std::to_string(y-1);


	std::list<std::string> urls = {
			str+"/"+z_str+"/"+xm1_str+"/"+yp1_str+".png",
			str+"/"+z_str+"/"+x_str+"/"+yp1_str+".png",
			str+"/"+z_str+"/"+xp1_str+"/"+yp1_str+".png",
			str+"/"+z_str+"/"+xm1_str+"/"+y_str+".png",
			str+"/"+z_str+"/"+x_str+"/"+y_str+".png",
			str+"/"+z_str+"/"+xp1_str+"/"+y_str+".png",
			str+"/"+z_str+"/"+xm1_str+"/"+ym1_str+".png",
			str+"/"+z_str+"/"+x_str+"/"+ym1_str+".png",
			str+"/"+z_str+"/"+xp1_str+"/"+ym1_str+".png",
			};

	return urls;
}

void TileBuilder::draw(){
		int hh = MAP_HEIGHT;
		int ww = MAP_HEIGHT*1.3;
		
		std::list<std::string> str = getTileUrls();

		glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		{
			glEnable(GL_TEXTURE_2D);
		
			glBindTexture (GL_TEXTURE_2D, tex);
			glColor4f(0.0, 0.6, 1.0, 0.9);
			if (str.front() != tilesource || tilesource == ""){
					m_image = curlImg(str.front().c_str());
					BindCVMat2GLTexture(m_image,tex);
					tilesource = str.front();
				}
	
			glBegin(GL_QUADS);
			glTexCoord2f (0.0, 0.0);
			glVertex3f (-1.0,1.0, 0.1);
			glTexCoord2f (1.0, 0.0);
			glVertex3f (1.0, 1.0, 0.1);
			glTexCoord2f (1.0, 1.0);
			glVertex3f (1.0, -1.0, 0.1);
			glTexCoord2f (0.0, 1.0);
			glVertex3f (-1.0, -1.0, 0.1);
	
			glEnd();
			glDisable(GL_TEXTURE_2D);

		}
		glPopAttrib();
}




