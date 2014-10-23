#ifndef _BUBBLE_H_
#define _BUBBLE_H

#include "CommonObject.h"

class Bubble : public CommonObject
{

public:
	int deadTime;
	Bubble();
	Bubble( cocos2d::CCLayer* layer, cocos2d::CCSprite* sprite, int deadTime );
	~Bubble();
	void update();

};
#endif