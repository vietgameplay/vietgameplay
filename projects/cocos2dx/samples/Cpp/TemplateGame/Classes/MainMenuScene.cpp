#include "Defines.h"
#include "actions/CCActionInterval.h"
#include "VGPLib/VGPLib.h"

CCRepeat *actionRepeat;
int timer_percent = 0;
CCProgressTimer* progressTimer;
CCSprite* sprite_move;

CCScene* MainMenuScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    MainMenuScene *layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

	CCScene* tran_Scene = CCTransitionFlipX::create( TRANSACTION_TIME, scene );

    // return the scene
    return tran_Scene;
}

// on "init" you need to initialize your instance
void MainMenuScene::onEnter()
{
	CCLayer::onEnter();  
	CCSprite* sprite = CCSprite::create("helloWorld.png");
	sprite->setPosition( CCPoint ( 400, 240 ) );
	addChild( sprite );

	CCSprite* sprite1 = CCSprite::create("exit.png", CCRect( 0, 0, 73, 62 ) );
	sprite1->setPosition( CCPoint ( 400, 240 ) );
	sprite1->setAnchorPoint( CCPoint ( 1, 0 ) );
	addChild( sprite1 );

	CCRotateBy *actionBy = CCRotateBy::create( 2, 360 );
	//repeat
	actionRepeat = CCRepeat::create( actionBy, 3 );
	//forever
	CCRepeatForever* _actionForever = CCRepeatForever::create( actionBy );
	sprite1->runAction( actionRepeat );

	CCLabelTTF *label = CCLabelTTF::create( "Welcome to Haputech company", "Marker Felt", 30 );
	label->setPosition( CCPoint( 400, 350 ) );
	addChild( label );

	CCLabelBMFont *label1 = CCLabelBMFont::create( "Welcome to Haputech company", "medium.fnt" );
	label1->setPosition( CCPoint( 400, 100 ) );
	addChild( label1 );

	CCMenuItemImage *pCloseItemImage = CCMenuItemImage::create( "CloseNormal.png", "CloseSelected.png", this, menu_selector(MainMenuScene::menuCloseCallback));
	pCloseItemImage->setPosition( CCPoint( 800, 480 ) );
	pCloseItemImage->setAnchorPoint( CCPoint( 1, 1 ) );
	CCMenu* pMenu = CCMenu::create( pCloseItemImage, NULL );
    pMenu->setPosition( CCPoint ( 0, 0 ) );
	addChild( pMenu );

	CCMenuItemFont* pCloseItemText = CCMenuItemFont::create( "Close", this, menu_selector( MainMenuScene::menuCloseCallback ) );
	pCloseItemText->setPosition( CCPoint( 800, 0 ) );
	pCloseItemText->setAnchorPoint( CCPoint( 1, 0 ) );
	CCMenu* pMenu1 = CCMenu::create( pCloseItemText, NULL );
    pMenu1->setPosition( CCPoint ( 0, 0 ) );
	addChild( pMenu1 );

	//make anim with sheet
	CCSprite * bee_body  = CCSprite::create(); // NEW - create a sprite here
	
	CCAnimation * anim_body = CCAnimation::create();
	
    //add frame cached on memory
	
	anim_body->addSpriteFrame( CCSpriteFrame::create( "bee_body_1.png", CCRect( 0, 0, 80, 117 ) ) );
	anim_body->addSpriteFrame( CCSpriteFrame::create( "bee_body_2.png", CCRect( 0, 0, 80, 117 ) ) );
	anim_body->addSpriteFrame( CCSpriteFrame::create( "bee_body_3.png", CCRect( 0, 0, 80, 117 ) ) );
	anim_body->addSpriteFrame( CCSpriteFrame::create( "bee_body_2.png", CCRect( 0, 0, 80, 117 ) ) );

	anim_body->setDelayPerUnit( 0.2f );
    anim_body->setLoops( -1 );
    bee_body->runAction( CCAnimate::create ( anim_body ) );
    bee_body->setPosition( CCPoint( 100, 240 ) );

	addChild( bee_body );
	
	CCSprite * bee_wing  = CCSprite::create(); // NEW - create a sprite here
	CCAnimation * anim_wing = CCAnimation::create();
	anim_wing->addSpriteFrame( CCSpriteFrame::create( "bee_wing_1.png", CCRect( 0, 0, 148, 93 ) ) );
	anim_wing->addSpriteFrame( CCSpriteFrame::create( "bee_wing_2.png", CCRect( 0, 0, 148, 93 ) ) );
	anim_wing->addSpriteFrame( CCSpriteFrame::create( "bee_wing_3.png", CCRect( 0, 0, 148, 93 ) ) );
	anim_wing->addSpriteFrame( CCSpriteFrame::create( "bee_wing_2.png", CCRect( 0, 0, 148, 93 ) ) );
	
	anim_wing->setDelayPerUnit( 0.005f );
    anim_wing->setLoops( -1 );
    bee_wing->runAction( CCAnimate::create ( anim_wing ) );
    bee_wing->setPosition( CCPoint( 96, 240 ) );

	addChild( bee_wing );

	//skeletal animation
	VGPLib::getInstance()->loadAnimation( "Enemy" );
	VGPArmature::getInstance()->addAnimation( this, "Enemy", 0, CCPoint( 500, 200 ) );

	//ProcessTimer
	VGPSprite::getInstance()->addFrame( this, "bar.png", CCPoint( 400, 50 ) );
	
	CCSprite *sprite_timer =  CCSprite::create( "timer_bar.png" );
	progressTimer = CCProgressTimer::create( sprite_timer );
	progressTimer->setType(kCCProgressTimerTypeBar);
	progressTimer->setBarChangeRate( CCPoint( 1, 0 ) ); //   (1, 0) -> left <-> right  (0, 1) -> up <-> down	
	progressTimer->setMidpoint( CCPoint( 1, 0 ) ); 		
	progressTimer->setPercentage(0);

	progressTimer->setPosition( CCPoint( 400, 50 ) );
	//progressTimer = VGPProgressTimer::getInstance()->createProgressTimer( sprite_timer, true, true, CCPoint( 400, 50 ) );  
	addChild( progressTimer );

	sprite_move = VGPSprite::getInstance()->createFrame( "CloseNormal.png", CCPoint( 100, 100 ) );
	addChild( sprite_move );

	schedule( schedule_selector ( MainMenuScene::update ) );
	setTouchEnabled(true);	
}

void MainMenuScene::update ( float dt )
{
	timer_percent++;
	if ( timer_percent == 100 )
		timer_percent = 0;
	progressTimer->setPercentage( timer_percent );
}

void MainMenuScene::ccTouchesEnded( CCSet *touches, CCEvent *pEvent )
{

}

void MainMenuScene::ccTouchesBegan(CCSet *touches, CCEvent *pEvent)
{

}
void MainMenuScene::ccTouchesMoved(CCSet *touches, CCEvent *pEvent)
{
	//get touch position
	CCTouch* touch = ( CCTouch* ) ( touches->anyObject() );
	CCPoint touchPosition = touch->getLocationInView();
	touchPosition = CCDirector::sharedDirector()->convertToGL( touchPosition );
	sprite_move->setPosition( touchPosition );
}

void MainMenuScene::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
