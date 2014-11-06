#include "Defines.h"

GameState* GameState::instance;

extern int s_frameCount;
extern int s_currentState;
extern int s_previousState;
Director *s_director = Director::sharedDirector();


GameState* GameState::getInstance()
{
	if ( instance == NULL )
		instance = new GameState();
	return instance;
}

void GameState::switchState( int currentState )
{
	s_frameCount = 0;
	s_previousState = s_currentState;
	s_currentState = currentState;
	switch ( s_currentState )
	{		
	case STATE_MAIN_MENU:
		s_director->replaceScene ( MainMenuScene::createScene() ); 
		break;		

	}
}