//
//  Game.cpp
//  Game
//
//  Created by VietGamePlay on 4/29/14.
//
//

#include "Game.h"

extern CCSize screenSize;
Game* Game::Instance = NULL;
Game* Game::getInstance()
{
	if (Instance == NULL)
	{
		Instance = new Game();
	}
	else
	{
		return Instance;
	}
	return Instance;
}

Game::Game()
{
    iScore = 0;
	iCurrentQuestion = 0;
    fTimeLeft = 0.0f;
}

Game::~Game()
{

}

void Game::init(CCLayer* layer)
{

};
void Game::input(int input)
{

};
void Game::update()
{

};
void Game::endGame()
{
};

int Game::getScore()
{
	return iScore;
};