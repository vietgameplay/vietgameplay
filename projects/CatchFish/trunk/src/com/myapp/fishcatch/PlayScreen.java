package com.vietgameplay.fishcatch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Random;
import java.util.StringTokenizer;

import com.vietgameplay.fishcatch.R;


import android.app.Activity;
import android.content.Intent;
import android.content.pm.ActivityInfo;
import android.content.res.Configuration;
import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.PorterDuff.Mode;
import android.graphics.Rect;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.os.Debug;
import android.os.Handler;
import android.util.Log;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.ViewGroup.LayoutParams;
import android.view.Window;

public class PlayScreen extends Activity implements SurfaceHolder.Callback {

	private static final String TAG = "DEBUG_P";									/* TODO Dung's variable define */
	SurfaceView view;
	float Pi = 3.1415f;
	Random random;
	
	Handler handlerDrawing;
	Runnable runnableDrawing;
	
	Bitmap fishBMP[];
	Bitmap cannonBMP[];
	Bitmap sharkBMP[];
	Bitmap PlayBackground;
	Bitmap coinSilverBMP;
	Bitmap coinGoldBMP;
	Bitmap coinTextBMP;
	Bitmap bulletBMP;
	Bitmap webBMP;
	Bitmap uiButtonBMP;
	
	Rect srcRectBackground;
	Rect desRectBackground;
	Rect srcRectLoading;
	Rect desRectLoading;
	Rect srcRectLoadingBar;
	Rect desRectLoadingBar;
	Rect srcRectPause;
	Rect desRectPause;
	Rect srcRectResume;
	Rect srcRectResumeSelected;
	Rect desRectResume;
	Rect srcRectRetry;
	Rect srcRectRetrySelected;
	Rect desRectRetry;
	Rect srcRectExit;
	Rect srcRectExitSelected;
	Rect desRectExit;
	Rect srcRectPauseBg;
	Rect desRectPauseBg;
	Rect srcRectTimeBar;
	Rect desRectTimeBar;
	Rect srcRectLevelBackGround;
	Rect srcRectLevel[];
	Rect desRectLevelText;
	Rect desRectLevelFirstNum;
	Rect desRectLevelSecondNum;
	
	Fish fish[][];
	Coin coin[][];
	Cannon cannon[];
	BulletWeb bulletweb[][];
	float posYFish[][];
	int degreeFish[][];
	
	Position desBulletPosition;
	Position cannonCenterPosition;

	Intent intentMainMenu;
	Intent intentEndGame;
	
	int uiButtonWidth;
	int uiButtonHeight;
	int level;
	int timeCount;
	int remainingTime;
	int pointToNextLevel;
	int numFish;
	int pointGot;
	int FPS = 30;
	int srcRightTimeBar;
	int desRightTimeBar;
	int srcRightTimeBarMax;
	int desRightTimeBarMax;
	int nextMove;
	int delay;
	int rightDestLoadingBar;
	int rightSrcLoadingBar;
	int percent;
	int degreeCannon;
	int currentCannon;
	int currentBullet;
	int maxnumFish[] ={15,10,8,6,4,4,4,5,4,3,2};
	int health[]    = {10,10,15,20,30,50,60,70,90,100,200};
	int coinPoint[] = { 2, 3, 4, 7, 9,11,13,17,20, 30, 50};
	int powerFee[]  = { 1, 2, 3, 4, 6, 8, 10};
	int power[]     = {10,20,30,40,50,60,70};
	int frameCount[] = {4,4,4,4,4,8,6,8,8,6,8};
	int frameWidth[] = {55,78,72,77,107,105,92,174,166,178,458};
	int frameHeight[] = {37,64,56,59,122,79,151,126,183,187,243};
	int cframeHeight[] = {74,76,76,83,85,90,94};
	float fishSpeed[]  = {4f,4f,3.7f,3.5f,3.3f,3f,2f,2.5f,2.3f,2f,3f};
	int fishTimeShow[] = { 500, 1000, 1000, 1500, 3000, 5000, 7000, 7000, 9000, 11000, 15000};
	int fishID[] = {
			R.drawable.fish1,								// 0
			R.drawable.fish2,								// 1			
			R.drawable.fish3,								// 2
			R.drawable.fish4,								// 3
			R.drawable.fish5,								// 4
			R.drawable.fish6,								// 5
			R.drawable.fish7,								// 6
			R.drawable.fish8,								// 7
			R.drawable.fish9,								// 8
			R.drawable.fish10,								// 9
			R.drawable.shark1,								// 10
			R.drawable.shark1d,								// 11
			R.drawable.shark2,								// 12
			R.drawable.shark2d								// 13
	};
	int cannonID[] = {
			R.drawable.cannon1,
			R.drawable.cannon2,
			R.drawable.cannon3,
			R.drawable.cannon4,
			R.drawable.cannon5,
			R.drawable.cannon6,
			R.drawable.cannon7
	};
	int levelFilename[] = {
			R.raw.level1,
			R.raw.level2,
			R.raw.level3,
			R.raw.level4,
			R.raw.level5,
			R.raw.level6,
			R.raw.level7,
			R.raw.level8,
			R.raw.level9
			};
			
	static float fishScale;
	static float cannonScale;
	boolean isLowMemoryDevice = false;
	boolean isPause = false;
	boolean isNextLevel = false;
	boolean getDegree = false;
	boolean printLog = true;
	boolean printLogDraw = true;
	boolean onLoad = true;
	boolean firstMove = true;
	boolean inRoute[][];
	boolean btnResumeSelected = false;
	boolean btnRetrySelected = false;
	boolean btnMusicSelected = false;
	boolean btnExitSelected = false;
	static boolean loaded = false;
	long timeFishMove;
	long timeResetDelay;
	long timeReleaseBtn;
	long timeControlFPS;
	long timeNextLevel;
	long timeResetTimeCount;
	float fishLeftReset;
	float fishRightReset;
	float nextFishDelay;																/* End of Dung's variable define */

	Boolean upButtonCheck=false;														/* TODO Loc's variable define */
	Boolean downButtonCheck=false;
	
	float widthWebIcr;
	float heightWebIcr;
	Bitmap bottomSRC;
//	Bitmap soundOnBMP;
//	Bitmap soundOffBMP;
	
	//bottom Image
	Rect srcRectBtm;
	Rect desRectBtm;

	//set Location Button UP
	Rect srcRectUpBtn;
	Rect srcRectUpBtn2;
	Rect desRectUpBtn;
	
	//set Location Button Down
	Rect srcRectDownBtn;
	Rect srcRectDownBtn2;
	Rect desRectDownBtn;
	
	//Get sizeButton Down Cannon(fist)
	int resDownCannonleft_F;
	int resDownCannonRight_F;
	//Get size Button Down Cannon(last)
	int resDownCannonleft_L;
	int resDownCannonRight_L;
	
	// Sound Rectangle
	Rect srcRectSoundOn;
	Rect srcRectSoundOnSelected;
	Rect srcRectSoundOff;
	Rect desRectSoundOn;
	Rect desRectSoundOff;																	/* End of Loc's variable define */
	
																			/* TODO Thinh's variable define */
	Bitmap numberBlack;
	
	Rect srcRectCoin[];
	Rect desRectCoin[];
	
	int money;
	String strMoney;														
	
	MediaPlayer mediaPlayer_background;										/* End of Thinh's variable define */
	

	
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
		
		mediaPlayer_background = MediaPlayer.create(this, R.raw.sound_background);
		
		widthWebIcr=0;
		heightWebIcr=0;
		
		onLoad = true;
		firstMove = true;
		getDegree = false;
		percent = 0;
		degreeCannon = 0;
		currentCannon = 0;
		currentBullet = 0;
		timeFishMove = 0;
		timeResetDelay = 0;
		nextFishDelay = 0f;
		timeReleaseBtn = 0;
		timeControlFPS = 0;
		nextMove = 0;
		delay = 0;
		money = 1000;
		strMoney = "";
		fishScale = (float)SplashScreen.scrHeight/600f;
		cannonScale = (float)SplashScreen.scrHeight/320f;
		
		// TODO Initialize loading
		BitmapFactory.Options opts = new BitmapFactory.Options(); 
        opts.inPurgeable = true;
        
        uiButtonBMP = BitmapFactory.decodeResource(getResources(), R.drawable.icon_ingame, opts);
        uiButtonWidth = uiButtonBMP.getWidth();
        uiButtonHeight = uiButtonBMP.getHeight();
        
        rightDestLoadingBar = (int)(0.892f*(SplashScreen.scrWidth/3.0f)) - (int)(0.09745f*(SplashScreen.scrWidth/3.0f));
        rightSrcLoadingBar = (int)(0.5248*uiButtonWidth);
        
		srcRectLoading = new Rect(0, (int)(0.6787*uiButtonHeight), (int)(0.6514*uiButtonWidth), (int)(0.8555*uiButtonHeight));
		srcRectLoadingBar = new Rect(0, (int)(0.6426*uiButtonHeight), 0, (int)(0.6748*uiButtonHeight));
		
		desRectLoading = new Rect(SplashScreen.scrWidth/3, SplashScreen.scrHeight/3, 2*SplashScreen.scrWidth/3, 2*SplashScreen.scrHeight/3);
		desRectLoadingBar = new Rect((int)(SplashScreen.scrWidth/3.0f)+(int)(0.09745f*(SplashScreen.scrWidth/3.0f)),
				(int)(SplashScreen.scrHeight/3.0f)+(int)(0.5556f*(SplashScreen.scrHeight/3.0f)),
				(int)(SplashScreen.scrWidth/3.0f)+(int)(0.09745f*(SplashScreen.scrWidth/3.0f)),
				(int)(SplashScreen.scrHeight/3.0f)+(int)(0.7222f*(SplashScreen.scrHeight/3.0f)));
		
		// TODO Initialize view 
		view = new SurfaceView(this);
		view.setLayoutParams(new LayoutParams(SplashScreen.scrHeight,SplashScreen.scrWidth));
        setContentView(view);
        view.getHolder().addCallback(this);
        
	}
	
	public void surfaceCreated(SurfaceHolder holder) {
	 	tryRunning(holder);
    }

    public void surfaceChanged(SurfaceHolder holder, int frmt, int w, int h) { 
    }

    public void surfaceDestroyed(SurfaceHolder holder) 
    {
    	
    }
    
    /* ------------------------------------------------------------------------------- Loading Areas */
    
    private void load10percent()
    {
    	Log.e(TAG,"loading......10");
    	random = new Random();
		intentMainMenu = new Intent(getApplicationContext(),MainMenuScreen.class);
		intentEndGame = new Intent(getApplicationContext(),EndGameScreen.class);
		desBulletPosition = new Position();
		
		BitmapFactory.Options opts = new BitmapFactory.Options(); 
        opts.inPurgeable = true;
        
		//PlayBackground = BitmapFactory.decodeResource(getResources(), R.drawable.game_bg_2_hd, opts);
		PlayBackground= decodeSampledBitmapFromResource(getResources(), R.drawable.game_bg_2_hd, SplashScreen.scrWidth, SplashScreen.scrHeight);
		bottomSRC = BitmapFactory.decodeResource(getResources(), R.drawable.bottom);
		numberBlack = BitmapFactory.decodeResource(getResources(), R.drawable.number_black);
		coinTextBMP = BitmapFactory.decodeResource(getResources(), R.drawable.cointext);
		
		// TODO Initialize source and destination rectangle
		srcRectBackground = new Rect(0, 0, PlayBackground.getWidth(), PlayBackground.getHeight());
		desRectBackground = new Rect(0, 0, SplashScreen.scrWidth, SplashScreen.scrHeight);
		
		// TODO Initialize fish and fish's animation
		fish 					= new Fish[11][15];
		fishBMP 				= new Bitmap[10];
		coin 					= new Coin[11][15];
		posYFish 				= new float[11][15];
		degreeFish 				= new int [11][15];
		inRoute 				= new boolean[11][15];
		cannon 					= new Cannon[7];
		cannonBMP 				= new Bitmap[7];
		sharkBMP				= new Bitmap[2];
		bulletweb 				= new BulletWeb[7][5];
		cannonCenterPosition	= new Position((int)(10.5f*SplashScreen.scrWidth/20f), SplashScreen.scrHeight);
		srcRectCoin 			= new Rect[6];
		desRectCoin 			= new Rect[6];
		srcRectLevel			= new Rect[11];
		percent = 10;
    }
        
    private void load40percent()
    {
    	Log.e(TAG,"loading......40");
    	
    	for (int i = 0; i < 6; i++)
    	{
    		srcRectCoin[i] = new Rect();
    		desRectCoin[i] = new Rect();
    	}
    	
    	for (int i = 0; i < 11; i++)
    	{
    		srcRectLevel[i] = new Rect();
    	}
    	srcRectLevelBackGround = new Rect(uiButtonWidth/2,0,uiButtonWidth,(int)(0.375f*uiButtonHeight));
    	
    	desRectLevelText = new Rect();
    	desRectLevelFirstNum = new Rect();
    	desRectLevelSecondNum = new Rect();
    	
    	// NEW
    	srcRectPause = new Rect((int)(0.8828f*uiButtonWidth),(int)(0.3828f*uiButtonHeight),uiButtonWidth,(int)(0.5f*uiButtonHeight));
    	desRectPause = new Rect(14*SplashScreen.scrWidth/15,(int)(13.5f*SplashScreen.scrHeight/15f),(int)(19.8f*SplashScreen.scrWidth/20f),(int)(19.8f*SplashScreen.scrHeight/20f));
    	
    	srcRectResume = new Rect(0,(int)(0.5469f*uiButtonHeight),(int)(0.1992f*uiButtonWidth),(int)(0.5889f*uiButtonHeight));
    	srcRectResumeSelected = new Rect(0,(int)(0.5889f*uiButtonHeight),(int)(0.1992f*uiButtonWidth),(int)(0.6348f*uiButtonHeight));
    	desRectResume = new Rect((int)(2*SplashScreen.scrWidth/5),(int)(SplashScreen.scrHeight/6),(int)(3*SplashScreen.scrWidth/5),(int)(2*SplashScreen.scrHeight/6));
    	
//    	srcRectOption = new Rect(0,0,optionBMP.getWidth(),optionBMP.getHeight());
//    	desRectOption = new Rect((int)(2*SplashScreen.scrWidth/5),(int)(2*SplashScreen.scrHeight/6),(int)(3*SplashScreen.scrWidth/5),(int)(3*SplashScreen.scrHeight/6));
    	
    	srcRectRetry = new Rect((int)(0.32715f*uiButtonWidth),(int)(0.5469f*uiButtonHeight),(int)(0.4941f*uiButtonWidth),(int)(0.5889f*uiButtonHeight));
    	srcRectRetrySelected = new Rect((int)(0.32715f*uiButtonWidth),(int)(0.5889f*uiButtonHeight),(int)(0.4941f*uiButtonWidth),(int)(0.6348f*uiButtonHeight));
    	desRectRetry = new Rect((int)(2*SplashScreen.scrWidth/5),(int)(3*SplashScreen.scrHeight/6),(int)(3*SplashScreen.scrWidth/5),(int)(4*SplashScreen.scrHeight/6));
    	
    	srcRectExit = new Rect((int)(0.1992f*uiButtonWidth),(int)(0.5469f*uiButtonHeight),(int)(0.32715f*uiButtonWidth),(int)(0.5889f*uiButtonHeight));
    	srcRectExitSelected = new Rect((int)(0.1992f*uiButtonWidth),(int)(0.5889f*uiButtonHeight),(int)(0.32715f*uiButtonWidth),(int)(0.6348f*uiButtonHeight));
    	desRectExit = new Rect((int)(2*SplashScreen.scrWidth/5),(int)(3*SplashScreen.scrHeight/6),(int)(3*SplashScreen.scrWidth/5),(int)(4*SplashScreen.scrHeight/6));
    	
    	srcRectPauseBg = new Rect(0,0,uiButtonWidth/2,(int)(0.375*uiButtonHeight));
    	desRectPauseBg = new Rect(0,0,SplashScreen.scrWidth,SplashScreen.scrHeight);
    	
    	// bottom image
        srcRectBtm = new Rect(0, 0, bottomSRC.getWidth(), 59*bottomSRC.getHeight()/100);
        desRectBtm = new Rect((int)(0.5f*SplashScreen.scrWidth/10f) ,(int)(7*SplashScreen.scrHeight/10),(int)(9*SplashScreen.scrWidth/10),SplashScreen.scrHeight+2);

        // Sound button
        srcRectSoundOn = new Rect((int)(0.4941f*uiButtonWidth), (int)(0.5469f*uiButtonHeight), (int)(0.65625f*uiButtonWidth), (int)(0.5889f*uiButtonHeight));
        srcRectSoundOnSelected = new Rect((int)(0.4941f*uiButtonWidth), (int)(0.5889f*uiButtonHeight), (int)(0.65625f*uiButtonWidth), (int)(0.6348f*uiButtonHeight));
        srcRectSoundOff = new Rect((int)(0.4941f*uiButtonWidth), (int)(0.5469f*uiButtonHeight), (int)(0.703125f*uiButtonWidth), (int)(0.5889f*uiButtonHeight));
        desRectSoundOn = new Rect((int)(7*SplashScreen.scrWidth/15),(int)(3.25f*SplashScreen.scrHeight/6f),(int)(8*SplashScreen.scrWidth/15f),(int)(3.75f*SplashScreen.scrHeight/6f));
        desRectSoundOff = new Rect((int)(7*SplashScreen.scrWidth/15),(int)(3.25f*SplashScreen.scrHeight/6f),(int)(8*SplashScreen.scrWidth/15f),(int)(3.75f*SplashScreen.scrHeight/6f));
		
        // time bar
        int leftTimeBar = (int)(71.1f*(8.5f*SplashScreen.scrWidth/10f)/100f) + (int)(0.5f*SplashScreen.scrWidth/10f);
        int topTimeBar = (int)((63.4f*(3f*SplashScreen.scrHeight/10f+2)/100f) + (7f*SplashScreen.scrHeight/10f));
        int bottomTimeBar = (int)((88f*(3f*SplashScreen.scrHeight/10f)/100f) + (7f*SplashScreen.scrHeight/10f)+4);
        
        srcRightTimeBar = 0;
        desRightTimeBar = leftTimeBar;
        
        srcRightTimeBarMax = (int)(27.7f*bottomSRC.getWidth()/100f);
        desRightTimeBarMax = (int)(98.7f*(8.5f*SplashScreen.scrWidth/10f)/100f) + (int)(0.5f*SplashScreen.scrWidth/10f) - leftTimeBar;
        
        srcRectTimeBar = new Rect(0,(int)(85.2f*bottomSRC.getHeight()/100f),srcRightTimeBar,bottomSRC.getHeight());
        desRectTimeBar = new Rect(leftTimeBar,topTimeBar,desRightTimeBar,bottomTimeBar);
        
        //set Location Button UP
		desRectUpBtn = new Rect((int)(11.7f*SplashScreen.scrWidth/20f),
								(int)(18*SplashScreen.scrHeight/20),
								(int)(13f*SplashScreen.scrWidth/20f),
								(int)(19.5f*SplashScreen.scrHeight/20f)
							   );
    	
    	//set Location Button Down
		desRectDownBtn = new Rect((int)(8*SplashScreen.scrWidth/20),
								  (int)(18*SplashScreen.scrHeight/20),
								  (int)(9.3f*SplashScreen.scrWidth/20f),
								  (int)(19.5f*SplashScreen.scrHeight/20f)
								 );
		
    	srcRectUpBtn = new Rect((int)(5.8f*bottomSRC.getWidth()/100), 
    							(int)(60*bottomSRC.getHeight()/100),
    							(int)(11.4f*bottomSRC.getWidth()/100),
    							(int)(84.5f*bottomSRC.getHeight()/100f)
    						   );
    	srcRectUpBtn2 = new Rect( 0, 
    							 60*bottomSRC.getHeight()/100,
    							 (int)(5.7f*bottomSRC.getWidth()/100),
    							 (int)(84.5f*bottomSRC.getHeight()/100f)
    							);
    	
    	srcRectDownBtn = new Rect((int)(17.3f*bottomSRC.getWidth()/100),
    							  (int)(60*bottomSRC.getHeight()/100),
    							  (int)(22.9f*bottomSRC.getWidth()/100),
    							  (int)(84.5f*bottomSRC.getHeight()/100f)
    							 );
    	srcRectDownBtn2 = new Rect((int)(11.6f*bottomSRC.getWidth()/100),
    							   (int)(60*bottomSRC.getHeight()/100),
    							   (int)(17.2f*bottomSRC.getWidth()/100),
    							   (int)(84.5f*bottomSRC.getHeight()/100f)
    							  );
    	
    	// TODO Create new
        
    	for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < maxnumFish[i]; j++)
			{
				fish[i][j] = new Fish();
				coin[i][j] = new Coin();
			}
			if (i < 7)
			{
				cannon[i] = new Cannon();
				for (int j = 0; j < 5; j++)
					bulletweb[i][j] = new BulletWeb();
			}
		}
    	
        BitmapFactory.Options opts = new BitmapFactory.Options();
		opts.inDensity = 1;
		opts.inTargetDensity = 1;
        opts.inPurgeable = true;
        
    	coinSilverBMP = BitmapFactory.decodeResource(getResources(), R.drawable.coinani1, opts);
		coinGoldBMP = BitmapFactory.decodeResource(getResources(), R.drawable.coinani2, opts);

		long mMaxVmHeap     = Runtime.getRuntime().maxMemory()/1024;
		long mMaxNativeHeap = 16*1024;
		if (mMaxVmHeap == 16*1024)
		     mMaxNativeHeap = 16*1024;
		else if (mMaxVmHeap == 24*1024)
		     mMaxNativeHeap = 24*1024;
		else
		    Log.w(TAG, "Unrecognized VM heap size = " + mMaxVmHeap);
		
		System.gc();
    	//sharkBMP[0] = BitmapFactory.decodeResource(getResources(), fishID[10], opts);
		int widthTemp = round(frameWidth[10]*fishScale);
		int heightTemp = round(frameHeight[10]*fishScale);
		
		float scaleTemp = fishScale;
		long sizeReqd        = 2*widthTemp * 4*heightTemp * 4  / 8;
		long allocNativeHeap = Debug.getNativeHeapAllocatedSize();
		
		if ((sizeReqd*1024 + allocNativeHeap ) >= mMaxNativeHeap*1024 && fishScale >= 1.0f)
		{
			float percentSize = (sizeReqd*1024 + allocNativeHeap - mMaxNativeHeap*1024)/(mMaxNativeHeap*1024);
			Log.d("DEV","percent"+percentSize);
		    fishScale -= 1.5f*percentSize/100;
		    Log.d("DEV","scale"+fishScale);
		    frameWidth[10] = round(frameWidth[10]*fishScale);
			frameHeight[10] = round(frameHeight[10]*fishScale);
			Log.d("DEV","width :"+frameWidth[10]+" height :"+frameHeight[10]);
			isLowMemoryDevice = true;
		}
		else
		{
			frameWidth[10] = widthTemp;
			frameHeight[10] = heightTemp;
		}
		
		sharkBMP[0] = decodeSampledBitmapFromResource(getResources(), fishID[10] ,2*frameWidth[10], 4*frameHeight[10]);
		System.gc();
    	sharkBMP[1] = decodeSampledBitmapFromResource(getResources(), fishID[11] ,frameWidth[10], 4*frameHeight[10]);
    	System.gc();
    	
    	frameWidth[10] = sharkBMP[1].getWidth();
    	frameHeight[10] = sharkBMP[0].getHeight()/4;
    	
    	fishScale = scaleTemp;
    	
    	
    	percent = 30;
    }   

    private void load70percent()
    {
    	Log.e(TAG,"loading......70");
    	fishLeftReset =  0.5f*SplashScreen.scrWidth/10f;
    	fishRightReset = 10.5f*SplashScreen.scrWidth/10f;
    	
    	BitmapFactory.Options opts = new BitmapFactory.Options();
		opts.inDensity = 1;
		opts.inTargetDensity = 1;
        opts.inPurgeable = true;
        
        bulletBMP = BitmapFactory.decodeResource(getResources(), R.drawable.bullet);
        webBMP = BitmapFactory.decodeResource(getResources(), R.drawable.web);
        
        Rect srcRectBullet[] = new Rect[5];
        srcRectBullet[0]= new Rect((int)(77.5f*bulletBMP.getWidth()/100),(int)(0f*bulletBMP.getHeight()/100),
					(int)(100f*bulletBMP.getWidth()/100),(int)(26.6f*bulletBMP.getHeight()/100));

        srcRectBullet[1]= new Rect((int)(54.6f*bulletBMP.getWidth()/100),(int)(0f*bulletBMP.getHeight()/100),
					(int)(77.3f*bulletBMP.getWidth()/100),(int)(25.2f*bulletBMP.getHeight()/100));

        srcRectBullet[2]= new Rect((int)(27.5f*bulletBMP.getWidth()/100),(int)(30.4f*bulletBMP.getHeight()/100),
					(int)(56.3f*bulletBMP.getWidth()/100),(int)(65.5f*bulletBMP.getHeight()/100));

        srcRectBullet[3]= new Rect((int)(27.3f*bulletBMP.getWidth()/100),(int)(71.3f*bulletBMP.getHeight()/100),
					(int)(54.5f*bulletBMP.getWidth()/100),(int)(100f*bulletBMP.getHeight()/100));

        srcRectBullet[4]= new Rect((int)(0f*bulletBMP.getWidth()/100),(int)(71.3f*bulletBMP.getHeight()/100),
					(int)(27.3f*bulletBMP.getWidth()/100),(int)(100f*bulletBMP.getHeight()/100));
    	Rect desRectBullet;
    	
    	Rect []srcWebImg= new Rect[5];
   		
   		srcWebImg[4]= new Rect((int)(0f*webBMP.getWidth()/100),(int)(42f*webBMP.getHeight()/100),
   								(int)(39f*webBMP.getWidth()/100),(int)(76f*webBMP.getHeight()/100));
   		srcWebImg[3]= new Rect((int)(56f*webBMP.getWidth()/100),(int)(34f*webBMP.getHeight()/100),
   								(int)(95f*webBMP.getWidth()/100),(int)(65f*webBMP.getHeight()/100));
   		srcWebImg[2]= new Rect((int)(0f*webBMP.getWidth()/100),(int)(74f*webBMP.getHeight()/100),
   								(int)(30f*webBMP.getWidth()/100),(int)(98f*webBMP.getHeight()/100));
   		srcWebImg[1]= new Rect((int)(38f*webBMP.getWidth()/100),(int)(66.6f*webBMP.getHeight()/100),
   								(int)(73.2f*webBMP.getWidth()/100),(int)(93.5f*webBMP.getHeight()/100));
   		srcWebImg[0]= new Rect((int)(76.7f*webBMP.getWidth()/100),(int)(66.7f*webBMP.getHeight()/100),
   								(int)(100*webBMP.getWidth()/100),88*webBMP.getHeight()/100);
    	
    	// TODO Initialize animation of fish 0 - 4
   		
    	for (int i = 0; i < 5; i++)
    	{
    		//Bitmap fishBMP = BitmapFactory.decodeResource(getResources(), fishID[i], opts);


			frameWidth[i] = round(frameWidth[10]*fishScale);
			frameHeight[i] = round(frameHeight[10]*fishScale);
			
			fishBMP[i] = decodeSampledBitmapFromResource(getResources(), fishID[i] ,frameWidth[i], (4+frameCount[i])*frameHeight[i]);
			
			frameWidth[i] = fishBMP[i].getWidth();
			frameHeight[i] = fishBMP[i].getHeight()/(4+frameCount[i]);

    			//fishBMP[i] = BitmapFactory.decodeResource(getResources(), fishID[i], opts);

    		for (int j = 0; j < maxnumFish[i]; j++)
    		{
    			// TODO Initialize mark variable of route of fish
    			inRoute[i][j] = false;
    			degreeFish[i][j] = 0;
    			
    			// TODO Initialize fish: animation and position
	    		int temp = random.nextInt(2);
	    		
				Position fishPosition = new Position();	
				int tempRandPos = 0;
				
				if (temp == 1)
				{
					tempRandPos = random.nextInt(2*SplashScreen.scrWidth/3) + SplashScreen.scrWidth/3;
					fishPosition = new Position(-frameWidth[i]-fishLeftReset-(random.nextInt(100)+100),random.nextInt(SplashScreen.scrHeight));

				}
				else if (temp == 0)
				{
					tempRandPos = random.nextInt(2*SplashScreen.scrWidth/3);
					fishPosition = new Position(fishRightReset+(random.nextInt(100)+100),random.nextInt(SplashScreen.scrHeight));

				}
				
				// TODO Random turn left or turn right
				int tempRand = random.nextInt(3);
				int leftRight = 0;
				if (tempRand == 0)
					leftRight = -1;
				else if (tempRand == 1)
					leftRight = 1;
				
				// TODO Init
				//Animation fishAnimation = new Animation();
				fish[i][j].InitializeAnimation( new Position(0, 0), frameWidth[i], frameHeight[i], 0, frameCount[i], 110, fishScale, true);
				fish[i][j].Initialize(fishPosition,temp,health[i],0,2,1,tempRandPos,leftRight,false);
				posYFish[i][j] = fishPosition.Y;
				
				// TODO Initialize coin animation
				coin[i][j].InitializeAnimation( new Position(0, 0), 60,60, 0, 10, 80, 0.5f, true);
				coin[i][j].Initialize(new Position(-99,-99),false);
				
    		}
    		
    		//fishBMP.recycle();
    		System.gc();
    		
    		// TODO Initialize 5 first cannon from 0 to 4
    		cannonBMP[i] = BitmapFactory.decodeResource(getResources(), cannonID[i], opts);
    		cannon[i].InitializeAnimation( new Position(0, 0), 74, cframeHeight[i], 0, 5, 80, cannonScale, false);
    		cannon[i].Initialize(new Position(cannonCenterPosition.X-cannonScale*(cannonBMP[i].getWidth()/2), cannonCenterPosition.Y-cannonScale*((cannonBMP[i].getHeight()/5))), false, false, power[i]);
    		
    		// TODO Initialize 5 first bullet
    		desRectBullet = new Rect((int)(cannonCenterPosition.X-cannonScale*((srcRectBullet[i].right - srcRectBullet[i].left)/2)), 
    								 (int)(cannonCenterPosition.Y-cannonScale*(cannonBMP[i].getHeight()/10)-cannonScale*(srcRectBullet[i].bottom - srcRectBullet[i].top)/3), 
    								 (int)(cannonCenterPosition.X+cannonScale*((srcRectBullet[i].right - srcRectBullet[i].left)/2)), 
    								 (int)(cannonCenterPosition.Y-cannonScale*(cannonBMP[i].getHeight()/10)+cannonScale*(2*(srcRectBullet[i].bottom - srcRectBullet[i].top)/3)));
    		for (int j = 0; j < 5; j++)
    			bulletweb[i][j].Initialize( srcRectBullet[i], desRectBullet,srcWebImg[i]);
    		
    		//cannonBMP.recycle();
    		System.gc();
    		
    		Log.e(TAG,"loading......70..........fish "+(i+1));
    	}

    	System.gc();
    	
    	percent = 30;
    }
    
    private boolean load100percent()
    {
    	Log.e(TAG,"loading......100");
    	
    	BitmapFactory.Options opts = new BitmapFactory.Options();
		opts.inDensity = 1;
		opts.inTargetDensity = 1;
        opts.inPurgeable = true;
        
        Rect srcRectBullet[] = new Rect[2];
        Rect desRectBullet;
        srcRectBullet[0]= new Rect(0,(int)(38.2f*bulletBMP.getHeight()/100),
				(int)(27.3f*bulletBMP.getWidth()/100),(int)(71.3f*bulletBMP.getHeight()/100));
        srcRectBullet[1]= new Rect((int)(27.3f*bulletBMP.getWidth()/100),0,
				(int)(54.5f*bulletBMP.getWidth()/100),(int)(30.4f*bulletBMP.getHeight()/100));
    	
    	Rect []srcWebImg= new Rect[2];
    	srcWebImg[1]= new Rect((int)(2f*webBMP.getWidth()/100),(int)(2f*webBMP.getHeight()/100),
 					(int)(53f*webBMP.getWidth()/100),(int)(42f*webBMP.getHeight()/100));
    	srcWebImg[0]= new Rect((int)(53f*webBMP.getWidth()/100),0,
 					webBMP.getWidth(),(int)(36f*webBMP.getHeight()/100));
    	
    	// TODO Initialize animation of fish 5 - 11
    	for (int i = 5; i < 11; i++)
    	{
			if(i < 10)
			{
				frameWidth[i] = round(frameWidth[10]*fishScale);
				frameHeight[i] = round(frameHeight[10]*fishScale);
				
				fishBMP[i] = decodeSampledBitmapFromResource(getResources(), fishID[i] ,frameWidth[i], (4+frameCount[i])*frameHeight[i]);
				
				frameWidth[i] = fishBMP[i].getWidth();
				frameHeight[i] = fishBMP[i].getHeight()/(4+frameCount[i]);
				
				fishBMP[i] = BitmapFactory.decodeResource(getResources(), fishID[i], opts);
			}
    		
			for (int j = 0; j < maxnumFish[i]; j++)
			{
				// TODO Initialize mark variable of route of fish
    			inRoute[i][j] = false;
    			degreeFish[i][j] = 0;
    			
				// TODO Initialize coin animation
    			
    			coin[i][j].InitializeAnimation( new Position(0, 0), 60,60, 0, 10, 80, 0.5f, true);
				coin[i][j].Initialize(new Position(-99,-99),false);
				
				// TODO Initialize fish: animation and position
				int temp = random.nextInt(2);
				
				Position fishPosition = new Position();
				int tempRandPos = 0;
				
				if (temp == 1)
				{
					tempRandPos = random.nextInt(2*SplashScreen.scrWidth/3) + SplashScreen.scrWidth/3;
					fishPosition = new Position(-frameWidth[i]-fishLeftReset-(random.nextInt(300)+200),random.nextInt(SplashScreen.scrHeight));

				}
				else if (temp == 0)
				{
					tempRandPos = random.nextInt(2*SplashScreen.scrWidth/3);
					fishPosition = new Position(fishRightReset+(random.nextInt(300)+200),random.nextInt(SplashScreen.scrHeight));
				
				}
				
				// TODO Random turn left or turn right
				int tempRand = random.nextInt(3);
				int leftRight = 0;
				if (tempRand == 0)
					leftRight = -1;
				else if (tempRand == 1)
					leftRight = 1;
				
				fish[i][j].InitializeAnimation( new Position(0, 0), frameWidth[i], frameHeight[i], 0, frameCount[i], (i!=9?110:150), fishScale, true);
				fish[i][j].Initialize(fishPosition,temp,health[i],0,2,1,tempRandPos,leftRight,false);
				posYFish[i][j] = fishPosition.Y;
				
			}
			
			if (i < 7)
			{
				// TODO Initialize 2 last cannon 5, 6
	    		cannonBMP[i] = BitmapFactory.decodeResource(getResources(), cannonID[i], opts);
	    		cannon[i].InitializeAnimation(new Position(0, 0), 74, cframeHeight[i], 0, 5, 80, cannonScale, false);
	    		cannon[i].Initialize(new Position(cannonCenterPosition.X-cannonScale*(cannonBMP[i].getWidth()/2), cannonCenterPosition.Y-cannonScale*(cannonBMP[i].getHeight()/5)), false, false, power[i]);
	    		
	    		desRectBullet = new Rect((int)(cannonCenterPosition.X-cannonScale*((srcRectBullet[i-5].right - srcRectBullet[i-5].left)/2)), 
						 (int)(cannonCenterPosition.Y-cannonScale*(cannonBMP[i].getHeight()/10)-cannonScale*((srcRectBullet[i-5].bottom - srcRectBullet[i-5].top)/3)), 
						 (int)(cannonCenterPosition.X+cannonScale*((srcRectBullet[i-5].right - srcRectBullet[i-5].left)/2)), 
						 (int)(cannonCenterPosition.Y-cannonScale*(cannonBMP[i].getHeight()/10)+cannonScale*(2*(srcRectBullet[i-5].bottom - srcRectBullet[i-5].top)/3)));
	    		
	    		// TODO Initialize 2 last bullet
	    		for (int j = 0; j < 5; j++)
	    			bulletweb[i][j].Initialize( srcRectBullet[i-5], desRectBullet,srcWebImg[i-5]);
	    		
	    		System.gc();
			}
			
			Log.e(TAG,"loading......100..........fish "+(i+1));
    	}
    	percent = 30;
    	
    	if(MainMenuScreen.soundOn){
    		mediaPlayer_background.setLooping(true);
    		mediaPlayer_background.start();
    	}
    	
    	return true;
    }
     
    
    /* ------------------------------------------------------------------------------- Running Areas */
    
    private void tryRunning(final SurfaceHolder holder) {
    	handlerDrawing = new Handler();
    	runnableDrawing = new Runnable() {
    		int count  = 0;
			public void run() {
				Log.e(TAG,"drawing......");
				timeControlFPS = System.currentTimeMillis();
				handlerDrawing.postDelayed(this, 10);
				
				count++;
				if (count > 1000)
					count = 5;
				// TODO Load resource
				if (count == 1)
				{
					if (!loaded)
					{
						load10percent();
					}
					else
						percent = 10;
				}
				else if (count == 2)
				{
					if (!loaded)
					{
						load40percent();
					}
					else
						percent = 30;
				}
				else if (count == 3)
				{
					if (!loaded)
					{
						load70percent();
					}
					else
						percent = 30;
				}
				else if (count == 4)
				{
					if (!loaded)
					{
						loaded = load100percent();
					}
					else
						percent = 30;
				}
				
				// TODO Update  
				update();
				
				// TODO Draw
				Canvas canvas = holder.lockCanvas();
				
		        if (canvas == null) {
		            Log.e(TAG, "Cannot draw onto the canvas as it's null");
		        } 
		        else 
		        {
		        	// TODO Clear screen
		        	canvas.drawColor(0,Mode.CLEAR);
		        	if (onLoad)
		        	{
		        		Log.d(TAG,"in draw loading");
			        	// TODO Draw loading
			        	drawLoading(canvas);
			        	
			        	if (loaded && (count == 4))
			        	{
			        		onLoad = false;
			        		level = 0;
							nextLevel();
			        	}
			        	handlerDrawing.postDelayed(this, 100);
		        	}
		        	else
		        	{
		        		
			        	// TODO Draw background
			        	drawBackground(canvas);
			        	
			        	// TODO Draw fish
			        	drawFish(canvas);
			        	
			        	// TODO Draw bottom bar
			        	drawBottom(canvas);
			        	
			        	//TODO draw button Cannon up
			        	drawUpCannon(canvas);
			        	
			        	//TODO draw button Cannon down
			        	drawDownCannon(canvas);
			        	
			        	// TODO Draw Time Bar
			        	drawTimeBar(canvas);
			        	
			        	//TODO Draw number black
			        	drawNumBlack(canvas);
			        	
			        	if (!isPause)
			        	{
			        		// TODO Draw bulletBMP
				        	drawBullet(canvas);
				        	
				        	// TODO Draw Pause button
				        	drawPauseButton(canvas);
			        	}
			        	
			        	// TODO Draw Cannon
			        	drawCannon(canvas);
			        	
			        	if (isPause)
			        	{
			        		if (isNextLevel)
				        	{
				        		drawNextLevel(canvas);
				        	}
			        		else
			        		{
				        		// TODO Draw pause background
				        		drawPauseBackground(canvas);
				        		
				        		// TODO Draw Resume button
				        		drawResumeButton(canvas);
				        		
				        		// TODO Draw Option button
				        		drawRetryButton(canvas);
				        		
				        		// TODO Draw music button
				        		drawSoundButton(canvas);
				        		
				        		// TODO Draw Exit button
				        		drawExitButton(canvas);
			        		}
			        	}	      	
		        	}
		            holder.unlockCanvasAndPost(canvas);
		            
		            if (isNextLevel && count > 4)
		        	{
		            	long timeTemp = System.currentTimeMillis();
		        		if (timeTemp - timeNextLevel >= 3000)
		        		{
		        			isNextLevel = false;
		        			isPause = false;
		        		}
		        	}
		            
		            if (btnResumeSelected)
		        	{
		        		btnResumeSelected = false;
		        		handlerDrawing.postDelayed(this, 500);
		        		isPause = false;
		        	}
		        	if (btnRetrySelected)
		        	{
		        		btnRetrySelected = false;
		        		handlerDrawing.postDelayed(this, 500);
		        		//resetLevel();
		        	}
		        	if (btnMusicSelected)
		        	{
		        		btnMusicSelected = false;
		        		handlerDrawing.postDelayed(this, 500);
		        	}
		        	if (btnExitSelected)
		        	{
		        		btnExitSelected = false;
		        		handlerDrawing.postDelayed(this, 500);
		        		exit();
		        	}
		        }
//		        long tempTime = System.currentTimeMillis();
//		        if ((tempTime - timeControlFPS) < (1000/FPS))
//		        {
//		        	handlerDrawing.postDelayed(this, (1000/FPS) - (tempTime-timeControlFPS+10));
//		        }
			}
		};	  
		handlerDrawing.postDelayed(runnableDrawing, 100);
    }
   
    /* ------------------------------------------------------------------------------- Update Areas */
    
    private void update()
    {
    	if (onLoad)
		{
	    	// TODO Update loading bar
	        srcRectLoadingBar.right += percent*rightSrcLoadingBar;
	        desRectLoadingBar.right += percent*rightDestLoadingBar;
		}
    	else
    	{
    		// TODO update time bar
    		updateTimeBar();
    		
    		if (!isPause)
    		{
    			if (level > 9)
    			{
    				handlerDrawing.removeCallbacks(runnableDrawing);
    				loaded = false;
    				intentEndGame.putExtra("ENDGAME", "ENDG"+pointGot);
    				startActivity(intentEndGame);
    				mediaPlayer_background.stop();
    				finish();
    			}
    			
    			if (remainingTime == timeCount)
    			{
    				handlerDrawing.removeCallbacks(runnableDrawing);
    				loaded = false;
    				intentEndGame.putExtra("ENDGAME", "OVER"+pointGot);
    				startActivity(intentEndGame);
    				mediaPlayer_background.stop();
    				finish();
    			}
    			
    			if (pointGot >= pointToNextLevel)
    				nextLevel();
    			
    			// TODO Update Button
        		updateButton();
        		
	    		// TODO Update Cannon
	    		updateCannon();
	    		
		    	// TODO Update Fish
	    		updateFish();
	    		
	    		// TODO Update bulletBMP
	    		updateBullet();
	    		
	    		// TODO Update number black
	    		updateNumBlack();
	    		
	    		// TODO update Web
	    		updateWeb();
	    		
    		}
    		else
    		{
    			
    		}
    	}
    }
    
    private void updateBullet()
    {
		for (int i = 0; i < 5; i++)
		{
			if (bulletweb[currentCannon][i].acceptDraw && (bulletweb[currentCannon][i].aFactor != 0))
			{
				if((bulletweb[currentCannon][i].destinationRect.bottom > 0))
				{
					int left = bulletweb[currentCannon][i].destinationRect.left;
					int right = bulletweb[currentCannon][i].destinationRect.right;
					float centerX = bulletweb[currentCannon][i].destinationRect.exactCenterX();
					float tempY = 0;
					tempY = 50*fishScale*(float)Math.cos(degreeCannon*Pi/180);
					
					int top = bulletweb[currentCannon][i].destinationRect.top - (int)tempY;
					int bottom = bulletweb[currentCannon][i].destinationRect.bottom - (int)tempY;
					float centerY = bulletweb[currentCannon][i].destinationRect.exactCenterY();
					
					float centerXNext = (centerY - bulletweb[currentCannon][i].bFactor)/bulletweb[currentCannon][i].aFactor;
					
					left += (int)(centerXNext - centerX);
					right += (int)(centerXNext - centerX);
					
					// TODO New destination rectangle for moving
					Rect desRect = new Rect(left, top, right, bottom);
					
					// TODO Update bullet
					bulletweb[currentCannon][i].Update(desRect);
					
					// TODO Check collision
					if (bulletweb[currentCannon][i].destinationRect.bottom < desRectBtm.top)
						checkCollision(new Position(bulletweb[currentCannon][i].destinationRect.exactCenterX(), bulletweb[currentCannon][i].destinationRect.exactCenterY()),i);
				}
				else if ((bulletweb[currentCannon][i].destinationRect.bottom < 0) || (bulletweb[currentCannon][i].destinationRect.right < 0) || (bulletweb[currentCannon][i].destinationRect.left > SplashScreen.scrWidth))
				{
					// TODO Out of screen, reset
					resetBullet(i);
				}
			}
		}
    }
   
    private void updateFish()
    {
    	// TODO Calculate time to show fish
    	if (timeFishMove == 0)
		{
    		// TODO First update
			timeFishMove = System.currentTimeMillis();
			timeResetDelay = System.currentTimeMillis();
			for (int i = 0; i < 11; i++)
				for (int j = 0; j < maxnumFish[i]; j++)
					fish[i][j].timeResetMove = System.currentTimeMillis();
			delay = (random.nextInt(15)+15)*1000;
			nextFishDelay = (1f + (float)random.nextInt(4) + random.nextFloat())*1000f;
		}
		if (timeFishMove != 0)
		{
			// TODO Next update, calculate
			// TODO Get current time
			long tempTime = System.currentTimeMillis();
			
			// TODO Calculate time to reset move when death
			for (int i = 0; i < 11; i++)
				for (int j = 0; j < maxnumFish[i]; j++)
				{
					if (fish[i][j].onMove == 2)
					{
						if ((tempTime - fish[i][j].timeResetMove) > fishTimeShow[i])
						{
							fish[i][j].onMove = 1;
							fish[i][j].timeResetMove = System.currentTimeMillis();
						}
					}
				}
			
			if (((float)(tempTime - timeFishMove) > nextFishDelay) || firstMove)
			{
				// TODO Next fish move
				firstMove = false;
				for (int i = 0; i < 11; i++)
					for (int j = 0; j < maxnumFish[i]; j++)
					{
						if (fish[i][j].onMove == 0)
						{
    						fish[i][j].onMove = 1;
						}
					}
				timeFishMove = tempTime;
			}
		}
		if ((System.currentTimeMillis() - timeResetDelay) >= delay)
		{
			// TODO Reset time 
			timeResetDelay = System.currentTimeMillis();
			nextFishDelay = (1f + (float)random.nextInt(2) + random.nextFloat())*1000f;
			delay = (random.nextInt(15)+15)*1000;
		}
		
		// TODO Update Fish
    	for (int i = 0; i < 11; i++)
    	{
    		for (int j = 0; j < maxnumFish[i]; j++)
    		{
    			if (fish[i][j].status == 1)
    			{
    				// TODO Fish alive, if move, update position
    				if (fish[i][j].onMove == 1)
    				{
	    				if (fish[i][j].direction == 1)
	    				{
	    					// TODO Enable go route
	    					if (fish[i][j].Position.X >= fish[i][j].posRoute)
	    						fish[i][j].enableRoute = true;
	    					if ((fish[i][j].Position.Y < -500) || (fish[i][j].Position.Y > SplashScreen.scrWidth+500))
	    						fish[i][j].status = 0;    // Death
	    					if (fish[i][j].Position.X > fishRightReset)
	    						fish[i][j].status = 0;    // Death
	    					else
	    						fish[i][j].Position.X += fishSpeed[i]*fishScale;      // Move right
	    				}
	    				else if (fish[i][j].direction == 0)
	    				{
	    					// TODO Enable go route
	    					if (fish[i][j].Position.X < fish[i][j].posRoute)
	    						fish[i][j].enableRoute = true;
	    					if ((fish[i][j].Position.Y < -500) || (fish[i][j].Position.Y > SplashScreen.scrWidth+500))
	    						fish[i][j].status = 0;    // Death
	    					if (fish[i][j].Position.X < -fish[i][j].animation.FrameWidth-fishLeftReset)
	    						fish[i][j].status = 0;   // Death
	    					else
	    						fish[i][j].Position.X -= fishSpeed[i]*fishScale;		// Move left
	    				}
	    				
	    				if (fish[i][j].enableRoute)
	    					getRoute(i, j);
    				}
    			}
    			else if (fish[i][j].status == 0)
    			{
    				resetFish(i,j);
    			}
    			else if (fish[i][j].status == 2)
    			{
    				if (fish[i][j].timeOutFish == 0)
    				{
    					// TODO Set time to begin show coin and fish death animation		
	    				
    					coin[i][j].InitializeAnimation(new Position(0, 0),60, 60, 0, 10, 80, 0.5f, true);
	    				
	    				Position coinPos =  new Position(fish[i][j].animation.destinationRect.right,fish[i][j].animation.destinationRect.top);
	    				coin[i][j].Initialize(coinPos, true);
	    				
	    				
	    				if (i < 10)
	    				{
	    					fish[i][j].InitializeAnimation( new Position(0, 0), frameWidth[i], frameHeight[i], frameCount[i], frameCount[i]+4, 140, fishScale, true);
	    				}	
	    				else
	    				{
//	    					if (fish[i][j].direction == 0)
//	    					{	
//		    					Matrix matrix = new Matrix();
//		    					matrix.preScale(-1.0f, 1.0f);
//		    					texture = Bitmap.createBitmap(sharkBMP[1], 0, 0, sharkBMP[1].getWidth(), sharkBMP[1].getHeight(), matrix, true);
//	    					}
//	    					else
//	    						texture = sharkBMP[1];
	    					fish[i][j].InitializeAnimation(new  Position(0, 0), frameWidth[i], frameHeight[i], 0, 4, 140, fishScale, true);
	    				}
	    				
	    				Position position = fish[i][j].Position;
	    				int direct = fish[i][j].direction;
	    				long timeOutFish = System.currentTimeMillis();
	    				fish[i][j].Initialize(position, direct, health[i], timeOutFish, 0, 2,fish[i][j].posRoute,fish[i][j].leftRight,false);
    				}
    				else
    				{
    		    		// TODO Check time to hide coin and set fish to death
    					long tempTime = System.currentTimeMillis();
    					if ((tempTime - fish[i][j].timeOutFish) > 1000)
    					{
    	    				
    						coin[i][j].InitializeAnimation(new Position(0, 0), 60, 60, 0, 10, 80, 0.5f, true);
    	    				//Bitmap coinTexture = coin[i][j].spriteStrip;
    	    				Position coinPos =  new Position(fish[i][j].animation.destinationRect.right,fish[i][j].animation.destinationRect.top);
    	    				coin[i][j].Initialize(coinPos, false);
    	    				
    	    				//Bitmap texture = fish[i][j].spriteStrip;
    	    				fish[i][j].InitializeAnimation(new Position(0, 0), frameWidth[i], frameHeight[i], 0, frameCount[i], 110, fishScale, true);
    						
    	    				Position position = fish[i][j].Position;
    	    				int direct = fish[i][j].direction;
    	    				fish[i][j].Initialize(position, direct, health[i], 0, 2, 0,fish[i][j].posRoute,fish[i][j].leftRight,false);
    	    				
    	    				// TODO Increase money
    	    				pointGot += coinPoint[i];
    	    				//money += coinPoint[i];
    	    				//if (money>999999)
    	    				//	money = 999999;
    					}
    				}
    			}
    			if ((i < 10) || ((i == 10) && fish[i][j].status == 2))
    				fish[i][j].Update(false,degreeFish[i][j]);
    			else 
    				fish[i][j].Update(true,degreeFish[i][j]);
    			// TODO Update coin
    			if (coin[i][j].isShow)
    			{
    				if (!coin[i][j].initialized)
    				{
    					int Coin = coinPoint[i];
    					int numCoin0 = Coin/10;
    					int numCoin1 = Coin%10;
    					coin[i][j].Initialize(coinTextBMP,36,49,numCoin0,numCoin1,fishScale);
    				}
    				coin[i][j].Update();
    			}
    		}
    	}
    	printLog = false;
    }    

    private void updateCannon()
    {
    	// TODO If shoot, rotate cannon to point direction
    	if (cannon[currentCannon].isShoot)
    	{
    		// TODO Rotate cannon
    		// TODO Step by degree
			cannon[currentCannon].Update(degreeCannon);
			cannon[currentCannon].isRotated = true;
			cannon[currentCannon].isShoot = false;
			cannon[currentCannon].Update();
    	}
    	
    	// TODO Normal, update with degree 0
    	if (!cannon[currentCannon].isRotated && !cannon[currentCannon].isShoot)
    		cannon[currentCannon].Update(degreeCannon);
    	
    	// TODO If rotated, start cannon animation
    	if (cannon[currentCannon].isRotated)
    		cannon[currentCannon].Update();
    	
    	// TODO Finish animation, reset cannon to normal and start bullet
    	if (!cannon[currentCannon].animation.Active)
    	{
    		cannon[currentCannon].isRotated = false;
    		cannon[currentCannon].animation.Active = true;
    		// TODO start bullet
    		if (money>=powerFee[currentCannon])
    		{
	    		bulletweb[currentCannon][currentBullet].acceptDraw = true;
	    		bulletweb[currentCannon][currentBullet].degrees = cannon[currentCannon].sumDegree;
	    		bulletweb[currentCannon][currentBullet].power = cannon[currentCannon].power;
	    		currentBullet++;
	    		if (currentBullet == 5)
	    			currentBullet = 0;
	    		// Update money
	    		money -= powerFee[currentCannon];
	    		
	    		//TODO start music
	    		if(MainMenuScreen.soundOn)
	    		{
	    			MediaPlayer mediaPlayer_cannon = MediaPlayer.create(this, R.raw.sound_cannon);
	    			mediaPlayer_cannon.start();
	    		}
    		}
    	}
    }

    private void updateButton()
    {
    	long tempTime = System.currentTimeMillis();
    	if (tempTime - timeReleaseBtn > 200)
    	{
    		if (upButtonCheck)
    			upButtonCheck = false;
    		if (downButtonCheck)
    			downButtonCheck = false;
    	}
    }
    
    private void updateNumBlack()
    {
    	strMoney = ""+money;
		int num = 6 - strMoney.length();
		for(int j=0; j<num;j++)
		{
			strMoney="0"+strMoney;
		}	
		String arrNum[] = new String[6];
		int test2[] = new int[6];
		for(int i=0; i<strMoney.length(); i++)
		{
			String str1=strMoney.substring(i, i+1);
			arrNum[i]=str1;
			test2[i] = Integer.parseInt(arrNum[i]);
			srcRectCoin[i] = new Rect(0, (10-test2[i]-1)*numberBlack.getHeight()/10, numberBlack.getWidth(), (10-test2[i])*numberBlack.getHeight()/10);
			desRectCoin[i] = new Rect((11+4*i)*SplashScreen.scrWidth/156, 254*SplashScreen.scrHeight/280, (11+4+4*i)*SplashScreen.scrWidth/156, 275*SplashScreen.scrHeight/280);
		}
    }
    
    private void updateWeb() {
		// TODO update Web
    	for (int i = 0; i < 5; i++)
    		
    	{
    		if (bulletweb[currentCannon][i].isBang) {
    			float widthWebImg = bulletweb[currentCannon][i].sourceRectWeb.right-bulletweb[currentCannon][i].sourceRectWeb.left;
    			float heightWebImg= bulletweb[currentCannon][i].sourceRectWeb.bottom- bulletweb[currentCannon][i].sourceRectWeb.top;
	    		
	    		Log.d("WEB","update web");
	    		widthWebIcr+=10*cannonScale;
	    		heightWebIcr+=10*cannonScale;
	    		bulletweb[currentCannon][i].destinationRectWeb = new Rect((int)(bulletweb[currentCannon][i].webPosition.X-widthWebIcr),(int)(bulletweb[currentCannon][i].webPosition.Y-heightWebIcr),
	    				(int)(bulletweb[currentCannon][i].webPosition.X+widthWebIcr),(int)(bulletweb[currentCannon][i].webPosition.Y+heightWebIcr));
	    		
	    		if (widthWebIcr > cannonScale*widthWebImg/2 && heightWebIcr > cannonScale*heightWebImg/2 ) {
		    		Log.d("WEB","hide web");
		    		widthWebIcr=cannonScale*widthWebImg/4;
		    		heightWebIcr=cannonScale*heightWebImg/4;
		    		bulletweb[currentCannon][i].acceptDraw = false;
		    		bulletweb[currentCannon][i].isBang=false;
		    	}
	    	}
	    	
    	}
	}
   
    private void updateTimeBar()
    {
    	// update time
    	if (timeResetTimeCount == 0)
    		timeResetTimeCount = System.currentTimeMillis();
    	long timeTemp = System.currentTimeMillis();
    	int temp = 0;
    	if (timeTemp - timeResetTimeCount >= 1000)
    	{
    		temp = (int)(timeTemp - timeResetTimeCount - 1000);
    		timeResetTimeCount = timeTemp - temp;
    		if (!isPause)
        	{
    			timeCount++;
    			srcRectTimeBar.right = (int)((float)timeCount*(float)srcRightTimeBarMax/(float)remainingTime);
    			desRectTimeBar.right = desRectTimeBar.left + (int)((float)timeCount*(float)desRightTimeBarMax/(float)remainingTime);
        	}
    	}
    }
    
    /* ------------------------------------------------------------------------------- Draw Areas */
    
    private void drawLoading(Canvas canvas)
    {
        // TODO Draw loading
        
    	canvas.save();
    	canvas.drawBitmap(uiButtonBMP, srcRectLoading, desRectLoadingBar, null);
    	canvas.drawBitmap(uiButtonBMP, srcRectLoading, desRectLoading, null);
    	canvas.restore();
    }
    
    private void drawBackground(Canvas canvas)
    {
    	// TODO Draw main menu background
		canvas.save();
		canvas.drawBitmap(PlayBackground, srcRectBackground, desRectBackground, null);
		canvas.restore();
    }
    
    private void drawBottom(Canvas canvas) {
		
    	// TODO Draw Bottom
    	canvas.save();
    	canvas.drawBitmap(bottomSRC, srcRectBtm, desRectBtm, null);
    	canvas.restore();
	}
      
    private void drawUpCannon(Canvas canvas) {
    	// TODO Draw Up Cannon
    	canvas.save();
    	if (!upButtonCheck)
    		canvas.drawBitmap(bottomSRC, srcRectUpBtn, desRectUpBtn, null);
    	else
    		canvas.drawBitmap(bottomSRC, srcRectUpBtn2, desRectUpBtn, null);
    	canvas.restore();
   }
   
    private void drawDownCannon(Canvas canvas) {
		// TODO Draw Down Cannon
    	canvas.save();
    	if (!downButtonCheck) 
    		canvas.drawBitmap(bottomSRC, srcRectDownBtn, desRectDownBtn, null);
    	else	
    		canvas.drawBitmap(bottomSRC, srcRectDownBtn2, desRectDownBtn, null);
    	canvas.restore();
		   
	}
   
    private void drawTimeBar(Canvas canvas)
    {
    	canvas.save();
    	canvas.drawBitmap(bottomSRC, srcRectTimeBar, desRectTimeBar, null);
    	canvas.restore();
    }
    
	private void drawPauseButton(Canvas canvas)
	{
		canvas.save();
		canvas.drawBitmap(uiButtonBMP, srcRectPause, desRectPause, null);
		canvas.restore();
	}
    
    private void drawSoundButton(Canvas canvas)
	{
		// TODO Draw sound on/off button
		canvas.save();
		if (btnMusicSelected)
		{
			canvas.drawBitmap(uiButtonBMP, srcRectSoundOnSelected, desRectSoundOn, null);
		}
		else
		{
			if (MainMenuScreen.soundOn)
				canvas.drawBitmap(uiButtonBMP, srcRectSoundOn, desRectSoundOn, null);
			else
				canvas.drawBitmap(uiButtonBMP, srcRectSoundOff, desRectSoundOff, null);
		}
		canvas.restore();
	}
	
	private void drawFish(Canvas canvas)
	{
		for (int i = 0; i < 11; i++)
			for (int j = 0; j < maxnumFish[i]; j++)
			{
				if (i < 10)
				{
					if (fish[i][j].status > 0)
					{
						fish[i][j].Draw(canvas,fishBMP[i],(fish[i][j].direction==1)?1.0f:-1.0f);
					}
				}
				else
				{
					if (fish[i][j].status == 1)
					{
						fish[i][j].Draw(canvas,sharkBMP[0],((fish[i][j].direction==1)?1.0f:-1.0f));
					}
					else if (fish[i][j].status == 2)
					{
						fish[i][j].Draw(canvas,sharkBMP[1],((fish[i][j].direction==1)?1.0f:-1.0f));
					}
				}
				
				// TODO Draw coin animation
				if (coin[i][j].isShow)
				{
					coin[i][j].Draw(canvas,(i<5?coinSilverBMP:coinGoldBMP));
				}
			}
	}
	
	private void drawCannon(Canvas canvas)
	{
		// TODO Draw Cannon
		cannon[currentCannon].Draw(canvas,cannonBMP[currentCannon]);
	}
	
	private void drawBullet(Canvas canvas)
	{
	   	//TODO Draw bulletBMP
		for (int i = 0; i < 5; i++)
		{
			if (bulletweb[currentCannon][i].acceptDraw)
				bulletweb[currentCannon][i].Draw(canvas,bulletBMP,webBMP);
		}
	}
	
	private void drawNumBlack(Canvas canvas)
	{
		// TODO Draw Number Score
		canvas.save();
		for (int i = 0; i < 6; i++)
			canvas.drawBitmap(numberBlack, srcRectCoin[i], desRectCoin[i], null);
		canvas.restore();
	}
	
	private void drawPauseBackground(Canvas canvas)
	{
		canvas.save();
		canvas.drawBitmap(uiButtonBMP, srcRectPauseBg, desRectPauseBg, null);
		canvas.restore();
	}
	
	private void drawResumeButton(Canvas canvas)
	{
		canvas.save();
		if (btnResumeSelected)
			canvas.drawBitmap(uiButtonBMP, srcRectResumeSelected, desRectResume, null);
		else
			canvas.drawBitmap(uiButtonBMP, srcRectResume, desRectResume, null);
		canvas.restore();
	}

	private void drawRetryButton(Canvas canvas)
	{
		canvas.save();
		if (btnRetrySelected)
			canvas.drawBitmap(uiButtonBMP, srcRectRetrySelected, desRectRetry, null);
		else
			canvas.drawBitmap(uiButtonBMP, srcRectRetry, desRectRetry, null);
		canvas.restore();
	}
	
	private void drawExitButton(Canvas canvas)
	{
		desRectExit = new Rect((int)(2*SplashScreen.scrWidth/5),(int)(4*SplashScreen.scrHeight/6),(int)(3*SplashScreen.scrWidth/5),(int)(5*SplashScreen.scrHeight/6));	
		
		canvas.save();
		if (btnExitSelected)
			canvas.drawBitmap(uiButtonBMP, srcRectExitSelected, desRectExit, null);
		else
			canvas.drawBitmap(uiButtonBMP, srcRectExit, desRectExit, null);
		canvas.restore();
	}
	
	private void drawNextLevel(Canvas canvas)
	{
		BitmapFactory.Options opts = new BitmapFactory.Options(); 
        opts.inPurgeable = true;
		Bitmap levelBMP = BitmapFactory.decodeResource(getResources(), levelBitmap[level-1],opts);
		
		Rect srcRectNextLevel = new Rect(0, 0, levelBMP.getWidth(), levelBMP.getHeight());
		
		canvas.save();
		canvas.drawBitmap(levelBMP, srcRectNextLevel, desRectBackground, null);
		canvas.restore();
	}
	
	/* ------------------------------------------------------------------------------- Functions */
	
	public int round(float input)
	{
		int output = (int)(input+0.5f);
		return output;
	}
	
	public static Bitmap decodeSampledBitmapFromResource(Resources res, int resId,
            int reqWidth, int reqHeight) {

        // First decode with inJustDecodeBounds=true to check dimensions
        final BitmapFactory.Options options = new BitmapFactory.Options();
        options.inJustDecodeBounds = true;
        BitmapFactory.decodeResource(res, resId, options);

        // Calculate inSampleSize
        options.inSampleSize = calculateInSampleSize(options, reqWidth, reqHeight);

        // Decode bitmap with inSampleSize set
        options.inJustDecodeBounds = false;
        return BitmapFactory.decodeResource(res, resId, options);
    }
    
    public static int calculateInSampleSize( BitmapFactory.Options options, int reqWidth, int reqHeight) 
    {
	    // Raw height and width of image
	    final int height = options.outHeight;
	    final int width = options.outWidth;
	    int inSampleSize = 1;
	
	    if (height > reqHeight || width > reqWidth) {
	
	        // Calculate ratios of height and width to requested height and width
	        final int heightRatio = Math.round((float) height / (float) reqHeight);
	        final int widthRatio = Math.round((float) width / (float) reqWidth);
	
	        // Choose the smallest ratio as inSampleSize value, this will guarantee
	        // a final image with both dimensions larger than or equal to the
	        // requested height and width.
	        inSampleSize = heightRatio < widthRatio ? heightRatio : widthRatio;
	    }
	
	    return inSampleSize;
	}
	
	private void resetFish(int i, int j)
	{
		// TODO Fish death, reset
		if (fish[i][j].direction == 1)
		{
			fish[i][j].Position.X = -fish[i][j].animation.FrameWidth-fishLeftReset;    	// Reset left
		}
		else if (fish[i][j].direction == 0)
		{
			fish[i][j].Position.X = fishRightReset;										// Reset right
		}
		fish[i][j].status = 1;             // Alive
		fish[i][j].health = health[i];
		degreeFish[i][j] = 0;
		randomGetRoute(i, j);
		// TODO Set fish wait to reset move
		fish[i][j].onMove = 2;
	}
	
	private void randomGetRoute(int i, int j)
	{
		// TODO Random position to start go route
		int tempRandPos = 0;
		if (fish[i][j].direction == 1)
		{
			tempRandPos = random.nextInt(2*SplashScreen.scrWidth/3) + SplashScreen.scrWidth/3;
		}
		else
		{
			tempRandPos = random.nextInt(2*SplashScreen.scrWidth/3);
		}
		// TODO Random turn left or turn right
		int tempRand = random.nextInt(3);
		int leftRight = 0;
		if (tempRand == 0)
			leftRight = -1;
		else if (tempRand == 1)
			leftRight = 1;
		
		int tempRandYPos = random.nextInt(9*SplashScreen.scrHeight/10);
		
		fish[i][j].posRoute = tempRandPos;
		fish[i][j].leftRight = leftRight;
		fish[i][j].enableRoute = false;
		fish[i][j].Position.Y = tempRandYPos;
		posYFish[i][j] = fish[i][j].Position.Y;
		fish[i][j].gotRoute = false;
		fish[i][j].radius = 0;
	}
	
	private boolean getRoute(int i, int j)
	{
		boolean result = true;
		Position centerO = new Position();
		if (!fish[i][j].gotRoute)
		{
			if (fish[i][j].direction == 1)
			{
				if (fish[i][j].leftRight == -1)
				{
					// TODO Turn left
					fish[i][j].radius = (float)Math.sqrt(
							(SplashScreen.scrWidth+fish[i][j].Position.Y)*(SplashScreen.scrWidth+fish[i][j].Position.Y) +
							(fish[i][j].Position.X*fish[i][j].Position.X));
				}
				else if (fish[i][j].leftRight == 1)
				{
					// TODO Turn right
					fish[i][j].radius = (float)Math.sqrt(
							(SplashScreen.scrWidth+SplashScreen.scrHeight-fish[i][j].Position.Y)*(SplashScreen.scrWidth+SplashScreen.scrHeight-fish[i][j].Position.Y) +
							(fish[i][j].Position.X*fish[i][j].Position.X));
				}
			}
			else if (fish[i][j].direction == 0)
			{
				if (fish[i][j].leftRight == -1)
				{
					// TODO Turn left
					fish[i][j].radius = (float)Math.sqrt(
							((SplashScreen.scrWidth+SplashScreen.scrHeight-fish[i][j].Position.Y)*(SplashScreen.scrWidth+SplashScreen.scrHeight-fish[i][j].Position.Y)) +
							((SplashScreen.scrWidth-fish[i][j].Position.X)*(SplashScreen.scrWidth-fish[i][j].Position.X)));
				}
				else if (fish[i][j].leftRight == 1)
				{
					// TODO Turn right
					fish[i][j].radius = (float)Math.sqrt(
							(SplashScreen.scrWidth+fish[i][j].Position.Y)*(SplashScreen.scrWidth+fish[i][j].Position.Y) +
							((SplashScreen.scrWidth-fish[i][j].Position.X)*(SplashScreen.scrWidth-fish[i][j].Position.X)));
				}
			}
			
			fish[i][j].gotRoute = true;
		}
		// TODO Get center of circle
		if (fish[i][j].direction == 1)
		{
			// TODO Left to right
			
			if (fish[i][j].leftRight == -1)
			{
				// TODO Turn left
				centerO = new Position(0,-SplashScreen.scrWidth);
			}
			else if (fish[i][j].leftRight == 1)
			{
				// TODO Turn right
				centerO = new Position(0,SplashScreen.scrWidth+SplashScreen.scrHeight);
			}
		}
		else if (fish[i][j].direction == 0)
		{
			// TODO Right to left
			
			if (fish[i][j].leftRight == -1)
			{
				// TODO Turn left
				centerO = new Position(SplashScreen.scrWidth,SplashScreen.scrWidth+SplashScreen.scrHeight);
			}
			else if (fish[i][j].leftRight == 1)
			{
				// TODO Turn right
				centerO = new Position(SplashScreen.scrWidth,-SplashScreen.scrWidth);
			}
		}
		if (fish[i][j].leftRight != 0)
		{
			// Get y position
			float tempY = getYfromX(fish[i][j].Position.X, centerO, fish[i][j].radius);
			if (tempY != 9999)
			{
				float x = 0;
				fish[i][j].Position.Y = tempY;
				x = tangentialEquation(fish[i][j].Position, centerO, posYFish[i][j], fish[i][j].radius);
				// TODO Get degree to rotate fish
				degreeFish[i][j] = calculateDegree(fish[i][j].Position, new Position(x, posYFish[i][j]), true);
			}
			else
				result = false;
		}
		return result;
	}
	
	private float getYfromX(float x, Position centerO, float r)
	{
		float y = 0;
		int a = 1;
		int b = (int)(-2*centerO.Y);
		int c = (int)((x*x) - (int)(2*centerO.X*x) + (int)(centerO.X*centerO.X) + (int)(centerO.Y*centerO.Y) - r*r); 
		y = equation2(a, b, c);
		return y;
	}
	
	private float equation2(int a, int b, int c)
	{
		float x1 = 0;
		float x2 = 0;
		float x = 9999;
		float delta = 0;
	
		delta=b*b-4*a*c;
		if (delta>0)
		{
			x1 = (float)((-b-Math.sqrt(delta))/(2*a));
			x2 = (float)((-b+Math.sqrt(delta))/(2*a));
		}
		else // a<>0 ,delta <=0
		{
			if (delta==0)
			{
				x1 = -b/(2*a);
			}
		}
		if (x2 == 0)
			x = x1;
		else
		{
			if (x1 >= -200 && x1 <= SplashScreen.scrHeight+200)
				x = x1;
			else if (x2 >= -200 && x2 <= SplashScreen.scrHeight+200)
				x = x2;
		}
		return x;
	}
	
	private void resetBullet(int cbullet)
	{
		bulletweb[currentCannon][cbullet].aFactor = 0;
		bulletweb[currentCannon][cbullet].bFactor = 0;
		bulletweb[currentCannon][cbullet].degrees = 0;
		bulletweb[currentCannon][cbullet].isBang = true;
		bulletweb[currentCannon][cbullet].destinationRect = 
			new Rect((int)(cannonCenterPosition.X-cannonScale*((bulletweb[currentCannon][cbullet].sourceRect.right - bulletweb[currentCannon][cbullet].sourceRect.left)/2)), 
					 (int)(cannon[currentCannon].animation.destinationRect.centerY()-cannonScale*((bulletweb[currentCannon][cbullet].sourceRect.bottom - bulletweb[currentCannon][cbullet].sourceRect.top)/3)), 
					 (int)(cannonCenterPosition.X+cannonScale*((bulletweb[currentCannon][cbullet].sourceRect.right - bulletweb[currentCannon][cbullet].sourceRect.left)/2)), 
					 (int)(cannon[currentCannon].animation.destinationRect.centerY()+cannonScale*(2*(bulletweb[currentCannon][cbullet].sourceRect.bottom - bulletweb[currentCannon][cbullet].sourceRect.top)/3)));
	}
		
	private int calculateDegree(Position pos, Position pos2, boolean fish)
	{
		int result = 0;
		float temp = 0f;
		float temp2 = 0f;
		double radian = 0;
		int degree = 0;
		double x = 0;
		double y = 0;
		if (fish)
		{
			// TODO Calculate degree to rotate cannon
			temp = pos.Y - pos2.Y;
			temp2 = pos.X - pos2.X;
			y = Math.abs(temp);
			x = Math.abs(temp2);
			// TODO Radian angle
			radian = Math.atan(y/x);
		}
		else
		{
			// TODO Calculate degree to rotate cannon
			temp = pos.X - pos2.X; 
			x = Math.abs(temp);
			y = Math.abs(pos.Y - pos2.Y);
			// TODO Radian angle
			radian = Math.atan(x/y);
		}
		// TODO Degree angle
		degree = (int)(radian*180/Pi);
		// TODO Return -degree to rotate to the left, degree to rotate to the right
		if (fish)
		{
			if (((temp > 0) && (temp2 > 0)) || ((temp < 0) && (temp2 < 0)))
				result = degree;
			else if (((temp > 0) && (temp2 < 0)) || ((temp < 0) && (temp2 > 0)))
				result = -degree;
		}
		else
		{
			if (temp > 0)
				result = degree;
			else
				result = -degree;
		}
		return result;
	}
	
	private float tangentialEquation(Position pos, Position centerO, float y, float r)
	{
		float x = 0;
		x = (centerO.X*pos.X - centerO.X*centerO.X - (y - centerO.Y)*(pos.Y - centerO.Y) + r*r)/(pos.X - centerO.X);
		return x;
	}

	private void equations(float posX, float posY, int cbullet)
	{
		bulletweb[currentCannon][cbullet].aFactor = ((float)bulletweb[currentCannon][cbullet].destinationRect.exactCenterY() - posY) / ((float)bulletweb[currentCannon][cbullet].destinationRect.exactCenterX() - posX);
		bulletweb[currentCannon][cbullet].bFactor = posY - bulletweb[currentCannon][cbullet].aFactor*posX;
	}

	private boolean checkCollision(Position pos, int cbullet)
	{
		boolean coll = false; 
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < maxnumFish[i]; j++)
			{
				if ((fish[i][j].animation.destinationRect.left <= pos.X) && (fish[i][j].animation.destinationRect.right >= pos.X)
						&& (fish[i][j].animation.destinationRect.top <= pos.Y) && (fish[i][j].animation.destinationRect.bottom >= pos.Y))
				{
					if (bulletweb[currentCannon][cbullet].power >= fish[i][j].health)
					{
						bulletweb[currentCannon][cbullet].power = bulletweb[currentCannon][cbullet].power - fish[i][j].health;
						fish[i][j].health = 0;
					}
					else 
					{
						fish[i][j].health -= bulletweb[currentCannon][cbullet].power;
						bulletweb[currentCannon][cbullet].power = 0;
					}
					
					// TODO Mark fish prepare to death 
					if (fish[i][j].health == 0)
					{
						fish[i][j].status = 2;
						if(MainMenuScreen.soundOn)
						{
							MediaPlayer mediaPlayer_fishdie = MediaPlayer.create(this, R.raw.sound_fishdie);
							mediaPlayer_fishdie.start();
						}
					}
					bulletweb[currentCannon][cbullet].webPosition = pos;
					coll = true;
				}
			}
		}
		
		// TODO Reset bullet
		if (coll)
			resetBullet(cbullet);
		return coll;
	}
		
	private void nextLevel()
	{
		isNextLevel = true;
		isPause = true;
		pointGot = 0;
		level++;
		readLevel(level);
		if (level != 1)
			for (int i = 0; i < 11; i++)
				for (int j = 0; j < maxnumFish[i]; j++)
					resetFish(i, j);
		timeNextLevel = System.currentTimeMillis();
		timeCount = 0;
		timeResetTimeCount = 0;
	}
	
	private void readLevel(int level)
	{
		String lineData = null;
		BufferedReader br;
		try
	    {
	    	InputStream is = getApplicationContext().getResources().openRawResource(levelFilename[level-1]);
			br = new BufferedReader(new InputStreamReader(is), 8192);
			
			// remaining time
			lineData = br.readLine();
			StringTokenizer lineToken = new StringTokenizer(lineData," ");
			remainingTime = Integer.parseInt(lineToken.nextToken().toString());
			
			// coin
			lineData = br.readLine();
			lineToken = new StringTokenizer(lineData," ");
			money = Integer.parseInt(lineToken.nextToken().toString());
			
			// point to next level
			lineData = br.readLine();
			lineToken = new StringTokenizer(lineData," ");
			pointToNextLevel = Integer.parseInt(lineToken.nextToken().toString());
			
			// num of fish
			lineData = br.readLine();
			lineToken = new StringTokenizer(lineData," ");
			numFish = Integer.parseInt(lineToken.nextToken().toString());
			
			// num of each fish
			lineData = br.readLine();
			lineToken = new StringTokenizer(lineData," ");
			for (int i = 0; i < 11; i++)
			{
				maxnumFish[i] = Integer.parseInt(lineToken.nextToken().toString());
			}
			
	    }
	    catch (Exception e) 
	    {       
	        e.printStackTrace();          
	    }
	}
		
	/* ------------------------------------------------------------------------------- Input */
	
	@Override
	public boolean onTouchEvent(MotionEvent event) {
		// TODO Get touch event
		if (event.getAction() == MotionEvent.ACTION_DOWN && !isNextLevel)
		{
			Log.d(TAG,"posX "+event.getX()+" "+"posY "+event.getY());
			int touchOnID = checkPosition(event);
			switch(touchOnID)
			{
				case 0 : {
					// TODO Choose shoot, set destination position of bullet
					cannon[currentCannon].isShoot = true;
					desBulletPosition.SetPosition(event.getX(),event.getY());
					equations((int)event.getX(), (int)event.getY(),currentBullet);
//					if (checkCollision(new Position(event.getX(), event.getY())))
//					{
						degreeCannon = calculateDegree(desBulletPosition,new Position(cannon[currentCannon].animation.destinationRect.exactCenterX(), cannon[currentCannon].animation.destinationRect.exactCenterY()),false);
//					}
					break;
				}
				case 1 : {
					// TODO Choose + button.
					upButtonCheck=true;
					timeReleaseBtn = System.currentTimeMillis();
					currentCannon++;
					if (currentCannon==7)
						currentCannon = 0;
					break;
				}
				case 2 : {
					// TODO Choose - button.
					downButtonCheck=true;
					timeReleaseBtn = System.currentTimeMillis();
					currentCannon--;
					if (currentCannon==-1)
						currentCannon = 6;
					break;
				}
				case 3 : {
					// TODO Pause
					//MainMenuScreen.soundOn=!MainMenuScreen.soundOn;
					isPause = true;
					break;
				}
				case 4 : {
					// TODO Resume
					btnResumeSelected = true;
					break;
				}
				case 5 : {
					btnRetrySelected = true;
					break;
				}
				case 6 : {
					btnExitSelected = true;
					break;
				}
				case 7 : {
					// TODO Touch on sound button
					MainMenuScreen.soundOn = !MainMenuScreen.soundOn;
					
					if(mediaPlayer_background.isPlaying())
					{
						mediaPlayer_background.stop();
						try {
							mediaPlayer_background.prepare();
						} catch (IOException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					}
					else
					{
						mediaPlayer_background.start();
						mediaPlayer_background.setLooping(true);
					}
					break;
				}
				default : 
					break;
			}
		}
		return super.onTouchEvent(event);
	}
	
	private int checkPosition(MotionEvent event)
	{

		// TODO check touch position for action
		int posX = (int)event.getX();
		int posY = (int)event.getY();
		Log.d(TAG,"posX "+posX+" "+"posY "+posY);
		if (!isPause)
		{
			if(posY >= (desRectBtm.top+ (desRectBtm.bottom-desRectBtm.top)/2))
			{
				// TODO Touch on bottom bar
				
				if (((posX>=desRectUpBtn.left)&&(posX<=desRectUpBtn.right))&&((posY>=desRectUpBtn.top)&&(posY<=desRectUpBtn.bottom))) 
				{
					// TODO Touch on + button
					Log.i(TAG,"Return 1");
					return 1;	
				}
				else if (((posX>=desRectDownBtn.left)&&(posX<=desRectDownBtn.right))&&((posY>=desRectDownBtn.top)&& posY<=desRectDownBtn.bottom)) 
				{
					// TODO Touch on - button
					Log.i(TAG,"Return 2");
					return 2;
				}
				else if (((posX >= desRectPause.left) && (posX <= desRectPause.right)) && ((posY >= desRectPause.top)&&(posY <= desRectPause.bottom)))
				{
					return 3;
				}
				
				return 8;
			}
		}
		else
		{
			if (((posX>=desRectResume.left)&&(posX<=desRectResume.right))&&((posY>=desRectResume.top)&&(posY<=desRectResume.bottom))) 
			{
				// TODO Touch on resume button
				Log.i(TAG,"Return 4");
				return 4;	
			}
			else if (((posX>=desRectRetry.left)&&(posX<=desRectRetry.right))&&((posY>=desRectRetry.top)&& posY<=desRectRetry.bottom)) 
			{
				// TODO Touch on option button
				Log.i(TAG,"Return 5");
				return 5;
			}
			else if (((posX >= desRectExit.left) && (posX <= desRectExit.right)) && ((posY >= desRectExit.top)&&(posY <= desRectExit.bottom)))
			{
				// Button exit
				return 6;
			}
			else if (((posX >= desRectSoundOn.left) && (posX <= desRectSoundOn.right)) && ((posY >= desRectSoundOn.top)&&(posY <= desRectSoundOn.bottom)))
			{
				// Button sound
				return 7;
			}
			
			return 9;
		}
		return 0;
	}
	
	private void exit()
	{
		handlerDrawing.removeCallbacks(runnableDrawing);
		loaded = false;
		mediaPlayer_background.stop();
		finish();
		startActivity(intentMainMenu);
		
	}
	
	@Override
	protected void onPause() {
		// TODO Auto-generated method stub
		handlerDrawing.removeCallbacks(runnableDrawing);
		loaded = false;
		mediaPlayer_background.stop();
		super.onPause();
	}
	
	@Override
	public void onBackPressed() {
		// TODO Auto-generated method stub
		handlerDrawing.removeCallbacks(runnableDrawing);
		loaded = false;
		//MainMenuScreen.stopped = false;
		startActivity(intentMainMenu);
		mediaPlayer_background.stop();
		finish();
		super.onBackPressed();
	}
}
