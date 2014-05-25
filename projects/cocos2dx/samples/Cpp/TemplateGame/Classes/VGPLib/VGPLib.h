#ifndef _VGPLIB_H_
#define _VGPLIB_H_

#include "cocos2d.h"
#include "VGPSprite.h"

using namespace cocos2d;

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
};

#endif