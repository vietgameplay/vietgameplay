package com.vietgameplay.tap2top;

import android.app.Activity;
import android.util.Log;
import android.view.ViewGroup;
import android.view.ViewGroup.LayoutParams;
import android.widget.LinearLayout;

import com.revmob.RevMob;
import com.revmob.RevMobAdsListener;
import com.revmob.ads.fullscreen.RevMobFullscreen;
import com.revmob.ads.banner.RevMobBanner;
import com.revmob.internal.RMLog;

public class RevmobAds {
	
	public static Activity s_activity = null;
	static RevmobAds s_instanceRevmobAds = null;
	
	private RevMob m_revmob = null;
	private RevMobAdsListener m_revmobListener = null;
	private RevMobBanner m_revmobBanner = null;
	private RevMobFullscreen m_revmobFullscreen = null;
	
	//status
	private int m_bannerStatus = 0;
	
	public final static int REVMOB_BANNER_NOT_RECEIVED = 0;
	public final static int REVMOB_BANNER_RECEIVED = 1;	
	public final static int REVMOB_BANNER_DISMISS = 2;
	public final static int REVMOB_BANNER_CLICKED = 3;
	public final static int REVMOB_BANNER_DISPLAYED = 4;
	
	public static void sinit()
	{
		Log.d("Revmob", "Revmob -------sinit");
		s_instanceRevmobAds = new RevmobAds();
		s_instanceRevmobAds.init();
	}
	
	public void init()
	{
		m_revmobListener = new RevMobAdsListener() {
			@Override
			public void onRevMobSessionIsStarted() {
				Log.d("Revmob", "RevMob -----session is started.");
			}
	    
			@Override
			public void onRevMobSessionNotStarted(String message) {
				Log.d("Revmob", "RevMob ------session failed to start.");
			}
	    
	    @Override
			public void onRevMobAdReceived() {
	    		m_bannerStatus = REVMOB_BANNER_RECEIVED;
	    		Log.d("Revmob", "RevMob -------ad received.");
			}

			@Override
			public void onRevMobAdNotReceived(String message) {
				m_bannerStatus = REVMOB_BANNER_NOT_RECEIVED;
				Log.d("Revmob", "RevMob --------ad not received.");
			}

			@Override
			public void onRevMobAdDismiss() {
				m_bannerStatus = REVMOB_BANNER_DISMISS;
				Log.d("Revmob", "Revmob --------Ad dismissed.");
			}

			@Override
			public void onRevMobAdClicked() {
				m_bannerStatus = REVMOB_BANNER_CLICKED;
				Log.d("Revmob", "Revmob -------Ad clicked.");
			}

			@Override
			public void onRevMobAdDisplayed() {
				m_bannerStatus = REVMOB_BANNER_DISPLAYED;
				Log.d("Revmob", "Revmob -------Ad displayed.");
			}
			
			@Override
			public void onRevMobEulaIsShown() {
				Log.d("Revmob", "Revmob ------- Eula is shown.");	
			}

			@Override
			public void onRevMobEulaWasAcceptedAndDismissed() {
				Log.d("Revmob", "Revmob ------- Eula was accepeted and dismissed.");
			}

			@Override
			public void onRevMobEulaWasRejected() {
				Log.d("Revmob", "Revmob -------Eula was rejected.");
				
			}
		};
		
		m_revmob = RevMob.startWithListener(s_activity, m_revmobListener);	
		
	}
	
	public static void sshowBannerRevMob(){	
		Log.d("Revmob", "Revmob -------sshowBannerRevMob");
		s_instanceRevmobAds.showBannerRevMob();
	}
	
	public void showBannerRevMob(){		
		if (m_revmob == null)
			return;
		s_activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {		
				m_revmobBanner = m_revmob.createBanner(s_activity, m_revmobListener);
				ViewGroup viewGroup = (ViewGroup) ((ViewGroup) s_activity.findViewById(android.R.id.content)).getChildAt(0);
				LinearLayout layout = new LinearLayout(s_activity);
				layout.setOrientation(LinearLayout.VERTICAL);			    
			    layout.setLayoutParams(new LayoutParams(LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT));
			    layout.addView(m_revmobBanner);			    
				viewGroup.addView(layout);
			}
		});
	}
	
	//hide banner
	public static void shideBannerRevMob(){	
		Log.d("Revmob", "Revmob -------shideBannerRevMob");
		s_instanceRevmobAds.hideBannerRevMob();
	}
	
	public void hideBannerRevMob(){
		s_activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {				
				if ( m_revmobBanner != null && m_bannerStatus != REVMOB_BANNER_NOT_RECEIVED )
					m_revmobBanner.hide();
			}
		});
    }
	
	//show interstitialAd
	public static void sshowInterstitialAdRevMob(){	
		Log.d("Revmob", "Revmob -------sshowInterstitialAdRevMob");
		s_instanceRevmobAds.showInterstitialAdRevMob();
	}
	
	public void showInterstitialAdRevMob(){
		if (m_revmob == null)
			return;
		s_activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				m_revmobFullscreen = m_revmob.createFullscreen(s_activity, m_revmobListener);
				m_revmobFullscreen.load();
				m_revmobFullscreen.show();
			}
		});
    }

}
