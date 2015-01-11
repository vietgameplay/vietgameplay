#include "Defines.h"

extern Languages s_language;
extern int s_currentScore;
extern int s_bestScore;
extern int s_frameCount;
extern int s_countPlayTime;

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
	s_countPlayTime++;
	s_frameCount = 0;
	//bg
	Sprite* bg = Sprite::create( IMAGE_BACKGROUND );
	bg->setPosition( BASE_SCREEN_HALF_W, BASE_SCREEN_HALF_H );
	addChild( bg );

	title = Label::createWithTTF("Game Over", "pixel.ttf", 60 );
	title->setPosition( BASE_SCREEN_HALF_W, BASE_SCREEN_H*3/4 );
	//title->setColor( Color3B( 100, 100, 100 ) );
	title->setVisible( false );
	addChild( title );
	

	stringstream ss;
	ss << s_currentScore;
	//score
	scoreLabel = Label::createWithTTF(ss.str(), "pixel.ttf", 100 );
	scoreLabel->setPosition( BASE_SCREEN_HALF_W, BASE_SCREEN_HALF_H + 50 );
	scoreLabel->setVisible( false );
	addChild( scoreLabel );

	//best score
	string bestScore = "Best: ";
	stringstream sss;
	if ( s_currentScore < s_bestScore)
		sss << s_bestScore;
	else
		sss << s_currentScore;
	bestScore = bestScore + sss.str();
	bestScoreLabel = Label::createWithTTF( bestScore, "pixel.ttf", 30 );
	bestScoreLabel->setPosition( BASE_SCREEN_HALF_W, BASE_SCREEN_HALF_H - 30 );
	bestScoreLabel->setColor( Color3B( 100, 100, 100 ) );
	bestScoreLabel->setVisible( false );
	addChild( bestScoreLabel );

	//best score
	newScore = Sprite::create("newScore.png");
	newScore->setPosition(BASE_SCREEN_HALF_W/2 - 40, BASE_SCREEN_HALF_H + 20  );
	newScore->setVisible(false);
	addChild( newScore );

	//play button
	playButton = MenuItemImage::create( "play.png", "play_pressed.png", CC_CALLBACK_1(GameOverScene::buttonCallBack, this));
	playButton->setPosition( BASE_SCREEN_HALF_W, BASE_SCREEN_H/3 + 10 );
	playButton->setTag( 1 ); //set tag play = 1
	playButton->setVisible( false );
	
	leaderboard = MenuItemImage::create( "leaderboard.png", "leaderboard_pressed.png", CC_CALLBACK_1(GameOverScene::buttonCallBack, this));
	leaderboard->setPosition( BASE_SCREEN_W - 60, title->getPositionY() - 60 );
	leaderboard->setTag( 2 ); //set tag leaderboard = 2
	leaderboard->setVisible( false );

	googlePlus = MenuItemImage::create( "googlePlus.png", "googlePlus_pressed.png", CC_CALLBACK_1(GameOverScene::buttonCallBack, this));
	googlePlus->setPosition( leaderboard->getPositionX() - leaderboard->getContentSize().width - 10, leaderboard->getPositionY() );
	googlePlus->setTag( 3 ); //set tag googlePlus = 3
	googlePlus->setVisible( false );



    auto menu = Menu::create(playButton, leaderboard, googlePlus, NULL);
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
		resultLabel->setPosition( BASE_SCREEN_HALF_W, BASE_SCREEN_H/5 - 20 );
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

		result->setPosition( BASE_SCREEN_HALF_W, BASE_SCREEN_H/5 - 20 );
		result->setVisible( false );
		addChild( result );
	}
		

	this->schedule( schedule_selector( ReadyScene::update ) );

	//submit score
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	submitScore(s_currentScore);
	#endif
}

void GameOverScene::update( float dt )
{	
	if ( s_frameCount == 2 )
	{
		title->setVisible( true );
	}
	else if ( s_frameCount == 8 )
	{
		scoreLabel->setVisible( true );
	}
	else if ( s_frameCount == 14 )
	{
		bestScoreLabel->setVisible( true );
	}
	else if ( s_frameCount == 20 )
	{
		playButton->setVisible( true );
		leaderboard->setVisible( true );
		googlePlus->setVisible( true );
	}
	else if ( s_frameCount == 26 )
	{
		if ( s_language == Languages::ENGLISH )
			resultLabel->setVisible( true );
		else
			result->setVisible( true );
	}
	else if ( s_frameCount >= 30 && s_frameCount <= 42 && s_currentScore > s_bestScore )
	{
		if ( s_frameCount == 30 )
		{
			newScore->setVisible(true);
			newScore->setScale(2.0f);
		}
		else if ( s_frameCount == 34 )
		{
			newScore->setScale(1.5f);
		}
		else if ( s_frameCount == 40 )
		{
			newScore->setScale(1.2f);

		}
		else if ( s_frameCount == 42 )
		{
			SimpleAudioEngine::getInstance()->playEffect( SFX_NEW_RECORED );
			newScore->setScale(1.0f);
			s_bestScore = s_currentScore;
			FileOperation::saveFile();
		}

	}
	else if ( s_frameCount > 42 )
	{
		//check internet
		#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		if ( !hasConnectivity() )
		{
			showInternetRetry();
			return;
		}
		#endif
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
		SimpleAudioEngine::getInstance()->playEffect( SFX_CONFIRM );
		GameState::getInstance()->switchState( STATE_READY );
		//show interstitial ad
		#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		if ( hasConnectivity() )
		{
			if ( s_countPlayTime == SHOW_INTERSTITIAL )
			{
				showInterstitialAdStartApp();
				s_countPlayTime = 0;
			}
		}
		#endif
		break;
	case 2: //leaderboard
		#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		showLeaderBoard();
		#endif
		break;
	case 3: //post g+
		#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		if ( s_language == Languages::ENGLISH)
		{
			string postStr = "Tap 2 Top, Let play game and who will touch on screen faster! Congratulations, you've gained ";
			stringstream ss;
			ss << s_currentScore;
			if ( s_currentScore == 1 )
				postStr = postStr + ss.str() + " point";
			else
				postStr = postStr + ss.str() + " points";
			postOnWallGooglePlus(postStr.c_str(), "https://play.google.com/store/apps/details?id=com.vietgameplay.tap2top");
		}
		else
		{
			string postStr = "Tap 2 Top, Cùng nhau chơi và xem ai chạm màn hình nhanh hơn! Xin chúc mừng, bạn đã đạt được ";
			stringstream ss;
			ss << s_currentScore;
			postStr = postStr + ss.str() + " điểm";
			postOnWallGooglePlus(postStr.c_str() , "https://play.google.com/store/apps/details?id=com.vietgameplay.tap2top");
		}
		#endif
		break;
	}
}
