package com.myapp.fishcatch;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.pm.ActivityInfo;
import android.content.res.Configuration;
import android.os.Bundle;
import android.os.Handler;
import android.view.Display;
import android.view.Window;
import android.view.WindowManager;
import android.widget.ImageView;

public class SplashScreen extends Activity {

	private ImageView splash;
	Display display;
	static int scrWidth = 1;
	static int scrHeight = 1;
	Intent intent;
	
	// TODO Set screen to landscape when rotate screen
	@Override
	public void onConfigurationChanged(Configuration newConfig) {
	    super.onConfigurationChanged(newConfig);
	    setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE);
	}
		
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		this.setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE);
		this.requestWindowFeature(Window.FEATURE_NO_TITLE);
		setContentView(R.layout.splash_screen);
		
		// TODO get screen width and screen height and save in Resource Manager
		Display display =  ((WindowManager) getSystemService(Context.WINDOW_SERVICE)).getDefaultDisplay();
		scrWidth = display.getWidth();
		scrHeight = display.getHeight();
		
		// TODO set image view
		splash = (ImageView)findViewById(R.id.imgSplash);
		splash.setImageResource(R.drawable.logo);
		splash.setMaxWidth(scrWidth);
		splash.setMaxHeight(scrHeight);
		splash.getLayoutParams().width = 8*(scrWidth/10);
		splash.getLayoutParams().height = 2*(scrHeight/5);
		
		intent = new Intent(this, MainMenuScreen.class);
		
		final Handler handler = new Handler();
		Runnable runnable = new Runnable()
		{
			int count = 1;
			public void run()
			{
				// TODO set effect of image
				splash.setAlpha(count);
				count+=3;
				if (count < 250)
					handler.postDelayed(this, 1);
				if (count == 250)
				{
					// TODO go to main menu
					startActivity(intent);
					finish();
				}
			}
		};
		handler.postDelayed(runnable, 1);
	}

}
