#ifndef _JNI_CODE_H_
#define _JNI_CODE_H_
extern "C"
{
	//google-----------------------
	//show banner
    void showBannerGoogle();
	
	//hide banner
    void hideBannerGoogle();

    //start app----------------------------------
    //show banner
	void showBannerStartApp();

	//hide banner
	void hideBannerStartApp();
	
	//show interstitial of Start app
    void showInterstitialAdStartApp();

    //revmob----------------------------
    void showInterstitialAdRevMob();
}
#endif
