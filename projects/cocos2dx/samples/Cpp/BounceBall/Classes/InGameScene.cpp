#include "Defines.h"
#include "actions/CCActionInterval.h"

extern GameState* s_gameState;
extern int s_frameCount;
extern int s_currentScore;
extern bool s_sfxSound;

InGameScene::InGameScene()
{
	this->arrayBubble = new CCArray();
	this->arrayBullet = new CCArray();
}

InGameScene::~InGameScene()
{
	this->arrayBubble->release();
	this->arrayBubble = NULL;	
	this->arrayBullet->release();
	this->arrayBullet = NULL;	
}

CCScene* InGameScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    InGameScene *layer = InGameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

	//CCScene* tran_Scene = CCTransitionFlipX::create( TRANSACTION_TIME, scene );

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
void InGameScene::onEnter()
{
	CCLayer::onEnter();
	s_currentScore = 0;
	s_frameCount = 0;
	isAllowShoot = true;
	delayShootCount = 0;

	//background
	CCSprite *bg = CCSprite::create( "background.png" );
	bg->setPosition( CCPoint( 240, 400 ) );
	this->addChild( bg );

	//score bar
	CCSprite *scoreBar = CCSprite::create( "score_bar.png" );
	scoreBar->setPosition( CCPoint( 480 - scoreBar->getContentSize().width/2, 700 ) );
	this->addChild( scoreBar );
	//score string
	str_score = CCLabelBMFont::create("0", "number.fnt" );
	str_score->setPosition( CCPoint( 440 - str_score->getContentSize().width/2, 700 ) );
	this->addChild( str_score );	

	CCSprite *braket = CCSprite::create( "bubble_blue.png" );
	braket->setPosition( CCPoint( 240, -25 ) );
	this->addChild( braket );
	//-------------------------------------------------------------------------------
	//enable touch
	setTouchEnabled(true);	

	//update each frame
	schedule( schedule_selector ( InGameScene::update ) );	
}

void InGameScene::update ( float dt )
{
	s_frameCount++;
	//crate bubble 
	if ( s_frameCount % (TIME_CREATE_BUBBLE*FPS - s_currentScore/POINT_DECREASE_TIME) == 0 ) //5 decrease time create bubble
	{
		Bubble* bubble;
		if ( s_currentScore < 10 )
		{
			bubble = new Bubble( this, CCSprite::create( "bubble_blue.png" ), 1 );
		}
		else if ( s_currentScore < 20 )
		{
			if ( rand()%10 == 0 )
				bubble = new Bubble( this, CCSprite::create( "bubble_red.png" ), 2 );
			else
				bubble = new Bubble( this, CCSprite::create( "bubble_blue.png" ), 1 );
		}
		else if ( s_currentScore < 30 )
		{
			if ( rand()%5 == 0 )
				bubble = new Bubble( this, CCSprite::create( "bubble_red.png" ), 2 );
			else
				bubble = new Bubble( this, CCSprite::create( "bubble_blue.png" ), 1 );
		}
		else if ( s_currentScore < 40 )
		{
			if ( rand()%4 == 0 )
				bubble = new Bubble( this, CCSprite::create( "bubble_red.png" ), 2 );
			else
				bubble = new Bubble( this, CCSprite::create( "bubble_blue.png" ), 1 );
		}
		else
		{
			if ( rand()%3 == 0 )
				bubble = new Bubble( this, CCSprite::create( "bubble_red.png" ), 2 );
			else
				bubble = new Bubble( this, CCSprite::create( "bubble_blue.png" ), 1 );
		}

		this->arrayBubble->addObject( bubble );
	}
	updateBullet();
	updateBubble();

	this->str_score->setString( convertDecToChar( s_currentScore ), true );

	//update delay shoot
	if( !isAllowShoot )
	{
		delayShootCount++;
		if ( delayShootCount == SHOOT_DELAY )
		{
			isAllowShoot = true;
			delayShootCount = 0;
		}				
	}
}

void InGameScene::updateBubble()
{
	CCObject* object_bubble = NULL;
	CCObject* object_bullet = NULL;

	CCARRAY_FOREACH( this->arrayBubble, object_bubble )
	{
		Bubble * bubble = dynamic_cast < Bubble* > ( object_bubble );
		if ( bubble->isAlive() )
		{
			bubble->update();
			CCARRAY_FOREACH( this->arrayBullet, object_bullet )
			{
				Bullet * bullet = dynamic_cast < Bullet* > ( object_bullet );
				//collision
				if ( bullet->isAlive() && bubble->isCollisionWith( bullet ) )
				{
					s_currentScore++;
					bubble->deadTime--;
					if ( bubble->deadTime == 0 )
						bubble->setAlive( false );
					else //change bubble_blue
						bubble->sprite->setDisplayFrame( CCSpriteFrame::create( "bubble_blue.png", CCRect( 0, 0, 113, 113 ) ) );
					bullet->setAlive( false );
					if ( s_sfxSound )
						CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect( "SFX_COLLISION.wav" );
				}			
			}

			if ( !bubble->isAlive() )
			{			
				bubble->setVisible( false );
			}

			//check gameover
			if ( bubble->getPositionY() < bubble->getSize().height/2 )
			{
				if ( s_sfxSound )
					CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect( "SFX_OVER.wav" );
				s_gameState->switchState( STATE_GAME_OVER );
			}
		}
	}

}

void InGameScene::updateBullet()
{
	CCObject* object = NULL;
	CCARRAY_FOREACH( this->arrayBullet, object )
	{
		Bullet * bullet = dynamic_cast < Bullet* > ( object );
		if ( bullet->isAlive() )
			bullet->update();
		else
			bullet->setVisible( false );
	}
}


void InGameScene::ccTouchesEnded( CCSet *touches, CCEvent *pEvent )
{

}

void InGameScene::ccTouchesBegan(CCSet *touches, CCEvent *pEvent)
{	
	if ( !isAllowShoot )
		return;
	isAllowShoot = false;
	CCTouch* touch = ( CCTouch* ) ( touches->anyObject() );
	CCPoint touchPosition = touch->getLocationInView();
	touchPosition = CCDirector::sharedDirector()->convertToGL( touchPosition );	
	if ( s_sfxSound )
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect( "SFX_SHOOT.wav" );
	Bullet* bullet = new Bullet( this, CCSprite::create( "bullet.png" ), touchPosition );
	this->arrayBullet->addObject( bullet );
}
void InGameScene::ccTouchesMoved(CCSet *touches, CCEvent *pEvent)
{
	//get touch position
	CCTouch* touch = ( CCTouch* ) ( touches->anyObject() );
	CCPoint touchPosition = touch->getLocationInView();
	touchPosition = CCDirector::sharedDirector()->convertToGL( touchPosition );	
}

char* InGameScene::convertDecToChar ( int num )
{
	if ( num == 0 )
	{
		char* str = "0";
		return str;
	}
	int n = num;
	int count = 0;
	int _array[20];
	while ( n != 0 )
	{
		_array[count] = n % 10;
		n /= 10;
		count++;
	}
	
	char* str = new char[count];
	for ( int i = count - 1; i >= 0; i-- )
		str[count - i - 1] = _array[i] + '0';
	str[count] = '\0';
	return str;
}