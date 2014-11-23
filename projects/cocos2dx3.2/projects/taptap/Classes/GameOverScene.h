#ifndef __GAMEOVER_SCENE_H__
#define __GAMEOVER_SCENE_H__

#include "cocos2d.h"

class GameOverScene : public cocos2d::LayerColor
{
public:
    
    static cocos2d::Scene* createScene();

    virtual void onEnter();  

    virtual void update( float dt );  

	void buttonCallBack( cocos2d::Ref* pSender );	

    CREATE_FUNC(GameOverScene);
};

#endif // __HELLOWORLD_SCENE_H__
