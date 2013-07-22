package com.vietgameplay.fishcatch;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Rect;

public class Coin {

	// The animation of coin
	Animation animation;
	
	// The image of coin
	//Bitmap spriteStrip;
	
	// The image of coin number
	Bitmap spriteStripText;
	
	// Show or hide
	public boolean isShow;
	
	// Frame Width
	int frameWidth;
	
	// Frame Height
	int frameHeight;
    
    // Mark initialized
    boolean initialized;
    
    // Position of cointext
    Position positionCT;
    
    // Scale
    float scale;
    
    int numCoin0;
    int numCoin1;
	
	 // Position
    public Position Position;
    
    public void Initialize(Bitmap texture, int frameWidth, int frameHeight,int numcoin0, int numcoin1, float scale)
    {
    	this.scale = scale;
    	this.spriteStripText = texture;
    	this.frameWidth = frameWidth;
    	this.frameHeight = frameHeight;
    	this.positionCT = new Position(animation.destinationRect.right,animation.destinationRect.top);
    	this.initialized = true;
    	this.numCoin0 = numcoin0;
    	this.numCoin1 = numcoin1;
    }
    
    public void Initialize(Position position, boolean show)
    {
    	
    	//this.spriteStrip = texture;
    	this.Position = position;
    	this.isShow = show;
    	this.initialized = false;
    }
    
    public void InitializeAnimation( Position position, int frameWidth, int frameHeight,int startFrame, int frameCount, int frametime, float scale, boolean looping)
    {
    	this.animation = new Animation(position, frameWidth, frameHeight, startFrame, frameCount, frametime, scale, looping);
    }
    
    public void Update()
    {
    	this.animation.Position = Position;
    	this.animation.Update(false);
    	this.positionCT = new Position(this.animation.destinationRect.right,this.animation.destinationRect.top);
    }
    
    public void Draw(Canvas canvas, Bitmap spriteStrip)
    {
    	this.animation.Draw(canvas,spriteStrip);
    	canvas.save();
    	canvas.drawBitmap(spriteStripText, new Rect(91*spriteStripText.getWidth()/100,0,spriteStripText.getWidth(),spriteStripText.getHeight()), new Rect((int)positionCT.X,(int)positionCT.Y+spriteStripText.getHeight()/6,(int)positionCT.X+2*spriteStripText.getWidth()/33,(int)positionCT.Y+spriteStripText.getHeight()/2), null);
    	canvas.drawBitmap(spriteStripText, new Rect((int)(numCoin0*9.1*spriteStripText.getWidth()/100),0,(int)((numCoin0+1)*9.1*spriteStripText.getWidth()/100),spriteStripText.getHeight()), new Rect((int)positionCT.X+2*spriteStripText.getWidth()/33,(int)positionCT.Y,(int)positionCT.X+7*spriteStripText.getWidth()/66,(int)positionCT.Y+spriteStripText.getHeight()/2), null);
    	canvas.drawBitmap(spriteStripText, new Rect((int)(numCoin1*9.1*spriteStripText.getWidth()/100),0,(int)((numCoin1+1)*9.1*spriteStripText.getWidth()/100),spriteStripText.getHeight()), new Rect((int)positionCT.X+7*spriteStripText.getWidth()/66,(int)positionCT.Y,(int)positionCT.X+5*spriteStripText.getWidth()/33,(int)positionCT.Y+spriteStripText.getHeight()/2), null);
    	canvas.restore();
    }
}
