package com.vietgameplay.fishcatch;

import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import com.vietgameplay.fishcatch.R;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.pm.ActivityInfo;
import android.content.res.Configuration;
import android.graphics.Color;
import android.os.Bundle;
import android.util.Log;
import android.view.Gravity;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.Window;
import android.view.ViewGroup.LayoutParams;
import android.view.inputmethod.InputMethodManager;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

public class EndGameScreen extends Activity {

	// TODO Declare variable
	private static final String TAG = "DEBUG";
		
	Intent intentMainMenu;
	
	String data[];
	
	int pos = -1;
	boolean getName;
	boolean gameOver;
	int score;
	
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
		
		score = Integer.parseInt(data.substring(4, data.length()));
		
		getName = readScore(score);
        
		//this.getWindow().setSoftInputMode(WindowManager.LayoutParams.SOFT_INPUT_STATE_ALWAYS_VISIBLE);
			
		// TODO Initialize
		LinearLayout endgameLayout = new LinearLayout(this);
		ImageView imgEndGame = new ImageView(this);
		
		// TODO Setting
		imgEndGame.setLayoutParams(new LayoutParams(SplashScreen.scrWidth,3*SplashScreen.scrHeight/10));
		if (gameOver)
			imgEndGame.setImageResource(R.drawable.game_over);
		else
			imgEndGame.setImageResource(R.drawable.end_game);
		
		endgameLayout.setBackgroundResource(R.drawable.endgamebg);
		endgameLayout.setLayoutParams(new LayoutParams(SplashScreen.scrWidth, SplashScreen.scrHeight));
		endgameLayout.setOrientation(LinearLayout.VERTICAL);
		endgameLayout.setGravity(Gravity.CENTER);
		endgameLayout.addView(imgEndGame,0);
		
		if (getName)
		{
			LinearLayout nameInputLayout = new LinearLayout(this);
			TextView lblName = new TextView(this);
			final EditText txtName = new EditText(this);
			Button btnOK = new Button(this);
		
			lblName.setText("Your name : ");
			lblName.setTextSize(SplashScreen.scrHeight/30);
			lblName.setTextColor(Color.BLUE);
			lblName.setLayoutParams(new LayoutParams(SplashScreen.scrWidth/6,SplashScreen.scrHeight/10));
			
			txtName.setLayoutParams(new LayoutParams(2*SplashScreen.scrWidth/6,SplashScreen.scrHeight/10));
			txtName.setFocusable(true);
			
			btnOK.setText("OK");
			btnOK.setTextSize(SplashScreen.scrHeight/30);
			btnOK.setTextColor(Color.BLUE);
			btnOK.setLayoutParams(new LayoutParams(SplashScreen.scrWidth/6,SplashScreen.scrHeight/10));
			btnOK.setOnClickListener(new OnClickListener() {
				
				public void onClick(View v) {
					// TODO Auto-generated method stub
					if (txtName.getText().toString().length() > 6 && txtName.getText().toString().length() < 30)
						writeScore(txtName.getText().toString());
					else
						Toast.makeText(getApplicationContext(), "You need to enter your name at least 6 character before leave.", Toast.LENGTH_LONG).show();
				}
			});
			
			nameInputLayout.setLayoutParams(new LayoutParams(SplashScreen.scrWidth, SplashScreen.scrHeight/10));
			nameInputLayout.setOrientation(LinearLayout.HORIZONTAL);
			nameInputLayout.setGravity(Gravity.CENTER);
			nameInputLayout.addView(lblName, 0);
			nameInputLayout.addView(txtName, 1);
			nameInputLayout.addView(btnOK, 2);
			
			endgameLayout.setGravity(Gravity.TOP);
			endgameLayout.addView(nameInputLayout, 1);
			
			InputMethodManager imm = (InputMethodManager)this.getSystemService(Context.INPUT_METHOD_SERVICE);

			if (imm != null){
			    imm.toggleSoftInput(InputMethodManager.SHOW_FORCED,0);
			    imm.showSoftInput(getCurrentFocus(), 0);
			}
		}
		
        setContentView(endgameLayout);
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
	    	InputStream is = openFileInput("highscore.txt");
			br = new BufferedReader(new InputStreamReader(is), 8192);
			int i = 0;
			while((lineData = br.readLine()) != null)
			{
				data[i] = "" + lineData + "\n";
				if (pos == -1)
				{
					try
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
					catch (Exception e) {
						// TODO: handle exception
						e.printStackTrace();
					}
				}
				i++;
			}
	    }
	    catch (Exception e) 
	    {       
	    	for (int i = 0; i < 5; i++)
	    		data[i] = "";
	    	result = true;
	        e.printStackTrace();          
	    }
		
		if (pos == -1)
		{
			for (int i = 0; i < 5; i++)
				if (data[i] == null || data[i] == "")
				{
					result = true;
					pos = i;
				}
		}
		
		if (result)
			return true;
		else
			return false;
	}
	

	@SuppressLint("WorldWriteableFiles")
	private void writeScore(String name)
	{
		String dataSave = "";
		
		if (pos != -1)
		{
			for (int i = 4; i > pos; i--)
			{
				data[i] = data[i-1];
			}
			data[pos] = "" + name + " " + score + "\r\n";
		
			for (int i = 0; i < 5; i++)
			{
				if (data[i] != null && data[i] != "")
					dataSave += data[i];
			}
		}
		else
		{
			dataSave = "" + name + " " + score + "\r\n";
		}
		
		try
		{
			FileOutputStream fos = openFileOutput("highscore.txt", Context.MODE_WORLD_WRITEABLE);
			fos.write(dataSave.getBytes());
			fos.close();
		}
		catch (IOException e) {
			// TODO: handle exception
			e.printStackTrace();
		}
		startActivity(intentMainMenu);
		finish();
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
		finish();
		super.onPause();
	}
	
	@Override
	public void onBackPressed() 
	{
		// TODO When press back button
		startActivity(intentMainMenu);
		finish();
		super.onBackPressed();
	}
}
