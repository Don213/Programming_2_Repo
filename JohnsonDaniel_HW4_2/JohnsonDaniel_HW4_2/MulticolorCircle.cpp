#include "Shape.h"
#include "MulticolorCircle.h"

#include "gl/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"


#include <stdio.h>
#include <string.h>
#include <math.h>


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

MulticolorCircle::MulticolorCircle()
{

}
MulticolorCircle::MulticolorCircle(int value) : Shape(value)//sets the value to be used for radius
{

}
MulticolorCircle::~MulticolorCircle()
{

}
void MulticolorCircle::draw()//specific draw function for multicolored circles
{
	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(getX(), getY());
	for (float angle = 0; angle < 360; angle += 1)
	{
		glVertex2f((getX() + sin(angle) * getValue()), (getY() + cos(angle) * getValue()));
	}
	glEnd();

	glColor3f(0, 1, 0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(getX(), getY());
	for (float angle = 0; angle < 360; angle += 1)
	{
		glVertex2f((getX() + sin(angle) * getValue()*2.0 / 3), (getY() + cos(angle) * getValue()*2.0 / 3));
	}
	glEnd();

	glColor3f(0, 0, 1);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(getX(), getY());
	for (float angle = 0; angle < 360; angle += 1)
	{
		glVertex2f((getX() + sin(angle) * getValue()*1.0 / 3), (getY() + cos(angle) * getValue()*1.0 / 3));
	}
	glEnd();

}
