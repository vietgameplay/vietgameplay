//
//  InGameScene.cpp
//  Game
//
//  Created by VietGamePlay on 5/1/14.
//
//

#include "InGameScene.h"
#include "EndGameScene.h"
#include "AppMacros.h"
#include "Game.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

extern int iFrameCount;
extern bool bGamePause;
extern char* GameDat[MAX_QUESTION][MAX_CHOICE];

InGameScene::InGameScene()
{
	CCScene::init();
}

InGameScene::~InGameScene()
{

}

void InGameScene::onEnter()
{
	CCScene::onEnter();

	m_pUILayer = TouchGroup::create();
	m_pUILayer->scheduleUpdate();
	addChild(m_pUILayer);
	Game::getInstance()->init();
	UIAnimationInit();

	this->schedule(schedule_selector(InGameScene::update));
}

void InGameScene::onExit()
{
	m_pUILayer->removeFromParent();

	SceneReader::sharedSceneReader()->purge();
	GUIReader::shareReader()->purge();
	cocos2d::extension::ActionManager::shareManager()->purge();
	CCScene::onExit();
}

void InGameScene::update(float dt)
{
	if (bGamePause)
	{
		return;
	}
	iFrameCount++;
	Game::getInstance()->iTimeLeft--;
	UILoadingBar* loadingBar = static_cast<UILoadingBar*>(m_pUILayer->getWidgetByName("LoadingBar"));
	loadingBar->setPercent(Game::getInstance()->iTimeLeft);
	//If time left < 0 ->game over
	if (Game::getInstance()->iTimeLeft < 0)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("SFX_DEAD.wav");
		EndGameScene* pEndGameScene = new EndGameScene();
		CCDirector::sharedDirector()->replaceScene(pEndGameScene);
	}
}


void InGameScene::UIAnimationInit()
{
	// ui animation root from json
	Layout* uianimation_root = dynamic_cast<Layout*>(GUIReader::shareReader()->widgetFromJsonFile("InGame_1.json"));
	m_pUILayer->addWidget(uianimation_root);

	// button right pressed
	UIButton* btnRight = static_cast<UIButton*>(m_pUILayer->getWidgetByName("btnRight"));
	btnRight->addTouchEventListener(this, toucheventselector(InGameScene::rightPressed));

	// button wrong pressed 
	UIButton* btnWrong = static_cast<UIButton*>(m_pUILayer->getWidgetByName("btnWrong"));
	btnWrong->addTouchEventListener(this, toucheventselector(InGameScene::wrongPressed));
	initGame();
};

void InGameScene::initGame()
{
	// lable score 
	UILabelBMFont* lblScore = static_cast<UILabelBMFont*>(m_pUILayer->getWidgetByName("lblScore"));
	lblScore->setText(ccsf("%d pts", Game::getInstance()->iScore));

	// lable word 
	UITextField* lblWord = static_cast<UITextField*>(m_pUILayer->getWidgetByName("txtWord"));
	lblWord->setText(GameDat[Game::getInstance()->iQuestion][Game::getInstance()->iChoice]);

	char* strImg = new char[20];
    memset(strImg, 0, 20);
	strcat(strImg, "dat_");
	strcat(strImg, GameDat[Game::getInstance()->iQuestion][0]);
	strcat(strImg, ".png");
	//image view
	UIImageView* image = static_cast<UIImageView*>(m_pUILayer->getWidgetByName("imgMain"));
	image->loadTexture(strImg);

	delete[]strImg;
};

void InGameScene::rightPressed(CCObject* pSender, TouchEventType type)
{
	if (type == TOUCH_EVENT_ENDED)
	{
		if (Game::getInstance()->iChoice == 0 && Game::getInstance()->iTimeLeft > 0)
		{
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("SFX_FLAP.wav");
			Game::getInstance()->next();
			initGame();
		}
		else
		{
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("SFX_DEAD.wav");
			Game::getInstance()->checkBest();
			EndGameScene* pEndGameScene = new EndGameScene();
			CCDirector::sharedDirector()->replaceScene(pEndGameScene);
		}
	}
}

void InGameScene::wrongPressed(CCObject* pSender, TouchEventType type)
{
	if (type == TOUCH_EVENT_ENDED)
	{
		if (Game::getInstance()->iChoice != 0 && Game::getInstance()->iTimeLeft > 0)
		{
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("SFX_FLAP.wav");
			Game::getInstance()->next();
			initGame();
		}
		else
		{
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("SFX_DEAD.wav");
			Game::getInstance()->checkBest();
			EndGameScene* pEndGameScene = new EndGameScene();
			CCDirector::sharedDirector()->replaceScene(pEndGameScene);
		}
	}
}