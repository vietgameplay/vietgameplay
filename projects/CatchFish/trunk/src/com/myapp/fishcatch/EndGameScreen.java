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
import android.graphics.Rect;
import android.graphics.PorterDuff.Mode;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.Window;
import android.view.ViewGroup.LayoutParams;

public class EndGameScreen extends Activity implements SurfaceHolder.Callback {

	// TODO Declare variable
	private static final String TAG = "DEBUG";
	SurfaceView view;
	
	Handler handlerDrawing;
	Runnable runnableDrawing;
	
	Bitmap background;
	Bitmap endGameBMP;
	Bitmap gameOverBMP;
	Bitmap labelBML;
	Bitmap virtualKeyboardBMP;
	
	Rect srcRectBackground;
	Rect desRectBackground;
	
	Intent intentMainMenu;
	
	String data[];
	
	int pos = -1;
	boolean getName;
	boolean gameOver;
	boolean isVirtualKeyboard;
	
	/* ------------------------------------------------------------------------------- Create Instance */
	
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
		Intent intent = getIntent();
		String data = intent.getExtras().getString("ENDGAME");
		if (data.substring(0, 4).equals("OVER"))
			gameOver = true;
		else
			gameOver = false;
		
		int score = Integer.parseInt(data.substring(4, data.length()));
		
		getName = readScore(score);
		
		isVirtualKeyboard = false;
		
		// TODO Initialize bitmap
		BitmapFactory.Options opts = new BitmapFactory.Options(); 
        opts.inPurgeable = true;
        background = BitmapFactory.decodeResource(getResources(), R.drawable.aboutbg, opts);
		
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

	/* ------------------------------------------------------------------------------- Running Areas */
	
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
		        	
		        	// TODO Draw background
		        	drawBackground(canvas);
		        	
		        	if (gameOver)
		        		drawGameOver(canvas);
		        	else
		        		drawEndGame(canvas);
		        	
		        	if (getName)
		        	{
		        		drawLabel(canvas);
		        		drawVirtualKeyboard(canvas);
		        	}
		        	
		        	holder.unlockCanvasAndPost(canvas);
		        }
			}
    	};
    	handlerDrawing.postDelayed(runnableDrawing, 100);
	}

	/* ------------------------------------------------------------------------------- Draw Areas */
	
	private void drawBackground(Canvas canvas)
	{
		// TODO Draw background
		canvas.save();
		canvas.drawBitmap(background, srcRectBackground, desRectBackground, null);
		canvas.restore();
	}

	private void drawGameOver(Canvas canvas)
	{
		canvas.save();
		canvas.drawBitmap(background, srcRectBackground, desRectBackground, null);
		canvas.restore();
	}
	
	private void drawEndGame(Canvas canvas)
	{
		canvas.save();
		canvas.drawBitmap(background, srcRectBackground, desRectBackground, null);
		canvas.restore();
	}
	
	private void drawLabel(Canvas canvas)
	{
		canvas.save();
		canvas.drawBitmap(background, srcRectBackground, desRectBackground, null);
		canvas.restore();
	}
	
	private void drawVirtualKeyboard(Canvas canvas)
	{
		canvas.save();
		canvas.drawBitmap(background, srcRectBackground, desRectBackground, null);
		canvas.restore();
	}
	
	/* ------------------------------------------------------------------------------- Functions */
	
	private boolean readScore(int score)
	{
		data = new String[5];
		String lineData = null;
		BufferedReader br;
		boolean result = false;
		try
	    {
	    	InputStream is = getApplicationContext().getResources().openRawResource(R.raw.highscore);
			br = new BufferedReader(new InputStreamReader(is), 8192);
			int i = 0;
			while((lineData = br.readLine()) != null)
			{
				data[i] = "" + lineData + "\n";
				if (pos == -1)
				{
					StringTokenizer lineToken = new StringTokenizer(lineData," ");
					lineToken.nextToken();
					String scoreStr = lineToken.nextToken();
					if (score > Integer.parseInt(scoreStr))
					{
						pos = i;
						result = true;
					}
				}
				i++;
			}
	    }
	    catch (Exception e) 
	    {       
	        e.printStackTrace();          
	    }
		if (result)
			return true;
		else
			return false;
	}
	
	private void writeScore(String name)
	{
		
	}
	
	/* ------------------------------------------------------------------------------- Input */
	
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
	public void onBackPressed() 
	{
		// TODO When press back button
		handlerDrawing.removeCallbacks(runnableDrawing);
		startActivity(intentMainMenu);
		finish();
		super.onBackPressed();
	}
}
