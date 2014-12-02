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

	//time
	auto sprite_timer = MenuItemImage::create( IMAGE_CIRCLE_UNDER, IMAGE_CIRCLE_UNDER, CC_CALLBACK_1(InGameScene::buttonCallBack, this));
	sprite_timer->setPosition( BASE_SCREEN_HALF_W, BASE_SCREEN_H/3 );
	sprite_timer->setTag( 1 ); //set tag play = 1
	
    auto menu = Menu::create(sprite_timer, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);	

	progressTimer = ProgressTimer::create( Sprite::create( IMAGE_CIRCLE ) );    
	progressTimer->setType(ProgressTimer::Type::RADIAL );	
	progressTimer->setReverseProgress(true);
	progressTimer->setPercentage(100);
	progressTimer->setPosition( sprite_timer->getPosition() );
	addChild( progressTimer );
	

	this->schedule( schedule_selector( InGameScene::update ) );

	#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	if ( hasConnectivity() )
	{
		showBannerGoogle();
		hideBannerStartApp();
	}
	#endif
}

void InGameScene::update( float dt )
{	
	//check internet
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	if ( !hasConnectivity() )
	{
		showInternetRetry();
		return;
	}
	#endif

	if ( s_frameCount == 0 )
	{
		GameState::getInstance()->switchState( STATE_GAMEOVER );
	}
	s_frameCount--;

	//set percent
	int percent = 100*s_frameCount/(FPS*TIME_OVER);
	progressTimer->setPercentage( percent );

}

bool InGameScene::onTouchBegan(Touch* touch, Event* event)
{
	return true;
}

void InGameScene::buttonCallBack( cocos2d::Ref* pSender )
{
	SimpleAudioEngine::getInstance()->playEffect( SFX_CONFIRM );
	s_currentScore++;
	stringstream ss;
	ss << s_currentScore;
	scoreString->setString( ss.str() );
}

