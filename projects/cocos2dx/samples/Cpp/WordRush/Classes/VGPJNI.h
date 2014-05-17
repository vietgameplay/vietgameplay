#ifndef __VGPJNI_H__
#define __VGPJNI_H__

#include <jni.h>

extern "C"
{
    extern void rateGame();
    extern void showLeaderBoard();
    extern void saveLeaderBoard();
    extern void showAchievement();
    extern void saveAchievement();
    extern void showAdmob();
    extern void hideAdmob();
	jint Java_com_vietgameplay_wordrush_GameView_stringFromJNI( JNIEnv *env, jobject thiz );
}

#endif
