#ifndef _VGPLIB_H_
#define _VGPLIB_H_

#include "cocos2d.h"
#include "cocos-ext.h"
#include "VGPSprite.h"
#include "VGPLabel.h"
#include "VGPArmature.h"
#include "VGPProgressTimer.h"

USING_NS_CC;
USING_NS_CC_EXT;

class VGPLib
{
protected:
	static VGPLib* instance;

public:
	static VGPLib* getInstance();	

	//exit game
	void exitGame();

	//convert Dec to char
	char* convertDecToChar ( int num );	

	//load animation of Skeletal animation
	//param name: name of ExportJson
	void loadAnimation( const char* name );
};

#endif