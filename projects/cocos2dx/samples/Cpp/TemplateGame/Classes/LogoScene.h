#ifndef _LOGO_SCENE_H_
#define _LOGO_SCENE_H_

#include "cocos2d.h"

class LogoScene : public cocos2d::CCLayerColor
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual void onEnter();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();

	virtual void update ( float dt );    

    CREATE_FUNC( LogoScene );
};

#endif // __HELLOWORLD_SCENE_H__
