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
	void				draw(int ax,int ay);
private:
	ScalableVectorString comp_text;
	ScalableVectorString dev_text;
};



#endif /* HEADSUPBATTERYINFO_H_ */
