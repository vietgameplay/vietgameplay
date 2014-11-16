package com.vietgameplay.exampleCocos2dx;

import android.app.Activity;
import android.util.Log;
import android.view.View;
import android.view.ViewGroup;
import android.view.ViewGroup.LayoutParams;
import android.widget.LinearLayout;

import com.google.android.gms.ads.AdListener;
import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.AdSize;
import com.google.android.gms.ads.AdView;

public class GoogleAds {
	
	public static Activity s_activity = null;
	static GoogleAds s_instanceGoogleAds = null;
	
	private AdView m_googleBanner = null;
	
	final static String GGP_ADMOB_ID="ca-app-pub-5629660628975902/1330315079";	
	
	public static void sinit()
	{
		Log.d("Google", "Google -------sinit");
		s_instanceGoogleAds = new GoogleAds();
		s_instanceGoogleAds.init();
	}
	
	public void init()
	{
		m_googleBanner = new AdView(s_activity);
		m_googleBanner.setAdSize(AdSize.SMART_BANNER);
		m_googleBanner.setAdUnitId(GGP_ADMOB_ID);
		// Set the AdListener.
	    m_googleBanner.setAdListener(new AdListener() {
	    	@Override
	    	public void onAdClosed() {
	    		Log.d("Google", "Google --Banner-- onAdClosed");		    		
	    	}

	    	/** Called when an ad failed to load. */
	    	@Override
	      	public void onAdFailedToLoad(int error) {
	    	  Log.d("Google", "Google --Banner-- onAdFailedToLoad");		
	      	}

	      /**
	       * Called when an ad is clicked and going to start a new Activity that will
	       * leave the application (e.g. breaking out to the Browser or Maps
	       * application).
	       */
	    	@Override
	      	public void onAdLeftApplication() {
	    	  	Log.d("Google", "Google --Banner-- onAdLeftApplication");		
	      	}

	      	/**
	       	* Called when an Activity is created in front of the app (e.g. an
	       	* interstitial is shown, or an ad is clicked and launches a new Activity).
	       	*/
	      	@Override
	      	public void onAdOpened() {
	      		Log.d("Google", "Google --Banner-- onAdOpened");	
	      	}

	      	/** Called when an ad is loaded. */
	      	@Override
	      	public void onAdLoaded() {
	      		Log.d("Google", "Google --Banner-- onAdLoaded");	
	      	}
	    }); 
	    // Start loading the ad in the background.
	    AdRequest adRequest = new AdRequest.Builder().build();
	    m_googleBanner.loadAd(adRequest);
	    ViewGroup viewGroup = (ViewGroup) ((ViewGroup) s_activity.findViewById(android.R.id.content)).getChildAt(0);
		LinearLayout layout = new LinearLayout(s_activity);
		layout.setOrientation(LinearLayout.VERTICAL);			    
	    layout.setLayoutParams(new LayoutParams(LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT));
	    layout.addView(m_googleBanner);			    
		viewGroup.addView(layout);
		
	}
	
	public static void sshowBannerGoogle(){	
		Log.d("Google", "Google -------sshowBannerGoogle");
		s_instanceGoogleAds.showBannerGoogle();
	}
	
	public void showBannerGoogle(){
		s_activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				if ( m_googleBanner != null )
					m_googleBanner.setVisibility(View.VISIBLE);			
			}
		});
	}
	
	//hide banner
	public static void shideBannerGoogle(){	
		Log.d("Google", "Google -------shideBannerGoogle");
		s_instanceGoogleAds.hideBannerGoogle();
	}
	
	public void hideBannerGoogle(){
		s_activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				if ( m_googleBanner != null )
					m_googleBanner.setVisibility(View.INVISIBLE);				
			}
		});
    }
	
	//show interstitialAd
	public static void sshowInterstitialAdGoogle(){	
		Log.d("Google", "Google -------sshowInterstitialAdGoogle");
		s_instanceGoogleAds.showInterstitialAdGoogle();
	}
	
	public void showInterstitialAdGoogle(){
		s_activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
			  
			}
		});
    }

}
