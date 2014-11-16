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

//google plus
import com.google.android.gms.common.ConnectionResult;
import com.google.android.gms.common.api.GoogleApiClient;
import com.google.android.gms.common.api.GoogleApiClient.ConnectionCallbacks;
import com.google.android.gms.common.api.GoogleApiClient.OnConnectionFailedListener;
import com.google.android.gms.games.Games;
import com.google.android.gms.plus.Plus;
import com.google.android.gms.plus.PlusShare;
import android.content.Intent;
import android.content.IntentSender.SendIntentException;

import android.R;
import android.app.Activity;

import android.net.Uri;
import android.os.Bundle;
import android.util.Log;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.view.ViewGroup.LayoutParams;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;


public class AppActivity extends Cocos2dxActivity implements ConnectionCallbacks, OnConnectionFailedListener  {
	
	static Activity m_activity = null;
	public static AppActivity s_instance = null;
	
	//google plus
	private final int RC_SIGN_IN = 0;
	private final String LEADERBOARD_ID = "leaderboard_taptap";
	private GoogleApiClient m_googleApiClient;	
	private boolean m_intentInProgress;
		
	protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);
		m_activity=this;
		s_instance = this;
		try {			
			//google plus------------------------------------
			logInGooglePlus();
			
			
			//google banner-------------------------------------------------------------------
			GoogleAds.s_activity = this;
			GoogleAds.sinit();
		    		    
			
		    //start app---------------------------------------------------------------------
			StartAppAds.s_activity = this;
			StartAppAds.sinit();	
			
			//revmob-----------------------------------------------------------------------
			RevmobAds.s_activity = this;
			RevmobAds.sinit();
			
			
		} catch (Exception e) {
			Log.d("Ads", "Revmob -------error: " + e);
		}			
	}
	
	static void slogInGooglePlus()
	{
		Log.d("Google plus", "Google plus ------slogInGooglePlus");
		s_instance.logInGooglePlus();
	}
	
	public void logInGooglePlus()
	{
		m_googleApiClient = new GoogleApiClient.Builder(m_activity)
        .addConnectionCallbacks(this)
        .addOnConnectionFailedListener(this)
        .addApi(Plus.API)
        .addScope(Plus.SCOPE_PLUS_LOGIN)
        .build();
	}
	
	static void slogOutGooglePlus()
	{
		Log.d("Google Plus", "Google Plus -------slogOutGooglePlus");
		s_instance.logOutGooglePlus();
	}
	
	public void logOutGooglePlus()
	{		
		if (m_googleApiClient.isConnected()) {
			Plus.AccountApi.clearDefaultAccount(m_googleApiClient);
			Plus.AccountApi.revokeAccessAndDisconnect(m_googleApiClient);
			//m_googleApiClient = build_GoogleApiClient();
			m_googleApiClient.connect();
		}		
	}
	
	static void spostOnWallGooglePlus(final String title, final String url)
	{
		Log.d("Google Plus", "Google Plus -------post on wall GooglePlus");
		s_instance.postOnWallGooglePlus(title, url);
	}
	
	public void postOnWallGooglePlus(final String content, final String url)
	{
		m_activity.runOnUiThread(new Runnable(){
			public void run(){				
				Intent shareIntent = new PlusShare.Builder(m_activity)
		        .setType("text/plain")
		        .setText(content)
		        .setContentUrl(Uri.parse(url))
		        .getIntent();
		
				startActivityForResult(shareIntent, 0);
			}
		});
			
	}
	
	protected void onStart() {
		 super.onStart();
		 if ( m_googleApiClient!= null )
			 m_googleApiClient.connect();
	}
	
	protected void onStop() {
		super.onStop();
		
		if (m_googleApiClient != null && m_googleApiClient.isConnected()) {
			m_googleApiClient.disconnect();
		}
		
	}

	/** Called when leaving the activity */
	@Override
	public void onPause() {
		StartAppAds.sonPause();
		super.onPause();
	}

	/** Called when returning to the activity */
	@Override
	public void onResume() {
		super.onResume();
		StartAppAds.sonResume();
	}

	/** Called before the activity is destroyed */
	@Override
	public void onDestroy() {		
		super.onDestroy();
	}
	
	/** Called before the activity is pressed back-key */
	@Override
	public void onBackPressed() {
		StartAppAds.sonBackPressed();
		super.onBackPressed();
	}
	@Override
	public void onConnected(Bundle arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void onConnectionSuspended(int arg0) {
		// TODO Auto-generated method stub
		m_googleApiClient.connect();
		
	}
	
	protected void onActivityResult(int requestCode, int responseCode, Intent intent) {
		if (requestCode == RC_SIGN_IN) {
			m_intentInProgress = false;
	
			if (!m_googleApiClient.isConnecting()) {
				m_googleApiClient.connect();
			}
		}
	}
	@Override
	public void onConnectionFailed(ConnectionResult arg0) {
		// TODO Auto-generated method stub
		if (!m_intentInProgress && arg0.hasResolution()) {
		    try {
		    	m_intentInProgress = true;
		    	startIntentSenderForResult(arg0.getResolution().getIntentSender(), RC_SIGN_IN, null, 0, 0, 0);
		    } catch (SendIntentException e) {
		      // The intent was canceled before it was sent.  Return to the default
		      // state and attempt to connect to get an updated ConnectionResult.
		    	m_intentInProgress = false;
		    	m_googleApiClient.connect();
		    }
		  }
	}
	
}
