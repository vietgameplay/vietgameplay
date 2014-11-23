#ifndef __LANGUAGE_SCENE_H__
#define __LANGUAGE_SCENE_H__

#include "cocos2d.h"

class LanguageScene : public cocos2d::LayerColor
{
public:
    
    static cocos2d::Scene* createScene();

    virtual void onEnter();  

    virtual void update( float dt );  

	void chooseLanguageCallBack( cocos2d::Ref* pSender );	
   
    CREATE_FUNC(LanguageScene);
};

#endif // __HELLOWORLD_SCENE_H__
