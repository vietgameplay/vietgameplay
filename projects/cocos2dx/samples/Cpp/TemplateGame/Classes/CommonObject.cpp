#include "CommonObject.h"
#include "VGPLib/VGPLib.h"

using namespace cocos2d;

CommonObject::CommonObject()
{
	this->sprite = NULL;
	this->layer  = NULL;
	this->alive  = true;	
}

CommonObject::CommonObject( cocos2d::CCLayer* layer, cocos2d::CCSprite* sprite )
{
	this->sprite = sprite;
	this->layer = layer;
	this->layer->addChild( this->sprite );
	//init infor x, y, w, h
	this->position = this->sprite->getPosition();
	this->originPosition = this->sprite->getPosition();
	this->size = this->sprite->getContentSize();
	this->alive = true;	
	currentState = 0;	
}

CommonObject::~CommonObject()
{
	this->sprite->release();
	this->sprite = NULL;	
}

bool CommonObject::isCollisionWith ( CommonObject* object )
{
	CCRect myRect = CCRect ( this->position.x - this->size.width/2, this->position.y - this->size.height/2, this->size.width, this->size.height ); 
	CCRect otherRect = CCRect ( object->position.x - object->size.width/2, object->position.y - object->size.height/2, object->size.width, object->size.height ); 
	return myRect.intersectsRect ( otherRect );
}

bool CommonObject::isAlive()
{
	return this->alive;
}

void CommonObject::setAlive( bool alive )
{
	this->alive = alive;
}

void CommonObject::setVisible ( bool visible )
{
	this->sprite->setVisible ( visible );
}

void CommonObject::setSprite ( cocos2d::CCSprite* sprite )
{
	this->sprite = sprite;
	this->position = this->sprite->getPosition();
	this->originPosition = this->sprite->getPosition();
	this->size = this->sprite->getContentSize();
}

void CommonObject::setFrame ( CCSpriteFrame* frame )
{
	this->sprite->setDisplayFrame ( frame );
}

void CommonObject::setLayer ( cocos2d::CCLayer* layer )
{
	this->layer = layer;
	this->layer->addChild ( this->sprite );
}

void CommonObject::setPosition( cocos2d::CCPoint pos )
{
	this->position = pos;
	this->sprite->setPosition ( pos );
}

void CommonObject::setPositionX( float pos_x )
{
	this->position.x = pos_x;
	this->sprite->setPositionX ( pos_x );
}

void CommonObject::setPositionY( float pos_y )
{
	this->position.y = pos_y;
	this->sprite->setPositionY ( pos_y );
}

void CommonObject::setState( int state )
{
	this->currentState = state;
}

CCPoint CommonObject::getOriginPosition()
{
	return this->originPosition;
}

CCPoint CommonObject::getPosition()
{
	return this->position;
}

float CommonObject::getPositionX()
{
	return this->position.x;
}

float CommonObject::getPositionY()
{
	return this->position.y;
}

CCSize CommonObject::getSize()
{
	return this->size;
}

float CommonObject::getWidth()
{
	return this->size.width;
}

float CommonObject::getHeight()
{
	return this->size.height;
}

int CommonObject::getState()
{
	return this->currentState;
}

bool CommonObject::isVisible()
{
	return this->sprite->isVisible();
}

void CommonObject::createStraightLineEquation( CCPoint begin_pos, CCPoint end_pos )
{
	this->straightLineEquation[0] = begin_pos.y - end_pos.y; //a
	this->straightLineEquation[1] = end_pos.x - begin_pos.x; //b
	this->straightLineEquation[2] = -( ( begin_pos.y - end_pos.y )*begin_pos.x + ( end_pos.x - begin_pos.x )*begin_pos.y ); //c
}

int CommonObject::getX( int y )
{
	return (int)( -(this->straightLineEquation[1]*y + this->straightLineEquation[2])/this->straightLineEquation[0] );
}

void CommonObject::remove()
{
	this->layer->removeChild ( this->sprite );
}