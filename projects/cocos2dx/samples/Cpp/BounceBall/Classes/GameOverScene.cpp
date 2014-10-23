#include "Defines.h"
using namespace cocos2d;

extern int s_frameCount;
extern bool s_sfxSound;
extern int s_bestScore;
extern int s_currentScore;
extern bool s_gameSuspended;

extern GameState* s_gameState;

GameOverScene::GameOverScene()
{
}
GameOverScene::~GameOverScene(){}

CCScene* GameOverScene::scene()
{
	// 'scene' is an autorelease object
	CCScene *s = CCScene::create();

	// 'layer' is an autorelease object
	GameOverScene *layer = GameOverScene::create();

	// add layer as a child to scene
	s->addChild(layer);

	return s;
}

// on "init" you need to initialize your instance
void GameOverScene::onEnter()
{
	CCLayer::onEnter();	
	if ( s_bestScore < s_currentScore )
		s_bestScore = s_currentScore;
	//background
	CCSprite *bg = CCSprite::create( "background.png" );
	bg->setPosition( CCPoint( 240, 400 ) );
	this->addChild( bg );

	//title 
	CCSprite *title = CCSprite::create("gameover.png");
	title->setPosition( CCPoint( 240, 600 ) );
	this->addChild( title );	

	//score	
	CCLabelBMFont * labelScore = CCLabelBMFont::create( InGameScene::convertDecToChar( s_currentScore ), "number.fnt" );
	labelScore->setPosition( CCPoint( 240, 480 ) );
	labelScore->setScale( 2.5 );
	this->addChild( labelScore );	
	//best score
	char bestStr[20] = "best ";
	strcat( bestStr, InGameScene::convertDecToChar( s_bestScore ) );
	CCLabelBMFont * labelBestScore = CCLabelBMFont::create( bestStr, "medium.fnt" );
	labelBestScore->setPosition( CCPoint( 240, 400 ) );
	this->addChild( labelBestScore );	

	//button play and volume
	CCMenuItemImage* playButton = CCMenuItemImage::create( "play.png", "play_pressed.png", this, menu_selector( MainMenuScene::swithState ) );
	volumeOnButton = CCMenuItemImage::create( "volume_on.png", "volume_on_pressed.png", this, menu_selector( MainMenuScene::swithState ) );
	volumeOffButton = CCMenuItemImage::create( "volume_off.png", "volume_off_pressed.png", this, menu_selector( MainMenuScene::swithState ) );
    
	playButton->setPosition( CCPoint( 240, 290 ) );
	playButton->setTag( 1 ); //id 1
	playButton->setScale( 0.8f );
	volumeOnButton->setPosition( CCPoint( 80, 80 ) );
	volumeOnButton->setTag( 2 ); //id 2
	volumeOffButton->setPosition( volumeOnButton->getPosition() );
	volumeOffButton->setTag( 3 ); //id 3

    CCMenu* pMenu = CCMenu::create(playButton, volumeOnButton, volumeOffButton, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild( pMenu );
	//sound
	setDisplaySoundButton( s_sfxSound );
	
}

void GameOverScene::update ( float dt )
{
}

void GameOverScene::swithState( CCObject* sender )
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

void GameOverScene::setDisplaySoundButton( bool is_sound )
{
	volumeOnButton->setVisible( s_sfxSound );
	volumeOffButton->setVisible( !s_sfxSound );
}


