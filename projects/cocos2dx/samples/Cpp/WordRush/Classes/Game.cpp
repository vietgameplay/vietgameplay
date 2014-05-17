//
//  Game.cpp
//  Game
//
//  Created by VietGamePlay on 4/29/14.
//
//

#include "Game.h"
#include "AppMacros.h"

Game* Game::Instance = NULL;
char* GameDat[MAX_QUESTION][MAX_CHOICE] = {
	{ "umbrella", "umbralla", "umbrella", "umbrrela"},
	{ "elephant", "elepphant", "elephant", "elephent"},
	{ "pillow", "pilow", "pillow", "pilot"},
	{ "tiger", "tigar", "tiger", "tigger"},
	{ "table", "tabble", "table", "tablle"},
	{ "banana", "banena", "banana", "banama" },
	{ "apple", "aple", "apple", "aplle" },
	{ "earth", "earch", "earth", "eartk" },
	{ "building", "builling", "building", "buildding" },
	{ "duck", "duckk", "duck", "ducck" },

	{ "zebra", "zebbra", "zebra", "zebrra"},
	{ "book", "boock", "book", "bock" },
	{ "lion", "rion", "lion", "jion" },
	{ "chicken", "chickken", "chicken", "chiccken" },
	{ "house", "housre", "house", "housse" },
	{ "cat", "bat", "cat", "pat" },
	{ "dog", "dogg", "dog", "bog" },
	{ "giraffe", "girraffe", "giraffe", "girafe" },
	{ "chair", "hair", "chair", "cheir" },
	{ "monkey", "monney", "monkey", "donkey" }
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
	iHeart = 0;
	iCurrentQuestion = 0;
	iQuestion = 0;
	iChoice = 0;
	iTimeSave = 0.0f;
	iTimeLeft = 0;
	bGameOver = false;
	bSave = false;
}

Game::~Game()
{

}

void Game::init()
{
	iScore  = 0;
	iHeart = 0;
	bSave = false;
	iTimeSave = TIME_SAVE;
	iTimeLeft = TIME_LEFT;
	iQuestion = rand() % MAX_QUESTION;
	iChoice   = rand() % MAX_CHOICE;
};

void Game::next()
{
	iTimeLeft = TIME_LEFT;
	iTimeSave = TIME_SAVE;
	iQuestion = rand() % MAX_QUESTION;
	iChoice = rand() % MAX_CHOICE;
	iCurrentQuestion++;
	if (iScore == SCORE_LEVEL_1)
	{
		iHeart++;
	}
	if (iScore == SCORE_LEVEL_2)
	{
		iHeart++;
	}
	if (iScore == SCORE_LEVEL_3)
	{
		iHeart++;
	}
	iScore++;

};

void Game::input(int input)
{

};

void Game::update()
{
	iTimeLeft--;
	if (iScore > iBest)
	{
		iBest = iScore;
	}
};
