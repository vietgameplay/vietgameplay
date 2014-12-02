package com.vietgameplay.tap2top;

import android.app.Activity;
import android.util.Log;
import android.view.View;
import android.view.ViewGroup;
import android.view.ViewGroup.LayoutParams;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;

import com.startapp.android.publish.StartAppAd;
import com.startapp.android.publish.AdDisplayListener;
import com.startapp.android.publish.AdEventListener;
import com.startapp.android.publish.Ad;
import com.startapp.android.publish.banner.Banner;

public class StartAppAds {
	
	public static Activity s_activity = null;
	static StartAppAds s_instanceStartAppAds = null;
	
	private StartAppAd m_startAppAd = null;
	private Banner m_startAppBanner = null;
	
	
	final static String STARTAPP_DEV_ID="110088576";	
	final static String STARTAPP_APP_ID="212708477";	
	
	public static void sinit()
	{
		Log.d("StartApp", "StartApp -------sinit");
		s_instanceStartAppAds = new StartAppAds();
		s_instanceStartAppAds.init();
	}
	
	public void init()
	{
		StartAppAd.init(s_activity, STARTAPP_DEV_ID, STARTAPP_APP_ID);
		m_startAppAd = new StartAppAd(s_activity);	
		m_startAppBanner = new Banner(s_activity);
		RelativeLayout.LayoutParams bannerParameters =
		            new RelativeLayout.LayoutParams(
		                        RelativeLayout.LayoutParams.WRAP_CONTENT,
		                        RelativeLayout.LayoutParams.WRAP_CONTENT);
		bannerParameters.addRule(RelativeLayout.CENTER_HORIZONTAL);
		bannerParameters.addRule(RelativeLayout.ALIGN_PARENT_BOTTOM);    
		s_activity.addContentView(m_startAppBanner, bannerParameters);	
		
	}
	
	public static void sshowBannerStartApp(){	
		Log.d("StartApp", "StartApp -------sshowBannerStartApp");
		s_instanceStartAppAds.showBannerStartApp();
	}
	
	public void showBannerStartApp(){
		s_activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				if ( m_startAppBanner != null )
					m_startAppBanner.showBanner();			
			}
		});
	}
	
	//hide banner
	public static void shideBannerStartApp(){	
		Log.d("StartApp", "StartApp -------shideBannerStartApp");
		s_instanceStartAppAds.hideBannerStartApp();
	}
	
	public void hideBannerStartApp(){
		s_activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				if ( m_startAppBanner != null )
					m_startAppBanner.hideBanner();
			}
		});
    }
	
	//show interstitialAd
	public static void sshowInterstitialAdStartApp(){	
		Log.d("StartApp", "StartApp -------sshowInterstitialAdStartApp");
		s_instanceStartAppAds.showInterstitialAdStartApp();
	}
	
	public void showInterstitialAdStartApp(){
		if ( m_startAppAd == null )
			return;
		
		s_activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				m_startAppAd.showAd(new AdDisplayListener() {
					@Override
					public void adHidden(Ad ad) {
						Log.d("StartApp", "StartApp-------------------------adHidden------------------");				
					}
					@Override
					public void adDisplayed(Ad ad) {
						Log.d("StartApp", "StartApp-------------------------adDisplayed------------------");				
					}
					@Override
					public void adClicked(Ad ad) {
						Log.d("StartApp", "StartApp-------------------------adClicked------------------");				
					}
				}); 
				
				//load ad
				m_startAppAd.loadAd (new AdEventListener() {
					@Override
					public void onReceiveAd(Ad ad) {
						Log.d("StartApp", "StartApp-------------------------onReceiveAd------------------");				
					}
					@Override
					public void onFailedToReceiveAd(Ad ad) {
						Log.d("StartApp", "StartApp-------------------------onFailedToReceiveAd------------------");				
					}
				}); 
			}
		});
	}
	
	public static void sonPause() {
		s_instanceStartAppAds.onPause();		
	}
	
	public void onPause() {
		m_startAppAd.onPause();		
	}
	
	public static void sonResume() {		
		s_instanceStartAppAds.onResume();
	}
	
	public void onResume() {		
		m_startAppAd.onResume();
	}	
	
	public static void sonBackPressed() {
		s_instanceStartAppAds.onBackPressed();		
	}
	
	public void onBackPressed() {
		m_startAppAd.onBackPressed();		
	}

}
