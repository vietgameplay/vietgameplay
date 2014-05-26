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

};
#endif