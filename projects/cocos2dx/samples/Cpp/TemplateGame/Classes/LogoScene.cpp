#include "Defines.h"
#include "VGPLib/VGPLib.h"

extern GameState* s_gameState;
extern VGPSprite* s_vgpSprite;
extern SimpleAudioEngine* s_SimpleAudioEngine;
extern int s_frameCount;

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

// on "init" you need to initialize your instance
void LogoScene::onEnter()
{
	CCLayerColor::onEnter(); 
	CCLayerColor::initWithColor( ccc4( 255, 255, 255, 255 ) );    
	s_frameCount = 0;

	//create logo
	s_vgpSprite->addFrame( this, IMAGE_LOGO, CCPoint( BASE_SCREEN_HALF_W, BASE_SCREEN_HALF_H ) );

	//call update after each frame
	this->schedule( schedule_selector (LogoScene::update ) );

	//read file
	FileOperation::readFile();
}

void LogoScene::update ( float dt )
{
	s_frameCount++;
	if ( s_frameCount == 3 )
	{
		s_SimpleAudioEngine->preloadEffect( "SFX_COLLISION.wav" );
		s_SimpleAudioEngine->preloadEffect( "SFX_OVER.wav" );
		s_SimpleAudioEngine->preloadEffect( "SFX_SHOOT.wav" );
	}
	if ( s_frameCount != FPS*TIME_LOGO )
		return;
	//switch state
	s_gameState->switchState( STATE_INGAME );
}
