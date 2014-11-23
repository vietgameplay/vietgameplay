#include "Defines.h"

extern Languages s_language;
extern int s_currentScore;
extern int s_frameCount;

Scene* InGameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = InGameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
void InGameScene::onEnter()
{
	LayerColor::onEnter();	
	LayerColor::initWithColor( Color4B(255, 255, 255 , 200) );
	s_frameCount = TIME_OVER*FPS;
	s_currentScore = 0;

	//touch
	EventListenerTouchOneByOne*  listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(InGameScene::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//score string	
	scoreString = Label::createWithTTF("0", "pixel.ttf", 70 );
	scoreString->setPosition( BASE_SCREEN_HALF_W, BASE_SCREEN_H*3/4 );
	scoreString->setColor( Color3B( 100, 100, 100 ) );
	addChild( scoreString );
	

	this->schedule( schedule_selector( InGameScene::update ) );
}

void InGameScene::update( float dt )
{	
	if ( s_frameCount == 0 )
		GameState::getInstance()->switchState( STATE_GAMEOVER );
	s_frameCount--;
}

bool InGameScene::onTouchBegan(Touch* touch, Event* event)
{
	s_currentScore++;
	stringstream ss;
	ss << s_currentScore;
	scoreString->setString( ss.str() );
	return true;
}

