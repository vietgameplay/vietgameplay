#ifndef _MAINMENU_SCENE_H_
#define _MAINMENU_SCENE_H_

#include "cocos2d.h"

using namespace cocos2d;

class MainMenuScene : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual void onEnter();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();

	virtual void update ( float dt ); 

	void menuCloseCallback(CCObject* pSender);

	void ccTouchesEnded( CCSet *touches, CCEvent *pEvent );
	void ccTouchesBegan(CCSet *touches, CCEvent *pEvent);
	void ccTouchesMoved(CCSet *touches, CCEvent *pEvent);

    CREATE_FUNC( MainMenuScene );
};

#endif // __HELLOWORLD_SCENE_H__
