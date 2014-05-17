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

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "VGPJNI.h"
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
extern void rateGame();
extern void showLeaderBoard();
#endif

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

	initUI();
}

void MainMenuScene::onExit()
{
	m_pUILayer->removeFromParent();

	SceneReader::sharedSceneReader()->purge();
	GUIReader::shareReader()->purge();
	cocos2d::extension::ActionManager::shareManager()->purge();

	CCScene::onExit();
}

void MainMenuScene::initUI()
{
	// ui animation root from json
	// load UI
	Layout* uianimation_root = dynamic_cast<Layout*>(GUIReader::shareReader()->widgetFromJsonFile("MainMenu.json"));
	m_pUILayer->addWidget(uianimation_root);

	// play button
	UIButton* btnPlay = static_cast<UIButton*>(m_pUILayer->getWidgetByName("btnPlay"));
	btnPlay->addTouchEventListener(this, toucheventselector(MainMenuScene::play));

	// close button
	UIButton* btnClose = static_cast<UIButton*>(m_pUILayer->getWidgetByName("btnClose"));
	btnClose->addTouchEventListener(this, toucheventselector(MainMenuScene::close));

    // rate button
	UIButton* btnRate = static_cast<UIButton*>(m_pUILayer->getWidgetByName("btnRate"));
	btnRate->addTouchEventListener(this, toucheventselector(MainMenuScene::rate));

    // leaderboard button
	UIButton* btnLeaderBoard = static_cast<UIButton*>(m_pUILayer->getWidgetByName("btnShowLeaderBoard"));
	btnLeaderBoard->addTouchEventListener(this, toucheventselector(MainMenuScene::show));

	//dialog panel
	UIPanel* pnlDialog = static_cast<UIPanel*>(m_pUILayer->getWidgetByName("pnlDialog"));
	pnlDialog->setVisible(false);
	pnlDialog->setTouchEnabled(false);

	// yes button
	UIButton* btnYes = static_cast<UIButton*>(m_pUILayer->getWidgetByName("btnYes"));
	btnYes->addTouchEventListener(this, toucheventselector(MainMenuScene::yes));
	btnYes->setTouchEnabled(false);

	// no button
	UIButton* btnNo = static_cast<UIButton*>(m_pUILayer->getWidgetByName("btnNo"));
	btnNo->addTouchEventListener(this, toucheventselector(MainMenuScene::no));
	btnNo->setTouchEnabled(false);

	//play animation
	cocos2d::extension::ActionManager::shareManager()->playActionByName("MainMenu.json", "Animation0");
}

void MainMenuScene::play(CCObject* pSender, TouchEventType type)
{
	if (type == TOUCH_EVENT_ENDED)
	{
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

		//dialog panel
		UIPanel* pnlDialog = static_cast<UIPanel*>(m_pUILayer->getWidgetByName("pnlDialog"));
		pnlDialog->setVisible(true);
		pnlDialog->setTouchEnabled(true);

		// yes button
		UIButton* btnYes = static_cast<UIButton*>(m_pUILayer->getWidgetByName("btnYes"));
		btnYes->addTouchEventListener(this, toucheventselector(MainMenuScene::yes));
		btnYes->setTouchEnabled(true);

		// no button
		UIButton* btnNo = static_cast<UIButton*>(m_pUILayer->getWidgetByName("btnNo"));
		btnNo->addTouchEventListener(this, toucheventselector(MainMenuScene::no));
		btnNo->setTouchEnabled(true);
	}
}

void MainMenuScene::no(CCObject* pSender, TouchEventType type)
{
	if (type == TOUCH_EVENT_ENDED)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("SFX_TAP.wav");
		//dialog panel
		UIPanel* pnlDialog = static_cast<UIPanel*>(m_pUILayer->getWidgetByName("pnlDialog"));
		pnlDialog->setVisible(false);
		pnlDialog->setTouchEnabled(false);
		// yes button
		UIButton* btnYes = static_cast<UIButton*>(m_pUILayer->getWidgetByName("btnYes"));
		btnYes->addTouchEventListener(this, toucheventselector(MainMenuScene::yes));
		btnYes->setTouchEnabled(false);

		// no button
		UIButton* btnNo = static_cast<UIButton*>(m_pUILayer->getWidgetByName("btnNo"));
		btnNo->addTouchEventListener(this, toucheventselector(MainMenuScene::no));
		btnNo->setTouchEnabled(false);
	}
}

void MainMenuScene::yes(CCObject* pSender, TouchEventType type)
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

void MainMenuScene::rate(CCObject* pSender, TouchEventType type)
{
	if (type == TOUCH_EVENT_ENDED)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("SFX_TAP.wav");
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		rateGame();
#endif
	}
}

void MainMenuScene::show(CCObject* pSender, TouchEventType type)
{
	if (type == TOUCH_EVENT_ENDED)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("SFX_TAP.wav");
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		showLeaderBoard();
#endif
	}
}