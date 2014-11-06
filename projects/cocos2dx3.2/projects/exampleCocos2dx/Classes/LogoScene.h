#ifndef __LOGOSCENE_SCENE_H__
#define __LOGOSCENE_SCENE_H__

#include "cocos2d.h"

class LogoScene : public cocos2d::LayerColor
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual void onEnter();  

    virtual void update( float dt );  

    // implement the "static create()" method manually
    CREATE_FUNC(LogoScene);
};

#endif // __HELLOWORLD_SCENE_H__