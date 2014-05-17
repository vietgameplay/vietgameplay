#include "LogoScene.h"
#include "MainMenuScene.h"


USING_NS_CC;
USING_NS_CC_EXT;

extern int iFrameCount;
extern bool bGamePause;

CCScene* LogoScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    LogoScene *layer = LogoScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool LogoScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // add "VietGamePlay" splash screen"
    CCSprite* pSprite = CCSprite::create("VietGamePlay.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
	// create and initialize a label
    CCLabelTTF* pLabel = CCLabelTTF::create("VietGamePlay", "Arial", 30);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width * 0.5, origin.y + visibleSize.height * 0.2));
	this->addChild(pLabel, 1);

	//call update after each frame/main game loop in update function
	this->schedule( schedule_selector (LogoScene::update ) );
	// Enable the touch events
	setTouchEnabled(true);


    return true;
}


void LogoScene::update(float dt)
{
	if ( bGamePause )
    {
		return;
    }
	iFrameCount++;
    if(iFrameCount == 90)
    {
        MainMenuScene* pMainMenuScene = new MainMenuScene();
        CCDirector::sharedDirector()->replaceScene(pMainMenuScene);
    }
}