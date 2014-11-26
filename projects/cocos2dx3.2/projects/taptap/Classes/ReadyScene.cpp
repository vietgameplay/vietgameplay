#include "Defines.h"

extern Languages s_language;

Scene* ReadyScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = ReadyScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
void ReadyScene::onEnter()
{
	LayerColor::onEnter();	
	LayerColor::initWithColor( Color4B(255, 255, 255 , 200) );

	//touch
	EventListenerTouchOneByOne*  listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(ReadyScene::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//title
	if ( s_language == Languages::ENGLISH )
	{
		Label *title = Label::createWithTTF("ready", "pixel.ttf", 50 );
		title->setPosition( BASE_SCREEN_HALF_W, BASE_SCREEN_H*3/4 );
		title->setColor( Color3B( 100, 100, 100 ) );
		addChild( title );
	}

	//circle
	auto circle = Sprite::create( IMAGE_CIRCLE );
	circle->setPosition( BASE_SCREEN_HALF_W, BASE_SCREEN_H/3 );
	addChild( circle );

	//hand
	Sprite * hand  = Sprite::create(); // NEW - create a sprite here
	Animation * anim_hand = Animation::create();
	anim_hand->addSpriteFrame( SpriteFrame::create( "hand1.png", Rect( 0, 0, 104, 210 ) ) );
	anim_hand->addSpriteFrame( SpriteFrame::create( "hand2.png", Rect( 0, 0, 104, 210 ) ) );
	anim_hand->setDelayPerUnit( 0.2f );
    anim_hand->setLoops( -1 );
    hand->runAction( Animate::create ( anim_hand ) );
	hand->setPosition( BASE_SCREEN_HALF_W, BASE_SCREEN_HALF_H - 180 );
	addChild( hand );

	//tapap
	if ( s_language == Languages::ENGLISH )
	{
		Label *taptapStr = Label::createWithTTF("Tap in circle to get point", "pixel.ttf", 20 );
		taptapStr->setPosition( BASE_SCREEN_HALF_W, BASE_SCREEN_H/3 - 210 );
		taptapStr->setColor( Color3B( 255, 228, 0 ) );
		addChild( taptapStr );
	}
	
	this->schedule( schedule_selector( ReadyScene::update ) );
}

void ReadyScene::update( float dt )
{	
}

bool ReadyScene::onTouchBegan(Touch* touch, Event* event)
{
	SimpleAudioEngine::getInstance()->playEffect( SFX_CONFIRM );
	GameState::getInstance()->switchState( STATE_INGAME );
	return true;
}

