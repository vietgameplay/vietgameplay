#ifndef __MAINMENU_SCENE_H__
#define __MAINMENU_SCENE_H__

#include "cocos2d.h"

class MainMenuScene : public cocos2d::Layer
{
private:
	cocos2d::Sprite* bubble ;
	cocos2d::Label* scoreLabelTTF;
	cocos2d::Label* scoreLabelBMF;
	cocos2d::Label* touchString;
	cocos2d::ProgressTimer* progressTimer;
	int percent;
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual void onEnter();  

	//update function
	virtual void update( float dt );
    
    // a selector callback
    void menuCloseCallback( cocos2d::Ref* pSender );

    void inGameCallback( cocos2d::Ref* pSender );

    void logInGPCallback( cocos2d::Ref* pSender );

    void logOutGPCallback( cocos2d::Ref* pSender );

    void postGPCallback( cocos2d::Ref* pSender );

	//touch
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

	// implement the "static create()" method manually
    CREATE_FUNC( MainMenuScene );
};

#endif // __HELLOWORLD_SCENE_H__
