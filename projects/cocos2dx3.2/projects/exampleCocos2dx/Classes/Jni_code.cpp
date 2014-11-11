#include "Jni_code.h"
#include "platform/android/jni/JniHelper.h"
#include <jni.h>
#include "Defines.h"

using namespace cocos2d;

extern "C"
{
	//show banner
    void showBannerGoogle(){
    	JniMethodInfo t;
		if (JniHelper::getStaticMethodInfo(t, GAMEVIEW_CLASS, "showBannerGoogle", "()V"))
		{
			t.env->CallStaticVoidMethod(t.classID,t.methodID);
		}
    }
	
    //hide banner
    void hideBannerGoogle(){
    	JniMethodInfo t;
		if (JniHelper::getStaticMethodInfo(t, GAMEVIEW_CLASS, "hideBannerGoogle", "()V"))
		{
			t.env->CallStaticVoidMethod(t.classID,t.methodID);
		}
    }

    //show banner
        void showBannerStartApp(){
        	JniMethodInfo t;
    		if (JniHelper::getStaticMethodInfo(t, GAMEVIEW_CLASS, "showBannerStartApp", "()V"))
    		{
    			t.env->CallStaticVoidMethod(t.classID,t.methodID);
    		}
        }

        //hide banner
        void hideBannerStartApp(){
        	JniMethodInfo t;
    		if (JniHelper::getStaticMethodInfo(t, GAMEVIEW_CLASS, "hideBannerStartApp", "()V"))
    		{
    			t.env->CallStaticVoidMethod(t.classID,t.methodID);
    		}
        }
	
    //show interstitial ad
    void showInterstitialAdStartApp(){
    	JniMethodInfo t;
		if (JniHelper::getStaticMethodInfo(t, GAMEVIEW_CLASS, "showInterstitialAdStartApp", "()V"))
		{
			t.env->CallStaticVoidMethod(t.classID,t.methodID);
		}
    }

}
