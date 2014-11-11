#include "Defines.h"

extern int s_frameCount;

Scene* LogoScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = LogoScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
void LogoScene::onEnter()
{
	LayerColor::onEnter();
	FileOperation::readFile(); 
	s_frameCount = 0;

	LayerColor::initWithColor( Color4B(255, 255, 255 , 255) );
	Sprite *logo = Sprite::create( IMAGE_LOGO );
	logo->setPosition( BASE_SCREEN_HALF_W, BASE_SCREEN_HALF_H );
	this->addChild( logo );

	//update for 3s -------------------------------------------
	//this->schedule( schedule_selector( LogoScene::update ), TIME_LOGO );

	////update for each frame ---------------------------------
	this->schedule( schedule_selector( LogoScene::update ) );

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	hideBannerGoogle();
	hideBannerStartApp();
#endif
}

void LogoScene::update( float dt )
{
	//--------------------------
	//call immediately the first into -> 3s 
	//Director::sharedDirector()->replaceScene( MainMenuScene::createScene() );

	//--------------------------
	s_frameCount++;
	//switch state
	if ( s_frameCount == FPS*TIME_LOGO )
		GameState::getInstance()->switchState( STATE_MAIN_MENU );
}

