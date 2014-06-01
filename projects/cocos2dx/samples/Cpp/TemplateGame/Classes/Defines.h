#ifndef _DEFINES_H
#define _DEFINES_H

//include state
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "FileOperation.h"
#include "GameState.h"
#include "LogoScene.h"
#include "InGameScene.h"
#include "GameOverScene.h"

//include object
#include "Bubble.h"
#include "Bullet.h"

//define for android
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#define  LOG_TAG    "vietgameplay"
#define  LOG(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#endif //CC_PLATFORM_ANDROID


//define game
#define FPS 40
#define FRAME_TIME FPS/1000.0f
#define TRANSACTION_TIME 0.5

#define BASE_SCREEN_W 480
#define BASE_SCREEN_H 800

#define BASE_SCREEN_HALF_W BASE_SCREEN_W/2
#define BASE_SCREEN_HALF_H BASE_SCREEN_H/2

#define USE_CHEAT 1
#define TIME_LOGO 3
#define TIME_CREATE_LOGO 1

//define state
#define STATE_LOGO 0
#define STATE_INGAME 1
#define STATE_GAME_OVER 2

#define BASE_BUBBLE_JUMP_STEP 2
#define BASE_BULLET_JUMP_STEP 10

#define GAMEVIEW_CLASS "com.vietgameplay.dragonmind.GameView"

#define IMAGE_LOGO "logo.png"
#define IMAGE_BUBBLE "bubble.png"
#define IMAGE_BACKGROUND "background.png"
#define IMAGE_GUN "gun.png"
#define IMAGE_BULLET "bullet.png"

#endif
