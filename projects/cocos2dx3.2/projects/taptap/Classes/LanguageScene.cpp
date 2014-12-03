#include "Defines.h"

extern Languages s_language;

Scene* LanguageScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = LanguageScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
void LanguageScene::onEnter()
{
	LayerColor::onEnter();	
	LayerColor::initWithColor( Color4B(255, 255, 255 , 200) );

	//title	
	Label *title = Label::createWithTTF("language", "pixel.ttf", 70 );
	title->setPosition( BASE_SCREEN_HALF_W, BASE_SCREEN_H*3/4 );
	title->setColor( Color3B( 100, 100, 100 ) );
	addChild( title );

	auto buttonEN = MenuItemImage::create( "flag_en.png", "flag_en_pressed.png", CC_CALLBACK_1(LanguageScene::chooseLanguageCallBack, this));
	buttonEN->setPosition( BASE_SCREEN_W/4, BASE_SCREEN_H/3 );
	buttonEN->setTag( 1 ); //set tag EN = 1

	auto buttonVI = MenuItemImage::create( "flag_vi.png", "flag_vi_pressed.png", CC_CALLBACK_1(LanguageScene::chooseLanguageCallBack, this));
	buttonVI->setPosition( BASE_SCREEN_W*3/4, BASE_SCREEN_H/3 );
	buttonVI->setTag( 2 ); //set tag VI = 1
	
    auto menu = Menu::create(buttonEN, buttonVI, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);	
	this->schedule( schedule_selector( LanguageScene::update ) );
}

void LanguageScene::update( float dt )
{	
}

void LanguageScene::chooseLanguageCallBack( cocos2d::Ref* pSender )
{
	CCNode* item = ( CCNode* )pSender;
	int tag = item->getTag();
	switch( tag )
	{
	case 1: //EN
		s_language = Languages::ENGLISH;
		break;
	case 2: //VI
		s_language = Languages::VIETNAMESE;
		break;
	}
	FileOperation::saveFile();
	SimpleAudioEngine::getInstance()->playEffect( SFX_CONFIRM );
	GameState::getInstance()->switchState( STATE_READY );
}

