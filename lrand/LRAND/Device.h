/*
 * DeviceAccess.h
 *
 *  Created on: Jan 23, 2017
 *      Author: erin
 */

#ifndef LRAND_LRAND_DEVICE_H_
#define LRAND_LRAND_DEVICE_H_

#define REQUEST_HEADER (void*)0xFF,(void*)0x00

class Device {
public:
					Device();
	virtual 		~Device();

	std::string		getPort(void);
	int				setPort(std::string);
	int				openPort();
	int				closePort();

	static std::string 			battery_state;
	static std::atomic<double> 	battery_life;
	static std::atomic<bool> 	is_charging;
	static std::atomic<bool> 	is_connected;
private:
	const void* greet[2] = {REQUEST_HEADER};
	char 			*portname;
	int				fd;
	int 			set_interface_attribs (int,int,int);
	void			set_blocking(int,int);
};

#endif /* LRAND_LRAND_DEVICE_H_ */
