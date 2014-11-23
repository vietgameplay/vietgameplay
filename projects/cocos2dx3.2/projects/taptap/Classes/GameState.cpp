#include "Defines.h"

GameState* GameState::instance;

extern int s_frameCount;
extern int s_currentState;
extern int s_previousState;


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
	case STATE_LANGUAGE:
		Director::sharedDirector()->replaceScene ( LanguageScene::createScene() ); 
		break;	
	case STATE_READY:
		Director::sharedDirector()->replaceScene ( ReadyScene::createScene() ); 
		break;		
	case STATE_INGAME:
		Director::sharedDirector()->replaceScene ( InGameScene::createScene() ); 
		break;			
	case STATE_GAMEOVER:
		Director::sharedDirector()->replaceScene ( GameOverScene::createScene() ); 
		break;

	}
}
