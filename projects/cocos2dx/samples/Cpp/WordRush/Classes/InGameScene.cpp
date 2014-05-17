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

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "VGPJNI.h"
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
extern void hideAdmob();
#endif

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

extern int iFrameCount;
extern bool bGamePause;
extern char* GameDat[MAX_QUESTION][MAX_CHOICE];

InGameScene::InGameScene()
{
	CCScene::init();
	this->effect = new VGP::Effect();
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
	initUI();
	this->effect->init(this->m_pUILayer, EFFECT_FLOWER);

	this->schedule(schedule_selector(InGameScene::update));
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    hideAdmob();
#endif
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
	Game::getInstance()->update();
	updateProcessBar();

	//If time left < 0 ->game over
	if (Game::getInstance()->iTimeLeft < 0)
	{
		checkEndGame();
	}

	blinkDiamon();
	updateDiamonImg();
	updateDiamonHave();
}


void InGameScene::initUI()
{
	// ui animation root from json
	Layout* uianimation_root = dynamic_cast<Layout*>(GUIReader::shareReader()->widgetFromJsonFile("InGame_1.json"));
	m_pUILayer->addWidget(uianimation_root);

	// button right pressed
	UIButton* btnRight = static_cast<UIButton*>(m_pUILayer->getWidgetByName("btnRight"));
	btnRight->addTouchEventListener(this, toucheventselector(InGameScene::rightPressed));
	//btnRight->loadTextureNormal("diamon.png", UI_TEX_TYPE_LOCAL);

	// button wrong pressed 
	UIButton* btnWrong = static_cast<UIButton*>(m_pUILayer->getWidgetByName("btnWrong"));
	btnWrong->addTouchEventListener(this, toucheventselector(InGameScene::wrongPressed));
	initGame();

	// button diamon pressed 
	UIButton* btnDiamon = static_cast<UIButton*>(m_pUILayer->getWidgetByName("btnDiamon"));
	btnDiamon->addTouchEventListener(this, toucheventselector(InGameScene::save));
	btnDiamon->setTouchEnabled(false);

	//image diamon
	UIImageView* imgDiamon1 = static_cast<UIImageView*>(m_pUILayer->getWidgetByName("imgDiamon1"));
	UIImageView* imgDiamon2 = static_cast<UIImageView*>(m_pUILayer->getWidgetByName("imgDiamon2"));
	UIImageView* imgDiamon3 = static_cast<UIImageView*>(m_pUILayer->getWidgetByName("imgDiamon3"));
	imgDiamon1->setVisible(false);
	imgDiamon2->setVisible(false);
	imgDiamon3->setVisible(false);

	//save dialog panel
	UIPanel* pnlSave = static_cast<UIPanel*>(m_pUILayer->getWidgetByName("pnlSave"));
	pnlSave->setVisible(false);
	pnlSave->setTouchEnabled(false);
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
		if (Game::getInstance()->iChoice % 2 == 0 && Game::getInstance()->iTimeLeft > 0)
		{
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("SFX_FLAP.wav");
			Game::getInstance()->next();
			initGame();
		}
		else
		{
			checkEndGame();
		}
	}
}

void InGameScene::wrongPressed(CCObject* pSender, TouchEventType type)
{
	if (type == TOUCH_EVENT_ENDED)
	{
		if (Game::getInstance()->iChoice % 2 != 0 && Game::getInstance()->iTimeLeft > 0)
		{
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("SFX_FLAP.wav");
			Game::getInstance()->next();
			initGame();
		}
		else
		{
			checkEndGame();
		}
	}
}

void InGameScene::checkEndGame()
{
	if (Game::getInstance()->iHeart > 0)
	{
		setVisibleSavePanel(true);
		if (Game::getInstance()->iTimeSave > 0)
		{
			Game::getInstance()->iTimeSave--;
		}
		else
		{
			switchEndGame();
		}
	}
	else
	{
		switchEndGame();
	}

}

void InGameScene::save(cocos2d::CCObject* pSender, cocos2d::ui::TouchEventType type)
{
	if (type == TOUCH_EVENT_ENDED)
	{
		if (Game::getInstance()->iTimeSave > 0)
		{
			setVisibleSavePanel(false);
			Game::getInstance()->iHeart--;
			//Game::getInstance()->iScore--;
			Game::getInstance()->next();
			initGame();
		}
	}
}

void InGameScene::setVisibleSavePanel(bool enable)
{
	//save dialog panel
	UIPanel* pnlDialog = static_cast<UIPanel*>(m_pUILayer->getWidgetByName("pnlSave"));
	UIButton* btnDiamon = static_cast<UIButton*>(m_pUILayer->getWidgetByName("btnDiamon"));
	if (enable)
	{

		pnlDialog->setVisible(true);
		pnlDialog->setTouchEnabled(true);
		// button diamon pressed 
		btnDiamon->setTouchEnabled(true);
	}
	else
	{
		pnlDialog->setVisible(false);
		pnlDialog->setTouchEnabled(false);
		// button diamon pressed 
		btnDiamon->setTouchEnabled(false);
	}
}

void InGameScene::switchEndGame()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("SFX_DEAD.wav");
	EndGameScene* pEndGameScene = new EndGameScene();
	CCDirector::sharedDirector()->replaceScene(pEndGameScene);
}

void InGameScene::blinkDiamon()
{
	// button right pressed
	if (iFrameCount % 3 == 0)
	{
		UIButton* btnRight = static_cast<UIButton*>(m_pUILayer->getWidgetByName("btnDiamon"));
		btnRight->loadTextureNormal("buttondiamonpressed1.png", UI_TEX_TYPE_LOCAL);
	}
	if (iFrameCount % 6 == 0)
	{
		UIButton* btnRight = static_cast<UIButton*>(m_pUILayer->getWidgetByName("btnDiamon"));
		btnRight->loadTextureNormal("buttondiamonpressed2.png", UI_TEX_TYPE_LOCAL);
	}
	if (iFrameCount % 9 == 0)
	{
		UIButton* btnRight = static_cast<UIButton*>(m_pUILayer->getWidgetByName("btnDiamon"));
		btnRight->loadTextureNormal("buttondiamonpressed3.png", UI_TEX_TYPE_LOCAL);
	}
}

void InGameScene::updateProcessBar()
{
	UILoadingBar* loadingBar = static_cast<UILoadingBar*>(m_pUILayer->getWidgetByName("LoadingBar"));
	loadingBar->setPercent(Game::getInstance()->iTimeLeft);

	UILoadingBar* prbSaveTime = static_cast<UILoadingBar*>(m_pUILayer->getWidgetByName("prbSaveTime"));
	prbSaveTime->setPercent(Game::getInstance()->iTimeSave);
}

void InGameScene::updateDiamonImg()
{
	//image diamon
	UIImageView* imgDiamon1 = static_cast<UIImageView*>(m_pUILayer->getWidgetByName("imgDiamon1"));
	UIImageView* imgDiamon2 = static_cast<UIImageView*>(m_pUILayer->getWidgetByName("imgDiamon2"));
	UIImageView* imgDiamon3 = static_cast<UIImageView*>(m_pUILayer->getWidgetByName("imgDiamon3"));
	imgDiamon1->setVisible(false);
	imgDiamon2->setVisible(false);
	imgDiamon3->setVisible(false);
	if (Game::getInstance()->iHeart == 1)
	{
		imgDiamon1->setVisible(true);
		imgDiamon2->setVisible(false);
		imgDiamon3->setVisible(false);
		this->effect->start(imgDiamon1->getPosition(), imgDiamon1->getPosition(), 0.3f);
	}
	if (Game::getInstance()->iHeart == 2)
	{
		imgDiamon1->setVisible(true);
		imgDiamon2->setVisible(true);
		imgDiamon3->setVisible(false);
		this->effect->start(imgDiamon2->getPosition(), imgDiamon2->getPosition(), 0.3f);
	}
	if (Game::getInstance()->iHeart == 3)
	{
		imgDiamon1->setVisible(true);
		imgDiamon2->setVisible(true);
		imgDiamon3->setVisible(true);
		this->effect->start(imgDiamon3->getPosition(), imgDiamon3->getPosition(), 0.3f);
	}
}

void InGameScene::updateDiamonHave()
{
	//image diamon
	UIImageView* imgDiamonHave1 = static_cast<UIImageView*>(m_pUILayer->getWidgetByName("imgDiamonHave1"));
	UIImageView* imgDiamonHave2 = static_cast<UIImageView*>(m_pUILayer->getWidgetByName("imgDiamonHave2"));
	UIImageView* imgDiamonHave3 = static_cast<UIImageView*>(m_pUILayer->getWidgetByName("imgDiamonHave3"));
	imgDiamonHave1->setVisible(false);
	imgDiamonHave2->setVisible(false);
	imgDiamonHave3->setVisible(false);
	if (Game::getInstance()->iHeart == 1)
	{
		imgDiamonHave1->setVisible(true);
		imgDiamonHave2->setVisible(false);
		imgDiamonHave3->setVisible(false);
	}
	if (Game::getInstance()->iHeart == 2)
	{
		imgDiamonHave1->setVisible(true);
		imgDiamonHave2->setVisible(true);
		imgDiamonHave3->setVisible(false);
	}
	if (Game::getInstance()->iHeart == 3)
	{
		imgDiamonHave1->setVisible(true);
		imgDiamonHave2->setVisible(true);
		imgDiamonHave3->setVisible(true);
	}
}