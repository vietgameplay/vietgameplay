#ifndef __COMMON_OBJECT_H__
#define __COMMON_OBJECT_H__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "AppMacros.h"
#include "Effect.h"

#define MAX_ANIM 100
class CommonObject : public cocos2d::CCObject
{
public:
	cocos2d::CCLayer*		layer; //layer of scene that object visible
	cocos2d::CCSprite*		sprite; //frame of character
	cocos2d::CCAnimation*	animations[MAX_ANIM]; //all animations of character
	cocos2d::CCAnimate*		animate; //all animations of character
	cocos2d::CCPoint		position; //position of object
	cocos2d::CCSize			size;			//size of object
	VGP::Effect* effect;
    cocos2d::extension::CCArmature* armature;
	bool alive; // live  or death
	int currentAnimation;
	int currentState;	
	int previousState;

public:
	CommonObject();
	~CommonObject();
    void init(CCLayer* layer, CCSprite* sprite);
    void init(CCLayer* layer);
    virtual void update(float dt){};
    virtual void destroy(){};
	//check collision with another
	bool isCollisionWith ( CommonObject* object );
    void loadAnimation(const char* strName, const char* strPNG, const char* strPlist, const char* strJSON, float scale);
	// is alive
	bool isAlive();

	//set visible
	void setVisible ( bool visible );

	//set layer :: add object on the layer
	void setLayer ( cocos2d::CCLayer* layer );

	//set sprite
	//need set layer before
	void setSprite ( cocos2d::CCSprite* sprite );

	//set frame for sprite 
	//need set sprite and set layer before
	void setFrame ( int spriteID, int frameID );

	//set position
	void setPosition( cocos2d::CCPoint pos );

	//set pos_X
	void setPositionX( float pos_x );
	
	//set pos_y
	void setPositionY( float pos_y );

	//set state
	void setState( int state );

	//get position
	cocos2d::CCPoint getPosition();

	//get position X
	float getPositionX();
	
	//get position Y
	float getPositionY();

	//get size
	cocos2d::CCSize getSize();

	//get width
	float getWidth();

	//get height
	float getHeight();

	//get state
	int getState();
	
	//remove object
	void remove();
	
		
	//is visible
	bool isVisible();

	//load all animation
	void loadAnimation();

	//set animation
	void setAnimation(int animID);
};
#endif //__COMMON_OBJECT_H__