/*
 * Tile.cpp
 *
 *  Created on: Jan 21, 2017
 *      Author: erin
 */

#include <lrand/lrand.h>

//cv::Mat data;
//std::string datasource;
//const int timeout = 10;
//
//size_t write_data(char *ptr, size_t size, size_t nmemb, void *userdata)
//{
//    std::vector<uchar> *stream = (std::vector<uchar>*)userdata;
//    size_t count = size * nmemb;
//    stream->insert(stream->end(), ptr, ptr + count);
//    return count;
//}
//
//void curlImg (int x,int y,int z){
//	std::vector<uchar> stream;
//	CURL *curl = curl_easy_init();
//	curl_easy_setopt(curl, CURLOPT_URL, datasource+"/"+std::to_string(z)+"/"+std::to_string(x)+"/"+std::to_string(y)+".png"); //the img url
//	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data); // pass the writefunction
//	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &stream); // pass the stream ptr to the writefunction
//	curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout); // timeout if curl_easy hangs,
//	curl_easy_perform(curl); // start curl
//	curl_easy_cleanup(curl); // cleanup
//	data = cv::imdecode(stream, -1); // 'keep-as-is'
//}

Tile::Tile() {
//	_data = cv::imread("/home/erin/workspace/HUD2/lrand/loadtile.png");
}

void Tile::fetch(int x,int y,int z){
//	std::thread _md(curlImg,x,y,z);
//	if (_md.joinable())
//		_md.join();
//	else
//		_data = cv::imread("/home/erin/workspace/HUD2/lrand/loadtile.png");
}

Tile::Tile(int tilex,int tiley,int zoom){
//	fetch(tilex,tiley,zoom);
}

Tile::~Tile() {
	// TODO Auto-generated destructor stub
}
