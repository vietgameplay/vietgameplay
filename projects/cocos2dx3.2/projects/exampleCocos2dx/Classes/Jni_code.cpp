#include "Jni_code.h"
#include "platform/android/jni/JniHelper.h"
#include <jni.h>
#include "Defines.h"

using namespace cocos2d;

extern "C"
{
	//google----------------------------------
	//show banner
    void showBannerGoogle(){
    	JniMethodInfo t;
		if (JniHelper::getStaticMethodInfo(t, GOOGLE_ADS_CLASS, "sshowBannerGoogle", "()V"))
		{
			t.env->CallStaticVoidMethod(t.classID,t.methodID);
		}
    }
	
    //hide banner
    void hideBannerGoogle(){
    	JniMethodInfo t;
		if (JniHelper::getStaticMethodInfo(t, GOOGLE_ADS_CLASS, "shideBannerGoogle", "()V"))
		{
			t.env->CallStaticVoidMethod(t.classID,t.methodID);
		}
    }

    //show interstitial ad
	void showInterstitialAdGoogle(){
		JniMethodInfo t;
		if (JniHelper::getStaticMethodInfo(t, GOOGLE_ADS_CLASS, "sshowInterstitialAdGoogle", "()V"))
		{
			t.env->CallStaticVoidMethod(t.classID,t.methodID);
		}
	}

	//google plus------------------------------
	//log in
	void logInGooglePlus(){
		JniMethodInfo t;
		if (JniHelper::getStaticMethodInfo(t, APPACTIVITY_CLASS, "slogInGooglePlus", "()V"))
		{
			t.env->CallStaticVoidMethod(t.classID,t.methodID);
		}
	}

	//log out
	void logOutGooglePlus(){
		JniMethodInfo t;
		if (JniHelper::getStaticMethodInfo(t, APPACTIVITY_CLASS, "slogOutGooglePlus", "()V"))
		{
			t.env->CallStaticVoidMethod(t.classID,t.methodID);
		}
	}

	 void postOnWallGooglePlus(const char* content, const char* url){
		JniMethodInfo t;

		if (JniHelper::getStaticMethodInfo(t, APPACTIVITY_CLASS, "spostOnWallGooglePlus", "(Ljava/lang/String;Ljava/lang/String;)V"))
		{
			jstring str_content = JniHelper::getEnv()->NewStringUTF(content);
			jstring str_url = JniHelper::getEnv()->NewStringUTF(url);
			t.env->CallStaticVoidMethod(t.classID,t.methodID, str_content, str_url);
		}
	}


    //startApp------------------------------------------
    //show banner
        void showBannerStartApp(){
        	JniMethodInfo t;
    		if (JniHelper::getStaticMethodInfo(t, STARTAPP_ADS_CLASS, "sshowBannerStartApp", "()V"))
    		{
    			t.env->CallStaticVoidMethod(t.classID,t.methodID);
    		}
        }

        //hide banner
        void hideBannerStartApp(){
        	JniMethodInfo t;
    		if (JniHelper::getStaticMethodInfo(t, STARTAPP_ADS_CLASS, "shideBannerStartApp", "()V"))
    		{
    			t.env->CallStaticVoidMethod(t.classID,t.methodID);
    		}
        }
	
    //show interstitial ad
    void showInterstitialAdStartApp(){
    	JniMethodInfo t;
		if (JniHelper::getStaticMethodInfo(t, STARTAPP_ADS_CLASS, "sshowInterstitialAdStartApp", "()V"))
		{
			t.env->CallStaticVoidMethod(t.classID,t.methodID);
		}
    }

    //revmob--------------------------------------------
    //show banner
	void showBannerRevMob(){
		JniMethodInfo t;
		if (JniHelper::getStaticMethodInfo(t, REVMOB_ADS_CLASS, "sshowBannerRevMob", "()V"))
		{
			t.env->CallStaticVoidMethod(t.classID,t.methodID);
		}
	}

	//hide banner
	void hideBannerRevMob(){
		JniMethodInfo t;
		if (JniHelper::getStaticMethodInfo(t, REVMOB_ADS_CLASS, "shideBannerRevMob", "()V"))
		{
			t.env->CallStaticVoidMethod(t.classID,t.methodID);
		}
	}

    //show interstitial ad
	void showInterstitialAdRevMob(){
		JniMethodInfo t;
		if (JniHelper::getStaticMethodInfo(t, REVMOB_ADS_CLASS, "sshowInterstitialAdRevMob", "()V"))
		{
			t.env->CallStaticVoidMethod(t.classID,t.methodID);
		}
	}

	//check internet
	bool hasConnectivity(){
			JniMethodInfo t;
			if (JniHelper::getStaticMethodInfo(t, APPACTIVITY_CLASS, "shasConnectivity", "()Z"))
			{
				return t.env->CallStaticBooleanMethod(t.classID,t.methodID);
			}
		}

}
