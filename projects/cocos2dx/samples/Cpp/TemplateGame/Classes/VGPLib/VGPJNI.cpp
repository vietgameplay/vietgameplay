#include "VGPJNI.h"
#include "../Defines.h"

extern "C"
{
	//admob	
    void showAdmobJNI()
	{
    	JniMethodInfo t;
		if ( JniHelper::getStaticMethodInfo( t, GAMEVIEW_CLASS, "showAdmobJNI", "()V" ) )
		{
			t.env->CallStaticVoidMethod(t.classID,t.methodID);
		}
    }
	
    void hideAdmobJNI()
	{
    	JniMethodInfo t;
		if ( JniHelper::getStaticMethodInfo( t, GAMEVIEW_CLASS, "hideAdmobJNI", "()V" ) )
		{
			t.env->CallStaticVoidMethod( t.classID,t.methodID );
		}
    }
	/*
	//facebook
	void showLeaderBoardJNI()
	{
    	JniMethodInfo t;
		if ( JniHelper::getStaticMethodInfo( t, GAMEVIEW_CLASS, "showLeaderBoardJNI", "()V" ) )
		{
			t.env->CallStaticVoidMethod( t.classID,t.methodID );
		}
    }
	
	void saveLeaderBoardJNI()
	{
    	JniMethodInfo t;
		if (JniHelper::getStaticMethodInfo(t, GAMEVIEW_CLASS, "saveLeaderBoardJNI", "()V" ) )
		{
			t.env->CallStaticVoidMethod( t.classID,t.methodID );
		}
    }
	jint Java_com_vietgameplay_dragonmind_GameView_stringFromJNI( JNIEnv *env, jobject thiz )
	{
		return s_currentScore;
	}
	
	void openURL( char* url)
	{
		JniMethodInfo t;
		if (JniHelper::getStaticMethodInfo(t, GAMEVIEW_CLASS, "openURL", "(Ljava/lang/String;)V" ) )
		{
			jstring string = NULL;
			if(url != NULL)
				string = t.env->NewStringUTF(url);
			
			t.env->CallStaticVoidMethod( t.classID,t.methodID, string );
			
			if(string != NULL)
				t.env->DeleteLocalRef( string );
		}
    }
	*/
}
