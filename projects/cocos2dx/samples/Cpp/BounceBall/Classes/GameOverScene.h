#ifndef _GAME_OVER_SCENE_H_
#define _GAME_OVER_SCENE_H_

#include "cocos2d.h"

class GameOverScene : public cocos2d::CCLayer
{
private:
	cocos2d::CCMenuItemImage *volumeOnButton, *volumeOffButton;

public:
	GameOverScene();
	~GameOverScene();
	virtual void onEnter();  
 
    static cocos2d::CCScene* scene();   

	virtual void update ( float dt );	
   
	void swithState( CCObject* sender );

	void setDisplaySoundButton( bool is_sound );

	 CREATE_FUNC( GameOverScene );
};

#endif