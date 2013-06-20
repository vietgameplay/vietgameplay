package com.myapp.fishcatch;

import java.io.IOException;

import android.app.Activity;
import android.content.Intent;
import android.content.pm.ActivityInfo;
import android.content.res.Configuration;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Paint.Style;
import android.graphics.PorterDuff.Mode;
import android.graphics.Rect;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.ViewGroup.LayoutParams;
import android.view.Window;

public class MainMenuScreen extends Activity implements SurfaceHolder.Callback {
	
	// TODO Declare variable
	private static final String TAG = "DEBUG";
	SurfaceView view;
	
	Handler handlerDrawingMain;
	Runnable runnableDrawingMain;
	
	Bitmap mainMenuBackground;
	Bitmap playGameBMP;
	Bitmap playGameSelectedBMP;
	Bitmap soundOnBMP;
	Bitmap soundOffBMP;
	Bitmap highScoreBMP;
	Bitmap highScoreSelectedBMP;
	Bitmap helpBMP;
	Bitmap helpSelectedBMP;
	Bitmap aboutBMP;
	Bitmap aboutSelectedBMP;
	
	Rect srcRectBackground;
	Rect desRectBackground;
	Rect srcRectPlay;
	Rect desRectPlay;
	Rect srcRectSound;
	Rect desRectSound;
	Rect srcRectAbout;
	Rect desRectAbout;
	Rect srcRectHelp;
	Rect desRectHelp;
	Rect srcRectHighScore;
	Rect desRectHighScore;
	
	boolean btnPlaySelect;
	boolean btnHighScoreSelect;
	boolean btnHelpSelect;
	boolean btnAboutSelect;
	static boolean soundOn;
	int playRectLeft;
	int playRectRight;
	int playRectTop;
	int playRectBottom;
	int soundRectLeft;
	int soundRectRight;
	int soundRectTop;
	int soundRectBottom;
	int helpRectLeft;
	int helpRectRight;
	int helpRectTop;
	int helpRectBottom;
	int aboutRectLeft;
	int aboutRectRight;
	int aboutRectTop;
	int aboutRectBottom;
	int highScoreRectLeft;
	int highScoreRectRight;
	int highScoreRectTop;
	int highScoreRectBottom;
	int count = 0;
	
	Intent intentPlayScreen;
	Intent intentHighScoreScreen;
	Intent intentHelpScreen;
	Intent intentAboutScreen;
	
	MediaPlayer mediaPlayer_changesound;
	MediaPlayer mediaPlayer_soundbackground;
	MediaPlayer mediaPlayer_soundbutton;
	
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
		
		mediaPlayer_changesound = MediaPlayer.create(this, R.raw.change_sound);
		mediaPlayer_soundbackground = MediaPlayer.create(this, R.raw.sound_background);
		mediaPlayer_soundbutton = MediaPlayer.create(this, R.raw.sound_play);
		
		// TODO Initialize variable
		btnPlaySelect = false;
		btnHighScoreSelect = false;
		btnHelpSelect = false;
		btnAboutSelect = false;
		soundOn = true;
		
		// TODO Initialize bitmap
		BitmapFactory.Options opts = new BitmapFactory.Options(); 
        opts.inPurgeable = true;
        mainMenuBackground = BitmapFactory.decodeResource(getResources(), R.drawable.background, opts);
		//mainMenuBackground = BitmapFactory.decodeResource(getResources(), R.drawable.background);
		playGameBMP = BitmapFactory.decodeResource(getResources(), R.drawable.ic_play);
		playGameSelectedBMP = BitmapFactory.decodeResource(getResources(), R.drawable.ic_play1);
		soundOnBMP = BitmapFactory.decodeResource(getResources(), R.drawable.soundon);
		soundOffBMP = BitmapFactory.decodeResource(getResources(), R.drawable.soundoff);
		helpBMP = BitmapFactory.decodeResource(getResources(), R.drawable.ic_help);
		helpSelectedBMP = BitmapFactory.decodeResource(getResources(), R.drawable.ic_help1);
		highScoreBMP = BitmapFactory.decodeResource(getResources(), R.drawable.ic_highscore);
		highScoreSelectedBMP = BitmapFactory.decodeResource(getResources(), R.drawable.ic_highscore1);
		aboutBMP = BitmapFactory.decodeResource(getResources(), R.drawable.ic_about);
		aboutSelectedBMP = BitmapFactory.decodeResource(getResources(), R.drawable.ic_about1);
				
		// TODO Declare rectangle dimension
		playRectLeft = (int)(2*SplashScreen.scrWidth/5);
		playRectTop = (int)(SplashScreen.scrHeight/6);
		playRectRight = (int)(3*SplashScreen.scrWidth/5);
		playRectBottom = (int)(2*SplashScreen.scrHeight/6);
		
		soundRectLeft = (int)(13.5*SplashScreen.scrWidth/15);
		soundRectTop = (int)(SplashScreen.scrHeight/20);
		soundRectRight = (int)(14.5*SplashScreen.scrWidth/15);
		soundRectBottom = (int)(3*SplashScreen.scrHeight/20);
		
		highScoreRectLeft = (int)(SplashScreen.scrWidth/4);
		highScoreRectTop = (int)(2*SplashScreen.scrHeight/6);
		highScoreRectRight = (int)(3*SplashScreen.scrWidth/4);
		highScoreRectBottom = (int)(SplashScreen.scrHeight/2);
		
		helpRectLeft = (int)(2*SplashScreen.scrWidth/5);
		helpRectTop = (int)(SplashScreen.scrHeight/2);
		helpRectRight = (int)(3*SplashScreen.scrWidth/5);
		helpRectBottom = (int)(4*SplashScreen.scrHeight/6);
		
		aboutRectLeft = (int)(2*SplashScreen.scrWidth/5);
		aboutRectTop = (int)(4*SplashScreen.scrHeight/6);
		aboutRectRight = (int)(3*SplashScreen.scrWidth/5);
		aboutRectBottom = (int)(5*SplashScreen.scrHeight/6);
		
		// TODO Initialize source and destination rectangle
		srcRectBackground = new Rect(0, 0, mainMenuBackground.getWidth(), mainMenuBackground.getHeight());
		desRectBackground = new Rect(0, 0, SplashScreen.scrWidth, SplashScreen.scrHeight);
		srcRectPlay = new Rect(0, 0, playGameBMP.getWidth(), playGameBMP.getHeight());
		desRectPlay = new Rect(playRectLeft, playRectTop, playRectRight, playRectBottom);
		srcRectSound = new Rect(0, 0, soundOnBMP.getWidth(), soundOnBMP.getHeight());
		desRectSound = new Rect(soundRectLeft, soundRectTop, soundRectRight, soundRectBottom);
		srcRectHelp = new Rect(0, 0, helpBMP.getWidth(), helpBMP.getHeight());
		desRectHelp = new Rect(helpRectLeft, helpRectTop, helpRectRight, helpRectBottom);
		srcRectHighScore = new Rect(0, 0, highScoreBMP.getWidth(), highScoreBMP.getHeight());
		desRectHighScore = new Rect(highScoreRectLeft, highScoreRectTop, highScoreRectRight, highScoreRectBottom);
		srcRectAbout = new Rect(0, 0, aboutBMP.getWidth(), aboutBMP.getHeight());
		desRectAbout = new Rect(aboutRectLeft, aboutRectTop, aboutRectRight, aboutRectBottom);

		intentPlayScreen= new Intent(this, PlayScreen.class);
		intentHighScoreScreen= new Intent(this, HighScoreScreen.class);
		intentHelpScreen= new Intent(this, HelpScreen.class);
		intentAboutScreen= new Intent(this, AboutScreen.class);
		
		// TODO Initialize surfaceview
		view = new SurfaceView(this);
		view.setLayoutParams(new LayoutParams(SplashScreen.scrHeight,SplashScreen.scrWidth));
        setContentView(view);
        view.getHolder().addCallback(this);
		
        mediaPlayer_soundbackground.setLooping(true);
	    mediaPlayer_soundbackground.start();
	}
	
	public void surfaceCreated(SurfaceHolder holder) {
        tryDrawing(holder);
    }

    public void surfaceChanged(SurfaceHolder holder, int frmt, int w, int h) {
    }

    public void surfaceDestroyed(SurfaceHolder holder) {

    }

    /* ------------------------------------------------------------------------------- Running Areas */
    
    private void tryDrawing(final SurfaceHolder holder) {
		// TODO Drawing
    	handlerDrawingMain = new Handler();
    	runnableDrawingMain = new Runnable() {
			public void run() {
				// TODO Auto-generated method stub
				handlerDrawingMain.postDelayed(this, 100);

				Canvas canvas = holder.lockCanvas();
		        if (canvas == null) {
		            Log.e(TAG, "Cannot draw onto the canvas as it's null");
		        } 
		        else 
		        {
		        	// TODO Clear screen
		        	canvas.drawColor(0, Mode.CLEAR);
		        	
		        	// TODO Draw main menu background
		        	drawBackground(canvas);
		        	
		        	// TODO Draw play game button
		        	drawButton(canvas);
		        	
		        	// TODO Draw sound on/off button
		        	drawSoundButton(canvas);
		        	
		        	// TODO Draw version of game		        	
		        	drawVersion(canvas);
		        	
		        	if (btnPlaySelect)
		        	{
		        		btnPlaySelect = false;
		        		handlerDrawingMain.postDelayed(this, 1000);
		        		nextState(intentPlayScreen);
		        	}
		        	else if (btnHighScoreSelect)
		        	{
		        		btnHighScoreSelect = false;
		        		handlerDrawingMain.postDelayed(this, 1000);
		        		nextState(intentHighScoreScreen);
		        	}
		        	else if (btnHelpSelect)
		        	{
		        		btnHelpSelect = false;
		        		handlerDrawingMain.postDelayed(this, 1000);
		        		nextState(intentHelpScreen);
		        	}
		        	else if (btnAboutSelect)
		        	{
		        		btnAboutSelect = false;
		        		handlerDrawingMain.postDelayed(this, 1000);
		        		nextState(intentAboutScreen);
		        	}
		        	
		            holder.unlockCanvasAndPost(canvas);
		        }
				
		        Log.d(TAG,"count "+count);
			}
		};
		handlerDrawingMain.postDelayed(runnableDrawingMain, 100);
    }
	
    /* ------------------------------------------------------------------------------- Draw Areas */
    
	public void drawBackground(Canvas canvas)
	{
		// TODO Draw main menu background
		canvas.save();
		canvas.drawBitmap(mainMenuBackground, srcRectBackground, desRectBackground, null);
		canvas.restore();
		
	}
	
	public void drawButton(Canvas canvas)
	{
		// TODO Draw play game button
		canvas.save();
		if (!btnPlaySelect)
			canvas.drawBitmap(playGameBMP, srcRectPlay, desRectPlay, null);
		else
			canvas.drawBitmap(playGameSelectedBMP, srcRectPlay, desRectPlay, null);
		if (!btnHighScoreSelect)
			canvas.drawBitmap(highScoreBMP, srcRectHighScore, desRectHighScore, null);
		else
			canvas.drawBitmap(highScoreSelectedBMP, srcRectHighScore, desRectHighScore, null);
		if (!btnHelpSelect)
			canvas.drawBitmap(helpBMP, srcRectHelp, desRectHelp, null);
		else
			canvas.drawBitmap(helpSelectedBMP, srcRectHelp, desRectHelp, null);
		if (!btnAboutSelect)
			canvas.drawBitmap(aboutBMP, srcRectAbout, desRectAbout, null);
		else
			canvas.drawBitmap(aboutSelectedBMP, srcRectAbout, desRectAbout, null);
		canvas.restore();
	}
	
	public void drawSoundButton(Canvas canvas)
	{
		// TODO Draw sound on/off button
		canvas.save();
		if (soundOn)
			canvas.drawBitmap(soundOnBMP, srcRectSound, desRectSound, null);
		else
			canvas.drawBitmap(soundOffBMP, srcRectSound, desRectSound, null);
		canvas.restore();
	}
			
	public void drawVersion(Canvas canvas)
	{
		// TODO Draw version of game
		Paint painttext = new Paint();
		painttext.setColor(Color.BLACK);
		painttext.setStyle(Style.FILL_AND_STROKE);
		painttext.setStrokeWidth(1.5f);
		painttext.setTextSize(view.getHeight()/24);
		
		canvas.save();
		canvas.drawText("Version: 1.0", view.getWidth()/24,  view.getHeight() - 2*painttext.getTextSize(), painttext);
		canvas.restore();
	}
	
	/* ------------------------------------------------------------------------------- Functions */
	
	public void nextState(Intent intent)
	{
		handlerDrawingMain.removeCallbacks(runnableDrawingMain);
		startActivity(intent);
		clearBitmap();
		finish();
	}
	
	private void readScore()
	{
		
	}
	
	public void clearBitmap()
	{
		mainMenuBackground.recycle();
		playGameBMP.recycle();
		playGameSelectedBMP.recycle();
		soundOnBMP.recycle();
		soundOffBMP.recycle();
		helpBMP.recycle();
		helpSelectedBMP.recycle();
		
	}
	
	/* ------------------------------------------------------------------------------- Input */
	
	@Override
	public boolean onTouchEvent(MotionEvent event) {
		// TODO Get touch position
		if (event.getAction() == MotionEvent.ACTION_DOWN)
		{
			int touchOnID = checkPosition(event);
			switch(touchOnID)
			{
				case 0 : {
					// TODO Selected button play
					btnPlaySelect = true;
					if(soundOn)
						mediaPlayer_soundbutton.start();
					break;
				}
				case 1 : {
					// TODO Selected button sound
					soundOn = !soundOn;
					mediaPlayer_changesound.start();
					
					if(mediaPlayer_soundbackground.isPlaying()){
						mediaPlayer_soundbackground.stop();
						try {
							mediaPlayer_soundbackground.prepare();
						} catch (IOException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
						mediaPlayer_soundbackground.seekTo(0);
					}
					else
					{
						mediaPlayer_soundbackground.start();
						mediaPlayer_soundbackground.isLooping();
					}
					break;
				}
				case 2 : {
					// TODO Selected button highscore
					btnHighScoreSelect = true;
					if(soundOn)
						mediaPlayer_soundbutton.start();
					break;
				}
				case 3 : {
					// TODO Selected button help
					btnHelpSelect = true;
					if(soundOn)
						mediaPlayer_soundbutton.start();
					break;
				}
				case 4 : {
					// TODO Selected button about
					btnAboutSelect = true;
					if(soundOn)
						mediaPlayer_soundbutton.start();
					break;
				}
			}
		}
		return super.onTouchEvent(event);
	}
	
	public int checkPosition(MotionEvent event)
	{
		int posX = (int)event.getX();
		int posY = (int)event.getY();
		Log.d(TAG,"posX "+posX+" "+"posY "+posY);
		
		if (((posX >= playRectLeft) && (posX <= playRectRight))
				&& ((posY >= playRectTop)&&(posY <= playRectBottom)))
		{
			Log.d(TAG,"in return 0");
			return 0;
		}
		else if (((posX >= soundRectLeft) && (posX <= soundRectRight))
				&& ((posY >= soundRectTop)&&(posY <= soundRectBottom)))
		{
			Log.d(TAG,"in return 1");
			return 1;
		}
		else if (((posX >= highScoreRectLeft) && (posX <= highScoreRectRight))
				&& ((posY >= highScoreRectTop)&&(posY <= highScoreRectBottom)))
		{
			Log.d(TAG,"in return 2");
			return 2;
		}
		else if (((posX >= helpRectLeft) && (posX <= helpRectRight))
				&& ((posY >= helpRectTop)&&(posY <= helpRectBottom)))
		{
			Log.d(TAG,"in return 3");
			return 3;
		}
		else if (((posX >= aboutRectLeft) && (posX <= aboutRectRight))
				&& ((posY >= aboutRectTop)&&(posY <= aboutRectBottom)))
		{
			Log.d(TAG,"in return 4");
			return 4;
		}
		else
			return -1;
	}
	
	@Override
	protected void onPause() {
		// TODO Auto-generated method stub
		Log.e(TAG, "on pause");
		handlerDrawingMain.removeCallbacks(runnableDrawingMain);
		mediaPlayer_soundbackground.stop();
		finish();
		super.onPause();
	}
	
	@Override
	public void onBackPressed() {
		// TODO When press back button
		mediaPlayer_soundbackground.stop();
		handlerDrawingMain.removeCallbacks(runnableDrawingMain);
		super.onBackPressed();
	}
}
