#ifndef _IN_GAME_SCENE_H_
#define _IN_GAME_SCENE_H_

#include "cocos2d.h"

using namespace cocos2d;

class InGameScene : public cocos2d::CCLayer
{
private:
	CCLabelBMFont* str_score;
	CCArray* arrayBubble;
	CCArray* arrayBullet;
public:

	InGameScene();
	~InGameScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual void onEnter();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();

	void updateBubble( );
	void updateBullet();
	void collisionBubble_Bullet();

	virtual void update ( float dt ); 

	void ccTouchesEnded( CCSet *touches, CCEvent *pEvent );
	void ccTouchesBegan(CCSet *touches, CCEvent *pEvent);
	void ccTouchesMoved(CCSet *touches, CCEvent *pEvent);

    CREATE_FUNC( InGameScene );
};

#endif // __HELLOWORLD_SCENE_H__
