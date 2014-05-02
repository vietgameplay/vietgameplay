//
//  MainMenuScene.cpp
//  Game
//
//  Created by VietGamePlay on 5/1/14.
//
//

#include "MainMenuScene.h"
#include "InGameScene.h"

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

    // exit button
    UIButton* exit_button = UIButton::create();
    //exit_button->setTouchEnabled(true);
    exit_button->loadTextures("CloseNormal.png", "CloseSelected.png", "");
    exit_button->setPosition(ccp(m_pUILayer->getContentSize().width - exit_button->getContentSize().width, exit_button->getContentSize().height));
    exit_button->addTouchEventListener(this, toucheventselector(MainMenuScene::menuCloseCallback));
    m_pUILayer->addWidget(exit_button);
}

void MainMenuScene::onExit()
{
    m_pUILayer->removeFromParent();

    SceneReader::sharedSceneReader()->purge();
    GUIReader::shareReader()->purge();
	cocos2d::extension::ActionManager::shareManager()->purge();

    CCScene::onExit();
}

void MainMenuScene::menuCloseCallback(CCObject* pSender, TouchEventType type)
{
    if (type == TOUCH_EVENT_ENDED)
    {
        CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        exit(0);
#endif
    }
}

void MainMenuScene::UIAnimationInit()
{
    // ui animation root from json
    Layout* uianimation_root = dynamic_cast<Layout*>(GUIReader::shareReader()->widgetFromJsonFile("MainMenu.json"));
    m_pUILayer->addWidget(uianimation_root);

    // TextButton button
    UIButton* button = static_cast<UIButton*>(m_pUILayer->getWidgetByName("Button_Play"));
    button->addTouchEventListener(this, toucheventselector(MainMenuScene::startUIAnimation));
}

void MainMenuScene::startUIAnimation(CCObject* pSender, TouchEventType type)
{
    if (type == TOUCH_EVENT_ENDED)
    {
		//cocos2d::extension::ActionManager::shareManager()->playActionByName("SampleUIAnimation.json", "Animation1");
        CCDirector::sharedDirector()->replaceScene(InGameScene::scene());
    }
}