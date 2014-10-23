#ifndef _GAME_STATE_H
#define _GAME_STATE_H


class GameState
{
public:
	static GameState* instance;
	static GameState* getInstance();

	//swich state
	void switchState( int currentState );
};
#endif