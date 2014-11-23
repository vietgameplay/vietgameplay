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

#define APPACTIVITY_CLASS "com.vietgameplay.taptap.AppActivity"
#define REVMOB_ADS_CLASS "com.vietgameplay.taptap.RevmobAds"
#define GOOGLE_ADS_CLASS "com.vietgameplay.taptap.GoogleAds"
#define STARTAPP_ADS_CLASS "com.vietgameplay.taptap.StartAppAds"
#define SAVE_PATH "/data/data/com.vietgameplay.taptap.AppActivity/tmpfile"

#define IMAGE_LOGO "logo.png"

enum class Languages
{
	UNKNOW,
	ENGLISH,
	VIETNAMESE
};

#endif
