#include "Defines.h"
#include "actions/CCActionInterval.h"
#include "VGPLib/VGPLib.h"

USING_NS_CC;
CCRepeat *actionRepeat;

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

}

void MainMenuScene::update ( float dt )
{
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
