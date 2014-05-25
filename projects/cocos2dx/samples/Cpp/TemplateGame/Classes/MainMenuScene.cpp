#include "Defines.h"

USING_NS_CC;


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
	sprite1->setPosition( CCPoint ( 800, 0 ) );
	sprite1->setAnchorPoint( CCPoint ( 1, 0 ) );
	addChild( sprite1 );

}

void MainMenuScene::update ( float dt )
{

}
