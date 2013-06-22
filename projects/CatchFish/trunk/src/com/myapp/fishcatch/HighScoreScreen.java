package com.myapp.fishcatch;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import android.app.Activity;
import android.content.Intent;
import android.content.pm.ActivityInfo;
import android.content.res.Configuration;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Rect;
import android.graphics.Paint.Style;
import android.graphics.PorterDuff.Mode;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.Window;
import android.view.ViewGroup.LayoutParams;

public class HighScoreScreen extends Activity implements SurfaceHolder.Callback {

	// TODO Declare variable
	private static final String TAG = "DEBUG";
	SurfaceView view;
	
	Handler handlerDrawing;
	Runnable runnableDrawing;
	
	Bitmap background;
	
	Rect srcRectBackground;
	Rect desRectBackground;
	
	String highScore[];
	
	Intent intentMainMenu;
	
	// TODO Set screen to landscape when rotate screen
	@Override
	public void onConfigurationChanged(Configuration newConfig) {
	    super.onConfigurationChanged(newConfig);
	    setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE);
	}
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		this.setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE);
		this.requestWindowFeature(Window.FEATURE_NO_TITLE);
		super.onCreate(savedInstanceState);
		
		intentMainMenu = new Intent(getApplicationContext(),MainMenuScreen.class);
		
		highScore = new String[5];
		getHighScore();
		
		// TODO Initialize bitmap
		BitmapFactory.Options opts = new BitmapFactory.Options(); 
        opts.inPurgeable = true;
		background = BitmapFactory.decodeResource(getResources(), R.drawable.background, opts);
        
		// TODO Initialize source and destination rectangle
		srcRectBackground = new Rect(0, 0, background.getWidth(), background.getHeight());
		desRectBackground = new Rect(0, 0, SplashScreen.scrWidth, SplashScreen.scrHeight);
		
		// TODO Initialize surfaceview
		view = new SurfaceView(this);
		view.setLayoutParams(new LayoutParams(SplashScreen.scrHeight,SplashScreen.scrWidth));
        setContentView(view);
        view.getHolder().addCallback(this);
	}
	
	public void surfaceChanged(SurfaceHolder holder, int format, int width,
			int height) {
		// TODO Auto-generated method stub
		
	}

	public void surfaceCreated(SurfaceHolder holder) {
		// TODO Auto-generated method stub
		tryDrawing(holder);
	}

	public void surfaceDestroyed(SurfaceHolder holder) {
		// TODO Auto-generated method stub
		
	}
	
	private void getHighScore()
	{
		String lineData = null;
		BufferedReader br;
		try
	    {
	    	InputStream is = openFileInput("highscore.txt");
			br = new BufferedReader(new InputStreamReader(is), 8192);
			int i = 0;
			while((lineData = br.readLine()) != null)
			{
				highScore[i] = "" + lineData + "\n";
				i++;
			}
	    }
	    catch (Exception e) 
	    {       
	    	for (int i = 0; i < 5; i++)
				highScore[i] = "No Data";
	        e.printStackTrace();          
	    }
		
		for (int i = 0; i < 5; i++)
		{
			if (highScore[i] == "" || highScore[i] == null)
				highScore[i] = "No Data";
		}
	}
	
	private void tryDrawing(final SurfaceHolder holder) {
		handlerDrawing = new Handler();
    	runnableDrawing = new Runnable() {
			public void run() {
				// TODO Auto-generated method stub
				handlerDrawing.postDelayed(this, 100);

				Canvas canvas = holder.lockCanvas();
		        if (canvas == null) {
		            Log.e(TAG, "Cannot draw onto the canvas as it's null");
		        } 
		        else 
		        {
		        	// TODO Clear screen
		        	canvas.drawColor(0, Mode.CLEAR);
		        	
		        	// TODO Draw
		        	drawBackground(canvas);
		        	
		        	drawHighScore(canvas);
		        	
		        	holder.unlockCanvasAndPost(canvas);
		        }
			}
    	};
    	handlerDrawing.postDelayed(runnableDrawing, 100);
	}
	
	private void drawBackground(Canvas canvas)
	{
		// TODO Draw background
		canvas.save();
		canvas.drawBitmap(background, srcRectBackground, desRectBackground, null);
		canvas.restore();
	}

	private void drawHighScore(Canvas canvas)
	{
		Paint painttext = new Paint();
		painttext.setColor(Color.BLACK);
		painttext.setStyle(Style.FILL_AND_STROKE);
		painttext.setStrokeWidth(1.5f);
		painttext.setTextSize(view.getHeight()/24);
		
		canvas.save();
		for (int i = 0; i < 5; i++)
			canvas.drawText(highScore[i], 2*view.getWidth()/5,  view.getHeight()/3 + i*view.getHeight()/16 , painttext);
		canvas.restore();
	}
	
	@Override
	public boolean onTouchEvent(MotionEvent event) {
		// TODO Get touch position
		if (event.getAction() == MotionEvent.ACTION_DOWN)
		{
		}
		return super.onTouchEvent(event);
	}
	
	@Override
	protected void onPause() {
		// TODO Auto-generated method stub
		Log.e(TAG, "on pause");
		handlerDrawing.removeCallbacks(runnableDrawing);
		finish();
		super.onPause();
	}
	
	@Override
	public void onBackPressed() {
		// TODO When press back button
		handlerDrawing.removeCallbacks(runnableDrawing);
		startActivity(intentMainMenu);
		finish();
		super.onBackPressed();
	}
}
