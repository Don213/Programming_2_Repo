#ifndef SHAPE
#define SHAPE
#pragma once

class Shape
{
private:
	static const int WIDTH = 720;
	static const int HEIGHT = 480;
	float x;
	float y;
	float deltaX;
	float deltaY;
	//int type;		// Identifies type of shape being stored.  See list below.
	//int radius;		// If its a circle this is the radius
	//int diameter;	// If its a square this is the diameter
	int value;
public:
	Shape();
	Shape(/*int type, */ int value); // Type: 0=Square, 1=Circle, 2=MultiColorCircle.    Value:  Radius or Diameter
	~Shape();
	void draw();
	void updateCoordinates();

	float getX();
	float getY();
	int getValue();
};
#endif