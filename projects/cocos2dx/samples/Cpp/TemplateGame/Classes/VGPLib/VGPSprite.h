#ifndef _VGPSPRITE_H_
#define _VGPSPRITE_H_

#include "cocos2d.h"

using namespace cocos2d;

class VGPSprite
{
protected:
	static VGPSprite* instance;

public:
	static VGPSprite* getInstance();

	CCSprite* createFrame ( char *pszFileName, CCPoint position, int zOrder, int tag, CCPoint anchor = CCPoint ( 0.5f, 0.5f ) );

	CCSprite* createFrame ( char *pszFileName, CCPoint position, int zOrder, CCPoint anchor = CCPoint ( 0.5f, 0.5f ) );

	CCSprite* createFrame ( char *pszFileName, CCPoint position, CCPoint anchor = CCPoint ( 0.5f, 0.5f ) );	
	
	CCSprite* createFrame ( char *pszFileName, CCRect rect, CCPoint position, int zOrder, int tag, CCPoint anchor = CCPoint ( 0.5f, 0.5f ) );

	CCSprite* createFrame ( char *pszFileName, CCRect rect, CCPoint position, int zOrder, CCPoint anchor = CCPoint ( 0.5f, 0.5f ) );

	CCSprite* createFrame ( char *pszFileName, CCRect rect, CCPoint position, CCPoint anchor = CCPoint ( 0.5f, 0.5f ) );	

	void addFrame ( CCLayer* layer, char *pszFileName, CCPoint position, int zOrder, int tag, CCPoint anchor = CCPoint ( 0.5f, 0.5f ) );

	void addFrame ( CCLayer* layer, char *pszFileName, CCPoint position, int zOrder, CCPoint anchor = CCPoint ( 0.5f, 0.5f ) );

	void addFrame (  CCLayer* layer, char *pszFileName, CCPoint position, CCPoint anchor = CCPoint ( 0.5f, 0.5f ) );	
		
	void addFrame ( CCLayer* layer, char *pszFileName, CCRect rect, CCPoint position, int zOrder, int tag, CCPoint anchor = CCPoint ( 0.5f, 0.5f ) );

	void addFrame ( CCLayer* layer, char *pszFileName, CCRect rect, CCPoint position, int zOrder, CCPoint anchor = CCPoint ( 0.5f, 0.5f ) );

	void addFrame (  CCLayer* layer, char *pszFileName, CCRect rect, CCPoint position, CCPoint anchor = CCPoint ( 0.5f, 0.5f ) );	

	/*

	CCSprite* createAnimation ( int spriteID, int animID, 
								float delay, int loop, CCPoint position, int zOrder, int tag );

	CCSprite* createAnimation ( int spriteID, int animID, 
								float delay, int loop, CCPoint position, int zOrder );

	CCSprite* createAnimation ( int spriteID, int animID, 
								float delay, int loop, CCPoint position);	

	void addAnimation ( CCLayer* layer, int spriteID, int animID, 
								float delay, int loop, CCPoint position, int zOrder, int tag );

	void addAnimation ( CCLayer* layer, int spriteID, int animID, 
								float delay, int loop, CCPoint position, int zOrder );

	void addAnimation ( CCLayer* layer, int spriteID, int animID, 
								float delay, int loop, CCPoint position);	


	CCSprite* createFrameMove ( int spriteID, int frameID, CCPoint srcPosition, 
								CCPoint desPosition, int jumpStep, int zOrder, int tag );

	CCSprite* createFrameMove ( int spriteID, int frameID, CCPoint srcPosition, 
								CCPoint desPosition, int jumpStep, int zOrder );

	CCSprite* createFrameMove ( int spriteID, int frameID, CCPoint srcPosition, 
								CCPoint desPosition, int jumpStep );
								

	void addFrameMove ( CCLayer* layer, int spriteID, int frameID, CCPoint srcPosition, 
								CCPoint desPosition, int jumpStep, int zOrder, int tag );

	void addFrameMove ( CCLayer* layer, int spriteID, int frameID, CCPoint srcPosition, 
								CCPoint desPosition, int jumpStep, int zOrder );

	void addFrameMove ( CCLayer* layer, int spriteID, int frameID, CCPoint srcPosition, 
								CCPoint desPosition, int jumpStep );


	CCMenuItemSprite* createButton ( int spriteID, int frameID, int frameSelectID, CCPoint position, int zOrder, int tag );


	CCMenuItemSprite* createButton ( int spriteID, int frameID, int frameSelectID, CCPoint position, int zOrder );

	CCMenuItemSprite* createButton ( int spriteID, int frameID, int frameSelectID, CCPoint position );
	
	void addButton ( CCLayer* layer, int spriteID, int frameID, int frameSelectID, CCPoint position, int zOrder, int tag );

	void addButton ( CCLayer* layer, int spriteID, int frameID, int frameSelectID, CCPoint position, int zOrder );

	void addButton ( CCLayer* layer, int spriteID, int frameID, int frameSelectID, CCPoint position );
	*/
};
#endif