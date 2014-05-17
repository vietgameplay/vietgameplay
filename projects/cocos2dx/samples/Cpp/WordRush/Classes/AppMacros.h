//
//  AppMacros.h
//  Game
//
//  Created by VietGamePlay on 4/29/14.
//
//

#ifndef Game_AppMacros_h
#define Game_AppMacros_h

#include "cocos2d.h"
#include "SimpleAudioEngine.h"


#define SAFE_DELETE_POINTER(p) if(p != NULL){ p->release(); p = NULL; }
#define ccsf(...) CCString::createWithFormat(__VA_ARGS__)->getCString()

#endif
