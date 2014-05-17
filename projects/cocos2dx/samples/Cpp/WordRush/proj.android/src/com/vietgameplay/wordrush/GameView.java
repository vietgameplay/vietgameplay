/****************************************************************************
Copyright (c) 2010-2011 cocos2d-x.org

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
package com.vietgameplay.wordrush;

import io.openkit.OKAchievement;
import io.openkit.OKAchievementScore;
import io.openkit.OKLog;
import io.openkit.OKLoginActivity;
import io.openkit.OKLoginActivityHandler;
import io.openkit.OKScore;
import io.openkit.OKUser;
import io.openkit.OpenKit;
import io.openkit.leaderboards.OKLeaderboardsActivity;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.cocos2dx.lib.Cocos2dxGLSurfaceView;

import android.app.Activity;
import android.content.Intent;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.PackageManager.NameNotFoundException;
import android.content.pm.Signature;
import android.net.Uri;
import android.os.Bundle;
import android.util.Base64;
import android.util.Log;
import android.view.Gravity;
import android.view.View;
import android.widget.Toast;
import android.widget.FrameLayout.LayoutParams;

import com.google.ads.AdRequest;
import com.google.ads.AdSize;
import com.google.ads.AdView;
public class GameView extends Cocos2dxActivity{
	static AdView adView;
	static Activity me;
	final String ADMOB_ID="a1537091a546250";
	
    protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);	
		me=this;
		try {
			LayoutParams adParams = new LayoutParams(LayoutParams.MATCH_PARENT,LayoutParams.MATCH_PARENT);
			adView = new AdView(this, AdSize.BANNER, ADMOB_ID);			
			AdRequest request = new AdRequest();
			adView.loadAd(request);
			adView.setGravity(Gravity.TOP|Gravity.CENTER);
			addContentView(adView, adParams);
		} catch (Exception e) {
			Log.d("", "error: " + e);
		}
		try {
	        PackageInfo info = getPackageManager().getPackageInfo("com.vietgameplay.wordrush", PackageManager.GET_SIGNATURES);
	        for (Signature signature : info.signatures) {
	            MessageDigest md = MessageDigest.getInstance("SHA");
	            md.update(signature.toByteArray());
	            //System.out.print("AAAAAAAAAAAAAAAAAAAAAAAAKeyHash:" + Base64.encodeToString(md.digest(), Base64.DEFAULT));

	        }
	    } catch (NameNotFoundException e) {
	    } catch (NoSuchAlgorithmException e) {
	    }
	    String myAppKey = "dpmwMT0XYF16ufHUVWyR";
	    String mySecretKey = "agrzdqNCYeLl0upuKdG61bzZSUSFfXqZ4iBhPcSQ";
	    OpenKit.configure(this, myAppKey, mySecretKey);
	}
	static void showLogin() {
		if (OKUser.getCurrentUser() == null) {
			OKLoginActivity.setActivityHandler(new OKLoginActivityHandler() {
				@Override
				public void onLoginDialogComplete() {
					OKLog.v("Finished showing the OpenKit login dialog");
				}
			});

			Intent launchOKLogin = new Intent(me, OKLoginActivity.class);
			me.startActivity(launchOKLogin);
		}
	}
	static void showAdmob(){
		me.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				adView.setVisibility(View.VISIBLE);
			}
		});
	}
	
	static void hideAdmob(){
		me.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				adView.setVisibility(View.INVISIBLE);
			}
		});
    }	
		static void showLeaderBoard(){
		me.runOnUiThread(new Runnable() {
			@Override
			public void run() {
			    showLogin();
				Intent launchOKLeaderboards = new Intent(me, OKLeaderboardsActivity.class);
				me.startActivityForResult(launchOKLeaderboards, 0);
			}
		});
	}
	public static native int  stringFromJNI();
	static void saveLeaderBoard(){
		me.runOnUiThread(new Runnable() {
			@Override
			public void run() {
			    showLogin();
				String value = stringFromJNI() + "";

				//Create the score, set it's score value, and set the leaderboard ID which is passed in as a parameter
				OKScore okscore = new OKScore();
				okscore.setScoreValue(Long.parseLong(value));

				//Set the metadata to 1 + the score value
				okscore.setMetadata((int)okscore.getScoreValue() + 1);
				//Set the display string to include the unit "OpenKit Points"
				okscore.setDisplayString("Score: " + okscore.getScoreValue());
				int leaderboardID = 2513;
				okscore.setOKLeaderboardID(leaderboardID );
				submitScore(okscore);
			}
		});
    }
	
	static void submitScore(final OKScore scoreToSubmit)
	{
		scoreToSubmit.submitScore(new OKScore.ScoreRequestResponseHandler() {

			@Override
			public void onSuccess() {
				//Toast.makeText(me, "Submitted score successfully: " + scoreToSubmit.getScoreValue(), Toast.LENGTH_SHORT).show();
			}

			@Override
			public void onFailure(Throwable error) {
				//Toast.makeText(me, "Can't to submit score!", Toast.LENGTH_LONG).show();
			}
		});
	}
	static void showAchievement()
	{
		me.runOnUiThread(new Runnable() {
			@Override
			public void run() {
			    showLogin();
			    Intent launchAchievementsIntent = OKAchievement.getAchievementsIntent(me);
			    me.startActivity(launchAchievementsIntent);
			}
		});
	}
	static void saveAchievement()
	{
		me.runOnUiThread(new Runnable() {
			@Override
			public void run() {
			    showLogin();
				OKAchievementScore achievementScore = new OKAchievementScore();
		        achievementScore.setProgress(9);
		        achievementScore.setOKAchievementId(647);//Copper
		        achievementScore.submitAchievementScore(new OKAchievementScore.AchievementScoreRequestResponseHandler() {
		            @Override
		            public void onSuccess() {
		                Log.i("OpenKit","Submitted an achievement score!");
		            }
		
		            @Override
		            public void onFailure(Throwable error) {
		                Log.i("OpenKit","Failed to submit achievement score.");
		            }
		        });
			}
		});
	}
    public Cocos2dxGLSurfaceView onCreateView() {
    	Cocos2dxGLSurfaceView glSurfaceView = new Cocos2dxGLSurfaceView(this);
    	// Word Rush should create stencil buffer
    	glSurfaceView.setEGLConfigChooser(5, 6, 5, 0, 16, 8);
    	
    	return glSurfaceView;
    }
    static void rateGame() {
  	  Intent intent = new Intent(Intent.ACTION_VIEW);
  	  intent.setData(Uri.parse("https://play.google.com/store/apps/details?id=com.vietgameplay.wordrush"));
  	  me.startActivity(intent);
  	}
  
    static {
        System.loadLibrary("wordrush");
    }     
}
