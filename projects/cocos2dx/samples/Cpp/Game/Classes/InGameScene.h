#ifndef __IN_GAME_SCENE_H__
#define __IN_GAME_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "Game.h"

class InGameScene : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    virtual void update(float dt);
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void registerWithTouchDispatcher();
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(InGameScene);
private:
    Game* game;
};

#endif // __IN_GAME_SCENE_H__
