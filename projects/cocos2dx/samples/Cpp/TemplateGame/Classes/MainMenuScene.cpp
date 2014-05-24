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

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
void MainMenuScene::onEnter()
{
	CCLayer::onEnter();  
}

void MainMenuScene::update ( float dt )
{

}
