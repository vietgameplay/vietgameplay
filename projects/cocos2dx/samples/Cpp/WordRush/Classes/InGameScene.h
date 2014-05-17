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
#include "Effect.h"

class InGameScene : public cocos2d::CCScene
{
public:
	InGameScene();
	~InGameScene();

    virtual void onEnter();
    virtual void onExit();
	virtual void update(float dt);

	VGP::Effect* effect;
protected:

	void initUI();
	void initGame();
	void checkEndGame();
	void rightPressed(cocos2d::CCObject* pSender, cocos2d::ui::TouchEventType type);
	void wrongPressed(cocos2d::CCObject* pSender, cocos2d::ui::TouchEventType type);
	void save(cocos2d::CCObject* pSender, cocos2d::ui::TouchEventType type);
	void setVisibleSavePanel(bool enable);
	void switchEndGame();
	void blinkDiamon();
	void updateProcessBar();
	void updateDiamonImg();
	void updateDiamonHave();
    cocos2d::ui::TouchGroup* m_pUILayer;
};



#endif /*__IN_GAME_SCENE_H__*/
