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
char* GameDat[MAX_QUESTION][MAX_CHOICE] = {
	{ "umbrella", "umbralla", "umbralle", "umbrrela", "umbrela" },
	{ "elephant", "elepphant", "elaphent", "elephent", "elephantt" },
	{ "pillow", "pilow", "pellow", "billow", "pilot" },
	{ "tiger", "tigar", "riger", "tiged", "tigger" },
	{ "table", "tabble", "tebla", "tablle", "tabla" },
	{ "banana", "banena", "banane", "banama", "bamana" },
	{ "apple", "aple", "applle", "aplle", "apaple" },
	{ "earth", "earch", "eatth", "eartk", "eacth" },
	{ "building", "builling", "bulding", "buelding", "builddng" },
	{ "duck", "duckk", "ducck", "dock", "dick" }
};
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
	iBest = 0;
	iCurrentQuestion = 0;
	iQuestion = 0;
	iChoice = 0;
    fTimeLeft = 0.0f;
	iTimeLeft = 0;
}

Game::~Game()
{

}

void Game::init()
{
	iScore    = 0;
	iTimeLeft = 100;
	iQuestion = rand() % MAX_QUESTION;
	iChoice   = rand() % MAX_CHOICE;
};

void Game::next()
{
	iTimeLeft = 100;
	iQuestion = rand() % MAX_QUESTION;
	iChoice = rand() % MAX_CHOICE;
	iCurrentQuestion++;
	iScore++;
};

void Game::input(int input)
{

};

void Game::update()
{

};

void Game::checkBest()
{
	if (iScore > iBest)
	{
		iBest = iScore;
	}
};