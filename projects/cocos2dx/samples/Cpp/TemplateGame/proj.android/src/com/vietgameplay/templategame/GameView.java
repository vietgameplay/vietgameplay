/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org

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
package com.vietgameplay.templategame;

import org.cocos2dx.lib.Cocos2dxActivity;

import android.R;
import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup.LayoutParams;
import android.widget.LinearLayout;

import com.google.ads.AdRequest;
import com.google.ads.AdSize;
import com.google.ads.AdView;
public class GameView extends Cocos2dxActivity{
	static AdView adView;
	static Activity s_activity;
	final String ADMOB_ID="ca-app-pub-5018149921290913/9750329584";

	protected void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		s_activity = this;
		try 
		{
			LayoutParams adParams = new LayoutParams(LayoutParams.MATCH_PARENT,LayoutParams.MATCH_PARENT);
			adView = new AdView(this, AdSize.BANNER, ADMOB_ID);			
			AdRequest request = new AdRequest();
			adView.loadAd(request);
			adView.setGravity(Gravity.TOP|Gravity.CENTER);
			// Adding full screen container
			addContentView(adView, adParams);
		} 
		catch (Exception e) 
		{
			Log.d("", "error: " + e);
		}
	}
	
	static void showAdmobJNI()
	{
		s_activity.runOnUiThread( new Runnable() 
		{
			@Override
			public void run() 
			{
				adView.setVisibility(View.VISIBLE);
			}
		} );
	}
	
	static void hideAdmobJNI()
	{
		s_activity.runOnUiThread( new Runnable() 
		{
			@Override
			public void run() 
			{
				adView.setVisibility(View.INVISIBLE);
			}
		} );
    }	
	
    static {
         System.loadLibrary("vietgameplay");
    }
}
