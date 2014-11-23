#ifndef __READY_SCENE_H__
#define __READY_SCENE_H__

#include "cocos2d.h"

class ReadyScene : public cocos2d::LayerColor
{
public:
    
    static cocos2d::Scene* createScene();

    virtual void onEnter();  

    virtual void update( float dt );  

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	
    CREATE_FUNC(ReadyScene);
};

#endif // __HELLOWORLD_SCENE_H__
