#include "Defines.h"

using namespace cocos2d;

extern int s_frameCount;
extern bool s_sfxSound;

extern CCDirector*		s_director;
extern GameState* s_gameState;

MainMenuScene::MainMenuScene()
{
}
MainMenuScene::~MainMenuScene(){}

CCScene* MainMenuScene::scene()
{
	// 'scene' is an autorelease object
	CCScene *s = CCScene::create();

	// 'layer' is an autorelease object
	MainMenuScene *layer = MainMenuScene::create();

	// add layer as a child to scene
	s->addChild(layer);
	
	return s;
}

// on "init" you need to initialize your instance
void MainMenuScene::onEnter()
{
	CCLayer::onEnter();	

	//background
	CCSprite *bg = CCSprite::create( "background.png" );
	bg->setPosition( CCPoint( 240, 400 ) );
	this->addChild( bg );

	//title Dragon Memory
	CCSprite *title = CCSprite::create("title.png");
	title->setPosition( CCPoint( 240, 650 ) );
	this->addChild( title );	
	//Set each element

	//button play and volume
	CCMenuItemImage* playButton = CCMenuItemImage::create( "play.png", "play_pressed.png", this, menu_selector( MainMenuScene::swithState ) );
	volumeOnButton = CCMenuItemImage::create( "volume_on.png", "volume_on_pressed.png", this, menu_selector( MainMenuScene::swithState ) );
	volumeOffButton = CCMenuItemImage::create( "volume_off.png", "volume_off_pressed.png", this, menu_selector( MainMenuScene::swithState ) );
    
	playButton->setPosition( CCPoint( 240, 400 ) );
	playButton->setTag( 1 ); //id 1
	volumeOnButton->setPosition( CCPoint( 80, 80 ) );
	volumeOnButton->setTag( 2 ); //id 2
	volumeOffButton->setPosition( volumeOnButton->getPosition() );
	volumeOffButton->setTag( 3 ); //id 3

    CCMenu* pMenu = CCMenu::create(playButton, volumeOnButton, volumeOffButton, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild( pMenu );
	//sound
	setDisplaySoundButton( s_sfxSound );

	//load sound
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("SFX_COLLISION.wav");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("SFX_CONFIRM.wav");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("SFX_OVER.wav");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("SFX_SHOOT.wav");
}

void MainMenuScene::update ( float dt )
{

}

void MainMenuScene::swithState( CCObject* sender )
{
	
	CCNode* item = ( CCNode* )sender;	
	int tag = item->getTag();
	switch ( tag )
	{
	case 1: //play
		s_gameState->switchState( STATE_INGAME );		
		break;
	case 2: //on off volume
	case 3: //on off volume
		s_sfxSound = !s_sfxSound;
		setDisplaySoundButton( s_sfxSound );
		if ( s_sfxSound )
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("SFX_CONFIRM.wav"); 
		break;
	}
}

void MainMenuScene::setDisplaySoundButton( bool is_sound )
{
	volumeOnButton->setVisible( s_sfxSound );
	volumeOffButton->setVisible( !s_sfxSound );
}


