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
package com.vietgameplay.tap2top;

import org.cocos2dx.lib.Cocos2dxActivity;






//google plus
import com.google.android.gms.common.ConnectionResult;
import com.google.android.gms.common.api.GoogleApiClient;
import com.google.android.gms.common.api.GoogleApiClient.ConnectionCallbacks;
import com.google.android.gms.common.api.GoogleApiClient.OnConnectionFailedListener;
import com.google.android.gms.games.Games;
import com.google.android.gms.plus.Plus;
import com.google.android.gms.plus.PlusShare;

import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentSender.SendIntentException;
import android.R;
import android.app.Activity;
import android.app.AlertDialog;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.net.Uri;
import android.os.Bundle;
import android.util.Log;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.view.ViewGroup.LayoutParams;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;

import com.google.android.gms.games.leaderboard.*;


public class AppActivity extends Cocos2dxActivity implements ConnectionCallbacks, OnConnectionFailedListener  {
	
	static Activity m_activity = null;
	public static AppActivity s_instance = null;
	
	//google plus
	private final int RC_SIGN_IN = 0;
	private final String LEADERBOARD_ID = "CgkIovKt98wEEAIQAA";
	private final int REQUEST_LEADERBOARD = 100;
	private GoogleApiClient m_googleApiClient;	
	private boolean m_intentInProgress;
	
	//show internet message
	private boolean isShowInternetMessage = false;
	
		
	protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);
		m_activity=this;
		s_instance = this;
		try {			
			//google plus------------------------------------
			 m_googleApiClient = new GoogleApiClient.Builder(m_activity)
	         .addConnectionCallbacks(this)
	         .addOnConnectionFailedListener(this)
	         .addApi(Plus.API)
	         .addScope(Plus.SCOPE_PLUS_LOGIN)
	         .build();
			
			
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

	static boolean sisGoogleConnected()
	{
		Log.d("Google plus", "Google plus ------sisGoogleConnected");
		return s_instance.isGoogleConnected();
	}	
	
	public boolean isGoogleConnected()
	{
		Log.d("Google plus", "Google plus ------isConnected:" + m_googleApiClient.isConnected());
		return m_googleApiClient.isConnected();
	}
	
	static void ssubmitScore(int score)
	{
		Log.d("Google plus", "Google plus ------ssubmitScore");
		s_instance.submitScore(score);
	}	
	
	public void submitScore(int score)
	{
		if (m_googleApiClient != null && m_googleApiClient.isConnected())
			Games.Leaderboards.submitScore(m_googleApiClient, LEADERBOARD_ID, (long)score);
		else
			logInGooglePlus();
	}
	
	static void sshowLeaderBoard()
	{
		Log.d("Google plus", "Google plus ------sshowLeaderBoard");
		s_instance.showLeaderBoard();
	}	
	
	public void showLeaderBoard()
	{
		Log.d("Google plus", "Google plus ------isConnected:" + m_googleApiClient.isConnected());
		if (m_googleApiClient != null && m_googleApiClient.isConnected())
			startActivityForResult(Games.Leaderboards.getLeaderboardIntent(m_googleApiClient, LEADERBOARD_ID), REQUEST_LEADERBOARD);
		else
			logInGooglePlus();
	}
	
	
	static void slogInGooglePlus()
	{
		Log.d("Google plus", "Google plus ------slogInGooglePlus");
		s_instance.logInGooglePlus();
	}	
	
	
	public void logInGooglePlus()
	{
		if (m_googleApiClient!= null )
			m_googleApiClient.connect();		
	}
	
	static void slogOutGooglePlus()
	{
		Log.d("Google Plus", "Google Plus -------slogOutGooglePlus");
		s_instance.logOutGooglePlus();
	}
	
	public void logOutGooglePlus()
	{		
		if (m_googleApiClient!= null && m_googleApiClient.isConnected()) {
			Plus.AccountApi.clearDefaultAccount(m_googleApiClient);
			Plus.AccountApi.revokeAccessAndDisconnect(m_googleApiClient);			
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
				if (m_googleApiClient!= null) {
					Intent shareIntent = new PlusShare.Builder(m_activity)
			        .setType("text/plain")
			        .setText(content)
			        .setContentUrl(Uri.parse(url))
			        .getIntent();		
					startActivityForResult(shareIntent, 0);
				}
			}
		});
			
	}
	
	
	//check connection
	public static boolean shasConnectivity()
    {		
        return s_instance.hasConnectivity();
    }
    public boolean hasConnectivity()
    {        
        try
        {
            if(m_activity != null)
            {                
                ConnectivityManager mConnectivityManager = (ConnectivityManager) m_activity.getSystemService(Context.CONNECTIVITY_SERVICE);
                if(mConnectivityManager == null)
                    return false;

                NetworkInfo mNetInfo = mConnectivityManager.getActiveNetworkInfo(); 
                
                if(mNetInfo == null)
                    return false;
                return mNetInfo.isConnected();
            }
        } catch(Exception ex){}
        
        return false;
    }
    
    
    //message show internet
    public static void sshowInternetRetry()
    {    		
		s_instance.showInternetRetry();
    }
    
    public void showInternetRetry()
    {
    	if( isShowInternetMessage )
    		return;
    	else
    		isShowInternetMessage = true;
    	Log.d("GAME", "----showInternetRetry");    
    	m_activity.runOnUiThread(new Runnable(){
			public void run(){		
		    	AlertDialog.Builder builder = new AlertDialog.Builder(m_activity);
		    	builder.setMessage("Internet is not available.");
		    	builder.setCancelable(true);
		    	builder.setPositiveButton("Retry", new DialogInterface.OnClickListener() {
		            public void onClick(DialogInterface dialog, int id) {
		            	isShowInternetMessage = false;
		                dialog.cancel();
		            }
		        });
		    	builder.setNegativeButton("Exit", new DialogInterface.OnClickListener() {
		            public void onClick(DialogInterface dialog, int id) {
		            	finish();
		                System.exit(0);
		            }
		        });
		
		        AlertDialog alert = builder.create();
		        alert.show();
			}
		});
		    
    }

	@Override
	public void onConnectionFailed(ConnectionResult arg0) {
		// TODO Auto-generated method stub
			if (!m_intentInProgress && arg0.hasResolution()) {
			    try {
			    	m_intentInProgress = true;
			    	startIntentSenderForResult(arg0.getResolution().getIntentSender(), RC_SIGN_IN, null, 0, 0, 0);
			    } catch (SendIntentException e) {		    
			    	m_intentInProgress = false;		    	
			    }
		  }
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
		//StartAppAds.sonBackPressed();
		super.onBackPressed();
	}
}
