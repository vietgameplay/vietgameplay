#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "cocos2d.h"
#include "CommonObject.h"

using namespace cocos2d;

class Character : public CommonObject
{
private:

public:
	Character();	
	~Character();
    virtual void init(CCLayer* layer);
	virtual void update();
    void switchState( int state);
};
#endif