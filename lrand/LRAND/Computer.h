/*
 * Computer.h
 *
 *  Created on: Mar 5, 2017
 *      Author: erin
 */

#ifndef LRAND_LRAND_COMPUTER_H_
#define LRAND_LRAND_COMPUTER_H_

class Computer {
public:
	Computer();
	virtual ~Computer();
	static std::atomic<double> 	battery_life;
	static std::atomic<bool> 	is_charging;
	static std::string 			battery_state;
};

#endif /* LRAND_LRAND_COMPUTER_H_ */
