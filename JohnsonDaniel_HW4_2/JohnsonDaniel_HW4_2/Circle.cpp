#include "Shape.h"
#include "Circle.h"

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

Circle::Circle()
{

}
Circle::Circle(int value) : Shape(value)//sets the value of the radius of the circle
{

}
Circle::~Circle()
{

}
void Circle::draw()//specific draw function
{
	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(getX(), getY());
	for (float angle = 0; angle < 360; angle += 1)
	{
		glVertex2f((getX() + sin(angle) * getValue()/*radius*/ ), (getY() + cos(angle) * /*radius*/ getValue()));
	}
	glEnd();
}