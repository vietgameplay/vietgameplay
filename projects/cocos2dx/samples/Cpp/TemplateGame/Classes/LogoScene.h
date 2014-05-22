#ifndef _LOGO_SCENE_H_
#define _LOGO_SCENE_H_

#include "cocos2d.h"

class LogoScene : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC( LogoScene );
};

#endif // __HELLOWORLD_SCENE_H__
