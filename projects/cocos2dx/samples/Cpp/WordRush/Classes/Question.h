//
//  Question.h
//  Question
//
//  Created by VietGamePlay on 4/29/14.
//
//

#ifndef Question_h
#define Question_h

#include "Character.h"

class Game
{
public:
	static Game* getInstance();
    Game();
    ~Game();
    void init(CCLayer* layer);
    void input(int input);
    void update();
    //bool isGameOver();
    //bool isGameWin();
    //bool isGameLose();
    void endGame();
	int getScore();
private:
	static Game* Instance;
    int iScore;
    float fTimeLeft;
    int iCurrentQuestion;

};

#endif /*Question_h*/
