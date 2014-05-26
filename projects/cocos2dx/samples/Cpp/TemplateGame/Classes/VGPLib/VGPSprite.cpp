#include "VGPLib.h"

VGPSprite* VGPSprite::instance;

VGPSprite* VGPSprite::getInstance()
{
	if ( instance == NULL )
		instance = new VGPSprite();
	return instance;
}


CCSprite* VGPSprite::createFrame ( char *pszFileName, CCPoint position, int zOrder, int tag, CCPoint anchor )
{
	CCSprite* sprite = CCSprite::create( pszFileName );
	sprite->setPosition( position );
	sprite->setZOrder( zOrder );
	sprite->setTag( tag );
	sprite->setAnchorPoint( anchor );
	return sprite;
}

CCSprite* VGPSprite::createFrame ( char *pszFileName, CCPoint position, int zOrder, CCPoint anchor )
{
	return createFrame ( pszFileName, position, zOrder, -1, anchor );
}

CCSprite* VGPSprite::createFrame ( char *pszFileName, CCPoint position, CCPoint anchor )
{
	return createFrame ( pszFileName, position, 0, -1, anchor );
}
	
CCSprite* VGPSprite::createFrame ( char *pszFileName, CCRect rect, CCPoint position, int zOrder, int tag, CCPoint anchor )
{
	CCSprite* sprite = CCSprite::create( pszFileName, rect );
	sprite->setPosition( position );
	sprite->setZOrder( zOrder );
	sprite->setTag( tag );
	sprite->setAnchorPoint( anchor );
	return sprite;
}

CCSprite* VGPSprite::createFrame ( char *pszFileName, CCRect rect, CCPoint position, int zOrder, CCPoint anchor )
{
	return createFrame ( pszFileName, rect, position, zOrder, -1, anchor );
}

CCSprite* VGPSprite::createFrame ( char *pszFileName, CCRect rect, CCPoint position, CCPoint anchor )
{
	return createFrame ( pszFileName, rect, position, 0, -1, anchor );
}

void VGPSprite::addFrame ( CCLayer* layer, char *pszFileName, CCPoint position, int zOrder, int tag, CCPoint anchor )
{
	layer->addChild ( createFrame ( pszFileName, position, zOrder, tag, anchor ) );
}

void VGPSprite::addFrame ( CCLayer* layer, char *pszFileName, CCPoint position, int zOrder, CCPoint anchor )
{
	layer->addChild ( createFrame ( pszFileName, position, zOrder, -1, anchor ) );
}

void VGPSprite::addFrame (  CCLayer* layer, char *pszFileName, CCPoint position, CCPoint anchor )
{
	layer->addChild ( createFrame ( pszFileName, position, 0, -1, anchor ) );
}
		
void VGPSprite::addFrame ( CCLayer* layer, char *pszFileName, CCRect rect, CCPoint position, int zOrder, int tag, CCPoint anchor )
{
	layer->addChild ( createFrame ( pszFileName, rect, position, zOrder, tag, anchor ) );
}

void VGPSprite::addFrame ( CCLayer* layer, char *pszFileName, CCRect rect, CCPoint position, int zOrder, CCPoint anchor )
{
	layer->addChild ( createFrame ( pszFileName, rect, position, zOrder, -1, anchor ) );
}

void VGPSprite::addFrame (  CCLayer* layer, char *pszFileName, CCRect rect, CCPoint position, CCPoint anchor )
{
	layer->addChild ( createFrame ( pszFileName, rect, position, 0, -1, anchor ) );
}
