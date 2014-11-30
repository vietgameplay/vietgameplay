#include "Defines.h"

extern Languages s_language;
extern int s_currentScore;
extern int s_bestScore;
extern int s_frameCount;

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

	title = Label::createWithTTF("game over", "pixel.ttf", 50 );
	title->setPosition( BASE_SCREEN_HALF_W, BASE_SCREEN_H*3/4 );
	title->setColor( Color3B( 100, 100, 100 ) );
	title->setVisible( false );
	addChild( title );
	

	stringstream ss;
	ss << s_currentScore;
	//score
	scoreLabel = Label::createWithTTF(ss.str(), "pixel.ttf", 110 );
	scoreLabel->setPosition( BASE_SCREEN_HALF_W, BASE_SCREEN_HALF_H + 100 );	
	scoreLabel->setVisible( false );
	addChild( scoreLabel );

	//best score
	string bestScore = "Best: ";
	if ( s_currentScore > s_bestScore )
		bestScore = bestScore + ss.str();
	else
	{
		stringstream ss;
		ss << s_bestScore;
		bestScore = bestScore + ss.str();
	}
	bestScoreLabel = Label::createWithTTF( bestScore, "pixel.ttf", 30 );
	bestScoreLabel->setPosition( BASE_SCREEN_HALF_W, BASE_SCREEN_HALF_H + 20 );
	bestScoreLabel->setColor( Color3B( 100, 100, 100 ) );
	bestScoreLabel->setVisible( false );
	addChild( bestScoreLabel );

	//play button
	playButton = MenuItemImage::create( "play.png", "play_pressed.png", CC_CALLBACK_1(GameOverScene::buttonCallBack, this));
	playButton->setPosition( BASE_SCREEN_HALF_W, BASE_SCREEN_H/3 + 60 );
	playButton->setTag( 1 ); //set tag play = 1
	playButton->setVisible( false );
	
    auto menu = Menu::create(playButton, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);	

	////social


	//result
	if ( s_language == Languages::ENGLISH )
	{		
		resultLabel = Label::createWithTTF("", "American_Typewriter.ttf", 20, Size( 400, 100), TextHAlignment::CENTER );
		if ( s_currentScore < POINT_LEVEL_1 )
		{
			resultLabel->setString("Too bad! The ability to touch the screen is too slow! Try to pass 50 points");
		}
		else if ( s_currentScore < POINT_LEVEL_2 )
		{
			resultLabel->setString("Bad! Still slow, Try to pass 60 points");
		}
		else if ( s_currentScore < POINT_LEVEL_3 )
		{
			resultLabel->setString("Cool! Can you pass 70 points? I don't think so!");
		}
		else if ( s_currentScore < POINT_LEVEL_4 )
		{
			resultLabel->setString("Great! Pass 80 points, You can challenge others?");
		}
		else if ( s_currentScore < POINT_LEVEL_5 )
		{
			resultLabel->setString("Good! The ability to win the challenge is very high, Why do not you try?");
		}
		else
		{
			resultLabel->setString("Perfect!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		}	
		resultLabel->setPosition( BASE_SCREEN_HALF_W, BASE_SCREEN_H/5 );	
		resultLabel->setColor( Color3B( 100, 0, 0 ) );
		resultLabel->setVisible( false );
		addChild( resultLabel );
	}
	else
	{
		if ( s_currentScore < POINT_LEVEL_1 )
		{
			result = Sprite::create("level1.png");
		}
		else if ( s_currentScore < POINT_LEVEL_2 )
		{	
			result = Sprite::create("level2.png");
		}
		else if ( s_currentScore < POINT_LEVEL_3 )
		{
			result = Sprite::create("level3.png");
		}
		else if ( s_currentScore < POINT_LEVEL_4 )
		{
			result = Sprite::create("level4.png");
		}
		else if ( s_currentScore < POINT_LEVEL_5 )
		{
			result = Sprite::create("level5.png");
		}
		else
		{
			result = Sprite::create("level6.png");
		}

		result->setPosition( BASE_SCREEN_HALF_W, BASE_SCREEN_H/5 );	
		result->setVisible( false );
		addChild( result );
	}
		

	this->schedule( schedule_selector( ReadyScene::update ) );
}

void GameOverScene::update( float dt )
{	
	if ( s_frameCount == 2 )
	{
		title->setVisible( true );
	}
	else if ( s_frameCount == 6 )
	{
		scoreLabel->setVisible( true );
	}
	else if ( s_frameCount == 10 )
	{
		bestScoreLabel->setVisible( true );
	}
	else if ( s_frameCount == 14 )
	{
		playButton->setVisible( true );
	}
	else if ( s_frameCount == 18 )
	{
		if ( s_language == Languages::ENGLISH )
			resultLabel->setVisible( true );
		else
			result->setVisible( true );
	}
	else if ( s_frameCount == 22 )
	{
		//new score
	}

	s_frameCount++;
}

void GameOverScene::buttonCallBack( cocos2d::Ref* pSender )
{
	CCNode* item = ( CCNode* )pSender;
	int tag = item->getTag();
	switch( tag )
	{
	case 1: //play
		if ( s_currentScore > s_bestScore )
			s_bestScore = s_currentScore;
		SimpleAudioEngine::getInstance()->playEffect( SFX_CONFIRM );
		GameState::getInstance()->switchState( STATE_READY );
		break;
	case 2: //VI
		s_language = Languages::VIETNAMESE;
		break;
	}
}
