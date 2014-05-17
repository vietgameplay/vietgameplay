//
//  MainMenuScene.h
//  Game
//
//  Created by VietGamePlay on 5/1/14.
//
//

#ifndef __MAIN_MENU_SCENE_H__
#define __MAIN_MENU_SCENE_H__


#include "cocos2d.h"
#include "cocos-ext.h"

class MainMenuScene : public cocos2d::CCScene
{
public:
    MainMenuScene();
    ~MainMenuScene();

    virtual void onEnter();
    virtual void onExit();

protected:
	void initUI();
    void play(cocos2d::CCObject* pSender, cocos2d::ui::TouchEventType type);
	void close(cocos2d::CCObject* pSender, cocos2d::ui::TouchEventType type);
	void no(cocos2d::CCObject* pSender, cocos2d::ui::TouchEventType type);
	void yes(cocos2d::CCObject* pSender, cocos2d::ui::TouchEventType type);
    void rate(cocos2d::CCObject* pSender, cocos2d::ui::TouchEventType type);
    void show(cocos2d::CCObject* pSender, cocos2d::ui::TouchEventType type);
    cocos2d::ui::TouchGroup* m_pUILayer;
};



#endif /*__MAIN_MENU_SCENE_H__*/
