#include "Oval.h"
#include "gl/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"

Oval::Oval()
{
	Shape::Shape(("Oval"), (0), (0), (10), (10));
}

Oval::Oval(string name, int x, int y, int width, int height) :
	Shape::Shape((name), (x), (y), (width), (height))
{
}

Oval::~Oval()
{
}


void Oval::draw()
{
	int centerX, centerY;

	centerX = getX() + getWidth() / 2;
	centerY = getY() + getHeight() / 2;

	// OpenGL does not have any primitives for drawing curves or circles.
	// However we can approximate an oval using a triangle fan from the center
	// to the edge for all 360 degrees of the oval (use a smaller angle for higher resolution)
	glColor3f(r, g, b);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(centerX, centerY);
	for (float angle = 0; angle < 360; angle += 1)
	{
		glVertex2f(centerX + sin(angle) * getWidth() / 2, centerY + cos(angle) * getHeight() / 2);
	}
	glEnd();
}
