//
//  Game.h
//  Game
//
//  Created by VietGamePlay on 4/29/14.
//
//

#ifndef Game_Game_h
#define Game_Game_h

#include "Character.h"

#define MAX_QUESTION 10
#define MAX_CHOICE   5
class Game
{
public:
	static Game* getInstance();
    Game();
    ~Game();
    void init();
	void next();
    void input(int input);
    void update();
    //bool isGameOver();
    //bool isGameWin();
    //bool isGameLose();
	void checkBest();
	int iScore;
	int iBest;
	float fTimeLeft;
	int iTimeLeft;
	int iCurrentQuestion;
	int iQuestion;
	int iChoice;
private:
	static Game* Instance;


};

#endif
