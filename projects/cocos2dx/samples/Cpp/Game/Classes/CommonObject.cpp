#include "CommonObject.h"

USING_NS_CC;
USING_NS_CC_EXT;

CommonObject::CommonObject()
{
	this->sprite = NULL;
	this->layer  = NULL;
	this->alive  = true;
    this->currentState = 0;
	this->currentAnimation = 0;
    this->previousState = 0;

	//this->effect = new VGP::Effect();
}

void CommonObject::init( CCLayer* layer, CCSprite* sprite)
{
	this->sprite = sprite;
	this->layer = layer;
	this->layer->addChild(this->sprite);

	//init infor x, y, w, h
	this->position = this->sprite->getPosition();
	this->size = this->sprite->getContentSize();
	this->alive = true;

	//this->effect = new VGP::Effect();
}
void CommonObject::init( CCLayer* layer)
{
	this->layer = layer;

	this->alive = true;

	//this->effect = new VGP::Effect();
}
void CommonObject::loadAnimation(const char* strName, const char* strPNG, const char* strPlist, const char* strJSON, float scale)
{
	//add armature
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo(strPNG, strPlist, strJSON);
	armature = CCArmature::create(strName);
	armature->setPosition(this->position);
    armature->getAnimation()->playByIndex(currentAnimation);
	armature->setScale(scale);
	this->layer->addChild(armature);
}
CommonObject::~CommonObject()
{
    SAFE_DELETE_POINTER(this->sprite);
    SAFE_DELETE_POINTER(this->armature);
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

void CommonObject::setVisible ( bool visible )
{
	this->sprite->setVisible ( visible );
}

void CommonObject::setSprite ( cocos2d::CCSprite* sprite )
{
	this->sprite = sprite;
	this->position = this->sprite->getPosition();
	this->size = this->sprite->getContentSize();
}

void CommonObject::setFrame ( int spriteID, int frameID )
{
}

void CommonObject::setLayer ( cocos2d::CCLayer* layer )
{
	this->layer = layer;
	this->layer->addChild ( this->sprite );
}

void CommonObject::setPosition( cocos2d::CCPoint pos )
{
	this->position = pos;
	//this->sprite->setPosition ( pos );
    this->armature->setPosition(pos);
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
    this->setAnimation(state);
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

void CommonObject::remove()
{
	this->layer->removeChild ( this->sprite );
}

bool CommonObject::isVisible()
{
	return this->sprite->isVisible();
}

void CommonObject::setAnimation(int animID)
{
	this->armature->getAnimation()->playByIndex(animID);
}
