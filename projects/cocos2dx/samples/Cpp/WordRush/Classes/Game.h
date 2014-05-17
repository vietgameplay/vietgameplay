//
//  Game.h
//  Game
//
//  Created by VietGamePlay on 4/29/14.
//
//

#ifndef Game_Game_h
#define Game_Game_h

#define MAX_QUESTION 20
#define MAX_CHOICE   4

//Game define
#define TIME_LEFT 100
#define TIME_SAVE 100

#define SCORE_LEVEL_1 9
#define SCORE_LEVEL_2 99
#define SCORE_LEVEL_3 299
//End Game define

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
	int iHeart;
	int iScore;
	int iBest;
	int iTimeSave;
	int iTimeLeft;
	int iCurrentQuestion;
	int iQuestion;
	int iChoice;
	bool bGameOver;
	bool bSave;
private:
	static Game* Instance;
};

#endif
