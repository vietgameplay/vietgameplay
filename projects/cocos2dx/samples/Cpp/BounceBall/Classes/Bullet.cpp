#include "Defines.h"

Bullet::Bullet()
{
}

Bullet::Bullet( CCLayer* layer, CCSprite* sprite, CCPoint end_pos  ) : CommonObject( layer, sprite )
{
	//random jumpstep 
	this->jumpStepY = BASE_BULLET_JUMP_STEP;	

	//begin position
	CCPoint begin_pos = CCPoint( BASE_SCREEN_HALF_W, 40 );

	//create strainght line equation
	setPosition( begin_pos );
	createStraightLineEquation( begin_pos, end_pos );
}

Bullet::~Bullet()
{
}

void Bullet::update()
{
	int nextY = getPositionY() + this->jumpStepY;
	int nextX = getX( nextY );
	setPosition( CCPoint( nextX, nextY ) );
	//if ( this->size. )
		//setAlive( false );
}