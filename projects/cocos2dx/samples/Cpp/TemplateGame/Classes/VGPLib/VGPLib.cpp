#include "VGPLib.h"
#include "../Defines.h"

using namespace cocos2d;

VGPLib* VGPLib::instance;

VGPLib* VGPLib::getInstance()
{
	if ( instance == NULL )
		instance = new VGPLib();
	return instance;
}

void VGPLib::exitGame()
{
	CCDirector::sharedDirector()->end();
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
	#endif
}

char* VGPLib::convertDecToChar ( int num )
{
	if ( num == 0 )
	{
		char* str = "0";
		return str;
	}
	int n = num;
	int count = 0;
	int _array[20];
	while ( n != 0 )
	{
		_array[count] = n % 10;
		n /= 10;
		count++;
	}
	
	char* str = new char[count];
	for ( int i = count - 1; i >= 0; i-- )
		str[count - i - 1] = _array[i] + '0';
	str[count] = '\0';
	return str;
}
