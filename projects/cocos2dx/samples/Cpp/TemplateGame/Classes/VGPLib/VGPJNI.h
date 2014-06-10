#ifndef _VGPJNI_H_
#define _VGPJNI_H_
#include "platform/android/jni/JniHelper.h"
#include <jni.h>
extern "C"
{

	//Admob
    extern void showAdmobJNI();
    extern void hideAdmobJNI();
	
	//facebook
    //extern void showLeaderBoardJNI();
    //extern void saveLeaderBoardJNI();

	//jint Java_com_vietgameplay_dragonmind_GameView_stringFromJNI( JNIEnv *env, jobject thiz );
	
	
    extern void openURL( char * url );
}

#endif
