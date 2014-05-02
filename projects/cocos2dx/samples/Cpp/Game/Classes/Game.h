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

class Game
{
public:
    Game();
    ~Game();
    void init(CCLayer* layer);
    void input(int input);
    void update();
    //bool isGameOver();
    //bool isGameWin();
    //bool isGameLose();
    void endGame();
private:
    int iScore;
    float fTimeLeft;
    int iCurrentLevel;

    //MC
    Character* character;
    Character* enemy;

};

#endif
