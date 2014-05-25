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




/*

CCSprite* VGPSprite::createAnimation ( int spriteID, int animID, 
							  float delay, int loop, CCPoint position, int zOrder, int tag )
{
	CCSprite * sprite  = CCSprite::create(); // NEW - create a sprite here
	CCAnimation * anim = CCAnimation::create();
    //add frame cached on memory
	for ( int i = s_spriteAnim[spriteID][animID][FRAME_BEGIN]; i <= s_spriteAnim[spriteID][animID][FRAME_END]; i++ )
		anim->addSpriteFrame( CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName( s_spriteFrame[spriteID][i] ) );
	
	anim->setDelayPerUnit( delay );
    anim->setLoops( loop );
    sprite->runAction( CCAnimate::create ( anim ) );
    sprite->setPosition( position );
	sprite->setZOrder( zOrder );
	sprite->setTag( tag );	
	return sprite;
}

CCSprite* VGPSprite::createAnimation ( int spriteID, int animID,
							  float delay, int loop, CCPoint position, int zOrder )
{
	return createAnimation ( spriteID, animID, delay, loop, position, zOrder, -1 );
}

CCSprite* VGPSprite::createAnimation ( int spriteID, int animID,
							  float delay, int loop, CCPoint position )
{
	return createAnimation ( spriteID, animID, delay, loop, position, 0, -1 );
}

void VGPSprite::addAnimation ( CCLayer* layer, int spriteID, int animID,
							  float delay, int loop, CCPoint position, int zOrder, int tag )
{
	CCSprite * sprite  = createAnimation ( spriteID, animID, delay, loop, position, zOrder, tag );
	layer->addChild( sprite );
}

void VGPSprite::addAnimation ( CCLayer* layer, int spriteID,  int animID,
							  float delay, int loop, CCPoint position, int zOrder )
{
	 addAnimation ( layer, spriteID, animID, delay, loop, position, zOrder, -1 );
}

void VGPSprite::addAnimation ( CCLayer* layer, int spriteID,  int animID,
							  float delay, int loop, CCPoint position )
{
	addAnimation ( layer, spriteID, animID, delay, loop, position, 0 );
}

CCSprite* VGPSprite::createFrameMove ( int spriteID, int frameID, CCPoint srcPosition, 
								CCPoint desPosition, int jumpStep, int zOrder, int tag )
{
	long distancePow2 =  ( desPosition.x - srcPosition.x) * ( desPosition.x - srcPosition.x) + ( desPosition.y - srcPosition.y) * ( desPosition.y - srcPosition.y);   
	int stepCount = distancePow2/( jumpStep*jumpStep );
	float duration = 1.0f*FRAME_TIME*stepCount;
	CCSprite* frame = createFrame( spriteID, frameID, srcPosition, zOrder, tag );
	CCFiniteTimeAction* actionMove = CCMoveTo::create( duration, desPosition ); 
	frame->runAction( CCSequence::create(actionMove, NULL) );
	return frame;
}

CCSprite* VGPSprite::createFrameMove ( int spriteID, int frameID, CCPoint srcPosition, 
								CCPoint desPosition, int jumpStep, int zOrder )
{
	return createFrameMove ( spriteID, frameID, srcPosition, desPosition, jumpStep, zOrder, -1 );
}

CCSprite* VGPSprite::createFrameMove ( int spriteID, int frameID, CCPoint srcPosition, 
								CCPoint desPosition, int jumpStep )
{
	return createFrameMove ( spriteID, frameID, srcPosition, desPosition, jumpStep, 0 );
}


void VGPSprite::addFrameMove ( CCLayer* layer, int spriteID, int frameID, CCPoint srcPosition, 
								CCPoint desPosition, int jumpStep, int zOrder, int tag )
{
	CCSprite* sprite = createFrameMove ( spriteID, frameID, srcPosition, desPosition, jumpStep, zOrder, tag );
	layer->addChild( sprite );
}

void VGPSprite::addFrameMove ( CCLayer* layer, int spriteID, int frameID, CCPoint srcPosition, 
								CCPoint desPosition, int jumpStep, int zOrder )
{
	addFrameMove ( layer, spriteID, frameID, srcPosition, desPosition, jumpStep, zOrder, -1 );	
}

void VGPSprite::addFrameMove ( CCLayer* layer, int spriteID, int frameID, CCPoint srcPosition, 
								CCPoint desPosition, int jumpStep )
{
	addFrameMove ( layer, spriteID, frameID, srcPosition, desPosition, jumpStep, 0 );	
}

CCMenuItemSprite* VGPSprite::createButton ( int spriteID, int frameID, int frameSelectID, CCPoint position, int zOrder, int tag )
{
	CCSprite* frame = CCSprite::createWithSpriteFrameName ( s_spriteFrame[spriteID][frameID] );
	CCSprite* frameSelect = CCSprite::createWithSpriteFrameName ( s_spriteFrame[spriteID][frameSelectID] );
	CCMenuItemSprite* button = CCMenuItemSprite::create ( frame, frameSelect, NULL, frame, NULL );
	button->setTag ( tag );
	button->setZOrder ( zOrder );
	button->setPosition ( position );
	return button;
}

CCMenuItemSprite* VGPSprite::createButton ( int spriteID, int frameID, int frameSelectID, CCPoint position, int zOrder )
{
	return createButton ( spriteID, frameID, frameSelectID, position, zOrder, -1 );
}

CCMenuItemSprite* VGPSprite::createButton ( int spriteID, int frameID, int frameSelectID, CCPoint position )
{
	return createButton ( spriteID, frameID, frameSelectID, position, 0 );
}

void VGPSprite::addButton ( CCLayer* layer, int spriteID, int frameID, int frameSelectID, CCPoint position, int zOrder, int tag )
{
	CCMenuItemSprite* button = createButton ( spriteID, frameID, frameSelectID, position, zOrder, tag );
	layer->addChild ( button );
}

void VGPSprite::addButton ( CCLayer* layer, int spriteID, int frameID, int frameSelectID, CCPoint position, int zOrder )
{
	addButton ( layer, spriteID, frameID, frameSelectID, position, zOrder, -1 );
}

void VGPSprite::addButton ( CCLayer* layer, int spriteID, int frameID, int frameSelectID, CCPoint position )
{
	addButton ( layer, spriteID, frameID, frameSelectID, position, 0 );
}

*/