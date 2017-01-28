/*
 * HeadsUpBatteryInfo.h
 *
 *  Created on: Jan 10, 2017
 *      Author: greg
 */

#ifndef HEADSUPBATTERYINFO_H_
#define HEADSUPBATTERYINFO_H_

class HeadsUpBatteryInfo
{
public:
						HeadsUpBatteryInfo();

	int 				render(void);
	void				draw(void);
private:
	ScalableVectorString comp_text;
	ScalableVectorString dev_text;
};



#endif /* HEADSUPBATTERYINFO_H_ */
