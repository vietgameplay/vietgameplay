#ifndef _MAIN_MENU_SCENE_H_
#define _MAIN_MENU_SCENE_H_

#include "cocos2d.h"

class MainMenuScene : public cocos2d::CCLayer
{

private:
	cocos2d::CCMenuItemImage *volumeOnButton, *volumeOffButton;
public:
	MainMenuScene();
	~MainMenuScene();
	virtual void onEnter();  
 
    static cocos2d::CCScene* scene();   

	virtual void update ( float dt );	
    CREATE_FUNC( MainMenuScene );
	
	void swithState( CCObject* sender );

	void setDisplaySoundButton( bool is_sound );
};

#endif