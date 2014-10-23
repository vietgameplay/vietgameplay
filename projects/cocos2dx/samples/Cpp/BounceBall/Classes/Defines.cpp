#include "Defines.h"

int s_cheat_count = 0;
bool s_cheat_enable = false;

//declare value here
int s_language = 0;
int s_frameCount = 0;
int s_currentState = 0;
int s_previousState = 0;
int s_nextState = 0;

bool s_gameSuspended = false;
bool s_pauseGame = false;

bool s_sfxSound = true;
bool s_musicSound = true;

int s_bestScore = 0;
int s_currentScore;


//---------------------------------System-------------------------------
CCDirector*		s_director = CCDirector::sharedDirector();

GameState* s_gameState = GameState::getInstance();