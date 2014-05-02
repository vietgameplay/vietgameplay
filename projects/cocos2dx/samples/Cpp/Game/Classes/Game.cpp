//
//  Game.cpp
//  Game
//
//  Created by VietGamePlay on 4/29/14.
//
//

#include "Game.h"

extern CCSize screenSize;

Game::Game()
{
    iScore = 0;
    iCurrentLevel = 0;
    fTimeLeft = 0.0f;
    character = new Character();
    enemy = new Character();

}

Game::~Game()
{
    SAFE_DELETE_POINTER(character);
    SAFE_DELETE_POINTER(enemy);
}

void Game::init(CCLayer* layer)
{
    character->init(layer);
    character->loadAnimation("Character", "Character0.png", "Character0.plist", "Character.ExportJson", 0.8);
    character->setPosition(ccp(150, 480 / 2));
    enemy->init(layer);
	enemy->loadAnimation("Enemy", "Enemy0.png", "Enemy0.plist", "Enemy.ExportJson", 0.8);
    enemy->setPosition(ccp(400, 480 / 2));
};
void Game::input(int input)
{
    character->switchState(input);
};
void Game::update()
{
    character->update();
};
void Game::endGame()
{
};
