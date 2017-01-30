/*
 * LANAccess.h
 *
 *  Created on: Jan 25, 2017
 *      Author: erin
 */

#ifndef INCLUDE_LRAND_LANACCESS_H_
#define INCLUDE_LRAND_LANACCESS_H_

typedef struct fcurl_data URL_FILE;

class LANAccess {
public:
	LANAccess();
	virtual ~LANAccess();
	int loadFile();
	int	pullUpdates();
	int pushUpdates();
private:
	URL_FILE *handle;
	std::string 	loaded_doc;
	rapidxml::xml_document<> *doc;
};

#endif /* INCLUDE_LRAND_LANACCESS_H_ */
