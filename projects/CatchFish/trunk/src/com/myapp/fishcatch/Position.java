package com.myapp.fishcatch;

public class Position
{	
	float X;
	float Y;
	
	public Position() {
		// TODO Auto-generated constructor stub
	}
	
	public Position(float x, float y)
	{
		X = x;
		Y = y;
	}
	
	public void SetPosition(float x, float y)
	{
		this.X = x;
		this.Y = y;
	}

	public void SetPosition(Position pos)
	{
		this.X = pos.X;
		this.Y = pos.Y;
	}
	
	public Position GetPosition()
	{
		return new Position(this.X, this.Y);
	}
}