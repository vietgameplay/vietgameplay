#include "Defines.h"

extern int s_frameCount;
extern Languages s_language;

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
		
	////update for each frame ---------------------------------
	this->schedule( schedule_selector( LogoScene::update ) );

}

void LogoScene::update( float dt )
{
	s_frameCount++;

	if ( s_frameCount == 2 )//load sound
	{
		SimpleAudioEngine::getInstance()->preloadEffect( SFX_CONFIRM );
	}
	//switch state
	if ( s_frameCount == FPS*TIME_LOGO )
	{
		if( s_language == Languages::UNKNOW )
			GameState::getInstance()->switchState( STATE_LANGUAGE );
		else
			GameState::getInstance()->switchState( STATE_READY );

		//save file
		FileOperation::saveFile();
	}
}

