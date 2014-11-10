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
import android.view.ViewGroup.LayoutParams;
import android.widget.LinearLayout;
//google
import com.google.ads.AdRequest;
import com.google.ads.AdSize;
import com.google.ads.AdView;
//start app
import com.startapp.android.publish.StartAppAd;
import com.startapp.android.publish.AdDisplayListener;
import com.startapp.android.publish.AdEventListener;
import com.startapp.android.publish.Ad;
public class AppActivity extends Cocos2dxActivity {
	
	static Activity m_activity;
	
	//google
	static AdView m_adView;
	
	//start app
	static StartAppAd m_startAppAd;
	
	final static String GGP_ADMOB_ID="ca-app-pub-5629660628975902/1330315079";	
	final static String STARTAPP_DEV_ID="110088576";	
	final static String STARTAPP_APP_ID="210163514";	
	
	protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);
		m_activity=this;
			
		try {
			//google banner
			LayoutParams adParams = new LayoutParams(LayoutParams.MATCH_PARENT,LayoutParams.MATCH_PARENT);
			AdRequest request = new AdRequest();
			
			m_adView = new AdView(this, AdSize.SMART_BANNER, GGP_ADMOB_ID);					
			m_adView.loadAd(request);
						
			m_adView.setGravity(Gravity.TOP|Gravity.LEFT);			
			// Adding full screen container
			addContentView(m_adView, adParams);		

			//start app
			StartAppAd.init(this, STARTAPP_DEV_ID, STARTAPP_APP_ID);
			m_startAppAd = new StartAppAd(this);	
			
		} catch (Exception e) {
			Log.d("ndtai", "error: " + e);
		}			
	}
	
	//show banner
	static void showBannerGoogle(){
		m_activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				m_adView.setVisibility(View.VISIBLE);				
			}
		});
	}
	
	//hide banner
	static void hideBannerGoogle(){
		m_activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				m_adView.setVisibility(View.INVISIBLE);
			}
		});
    }
	
	//show interstitialAd
	static void showInterstitialAdStartApp(){
		try{
				
			// show the ad
			m_startAppAd.showAd(new AdDisplayListener() {
				@Override
				public void adHidden(Ad ad) {
					Log.d("ndtai", "-------------------------adHidden------------------");				
				}
				@Override
				public void adDisplayed(Ad ad) {
					Log.d("ndtai", "-------------------------adDisplayed------------------");				
				}
				@Override
				public void adClicked(Ad ad) {
					Log.d("ndtai", "-------------------------adClicked------------------");				
				}
			}); 
			
			//load ad
			m_startAppAd.loadAd (new AdEventListener() {
				@Override
				public void onReceiveAd(Ad ad) {
					Log.d("ndtai", "-------------------------onReceiveAd------------------");				
				}
				@Override
				public void onFailedToReceiveAd(Ad ad) {
					Log.d("ndtai", "-------------------------onFailedToReceiveAd------------------");				
				}
			}); 
		}
		catch(Exception e ){
			Log.d("ndtai", "error: " + e);
		}
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
