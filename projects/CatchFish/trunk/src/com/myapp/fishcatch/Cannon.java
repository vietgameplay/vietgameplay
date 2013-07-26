package com.vietgameplay.fishcatch;

import android.graphics.Bitmap;
import android.graphics.Canvas;

public class Cannon {
	
	// Pi
	float Pi = 3.1415f;
		
	// The animation of Cannon
	Animation animation;
	
	// The image of Cannon
	//Bitmap spriteStrip;
	
	// Mark cannon shoot
	boolean isShoot;
	
	// Mark cannon rotate
	boolean isRotated;
	
	// Power
	int power;
	
	// Degree
	int sumDegree;
	
    // Position
    public Position Position;

    public void Initialize( Position position, boolean shoot, boolean rotated, int power)
    {
    	
    	//this.spriteStrip = texture;
    	//this.spriteStrip = Bitmap.createBitmap(texture);
    	this.Position = position;
    	this.isShoot = shoot;
    	this.isRotated = rotated;
    	this.sumDegree = 0;
    	this.power = power;
    }
    
    public void InitializeAnimation( Position position, int frameWidth, int frameHeight,int startFrame, int frameCount, int frametime, float scale, boolean looping)
    {
    	this.animation = new Animation(position, frameWidth, frameHeight, startFrame, frameCount, frametime, scale, looping);
    }
    
    public void Update()
    {
    	this.animation.Position = this.Position;
    	this.animation.Update(Position,true);
    }
    
    public void Update(int degree)
    {
    	this.sumDegree = degree;
    	this.animation.Update(Position,false);
    }
    
    public void Draw(Canvas canvas, Bitmap spriteStrip)
    {
    	this.animation.Draw(canvas, sumDegree, spriteStrip);
    }
}
