#include "Defines.h"

USING_NS_CC;

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

	//call update after each 3s
	//this->schedule( schedule_selector (LogoScene::update ), 3 );


	//call update after each frame
	this->schedule( schedule_selector (LogoScene::update ) );

	//read file
	FileOperation::readFile();
}

void LogoScene::update ( float dt )
{
	s_frameCount++;
	if ( s_frameCount != FPS*TIME_LOGO )
		return;
	//switch state
	CCDirector::sharedDirector()->replaceScene ( MainMenuScene::scene() );
}
