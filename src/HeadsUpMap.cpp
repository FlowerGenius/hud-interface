/*
 * HeadsUpMap.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */

#include "header.h"
#include "TileBuilder.h"
#include "HeadsUpWaypoint.h"
#include "HeadsUpMap.h"

#define LONGITUDE	-79.397019
#define LATITUDE	43.662603

extern std::atomic<double> m_latitude;
extern std::atomic<double> m_longitude;
extern std::pair<double,double> coords;
std::atomic<double> counter;
extern std::atomic<bool> EXIT_THREADS;

HeadsUpWaypoint wayp = HeadsUpWaypoint();


int interval=0;
std::string data;
std::string leftbound;
std::string coordsep;
std::string rightbound;
std::string sub1,coordstring,longstring,latstring;
size_t pos=0;

std::atomic<bool> coordschanged (true);

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

std::pair<double,double> getCoords(int timeout=10)
{
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

	m_latitude  = std::atof(coordstring.substr(0,pos).c_str());
	m_longitude = std::atof(coordstring.substr(pos+1).c_str());


	curl_easy_cleanup(curl);
	curl_global_cleanup();
	counter = counter + 1.0;

	return {m_latitude,m_longitude};
}

void computerGetGeoLocation(){
	while(!EXIT_THREADS){
		getCoords();
	}
	puts("Geolocation Thread Exited Successfully");
}

void computerGetDirection(){
	while(!EXIT_THREADS){
		getCoords();
	}
	puts("Direction Thread Exited Successfully");
}

HeadsUpMap::HeadsUpMap(){
	getCoords();
//		wayp.setText("WAY1");
//		double f=m_latitude-0.001,s=m_longitude+0.001;
//		wayp.set(std::pair<double,double>({f,s}));

}

	void HeadsUpMap::draw(){
		glViewport(width-RIGHT_MARGIN-MAP_WIDTH, height-MAP_HEIGHT-TOP_MARGIN,  MAP_WIDTH, MAP_HEIGHT);

		glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		{
			glBegin(GL_POLYGON);   //We want to draw a map, i.e. shape with four bevel sides
			glColor4f(0.0, 0.6, 0.6, 0.9);
			glVertex2f(-1, 0.8);
			glVertex2f(-0.8, 1);
			glVertex2f(1, 1);
			glVertex2f(1, -0.8);
			glVertex2f(0.8, -1);
			glVertex2f(-1, -1);
			glEnd();
		}
		glPopAttrib();
		glViewport(width-RIGHT_MARGIN-MAP_WIDTH+2, height-MAP_HEIGHT-TOP_MARGIN+2,  MAP_WIDTH-4, MAP_HEIGHT-4);

		tiles.draw();
		//wayp.draw();



	}



