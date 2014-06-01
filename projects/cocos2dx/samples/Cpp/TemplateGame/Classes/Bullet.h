#ifndef _BULLET_H_
#define _BULLETE_H

#include "CommonObject.h"

class Bullet : public CommonObject
{

public:
	Bullet();
	Bullet( cocos2d::CCLayer* layer, cocos2d::CCSprite* sprite, CCPoint end_pos );
	~Bullet();
	void update();

};
#endif