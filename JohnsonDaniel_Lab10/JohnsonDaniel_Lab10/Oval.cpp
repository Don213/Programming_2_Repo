#include "Oval.h"
#include "gl/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"

Oval::Oval()
{
	name = "Oval";
	x = 0;
	y = 0;
	width = 10;
	height = 10;
}

Oval::Oval(string name, int x, int y, int width, int height) :
	name(name), x(x), y(y), width(width), height(height)
{
}

Oval::~Oval()
{
}

string Oval::getName()
{
	return name;
}

int Oval::getX()
{
	return x;
}

int Oval::getY()
{
	return y;
}

int Oval::getWidth()
{
	return width;
}

int Oval::getHeight()
{
	return height;
}

void Oval::draw()
{
	int centerX, centerY;

	centerX = x + width / 2;
	centerY = y + height / 2;

	// OpenGL does not have any primitives for drawing curves or circles.
	// However we can approximate an oval using a triangle fan from the center
	// to the edge for all 360 degrees of the oval (use a smaller angle for higher resolution)
	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(centerX, centerY);
	for (float angle = 0; angle < 360; angle += 1)
	{
		glVertex2f(centerX + sin(angle) * width / 2, centerY + cos(angle) * height / 2);
	}
	glEnd();
}

bool Oval::pointInShape(int pointX, int pointY)
{
	if ((pointX >= x) && (pointX < x + width) && (pointY >= y) && (pointY <= y + height))
		return true;
	return false;
}