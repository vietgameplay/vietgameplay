#ifndef _JNI_CODE_H_
#define _JNI_CODE_H_
extern "C"
{
	//google--------------------------------
	//show banner
    void showBannerGoogle();
	
	//hide banner
    void hideBannerGoogle();

    //show interstitial
    void showInterstitialAdGoogle();

    //google plus------------------------------
    //log in
    void logInGooglePlus();

    //log out
    void logOutGooglePlus();

    //post on wall
    void postOnWallGooglePlus(const char* title, const char* url);

    //start app----------------------------------
    //show banner
	void showBannerStartApp();

	//hide banner
	void hideBannerStartApp();
	
	//show interstitial of Start app
    void showInterstitialAdStartApp();

    //revmob----------------------------
    //show banner
	void showBannerRevMob();

	//hide banner
	void hideBannerRevMob();

	//show interstitial
    void showInterstitialAdRevMob();
}
#endif
