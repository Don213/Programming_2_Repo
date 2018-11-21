#include "Shape.h"
#include "gl/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"
#include <cstdlib>
#include <cmath>
using namespace std;


Shape::Shape()
{
	// By default, make this a circle of radius 20 pixels
	//type = 1;
	//radius = 20;
	value = 20;

	// Start at a random position and speed
	x = (float)(rand() % WIDTH);
	y = (float)(rand() % HEIGHT);
	deltaX = ((static_cast<float>(rand()) / RAND_MAX) * 8) - 4;
	deltaY = ((static_cast<float>(rand()) / RAND_MAX) * 8) - 4;
}

Shape::Shape(/*int type, */ int value)
{
	this->value = value;

	/*
	if (type == 0)
	{
		// Square
		diameter = value;
	}
	else if (type == 1)
	{
		// Circle
		radius = value;
	}
	else if (type == 2)
	{
		// Multicolorcircle
		radius = value;
	}
	*/

	// Start at a random position and speed
	x = (float)(rand() % WIDTH);
	y = (float)(rand() % HEIGHT);
	deltaX = ((static_cast<float>(rand()) / RAND_MAX) * 8) - 4;
	deltaY = ((static_cast<float>(rand()) / RAND_MAX) * 8) - 4;
}


Shape::~Shape()
{
}


void Shape::draw()
{
	// Draw a line
	glBegin(GL_LINES);
	glVertex2f(x, y);
	glVertex2f(x+value, y+value);
	glEnd();

	
	// Draw a line
	glBegin(GL_LINES);
	glVertex2f(x+value, y);
	glVertex2f(x, y+value);
	glEnd();
	
}


// This function draws the shape
/*
void Shape::draw()
{

	// Square
	if (type == 0)
	{
		glColor3f(1, 0, 1);
		glBegin(GL_QUADS);
		glVertex2f(x - (diameter / 2), y - (diameter / 2));
		glVertex2f(x + (diameter / 2), y - (diameter / 2));
		glVertex2f(x + (diameter / 2), y + (diameter / 2));
		glVertex2f(x - (diameter / 2), y + (diameter / 2));
		glEnd();
	}
	// Circle
	else if (type == 1)
	{
		glColor3f(1, 0, 0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for (float angle = 0; angle < 360; angle += 1)
		{
			glVertex2f(x + sin(angle) * radius, y + cos(angle) * radius);
		}
		glEnd();
	}
	else if (type == 2) // Multicolor circle
	{
		glColor3f(1, 0, 0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for (float angle = 0; angle < 360; angle += 1)
		{
			glVertex2f(x + sin(angle) * radius, y + cos(angle) * radius);
		}
		glEnd();

		glColor3f(0, 1, 0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for (float angle = 0; angle < 360; angle += 1)
		{
			glVertex2f(x + sin(angle) * radius*2.0 / 3, y + cos(angle) * radius*2.0 / 3);
		}
		glEnd();

		glColor3f(0, 0, 1);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for (float angle = 0; angle < 360; angle += 1)
		{
			glVertex2f(x + sin(angle) * radius*1.0 / 3, y + cos(angle) * radius*1.0 / 3);
		}
		glEnd();
	}
}
*/

// This function updates the location of the shape, by adding in deltaX to the x coordinate
// and deltaY to the y coordinate.  Since the delta's can be negative this allows for moving
// up or down.
// If the center of the ball goes off the edge of the screen, reverse the direction.
void Shape::updateCoordinates()
{
	x += deltaX;
	y += deltaY;

	// Check if we hit the edge of the screen and if we did
	// move it back so it fits and then change the direction
	if (x >= WIDTH)
	{
		x -= deltaX;
		// deltaX is positive, so make it negative
		deltaX *= -1;
	}
	else if (x < 0)
	{
		deltaX *= -1;    // deltaX is negative, so make it positive
		x += deltaX;    // add it in so we are not off the edge
	}
	if (y >= HEIGHT)
	{
		y -= deltaY;  // Same for the Y directions
		deltaY *= -1;
	}
	else if (y < 0)
	{
		deltaY *= -1;
		y += deltaY;
	}
}


///////////////////New methods
float Shape::getX()
{
	return x;
}
float Shape::getY()
{
	return y;
}
int Shape::getValue()
{
	return value;
}




