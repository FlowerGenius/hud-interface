/*
 * User.h
 *
 *  Created on: Mar 5, 2017
 *      Author: erin
 */

#ifndef LRAND_LRAND_USER_H_
#define LRAND_LRAND_USER_H_

class User {
public:
	User();
	virtual ~User();
	static std::atomic<double> 	m_latitude;
	static std::atomic<double> 	m_longitude;
	static std::atomic<double> 	m_altitude;

	static std::atomic<double>	m_direction;
	static std::atomic<double> 	m_yaw;
	static std::atomic<double> 	m_pitch;
	static std::atomic<double> 	m_roll;

	static gps::Point			coords;

};

#endif /* LRAND_LRAND_USER_H_ */
