#include "Defines.h"

extern int s_currentScore;

Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);
	

	Scene* tran_Scene = TransitionFlipX::create(0.5f, scene );
	return tran_Scene;

    // return the scene
    //return scene;
}

// on "init" you need to initialize your instance
void MainMenuScene::onEnter()
{
	Layer::onEnter();

    s_currentScore = 0;

	//touch
	EventListenerTouchOneByOne*  listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(MainMenuScene::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(MainMenuScene::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(MainMenuScene::onTouchEnded, this);	
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	//make a string to show touch
	touchString = Label::createWithTTF("No touch", "pixel.ttf", 30 );
	touchString->setPosition( 100, 100 );
	addChild( touchString, 1 );

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MainMenuScene::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

	//button string -----------------------
	MenuItemFont* pCloseItemText = MenuItemFont::create( "Close", this, menu_selector( MainMenuScene::menuCloseCallback ) );
	pCloseItemText->setPosition( Vec2( 700, 400 ) );

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, pCloseItemText, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);

	//sprite ---------------------
	bubble = Sprite::create("bubble.png", CCRect( 0, 0, 113, 113 ) );
	bubble->setPosition( Vec2 ( BASE_SCREEN_HALF_W, BASE_SCREEN_H + bubble->getContentSize().height ) );	
	addChild( bubble ); 
    
	//font -----------------------
	scoreLabelTTF = Label::createWithTTF("0", "pixel.ttf", 30 );
	scoreLabelTTF->setPosition( Vec2(  BASE_SCREEN_HALF_W, BASE_SCREEN_HALF_H ) );
	addChild( scoreLabelTTF );

	scoreLabelBMF= Label::createWithBMFont( "medium.fnt", "0" );
	scoreLabelBMF->setPosition( Vec2(  BASE_SCREEN_HALF_W, BASE_SCREEN_HALF_H - 30 ) );
	addChild( scoreLabelBMF );

	//sheet animation
	Sprite * bee_body  = Sprite::create(); // NEW - create a sprite here

	Animation * anim_body = Animation::create();
	anim_body->addSpriteFrame( SpriteFrame::create( "bee_body_1.png", Rect( 0, 0, 80, 117 ) ) );
	anim_body->addSpriteFrame( SpriteFrame::create( "bee_body_2.png", Rect( 0, 0, 80, 117 ) ) );
	anim_body->addSpriteFrame( SpriteFrame::create( "bee_body_3.png", Rect( 0, 0, 80, 117 ) ) );
	anim_body->addSpriteFrame( SpriteFrame::create( "bee_body_2.png", Rect( 0, 0, 80, 117 ) ) );
	anim_body->setDelayPerUnit( 0.2f );
    anim_body->setLoops( -1 );
    bee_body->runAction( Animate::create ( anim_body ) );
    bee_body->setPosition( Vec2( 100, 240 ) );
	addChild( bee_body );

	ArmatureDataManager::getInstance()->addArmatureFileInfo( "Enemy0.png", "Enemy0.plist", "Enemy.ExportJson" );
	Armature* armature = Armature::create( "Enemy" );
	armature->setPosition( Vec2(600, 200 ) );
	armature->getAnimation()->playByIndex(0);
	addChild(armature);

	//progress timer
	percent = 0;
	Sprite *sprite_bar = Sprite::create( "bar.png" );
	sprite_bar->setPosition( Vec2( 400, 50 ) );
	addChild( sprite_bar );

	Sprite *sprite_timer =  Sprite::create( "timer_bar.png" );
	progressTimer = ProgressTimer::create( sprite_timer );    
	progressTimer->setType(ProgressTimer::Type::BAR );
	progressTimer->setMidpoint( Vec2( 1, 0 ) ); 
	progressTimer->setBarChangeRate( Vec2( 1, 0 ) ); //   (1, 0) -> left <-> right  (0, 1) -> up <-> down
	progressTimer->setPercentage(percent);
	progressTimer->setPosition( Vec2( 400, 50 ) );
	addChild( progressTimer );


	//update each frame
	this->schedule( schedule_selector( MainMenuScene::update ) );   
}

void MainMenuScene::update( float dt )
{
	float currentPositionY = bubble->getPositionY();
	bubble->setPositionY( currentPositionY - 3 );
	if ( bubble->getPositionY() < -bubble->getContentSize().height )
	{
		bubble->setPosition( Vec2 ( BASE_SCREEN_HALF_W, BASE_SCREEN_H + bubble->getContentSize().height ) );	
		
		s_currentScore++;

		//convert to string
		stringstream str_score;
		str_score << s_currentScore;		
		scoreLabelTTF->setString( str_score.str() );
		scoreLabelBMF->setString( str_score.str() );
	}

	//update progress timer
	if( percent == 100 )
		percent = 0;
	percent++;
	progressTimer->setPercentage( percent );
}

//touch
bool MainMenuScene::onTouchBegan(Touch* touch, Event* event)
{
	touchString->setString( "Touch began" );
	touchString->setPosition( touch->getLocation() );
	SimpleAudioEngine::getInstance()->playEffect("SFX_CONFIRM.wav");
	return true;
}

void MainMenuScene::onTouchMoved(Touch* touch, Event* event)
{
	touchString->setString( "Touch moved" );
	touchString->setPosition( touch->getLocation() );
}

void MainMenuScene::onTouchEnded(Touch* touch, Event* event)
{
	touchString->setString( "Touch ended" );
	touchString->setPosition( touch->getLocation() );
}

void MainMenuScene::menuCloseCallback(Ref* pSender)
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
