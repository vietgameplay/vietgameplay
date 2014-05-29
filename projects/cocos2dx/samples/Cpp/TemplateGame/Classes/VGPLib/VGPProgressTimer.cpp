#include "VGPLib.h"

VGPProgressTimer* VGPProgressTimer::instance;

VGPProgressTimer* VGPProgressTimer::getInstance()
{
	if ( instance == NULL )
		instance = new VGPProgressTimer();
	return instance;
}

CCProgressTimer* VGPProgressTimer::createProgressTimer( CCSprite *spriteFrame, bool left_right_or_up_down, bool direction, int initPercent, CCPoint position, int zOrder, int tag )
{
	CCProgressTimer* progressTimer = CCProgressTimer::create( spriteFrame );    
	progressTimer->setType(kCCProgressTimerTypeBar);
	if ( left_right_or_up_down )
		progressTimer->setBarChangeRate( CCPoint( 1, 0 ) ); //   (1, 0) -> left <-> right  (0, 1) -> up <-> down
	else
		progressTimer->setBarChangeRate( CCPoint( 0, 1 ) ); //   (1, 0) -> left <-> right  (0, 1) -> up <-> down
	if ( direction )
		progressTimer->setMidpoint( CCPoint( 1, 0 ) ); 	
	else
		progressTimer->setPercentage( initPercent );
	progressTimer->setPosition( position );
	progressTimer->setZOrder( zOrder );
	progressTimer->setTag( tag );
	return progressTimer;
}

CCProgressTimer* VGPProgressTimer::createProgressTimer( CCSprite *spriteFrame, bool left_right_or_up_down, bool direction, int initPercent, CCPoint position, int zOrder )
{
	return createProgressTimer( spriteFrame, left_right_or_up_down, direction, initPercent, position, zOrder, -1 );
}

CCProgressTimer* VGPProgressTimer::createProgressTimer( CCSprite *spriteFrame, bool left_right_or_up_down, bool direction, int initPercent, CCPoint position )
{
	return createProgressTimer( spriteFrame, left_right_or_up_down, direction, initPercent, position, 0, -1 );
}
