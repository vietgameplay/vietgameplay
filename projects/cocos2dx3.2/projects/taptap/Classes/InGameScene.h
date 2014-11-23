#ifndef __INGAME_SCENE_H__
#define __INGAME_SCENE_H__

#include "cocos2d.h"

class InGameScene : public cocos2d::LayerColor
{
private:
	cocos2d::Label *scoreString;

public:
    
    static cocos2d::Scene* createScene();

    virtual void onEnter();  

    virtual void update( float dt );  

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	
    CREATE_FUNC(InGameScene);
};

#endif // __HELLOWORLD_SCENE_H__
