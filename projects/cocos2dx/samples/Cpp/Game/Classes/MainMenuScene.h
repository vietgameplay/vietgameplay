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
//#include "../../testBasic.h"

class MainMenuScene : public cocos2d::CCScene
{
public:
    MainMenuScene();
    ~MainMenuScene();

    virtual void onEnter();
    virtual void onExit();

protected:
    // a selector callback
    void menuCloseCallback(cocos2d::CCObject* pSender, cocos2d::ui::TouchEventType type);

    void UIAnimationInit();
    void startUIAnimation(cocos2d::CCObject* pSender, cocos2d::ui::TouchEventType type);

protected:
    cocos2d::ui::TouchGroup* m_pUILayer;
};



#endif /*__MAIN_MENU_SCENE_H__*/
