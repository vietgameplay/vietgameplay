#ifndef _DEFINES_H
#define _DEFINES_H

//include state
#include "cocos2d.h"
#include "LogoScene.h"
#include "MainMenuScene.h"

#include "FileOperation.h"


//include object


//define for android
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#define  LOG_TAG    "vietgameplay"
#define  LOG(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#endif //CC_PLATFORM_ANDROID


//define game
#define FPS 40
#define FRAME_TIME FPS/1000.0f
#define TRANSACTION_TIME 0.5

#define BASE_SCREEN_W 800
#define BASE_SCREEN_H 480

#define USE_CHEAT 1


//define state
#define STATE_LOGO 0

#define GAMEVIEW_CLASS "com.vietgameplay.dragonmind.GameView"

#define TIME_LOGO 3

#endif
