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
std::string data;

extern cv::Mat BindCVMat2GLTexture(cv::Mat& image, GLuint& imageTexture);
extern int long2tilex(double lon,int z);
extern int lat2tiley(double lat,int z);
cv::Mat m_image;
std::string datsource = "http://a.tile.openstreetmap.org";

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


TileBuilder::~TileBuilder() {
	// TODO Auto-generated destructor stub
}



std::pair<double,double> TileBuilder::getCoords(int timeout=10)
{
    std::vector<uchar> stream;
    CURL *curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "http://whatismycountry.com/1"); //the img url
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &writeCallback);
	curl_easy_setopt(curl, CURLOPT_VERBOSE, 0); //tell curl to output its progress

	curl_easy_perform(curl);
	leftbound 	= "<p>Coordinates ";
	coordsep 	= " ";
	rightbound	= "</p>";

	sub1		= data.substr(data.find(leftbound)+leftbound.size());
	coordstring	= sub1.substr(0,sub1.find(rightbound));

	pos 		= coordstring.find(coordsep);

	latstring=coordstring.substr(0,pos);
	longstring=coordstring.substr(pos+1);

	curl_easy_cleanup(curl);
	curl_global_cleanup();

	return {std::atof(latstring.c_str()),std::atof(longstring.c_str())};


}



int interval=0;
void doGetCoords(TileBuilder t){	
	
	while(1){
		if (interval % 10 == 0){
			t.setCoords();
		}
		interval++;
	}
}

TileBuilder::TileBuilder() {
	dsource = datsource;
	z = 18;
	coords = getCoords();

}

// std::vector<std::string> TileBuilder::getTileUrls(){
// 	std::string str = dsource;
// 
// 	int x = long2tilex(coords.second,z);
// 	int y = lat2tiley(coords.first,z);
// 
// 	std::string z_str =std::to_string(z);
// 	std::string x_str = std::to_string(x);
// 	std::string xp1_str = std::to_string(x+1);
// 	std::string xm1_str = std::to_string(x-1);
// 
// 
// 
// 	std::string y_str  = std::to_string(y);
// 	std::string yp1_str  = std::to_string(y+1);
// 	std::string ym1_str  = std::to_string(y-1);
// 
// 
// 	std::vector<std::string> urls = {
// 			str+"/"+z_str+"/"+xm1_str+"/"+yp1_str+".png",
// 			str+"/"+z_str+"/"+x_str+"/"+yp1_str+".png",
// 			str+"/"+z_str+"/"+xp1_str+"/"+yp1_str+".png",
// 			str+"/"+z_str+"/"+xm1_str+"/"+y_str+".png",
// 			str+"/"+z_str+"/"+x_str+"/"+y_str+".png",
// 			str+"/"+z_str+"/"+xp1_str+"/"+y_str+".png",
// 			str+"/"+z_str+"/"+xm1_str+"/"+ym1_str+".png",
// 			str+"/"+z_str+"/"+x_str+"/"+ym1_str+".png",
// 			str+"/"+z_str+"/"+xp1_str+"/"+ym1_str+".png",
// 			};
// 
// 	return urls;
// }

std::string TileBuilder::getTileUrl(){

	std::string url = dsource+"/"+std::to_string(z)+"/"+std::to_string(long2tilex(coords.second,z))+"/"+std::to_string(lat2tiley(coords.first,z))+".png";
	return url;
}

void TileBuilder::setCoords(){
	coords = getCoords();
}


void TileBuilder::draw(){
		
		//std::vector<std::string> str = getTileUrls();
		setCoords();
		std::string str = getTileUrl();

			glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			{
				glColor4f(0.5, 0.5, 0.5, 0.9);

				glEnable(GL_TEXTURE_2D);
				// Create Texture
				glGenTextures(1, &tex);
				glBindTexture(GL_TEXTURE_2D, tex); // 2d texture (x and y size)

				glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
				glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smalled than texture

				if (str != tilesource){
					m_image =  curlImg(str.c_str());
					tilesource = str;
				}
				glTexImage2D(GL_TEXTURE_2D, 0, 3, m_image.cols, m_image.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, m_image.data);

				glBindTexture(GL_TEXTURE_2D, tex); // choose the texture to use.
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




