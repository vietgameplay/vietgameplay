//
//  EndGameScene.cpp
//  Game
//
//  Created by VietGamePlay on 5/1/14.
//
//

#include "EndGameScene.h"
#include "InGameScene.h"
#include "AppMacros.h"
#include "Game.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "VGPJNI.h"
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
extern void rateGame();
extern void showLeaderBoard();
extern void saveLeaderBoard();
extern void showAdmob();
#endif

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

EndGameScene::EndGameScene()
{
	CCScene::init();
}

EndGameScene::~EndGameScene()
{

}

void EndGameScene::onEnter()
{
	CCScene::onEnter();

	m_pUILayer = TouchGroup::create();
	m_pUILayer->scheduleUpdate();
	addChild(m_pUILayer);

	initUI();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    showAdmob();
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    if(Game::getInstance()->iScore > Game::getInstance()->iBest)
    {
        saveLeaderBoard();
    }
#endif
}

void EndGameScene::onExit()
{
	m_pUILayer->removeFromParent();

	SceneReader::sharedSceneReader()->purge();
	GUIReader::shareReader()->purge();
	cocos2d::extension::ActionManager::shareManager()->purge();

	CCScene::onExit();
}

void EndGameScene::initUI()
{
	// ui animation root from json
	Layout* uianimation_root = dynamic_cast<Layout*>(GUIReader::shareReader()->widgetFromJsonFile("EndGame_1.json"));
	m_pUILayer->addWidget(uianimation_root);

	// replay button
	UIButton* btnRePlay = static_cast<UIButton*>(m_pUILayer->getWidgetByName("btnRePlay"));
	btnRePlay->addTouchEventListener(this, toucheventselector(EndGameScene::rePlay));

	// close button
	UIButton* btnClose = static_cast<UIButton*>(m_pUILayer->getWidgetByName("btnClose"));
	btnClose->addTouchEventListener(this, toucheventselector(EndGameScene::close));

	// lable score 
	UILabelBMFont* lbliScore = static_cast<UILabelBMFont*>(m_pUILayer->getWidgetByName("lbliScore"));
	lbliScore->setText(ccsf("%d pts", Game::getInstance()->iScore));

	// lable score 
	UILabelBMFont* lbliBest = static_cast<UILabelBMFont*>(m_pUILayer->getWidgetByName("lbliBest"));
	lbliBest->setText(ccsf("%d pts", Game::getInstance()->iBest));

	//dialog panel
	UIPanel* pnlDialog = static_cast<UIPanel*>(m_pUILayer->getWidgetByName("pnlDialog"));
	pnlDialog->setVisible(false);
	pnlDialog->setTouchEnabled(false);

	// yes button
	UIButton* btnYes = static_cast<UIButton*>(m_pUILayer->getWidgetByName("btnYes"));
	btnYes->addTouchEventListener(this, toucheventselector(EndGameScene::yes));

	// no button
	UIButton* btnNo = static_cast<UIButton*>(m_pUILayer->getWidgetByName("btnNo"));
	btnNo->addTouchEventListener(this, toucheventselector(EndGameScene::no));

    // rate button
	UIButton* btnRate = static_cast<UIButton*>(m_pUILayer->getWidgetByName("btnRate"));
	btnRate->addTouchEventListener(this, toucheventselector(EndGameScene::rate));

    // leaderboard button
	UIButton* btnLeaderBoard = static_cast<UIButton*>(m_pUILayer->getWidgetByName("btnShowLeaderBoard"));
	btnLeaderBoard->addTouchEventListener(this, toucheventselector(EndGameScene::show));

}

void EndGameScene::rePlay(CCObject* pSender, TouchEventType type)
{
	if (type == TOUCH_EVENT_ENDED)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("SFX_TAP.wav");
		InGameScene* pInGameScene = new InGameScene();
		CCDirector::sharedDirector()->replaceScene(pInGameScene);
	}
}

void EndGameScene::close(CCObject* pSender, TouchEventType type)
{
	if (type == TOUCH_EVENT_ENDED)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("SFX_TAP.wav");
		//dialog panel
		UIPanel* pnlDialog = static_cast<UIPanel*>(m_pUILayer->getWidgetByName("pnlDialog"));
		pnlDialog->setVisible(true);
		pnlDialog->setTouchEnabled(true);
	}
}

void EndGameScene::no(CCObject* pSender, TouchEventType type)
{
	if (type == TOUCH_EVENT_ENDED)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("SFX_TAP.wav");
		//dialog panel
		UIPanel* pnlDialog = static_cast<UIPanel*>(m_pUILayer->getWidgetByName("pnlDialog"));
		pnlDialog->setVisible(false);
		pnlDialog->setTouchEnabled(false);
	}
}

void EndGameScene::yes(CCObject* pSender, TouchEventType type)
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

void EndGameScene::rate(CCObject* pSender, TouchEventType type)
{
	if (type == TOUCH_EVENT_ENDED)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("SFX_TAP.wav");
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		rateGame();
#endif
	}
}

void EndGameScene::show(CCObject* pSender, TouchEventType type)
{
	if (type == TOUCH_EVENT_ENDED)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("SFX_TAP.wav");
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		showLeaderBoard();
#endif
	}
}