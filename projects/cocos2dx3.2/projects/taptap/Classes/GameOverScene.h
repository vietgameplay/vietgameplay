#ifndef __GAMEOVER_SCENE_H__
#define __GAMEOVER_SCENE_H__

#include "cocos2d.h"

class GameOverScene : public cocos2d::LayerColor
{
private:
	cocos2d::Label *title;
	cocos2d::Label *scoreLabel;
	cocos2d::Label *bestScoreLabel;
	cocos2d::MenuItemImage* playButton;
	cocos2d::Label *resultLabel; //en
	cocos2d::Sprite *result; //vi
	cocos2d::MenuItemImage *leaderboard;
	cocos2d::MenuItemImage *googlePlus;
	cocos2d::Sprite * newScore;
public:
    
    static cocos2d::Scene* createScene();

    virtual void onEnter();  

    virtual void update( float dt );  

	void buttonCallBack( cocos2d::Ref* pSender );	

    CREATE_FUNC(GameOverScene);
};

#endif // __HELLOWORLD_SCENE_H__
