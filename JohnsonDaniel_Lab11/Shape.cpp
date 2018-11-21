#include "Shape.h"
#include "gl/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"


Shape::Shape()
{
	name = "Shape";
	x = 0;
	y = 0;
	width = 10;
	height = 10;
	changeColor();
}

Shape::Shape(string name, int x, int y, int width, int height) :
	name(name), x(x), y(y), width(width), height(height)
{
	changeColor();
}


Shape::~Shape()
{
}

void Shape::draw()
{
	// Draw a line
	glBegin(GL_LINES);
	glVertex2f(x, y);
	glVertex2f(x+width, y+height);
	glEnd();

	
	// Draw a line
	glBegin(GL_LINES);
	glVertex2f(x+width, y);
	glVertex2f(x, y+height);
	glEnd();
	
}

string Shape::getName()
{
	return name;
}

int Shape::getX()
{
	return x;
}

int Shape::getY()
{
	return y;
}

int Shape::getWidth()
{
	return width;
}

int Shape::getHeight()
{
	return height;
}

bool Shape::pointInShape(int pointX, int pointY)
{
	if ((pointX >= x) && (pointX < x + width) && (pointY >= y) && (pointY <= y + height))
		return true;
	return false;
}
void Shape::changeColor()
{
	r = (float)rand() / RAND_MAX;
	g = (float)rand() / RAND_MAX;
	b = (float)rand() / RAND_MAX;
}