#include "Rectangle.h"
#include "gl/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"


Rectangle::Rectangle()
{
	Shape::Shape(("Rectangle"), (0), (0), (10), (10));

}

Rectangle::Rectangle(string name, int x, int y, int width, int height) :
	Shape::Shape((name), (x), (y), (width), (height))
{
}

Rectangle::~Rectangle()
{
}


void Rectangle::draw()
{
	glColor3f(0, 0, 1); // Change to blue
	glBegin(GL_QUADS);  // Use GL_LINE_LOOP for hollow
	glVertex2f(getX(),getY()); // x1,y1
	glVertex2f(getX() + getWidth(), getY()); // x2, y1
	glVertex2f(getX() + getWidth(), getY() + getHeight()); // x2, y2
	glVertex2f(getX(), getY() + getHeight()); // x1, y2
	glEnd();
}

