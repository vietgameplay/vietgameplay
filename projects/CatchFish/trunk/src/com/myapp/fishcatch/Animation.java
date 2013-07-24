package com.vietgameplay.fishcatch;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Rect;

public class Animation {
	
	// Pi
	float Pi = 3.1415f;
		
	// Texture
	//Bitmap spriteStrip;
	
	// The scale used to display the sprite strip
    float scale;

    // Time to control elapsedtime
    long oldTime;
    
    // The time since we last updated the frame
    int elapsedTime;

    // The time we display a frame until the next one
    int frameTime;

    // The number of frame start
    int startFrame;
    
    // The number of frames that the animation contains
    int frameCount;

    // The index of the current frame we are displaying
    public int currentFrame;

    // The area of the image strip we want to display
    Rect sourceRect = new Rect();

    // The area where we want to display the image strip in the game
    Rect destinationRect = new Rect();

    // Width of a given frame
    public int FrameWidth;

    // Height of a given frame
    public int FrameHeight;

    // The state of the Animation
    public boolean Active;

    // Determines if the animation will keep playing or deactive after one run
    public boolean Looping;

    // Position
    public Position Position;

    // Go forward
    public boolean Forward;
    
    public Animation( Position position, int frameWidth, int frameHeight,int startFrame, int frameCount, int frametime, float scale, boolean looping)
    {
    	 // Keep a local copy of the values passed in
    	this.Position = position;
        //this.spriteStrip = Bitmap.createBitmap(texture);
    	//this.spriteStrip = texture;
        this.FrameWidth = frameWidth;
        this.FrameHeight = frameHeight;
        this.frameCount = frameCount;
        this.frameTime = frametime;
        this.scale = scale;
        
        Looping = looping;

        // Set the time to zero
        elapsedTime = 0;
        oldTime = 0;
        currentFrame = startFrame;

        // Set the Animation to active by default
        Active = true;

        // Set way to go
        Forward = true;
    }
    
//    public void Initialize( Position position, int frameWidth, int frameHeight,int startFrame, int frameCount, int frametime, float scale, boolean looping)
//    {
//        // Keep a local copy of the values passed in
//    	this.Position = position;
//        //this.spriteStrip = Bitmap.createBitmap(texture);
//    	//this.spriteStrip = texture;
//        this.FrameWidth = frameWidth;
//        this.FrameHeight = frameHeight;
//        this.frameCount = frameCount;
//        this.frameTime = frametime;
//        this.scale = scale;
//        
//        Looping = looping;
//
//        // Set the time to zero
//        elapsedTime = 0;
//        oldTime = 0;
//        currentFrame = startFrame;
//
//        // Set the Animation to active by default
//        Active = true;
//
//        // Set way to go
//        Forward = true;
//    }
    
    public void Update(boolean shark)
    {
        // Do not update the game if we are not active
        if (Active == false)
            return;
        // Update the elapsed time
        if (oldTime == 0)
        	oldTime = System.currentTimeMillis();

        elapsedTime = (int)(System.currentTimeMillis()-oldTime);

        // If the elapsed time is larger than the frame time
        // We need to switch frames
        if (elapsedTime > frameTime)
        {
            // Move to the next frame
            currentFrame++;

            // If currentFrame is equal to frameCount reset currentFrame to zero
            if (currentFrame == frameCount)
            {
                currentFrame = startFrame;
                // If we are not looping deactivate the animation
                if (Looping == false)
                    Active = false;
            }

            // Reset the elapsed time to zero
            elapsedTime = 0;
            oldTime = System.currentTimeMillis();
        }

        // Grap the correct frame in the image strip y multiflying the currentFrame index by the frame width
        sourceRect = new Rect(0, currentFrame * FrameHeight, FrameWidth, (currentFrame * FrameHeight)+ FrameHeight);
        if (shark && currentFrame >= frameCount/2)
        	sourceRect = new Rect(FrameWidth, (currentFrame-frameCount/2) * FrameHeight, 2*FrameWidth, ((currentFrame-frameCount/2) * FrameHeight)+ FrameHeight);
        // Grap the correct frame in the image strip by multiflyig the current Frame index by te frame width
        //if (shark)
        	destinationRect = new Rect((int)Position.X, (int)Position.Y,(int)Position.X + FrameWidth, (int)Position.Y + FrameHeight);
        //else
        	//destinationRect = new Rect((int)Position.X, (int)Position.Y,(int)Position.X + (int)(FrameWidth * scale), (int)Position.Y + (int)(FrameHeight * scale));
        
    }
    
    public void Update(Position Pos)
    {
    	// Grap the correct frame in the image strip y multiflying the currentFrame index by the frame width
        sourceRect = new Rect(0, currentFrame * FrameHeight, FrameWidth, (currentFrame * FrameHeight)+ FrameHeight);
        // Grap the correct frame in the image strip by multiflyig the current Frame index by te frame width
        destinationRect = new Rect((int)Pos.X, (int)Pos.Y,(int)Pos.X + (int)(FrameWidth * scale), (int)Pos.Y + (int)(FrameHeight * scale));
    }
    
    // TODO Draw function for coin,...
    public void Draw(Canvas canvas, Bitmap spriteStrip)
    {
    	canvas.save();
    	canvas.drawBitmap(spriteStrip, sourceRect, destinationRect, null);
    	canvas.restore();
    }
    
    // TODO Draw function for cannon
    public void Draw(Canvas canvas, int degree, Bitmap spriteStrip)
    {
    	canvas.save();
		canvas.rotate(degree, destinationRect.exactCenterX(), destinationRect.exactCenterY());
		canvas.drawBitmap(spriteStrip, sourceRect, destinationRect, null);
		canvas.restore();
    }
    
    // TODO Draw function for fish
    public void Draw(Canvas canvas, int degree, Bitmap spriteStrip, float scaleX)
    {
    	canvas.save();
		canvas.rotate(degree, destinationRect.exactCenterX(), destinationRect.exactCenterY());
		canvas.scale(scaleX, 1.0f, destinationRect.exactCenterX(), destinationRect.exactCenterY());
		canvas.drawBitmap(spriteStrip, sourceRect, destinationRect, null);
		canvas.restore();
    }
    
}
