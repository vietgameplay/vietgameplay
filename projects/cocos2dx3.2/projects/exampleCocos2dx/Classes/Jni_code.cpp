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

}
