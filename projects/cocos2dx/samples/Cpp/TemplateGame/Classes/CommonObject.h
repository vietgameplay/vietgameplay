#ifndef _COMMON_OBJECT_H
#define _COMMON_OBJECT_H

#include "cocos2d.h"

using namespace cocos2d;

class CommonObject : public CCObject
{
protected:
	CCLayer*		layer; //layer of scene that object visible
	CCSprite*		sprite; //frame of character	
	CCPoint		position; //position of object
	CCPoint		originPosition; //position of object when init ( origin )
	CCSize			size;			//size of object
	
	bool alive; // live  or death

	int currentState;	
	int previousState;

	//array of straight-line equation
	float straightLineEquation[3]; //ax + by + c = 0
	int jumpStepY;  //increase y and calculates x

public:
	CommonObject();
	CommonObject( CCLayer* layer, CCSprite* sprite  );
	~CommonObject();
	//check collision with another
	bool isCollisionWith ( CommonObject* object );

	// is alive
	bool isAlive();

	//set alive
	void setAlive( bool alive );

	//set visible
	void setVisible ( bool visible );

	//set layer :: add object on the layer
	void setLayer ( CCLayer* layer );

	//set sprite
	//need set layer before
	void setSprite ( CCSprite* sprite );

	//set frame for sprite 
	//need set sprite and set layer before
	void setFrame ( CCSpriteFrame* frame );

	//set position
	void setPosition( CCPoint pos );

	//set pos_X
	void setPositionX( float pos_x );
	
	//set pos_y
	void setPositionY( float pos_y );

	//set state
	void setState( int state );

	//get origin position
	CCPoint getOriginPosition();

	//get position
	CCPoint getPosition();

	//get position X
	float getPositionX();
	
	//get position Y
	float getPositionY();

	//get size
	CCSize getSize();

	//get width
	float getWidth();

	//get height
	float getHeight();

	//get state
	int getState();
	
	//is visible
	bool isVisible();

	//remove object
	void remove();

	void createStraightLineEquation( CCPoint begin_pos, CCPoint end_pos );

	//from straight-line equation give y calculate x
	int getX( int y );
	
	virtual void update(){}; 
};
#endif