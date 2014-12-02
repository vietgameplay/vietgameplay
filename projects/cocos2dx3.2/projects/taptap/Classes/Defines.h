#ifndef _DEFINES_H
#define _DEFINES_H

#include <iostream>

#include "AppDelegate.h"
#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "Jni_code.h"
#endif

#include "GameState.h"
#include "LogoScene.h"
#include "LanguageScene.h"
#include "SimpleAudioEngine.h"
#include "FileOperation.h"
#include "ReadyScene.h"
#include "InGameScene.h"
#include "GameOverScene.h"


USING_NS_CC;
using namespace CocosDenshion;
//using namespace cocos2d::extension;
//using namespace cocostudio;
using namespace std;

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
#define TIME_LOGO 2

//define state
#define STATE_LOGO 0
#define STATE_LANGUAGE 1
#define STATE_READY 2
#define STATE_INGAME 3
#define STATE_GAMEOVER 4


//time
#define TIME_OVER 10

//point
#define POINT_MAX 400
#define POINT_LEVEL_1 50
#define POINT_LEVEL_2 60
#define POINT_LEVEL_3 70
#define POINT_LEVEL_4 80
#define POINT_LEVEL_5 90
#define POINT_LEVEL_6 100




#define APPACTIVITY_CLASS "com.vietgameplay.tap2top.AppActivity"
#define REVMOB_ADS_CLASS "com.vietgameplay.tap2top.RevmobAds"
#define GOOGLE_ADS_CLASS "com.vietgameplay.tap2top.GoogleAds"
#define STARTAPP_ADS_CLASS "com.vietgameplay.tap2top.StartAppAds"

#define IMAGE_LOGO "logo.png"
#define IMAGE_CIRCLE_UNDER "circle_under.png"
#define IMAGE_CIRCLE "circle.png"

#define SFX_CONFIRM "SFX_CONFIRM.wav"
#define SFX_DEAD "SFX_DEAD.wav"
#define SFX_NEW_RECORED "SFX_NEW_RECORED.wav"

enum class Languages
{
	UNKNOW,
	ENGLISH,
	VIETNAMESE
};

#endif
