#include "VGPJNI.h"
#include "platform/android/jni/JniHelper.h"
#include "Game.h"
using namespace cocos2d;

extern "C"
{
    //rate
    void rateGame(){
    	JniMethodInfo t;
		if (JniHelper::getStaticMethodInfo(t, "com.vietgameplay.wordrush.GameView"
						,"rateGame"
						,"()V"))
		{
			t.env->CallStaticVoidMethod(t.classID,t.methodID);
		}
    }
    //end rate

    //admob
    void showAdmob(){
    	JniMethodInfo t;
		if (JniHelper::getStaticMethodInfo(t, "com.vietgameplay.wordrush.GameView"
                                           ,"showAdmob"
                                           ,"()V"))
		{
			t.env->CallStaticVoidMethod(t.classID,t.methodID);
		}
    }
    void hideAdmob(){
    	JniMethodInfo t;
		if (JniHelper::getStaticMethodInfo(t, "com.vietgameplay.wordrush.GameView"
                                           ,"hideAdmob"
                                           ,"()V"))
		{
			t.env->CallStaticVoidMethod(t.classID,t.methodID);
		}
    }

    //end admob

    //leaderboard
    void showLeaderBoard()
	{
		JniMethodInfo t;
		if (JniHelper::getStaticMethodInfo(t, "com.vietgameplay.wordrush.GameView"
                                           ,"showLeaderBoard"
                                           ,"()V"))
		{
			t.env->CallStaticVoidMethod(t.classID, t.methodID);
		}
	}
	void saveLeaderBoard()
	{
		JniMethodInfo t;
		if (JniHelper::getStaticMethodInfo(t, "com.vietgameplay.wordrush.GameView"
                                           ,"saveLeaderBoard"
                                           ,"()V"))
		{
			t.env->CallStaticVoidMethod(t.classID, t.methodID);
		}
	}
	void showAchievement()
	{
		JniMethodInfo t;
		if (JniHelper::getStaticMethodInfo(t, "com.vietgameplay.wordrush.GameView"
                                           ,"showAchievement"
                                           ,"()V"))
		{
			t.env->CallStaticVoidMethod(t.classID, t.methodID);
		}
	}
	void saveAchievement()
	{
		JniMethodInfo t;
		if (JniHelper::getStaticMethodInfo(t, "com.vietgameplay.wordrush.GameView"
                                           ,"saveAchievement"
                                           ,"()V"))
		{
			t.env->CallStaticVoidMethod(t.classID, t.methodID);
		}
	}
	jint Java_com_vietgameplay_wordrush_GameView_stringFromJNI( JNIEnv *env, jobject thiz )
	{
		return Game::getInstance()->iScore;
	}

    //end leaderboard
}
