/*
 * DeviceAccess.h
 *
 *  Created on: Jan 23, 2017
 *      Author: erin
 */

#ifndef INCLUDE_LRAND_DEVICEACCESS_H_
#define INCLUDE_LRAND_DEVICEACCESS_H_

#define REQUEST_HEADER (void*)0xFF,(void*)0x00

class DeviceAccess {
public:
					DeviceAccess();
	virtual 		~DeviceAccess();

	std::string		getPort(void);
	int				setPort(std::string);
	int				openPort();
	int				closePort();
private:
	const void* greet[2] = {REQUEST_HEADER};
	char 			*portname;
	int				fd;
	int 			set_interface_attribs (int,int,int);
	void			set_blocking(int,int);
};

#endif /* INCLUDE_LRAND_DEVICEACCESS_H_ */
