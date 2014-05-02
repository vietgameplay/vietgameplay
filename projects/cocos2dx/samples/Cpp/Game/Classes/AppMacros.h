//
//  AppMacros.h
//  Game
//
//  Created by VietGamePlay on 4/29/14.
//
//

#ifndef Game_AppMacros_h
#define Game_AppMacros_h

#define SAFE_DELETE_POINTER(p) if(p != NULL){ p->release(); p = NULL; }

#endif
