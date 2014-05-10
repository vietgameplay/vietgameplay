//
//  InGameScene.h
//  Game
//
//  Created by VietGamePlay on 5/1/14.
//
//

#ifndef __IN_GAME_SCENE_H__
#define __IN_GAME_SCENE_H__


#include "cocos2d.h"
#include "cocos-ext.h"
//#include "../../testBasic.h"

class InGameScene : public cocos2d::CCScene
{
public:
	InGameScene();
	~InGameScene();

    virtual void onEnter();
    virtual void onExit();
	virtual void update(float dt);


protected:

    void UIAnimationInit();
	void initGame();
	void rightPressed(cocos2d::CCObject* pSender, cocos2d::ui::TouchEventType type);
	void wrongPressed(cocos2d::CCObject* pSender, cocos2d::ui::TouchEventType type);

protected:
    cocos2d::ui::TouchGroup* m_pUILayer;
};



#endif /*__IN_GAME_SCENE_H__*/
