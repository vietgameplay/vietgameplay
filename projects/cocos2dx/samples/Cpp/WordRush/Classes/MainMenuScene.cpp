//
//  MainMenuScene.cpp
//  Game
//
//  Created by VietGamePlay on 5/1/14.
//
//

#include "MainMenuScene.h"
#include "InGameScene.h"
#include "AppMacros.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

MainMenuScene::MainMenuScene()
{
    CCScene::init();
}

MainMenuScene::~MainMenuScene()
{

}

void MainMenuScene::onEnter()
{
    CCScene::onEnter();

    m_pUILayer = TouchGroup::create();
    m_pUILayer->scheduleUpdate();
    addChild(m_pUILayer);

    UIAnimationInit();
}

void MainMenuScene::onExit()
{
    m_pUILayer->removeFromParent();

    SceneReader::sharedSceneReader()->purge();
    GUIReader::shareReader()->purge();
	cocos2d::extension::ActionManager::shareManager()->purge();

    CCScene::onExit();
}

void MainMenuScene::UIAnimationInit()
{
    // ui animation root from json
    Layout* uianimation_root = dynamic_cast<Layout*>(GUIReader::shareReader()->widgetFromJsonFile("MainMenu.json"));
    m_pUILayer->addWidget(uianimation_root);

    // play button
    UIButton* btnPlay = static_cast<UIButton*>(m_pUILayer->getWidgetByName("btnPlay"));
	btnPlay->addTouchEventListener(this, toucheventselector(MainMenuScene::play));

	// close button
	UIButton* btnClose = static_cast<UIButton*>(m_pUILayer->getWidgetByName("btnClose"));
	btnClose->addTouchEventListener(this, toucheventselector(MainMenuScene::close));
}

void MainMenuScene::play(CCObject* pSender, TouchEventType type)
{
    if (type == TOUCH_EVENT_ENDED)
    {
		//cocos2d::extension::ActionManager::shareManager()->playActionByName("SampleUIAnimation.json", "Animation1");
        //CCDirector::sharedDirector()->replaceScene(InGameScene::scene());
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("SFX_TAP.wav");
		InGameScene* pInGameScene = new InGameScene();
		CCDirector::sharedDirector()->replaceScene(pInGameScene);
    }
};

void MainMenuScene::close(CCObject* pSender, TouchEventType type)
{
	if (type == TOUCH_EVENT_ENDED)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("SFX_TAP.wav");
		CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		exit(0);
#endif
	}
}