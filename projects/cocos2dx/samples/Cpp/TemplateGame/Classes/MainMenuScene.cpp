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

	CCScene* tran_Scene = CCTransitionFlipX::create(0.5f, scene );

    // return the scene
    return tran_Scene;
}

// on "init" you need to initialize your instance
void MainMenuScene::onEnter()
{
	CCLayer::onEnter();  
	CCSprite* sprite = CCSprite::create("HelloWorld.png");
	sprite->setPosition( CCPoint ( 400, 240 ) );
	addChild( sprite );

}

void MainMenuScene::update ( float dt )
{

}
