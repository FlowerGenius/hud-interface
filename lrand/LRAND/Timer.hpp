/*
 * Timer.hpp
 *
 *  Created on: Jan 13, 2017
 *      Author: erin
 */

#ifndef LRAND_LRAND_TIMER_HPP_
#define LRAND_LRAND_TIMER_HPP_

class Timer
{
public:
	enum UNITS
	{
		USEC = 0,
		MSEC,
		SEC
	};

	Timer() : m_t0(0), m_diff(0)
	{
		m_tick_frequency = (float)cv::getTickFrequency();

		m_unit_mul[USEC] = 1000000;
		m_unit_mul[MSEC] = 1000;
		m_unit_mul[SEC]  = 1;
	}

	void clear()
	{
		m_t0 = m_diff = 0;
	}

	void start()
	{
		m_t0 = cv::getTickCount();
	}

	void stop()
	{
		m_diff = cv::getTickCount() - m_t0;
	}

	float time(UNITS u = MSEC)
	{
		float sec = m_diff / m_tick_frequency;

		return sec * m_unit_mul[u];
	}

public:
	float m_tick_frequency;
	int64 m_t0;
	int64 m_diff;
	int   m_unit_mul[3];
};



#endif /* LRAND_LRAND_TIMER_HPP_ */
