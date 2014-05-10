#include "Character.h"
#include "cocos-ext.h"
#include "GameDefine.h"

USING_NS_CC_EXT;
extern CCSize screenSize;

Character::Character() : CommonObject ()
{	
	this->currentState = CHARACTER_STATE_IDLE;

	this->layer = layer;


}
void Character::init(CCLayer* layer)
{
	this->layer = layer;

    //this->position = CCPoint ( screenSize.width/2, screenSize.height/4 );
	//set position
	//setPosition( this->position );
}

Character::~Character()
{

}

void Character::switchState( int state)
{
	switch( state )
	{
	case CHARACTER_STATE_IDLE:
		{
			setState(CHARACTER_STATE_IDLE);
		}
		break;
	case CHARACTER_STATE_RUN:
		{
            setState(CHARACTER_STATE_RUN);
		}
		break;	
	case CHARACTER_STATE_ATTACK:
		{
			setState(CHARACTER_STATE_ATTACK);
		}
		break;
	case CHARACTER_STATE_HURT:
		{
			setState(CHARACTER_STATE_HURT);
		}
		break;
	case CHARACTER_STATE_DIE:
		{
            setState(CHARACTER_STATE_DIE);
		}
		break;
    default:
		{
			setState(CHARACTER_STATE_IDLE);
		}
		break;
	}
	this->currentState = state;
}

void Character::update()
{


}




