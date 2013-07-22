package com.vietgameplay.fishcatch;


import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Rect;


public class BulletWeb {
	
	// The image of Bullet
	Bitmap spriteStripBullet;
	
	// The image of Bullet
	Bitmap spriteStripWeb;

	// Mark web open
	boolean isBang;
    
    // The area of the image strip we want to display
    Rect sourceRect = new Rect();

    // The area where we want to display the image strip in the game
    Rect destinationRect = new Rect();
    
    // The area of the image strip we want to display
    Rect sourceRectWeb = new Rect();

    // The area where we want to display the image strip in the game
    Rect destinationRectWeb = new Rect();
    
    // Power
 	int power;
 	
    // Degree to rotate
    int degrees;
    
    // Mark bullet for draw or not
    boolean acceptDraw;
    
    
    float aFactor;
	float bFactor;
	
	// Position to show web
	Position webPosition;
    
    
    public void Initialize(Bitmap texture, Bitmap texture2, Rect sourceRect, Rect destinationRect, Rect srcRectWeb)
    {
    	this.spriteStripBullet = texture;
    	this.spriteStripWeb = texture2;
    	this.isBang = false;
    	this.sourceRect = sourceRect;
    	this.destinationRect = destinationRect;
    	this.acceptDraw = false;
    	this.degrees = 0;
    	this.aFactor = 0;
    	this.bFactor = 0;
    	this.sourceRectWeb = srcRectWeb;
    	this.webPosition = new Position();
    }
    
    public void Update(Rect desRect)
    {
    	this.destinationRect = desRect;
    }
    
    public void Draw(Canvas canvas)
    {
    	if (isBang)
    	{
    		canvas.save();
        	canvas.drawBitmap(spriteStripWeb, sourceRectWeb, destinationRectWeb, null);
        	canvas.restore();
    	}
    	else
    	{
    		int tempX = 0;
    		if (degrees >= -50 && degrees <= 50)
    		{
    			if (degrees > 0)
    				tempX = destinationRect.left-(int)(10*PlayScreen.cannonScale);
    			else
    				tempX = destinationRect.right+(int)(10*PlayScreen.cannonScale);
    		}
    		else
    		{
    			tempX = destinationRect.centerX();
    		}
    			
    		canvas.save();
        	canvas.rotate(degrees, tempX, destinationRect.top+2*(destinationRect.bottom - destinationRect.top)/3);
        	canvas.drawBitmap(spriteStripBullet, sourceRect, destinationRect, null);
        	canvas.restore();
    	}
    }
}
