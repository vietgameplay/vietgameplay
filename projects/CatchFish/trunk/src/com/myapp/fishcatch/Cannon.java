package com.myapp.fishcatch;

import android.graphics.Bitmap;
import android.graphics.Canvas;

public class Cannon {
	
	// Pi
	float Pi = 3.1415f;
		
	// The animation of Cannon
	Animation animation;
	
	// The image of Cannon
	Bitmap spriteStrip;
	
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

    public void Initialize(Animation animation, Bitmap texture, Position position, boolean shoot, boolean rotated, int power)
    {
    	this.animation = animation;
    	this.spriteStrip = texture;
    	this.Position = position;
    	this.isShoot = shoot;
    	this.isRotated = rotated;
    	this.sumDegree = 0;
    	this.power = power;
    }
    
    public void Update()
    {
    	this.animation.Position = this.Position;
    	this.animation.Update(false);
    }
    
    public void Update(int degree)
    {
    	this.sumDegree = degree;
    	this.animation.Update(Position);
    }
    
    public void Draw(Canvas canvas)
    {
    	this.animation.Draw(canvas, sumDegree);
    }
}
