#ifndef _VGPPROGRESS_TIMER_H_
#define _VGPPROGRESS_TIMER_H_

#include "cocos2d.h"

USING_NS_CC;

class VGPProgressTimer
{
protected:
	static VGPProgressTimer* instance;

public:
	static VGPProgressTimer* getInstance();	

	//left_right_or_up_down = true: left - > right  or right - > left
	//left_right_or_up_down = false: up - > down  or down - > up
	CCProgressTimer *createProgressTimer( CCSprite *spriteFrame, bool left_right_or_up_down, bool direction, int initPercent, CCPoint position, int zOrder, int tag );

	CCProgressTimer *createProgressTimer( CCSprite *spriteFrame, bool left_right_or_up_down, bool direction, int initPercent, CCPoint position, int zOrder );

	CCProgressTimer *createProgressTimer( CCSprite *spriteFrame, bool left_right_or_up_down, bool direction, int initPercent, CCPoint position );


	
};

#endif