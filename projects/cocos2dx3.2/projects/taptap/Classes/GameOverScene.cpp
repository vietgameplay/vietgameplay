#include "Defines.h"

extern Languages s_language;
extern int s_currentScore;
extern int s_bestScore;

Scene* GameOverScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameOverScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
void GameOverScene::onEnter()
{
	LayerColor::onEnter();	
	LayerColor::initWithColor( Color4B(255, 255, 255 , 200) );

	if ( s_language == Languages::ENGLISH )
	{
		Label *title = Label::createWithTTF("game over", "pixel.ttf", 50 );
		title->setPosition( BASE_SCREEN_HALF_W, BASE_SCREEN_H*3/4 );
		title->setColor( Color3B( 100, 100, 100 ) );
		addChild( title );
	}

	stringstream ss;
	ss << s_currentScore;
	//score
	Label *scoreLabel = Label::createWithTTF(ss.str(), "pixel.ttf", 110 );
	scoreLabel->setPosition( BASE_SCREEN_HALF_W, BASE_SCREEN_HALF_H + 100 );	
	addChild( scoreLabel );

	//best score
	string bestScore = "Best: ";
	bestScore = bestScore + ss.str();
	Label *bestScoreLabel = Label::createWithTTF( bestScore, "pixel.ttf", 30 );
	bestScoreLabel->setPosition( BASE_SCREEN_HALF_W, BASE_SCREEN_HALF_H );
	bestScoreLabel->setColor( Color3B( 100, 100, 100 ) );
	addChild( bestScoreLabel );

	//play button
	auto playButton = MenuItemImage::create( "play.png", "play_pressed.png", CC_CALLBACK_1(GameOverScene::buttonCallBack, this));
	playButton->setPosition( BASE_SCREEN_HALF_W, BASE_SCREEN_H/3 + 20 );
	playButton->setTag( 1 ); //set tag play = 1
	
    auto menu = Menu::create(playButton, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);	


	//result
	Label *resultLabel = Label::createWithTTF("vvvvvvvvvvvvv", "pixel.ttf", 30 );
	resultLabel->setPosition( BASE_SCREEN_HALF_W, BASE_SCREEN_H/4 );	
	resultLabel->setColor( Color3B( 100, 0, 0 ) );
	addChild( resultLabel );

	this->schedule( schedule_selector( ReadyScene::update ) );
}

void GameOverScene::update( float dt )
{	
}

void GameOverScene::buttonCallBack( cocos2d::Ref* pSender )
{
	CCNode* item = ( CCNode* )pSender;
	int tag = item->getTag();
	switch( tag )
	{
	case 1: //play
		GameState::getInstance()->switchState( STATE_READY );
		break;
	case 2: //VI
		s_language = Languages::VIETNAMESE;
		break;
	}
}
