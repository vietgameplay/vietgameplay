#include "VGPLib/VGPLib.h"
#include "Defines.h"

GameState* GameState::instance;

extern int s_language;
extern int s_frameCount;
extern int s_currentState;
extern int s_previousState;
extern int s_nextState;
extern CCDirector*		s_director;


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
	case STATE_INGAME:
		s_director->replaceScene ( InGameScene::scene() ); 
		break;	
	case STATE_GAME_OVER:
		s_director->replaceScene ( GameOverScene::scene() ); 
		break;	

	}
}
