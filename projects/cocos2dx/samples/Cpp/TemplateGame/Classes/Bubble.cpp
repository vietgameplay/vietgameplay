#include "Defines.h"

Bubble::Bubble()
{
}

Bubble::Bubble( CCLayer* layer, CCSprite* sprite  ) : CommonObject( layer, sprite )
{
	//random jumpstep 
	this->jumpStepY = BASE_BUBBLE_JUMP_STEP + rand()%4;
	int X_left = this->size.width/2;
	int X_right = BASE_SCREEN_W - this->size.width;
	int Y_down = -this->size.height/2;
	int Y_top = BASE_SCREEN_H - Y_down;

	//begin position
	CCPoint begin_pos = CCPoint( X_left + rand() % X_right, Y_top );

	//end position
	CCPoint end_pos = CCPoint( X_left + rand() % X_right, Y_down );
	//create strainght line equation
	setPosition( begin_pos );
	createStraightLineEquation( begin_pos, end_pos );
}

Bubble::~Bubble()
{
}

void Bubble::update()
{
	int nextY = getPositionY() - this->jumpStepY;
	int nextX = getX( nextY );
	setPosition( CCPoint( nextX, nextY ) );
	if ( getPositionY() < ( - this->size.height/2 ) )
		setAlive( false );
}