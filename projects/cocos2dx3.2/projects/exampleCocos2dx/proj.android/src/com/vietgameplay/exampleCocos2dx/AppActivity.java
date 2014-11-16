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


public class AppActivity extends Cocos2dxActivity {
	
	static Activity m_activity = null;
		
	protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);
		m_activity=this;
			
		try {			
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
}
