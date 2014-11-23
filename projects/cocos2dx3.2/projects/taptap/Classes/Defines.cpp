#include "Defines.h"

//declare value here
int s_frameCount = 0;
Languages s_language = Languages::UNKNOW; //need choose language
int s_currentState = 0;
int s_previousState = 0;
int s_nextState = 0;

bool s_gameSuspended = false;
bool s_pauseGame = false;

bool s_sfxSound = true;
bool s_musicSound = true;

int s_bestScore = 0;
int s_currentScore;
