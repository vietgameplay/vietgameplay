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

	UIAnimationInit();
}

void EndGameScene::onExit()
{
	m_pUILayer->removeFromParent();

	SceneReader::sharedSceneReader()->purge();
	GUIReader::shareReader()->purge();
	cocos2d::extension::ActionManager::shareManager()->purge();

	CCScene::onExit();
}

void EndGameScene::UIAnimationInit()
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
		CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		exit(0);
#endif
	}
}