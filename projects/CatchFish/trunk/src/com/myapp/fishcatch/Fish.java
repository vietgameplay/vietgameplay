package com.vietgameplay.fishcatch;

import android.graphics.Bitmap;
import android.graphics.Canvas;


public class Fish {

	// The animation of Fish
	Animation animation;
	
	// The image of Fish
	//Bitmap spriteStrip;

    // Position
    public Position Position;
    
    // Direction
    public int direction;
    
    // moving: 1, or stop: 0, or wait to set move: 2
    public int onMove;
    
    // Health
    public int health;
    
    // Time to show death animation and coin
    long timeOutFish;
    
    // Time to set new move
    long timeResetMove;
    
    // Death 0 or alive 1 or prepare to death 2
    public int status;
    
    // Enable route
    public boolean enableRoute;
    
    // Mark for get route
    public boolean gotRoute;
    
    // Radius of circle route
    public float radius;
    
    // Position to go to route
    public int posRoute;
    
    // Degree to rotate
    public int degree;
    
    // Turn left -1 or turn right 1.
    public int leftRight;
    
    public void InitializeAnimation( Position position, int frameWidth, int frameHeight,int startFrame, int frameCount, int frametime, float scale, boolean looping)
    {
    	this.animation = new Animation(position, frameWidth, frameHeight, startFrame, frameCount, frametime, scale, looping);
    }
    
    public void Initialize( Position position, int direct, int health, long timeoutFish,int onMove, int status, int posRoute, int leftRight, boolean enableRoute)
    {
    	//this.spriteStrip = texture;
    	//this.spriteStrip = Bitmap.createBitmap(texture);
    	this.Position = position;
    	this.status = status;
    	this.direction = direct;
    	this.health = health;
    	this.onMove = onMove;
    	this.timeOutFish = timeoutFish;
    	this.degree = 0;
    	this.leftRight = leftRight;
    	this.enableRoute = enableRoute;
    	this.posRoute = posRoute;
    	this.gotRoute = false;
    	this.radius = 0;
    	this.timeResetMove = 0;
    }
    
    public void Update(boolean shark, int degree)
    {
    	this.animation.Position = Position;
    	this.degree = degree;
    	this.animation.Update(shark);
    }
    
    public void Draw(Canvas canvas, Bitmap spriteStrip, float scaleX)
    {
    	this.animation.Draw(canvas, degree, spriteStrip, scaleX);
    }
}
