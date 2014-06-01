#include "Defines.h"
#include "actions/CCActionInterval.h"
#include "VGPLib/VGPLib.h"

extern VGPSprite* s_vgpSprite;
extern VGPLabel* s_vgpLabel;
extern VGPLib* s_vgpLib;
extern GameState* s_gameState;
extern SimpleAudioEngine* s_SimpleAudioEngine;
extern int s_frameCount;
extern int s_currentScore;

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

	//-----------------------------create object -------------------------------
	//create background
	s_vgpSprite->addFrame( this, IMAGE_BACKGROUND, CCPoint( BASE_SCREEN_HALF_W, BASE_SCREEN_HALF_H ) );
	//gun
	s_vgpSprite->addFrame( this, IMAGE_GUN, CCPoint( BASE_SCREEN_HALF_W, 0 ) );
	
	//score
	this->str_score = s_vgpLabel->createLabelBMFont( "0", "medium.fnt", CCPoint( BASE_SCREEN_HALF_W, BASE_SCREEN_H - 100 ) );
	this->str_score->setScale( 2 );
	addChild( this->str_score );
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
	if ( s_frameCount % (TIME_CREATE_LOGO*FPS) == 0 )
	{
		Bubble* bubble = new Bubble( this, CCSprite::create( IMAGE_BUBBLE ) );
		this->arrayBubble->addObject( bubble );
	}
	updateBullet();
	updateBubble();

	this->str_score->setString( s_vgpLib->convertDecToChar( s_currentScore ), true );
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
					bubble->setAlive( false );
					bullet->setAlive( false );
					s_SimpleAudioEngine->playEffect( "SFX_COLLISION.wav" );
				}			
			}

			if ( !bubble->isAlive() )
			{			
				bubble->setVisible( false );
			}

			//check gameover
			if ( bubble->getPositionY() < -bubble->getSize().height/2 )
			{
				s_SimpleAudioEngine->playEffect( "SFX_OVER.wav" );
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
	CCTouch* touch = ( CCTouch* ) ( touches->anyObject() );
	CCPoint touchPosition = touch->getLocationInView();
	touchPosition = CCDirector::sharedDirector()->convertToGL( touchPosition );	
	s_SimpleAudioEngine->playEffect( "SFX_SHOOT.wav" );
	Bullet* bullet = new Bullet( this, CCSprite::create( IMAGE_BULLET), touchPosition );
	this->arrayBullet->addObject( bullet );
}
void InGameScene::ccTouchesMoved(CCSet *touches, CCEvent *pEvent)
{
	//get touch position
	CCTouch* touch = ( CCTouch* ) ( touches->anyObject() );
	CCPoint touchPosition = touch->getLocationInView();
	touchPosition = CCDirector::sharedDirector()->convertToGL( touchPosition );	
}