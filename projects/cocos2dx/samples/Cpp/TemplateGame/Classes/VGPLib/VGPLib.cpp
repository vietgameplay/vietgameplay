#include "VGPLib.h"
#include "../Defines.h"

VGPLib* VGPLib::instance;

CCArmatureDataManager *s_CCArmatureDataManager = CCArmatureDataManager::sharedArmatureDataManager();

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

void VGPLib::loadAnimation( const char* name )
{
	int len = strlen( name );
	char *imageName = new char[ len + 5 ];
	char *plistName = new char[ len + 7 ];
	char *exportJsonName = new char[ len + 11 ];
	strcpy ( imageName, name ); 
	strcpy ( plistName, name ); 
	strcpy ( exportJsonName, name ); 
	strcat ( imageName, "0.png" );
	strcat ( plistName, "0.plist" );
	strcat ( exportJsonName, ".ExportJson" );
	s_CCArmatureDataManager->addArmatureFileInfo( imageName, plistName, exportJsonName );
}
