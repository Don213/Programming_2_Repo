#include "Rectangle.h"
#include "gl/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"


Rectangle::Rectangle()
{
	name = "Rectangle";
	x = 0;
	y = 0;
	width = 10;
	height = 10;
}

Rectangle::Rectangle(string name, int x, int y, int width, int height) :
	name(name), x(x), y(y), width(width), height(height)
{
}


Rectangle::~Rectangle()
{
}

void Rectangle::draw()
{
	glColor3f(0, 0, 1); // Change to blue
	glBegin(GL_QUADS);  // Use GL_LINE_LOOP for hollow
	glVertex2f(x, y); // x1,y1
	glVertex2f(x + width, y); // x2, y1
	glVertex2f(x + width, y + height); // x2, y2
	glVertex2f(x, y + height); // x1, y2
	glEnd();
}

string Rectangle::getName()
{
	return name;
}

int Rectangle::getX()
{
	return x;
}

int Rectangle::getY()
{
	return y;
}

int Rectangle::getWidth()
{
	return width;
}

int Rectangle::getHeight()
{
	return height;
}

bool Rectangle::pointInShape(int pointX, int pointY)
{
	if ((pointX >= x) && (pointX < x + width) && (pointY >= y) && (pointY <= y + height))
		return true;
	return false;
}