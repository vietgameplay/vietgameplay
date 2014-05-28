#ifndef _VGPARMATURE_H_
#define _VGPARMATURE_H_

#include "cocos2d.h"

USING_NS_CC;
USING_NS_CC_EXT;

class VGPArmature
{
protected:
	static VGPArmature* instance;

public:
	static VGPArmature* getInstance();	

	CCArmature* createAnimation( const char *name, int playIndex, CCPoint position, int zOrder, int tag );

	CCArmature* createAnimation( const char *name, int playIndex, CCPoint position, int zOrder );

	CCArmature* createAnimation( const char *name, int playIndex, CCPoint position );

	void addAnimation( CCLayer *layer, const char *name, int playIndex, CCPoint position, int zOrder, int tag );

	void addAnimation( CCLayer *layer, const char *name, int playIndex, CCPoint position, int zOrder );

	void addAnimation( CCLayer *layer, const char *name, int playIndex, CCPoint position );
	
};

#endif