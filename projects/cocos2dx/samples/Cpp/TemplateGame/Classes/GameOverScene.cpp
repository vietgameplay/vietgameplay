#include "Defines.h"
#include "VGPLib/VGPLib.h"

USING_NS_CC;

extern VGPSprite* s_vgpSprite;
extern VGPLabel* s_vgpLabel;
extern VGPLib* s_vgpLib;
extern GameState* s_gameState;
extern int s_frameCount;
extern int s_currentScore;

CCScene* GameOverScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameOverScene *layer = GameOverScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
void GameOverScene::onEnter()
{
	CCLayer::onEnter(); 
	//create bg
	s_vgpSprite->addFrame( this, IMAGE_BACKGROUND, CCPoint( BASE_SCREEN_HALF_W, BASE_SCREEN_HALF_H ) );
	//string game over
	CCLabelBMFont* title = s_vgpLabel->createLabelBMFont( "GAME OVER", "medium.fnt", CCPoint( BASE_SCREEN_HALF_W, 600 ) );
	title->setScale( 2 );
	addChild( title );
	//add button replay
	CCMenuItemFont* replay = CCMenuItemFont::create( "Replay" , this, menu_selector( GameOverScene::menuCloseCallback ) );
	replay->setPosition( CCPoint( BASE_SCREEN_HALF_W, BASE_SCREEN_HALF_H ) );
	CCMenu* menu = CCMenu::create( replay, NULL );
	menu->setPosition( CCPoint( 0 , 0 ) );
	addChild( menu );

	//call update after each frame
	this->schedule( schedule_selector (LogoScene::update ) );

	//read file
	FileOperation::readFile();
}

void GameOverScene::update ( float dt )
{
	
}

void GameOverScene::menuCloseCallback(CCObject* pSender)
{
	s_gameState->switchState( STATE_INGAME );
}
