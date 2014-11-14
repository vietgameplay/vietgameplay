/****************************************************************************
Copyright (c) 2008-2010 Ricardo Quesada
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2011      Zynga Inc.
Copyright (c) 2013-2014 Chukong Technologies Inc.
 
http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package com.vietgameplay.exampleCocos2dx;

import org.cocos2dx.lib.Cocos2dxActivity;

import android.R;
import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.view.ViewGroup.LayoutParams;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;

//google----------------------------
import com.google.android.gms.ads.AdListener;
import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.AdSize;
import com.google.android.gms.ads.AdView;



//start app-------------------------------------
import com.startapp.android.publish.StartAppAd;
import com.startapp.android.publish.AdDisplayListener;
import com.startapp.android.publish.AdEventListener;
import com.startapp.android.publish.Ad;
import com.startapp.android.publish.banner.Banner;

//Revmob----------------------------------------
import com.revmob.RevMob;
import com.revmob.RevMobAdsListener;
import com.revmob.ads.fullscreen.RevMobFullscreen;
import com.revmob.ads.banner.RevMobBanner;
import com.revmob.internal.RMLog;

public class AppActivity extends Cocos2dxActivity {
	
	static Activity m_activity = null;
	
	//google--------------------------------
	static AdView m_googleBanner = null;
	
	final static String GGP_ADMOB_ID="ca-app-pub-5629660628975902/1330315079";	
	
	//start app---------------------------
	static StartAppAd m_startAppAd = null;
	static Banner m_startAppBanner = null;
	
	
	final static String STARTAPP_DEV_ID="110088576";	
	final static String STARTAPP_APP_ID="210163514";	
	
	//revmob---------------------------------------
	static RevMob m_revmob = null;
	static RevMobAdsListener m_revmobListener = null;
	static RevMobBanner m_revmobBanner = null;
	static RevMobFullscreen m_revmobFullscreen = null;
	
	protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);
		m_activity=this;
			
		try {			
			//google banner-------------------------------------------------------------------
			m_googleBanner = new AdView(this);
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
		    ViewGroup viewGroup = (ViewGroup) ((ViewGroup) m_activity.findViewById(android.R.id.content)).getChildAt(0);
			LinearLayout layout = new LinearLayout(m_activity);
			layout.setOrientation(LinearLayout.VERTICAL);			    
		    layout.setLayoutParams(new LayoutParams(LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT));
		    layout.addView(m_googleBanner);			    
			viewGroup.addView(layout);
		    		    
			
		    //start app---------------------------------------------------------------------
			StartAppAd.init(this, STARTAPP_DEV_ID, STARTAPP_APP_ID);
			m_startAppAd = new StartAppAd(this);	
			m_startAppBanner = new Banner(this);
			RelativeLayout.LayoutParams bannerParameters =
			            new RelativeLayout.LayoutParams(
			                        RelativeLayout.LayoutParams.WRAP_CONTENT,
			                        RelativeLayout.LayoutParams.WRAP_CONTENT);
			bannerParameters.addRule(RelativeLayout.CENTER_HORIZONTAL);
			bannerParameters.addRule(RelativeLayout.ALIGN_PARENT_BOTTOM);    
			addContentView(m_startAppBanner, bannerParameters);		
			
			//revmob-----------------------------------------------------------------------
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
		    	Log.d("Revmob", "RevMob -------ad received.");
				}

				@Override
				public void onRevMobAdNotReceived(String message) {
					Log.d("Revmob", "RevMob --------ad not received.");
				}

				@Override
				public void onRevMobAdDismiss() {
					Log.d("Revmob", "Revmob --------Ad dismissed.");
				}

				@Override
				public void onRevMobAdClicked() {
					Log.d("Revmob", "Revmob -------Ad clicked.");
				}

				@Override
				public void onRevMobAdDisplayed() {
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
			
			m_revmob = RevMob.startWithListener(this, m_revmobListener);		
			
			
		} catch (Exception e) {
			Log.d("Ads", "Revmob -------error: " + e);
		}			
	}
	
	//google-------------------------------
	//show banner
	static void showBannerGoogle(){
		m_activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				if ( m_googleBanner != null )
					m_googleBanner.setVisibility(View.VISIBLE);			
			}
		});
	}
	
	//hide banner
	static void hideBannerGoogle(){
		m_activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				if ( m_googleBanner != null )
					m_googleBanner.setVisibility(View.INVISIBLE);				
			}
		});
    }
	
	//show interstitialAd
	static void showInterstitialAdGoogle(){
		m_activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
			  
			}
		});
    }
	
	
	//startapp-------------------------------
	//show banner
	static void showBannerStartApp(){
		m_activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				if ( m_startAppBanner != null )
					m_startAppBanner.showBanner();			
			}
		});
	}
		
	//hide banner
	static void hideBannerStartApp(){
		m_activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				if ( m_startAppBanner != null )
					m_startAppBanner.hideBanner();
			}
		});
    }
	//show interstitialAd
	static void showInterstitialAdStartApp(){
		if ( m_startAppAd == null )
			return;
		
		m_activity.runOnUiThread(new Runnable() {
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
	
	
	//Revmob------------------------------------
	static void showBannerRevMob(){		
		if (m_revmob == null)
			return;
		m_activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {		
				m_revmobBanner = m_revmob.createBanner(m_activity, m_revmobListener);
				ViewGroup viewGroup = (ViewGroup) ((ViewGroup) m_activity.findViewById(android.R.id.content)).getChildAt(0);
				LinearLayout layout = new LinearLayout(m_activity);
				layout.setOrientation(LinearLayout.VERTICAL);			    
			    layout.setLayoutParams(new LayoutParams(LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT));
			    layout.addView(m_revmobBanner);			    
				viewGroup.addView(layout);
			}
		});
	}
	
	//hide banner
	static void hideBannerRevMob(){
		m_activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {				
				if ( m_revmobBanner != null )
					m_revmobBanner.hide();
			}
		});
    }
	//show interstitialAd	
	static void showInterstitialAdRevMob(){
		if (m_revmob == null)
			return;
		m_activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				m_revmobFullscreen = m_revmob.createFullscreen(m_activity, m_revmobListener);
				m_revmobFullscreen.load();
				m_revmobFullscreen.show();
			}
		});
    }

	
	/** Called when leaving the activity */
	@Override
	public void onPause() {
		m_startAppAd.onPause();
		super.onPause();
	}

	/** Called when returning to the activity */
	@Override
	public void onResume() {
		super.onResume();
		m_startAppAd.onResume();
	}

	/** Called before the activity is destroyed */
	@Override
	public void onDestroy() {		
		super.onDestroy();
	}
	
	/** Called before the activity is pressed back-key */
	@Override
	public void onBackPressed() {
		m_startAppAd.onBackPressed();
		super.onBackPressed();
	}
}
