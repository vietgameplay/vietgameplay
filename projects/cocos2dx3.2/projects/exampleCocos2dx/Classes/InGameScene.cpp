#include "Defines.h"


Scene* InGameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = InGameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);
	

	//Scene* tran_Scene = TransitionFlipX::create(0.5f, scene );
	return scene;

    // return the scene
    //return scene;
}

// on "init" you need to initialize your instance
void InGameScene::onEnter()
{
	Layer::onEnter();

	//multiple touch
	auto listener = EventListenerTouchAllAtOnce::create();
    listener->onTouchesBegan = CC_CALLBACK_2(InGameScene::onTouchesBegan, this);
    listener->onTouchesMoved = CC_CALLBACK_2(InGameScene::onTouchesMoved, this);
    listener->onTouchesEnded = CC_CALLBACK_2(InGameScene::onTouchesEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
   
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(InGameScene::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

	// create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

	auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);

	//update each frame
	this->schedule( schedule_selector( InGameScene::update ) );   
}

void InGameScene::update( float dt )
{
	
}

void InGameScene::onTouchesBegan(const std::vector<Touch*>& touches, Event  *event)
{
    for ( auto &item: touches )
    {
        auto title = Label::createWithTTF("touch here", "pixel.ttf", 30 );
		title->setPosition(item->getLocation());
        addChild(title);
    }
}

void InGameScene::onTouchesMoved(const std::vector<Touch*>& touches, Event  *event)
{
    for( auto &item: touches)
    {
       
    }
}

void InGameScene::onTouchesEnded(const std::vector<Touch*>& touches, Event  *event)
{
    for ( auto &item: touches )
    {
       
    }
}


void InGameScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
