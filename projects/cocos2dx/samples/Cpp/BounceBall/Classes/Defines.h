#ifndef _DEFINES_H
#define _DEFINES_H

//include state
#include "cocos2d.h"
#include "../../CocosDenshion/include/SimpleAudioEngine.h"
#include "GameState.h"
#include "MainMenuScene.h"
#include "InGameScene.h"
#include "GameOverScene.h"

//include object
#include "Bubble.h"
#include "Bullet.h"

//define game
#define FPS 40
#define FRAME_TIME FPS/1000.0f
#define TRANSACTION_TIME 0.5

#define BASE_SCREEN_W 480
#define BASE_SCREEN_H 800

#define BASE_SCREEN_HALF_W BASE_SCREEN_W/2
#define BASE_SCREEN_HALF_H BASE_SCREEN_H/2

#define TIME_CREATE_BUBBLE 1
#define POINT_DECREASE_TIME 5

//define state
#define STATE_MAIN_MENU 0
#define STATE_INGAME 1
#define STATE_GAME_OVER 2

#define BASE_BUBBLE_JUMP_STEP 4
#define BASE_BULLET_JUMP_STEP 15

#define SHOOT_DELAY 15

#endif
