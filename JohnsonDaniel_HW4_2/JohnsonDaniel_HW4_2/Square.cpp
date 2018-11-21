#include "Shape.h"
#include "Square.h"

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

Square::Square()
{

}
Square::Square(int value) : Shape(value)//sets value for the diameter of the square
{

}
Square::~Square()
{

}
void Square::draw()
{
	glColor3f(1, 0, 1);
	glBegin(GL_QUADS);
	glVertex2f((getX() - (getValue() / 2)), (getY() - (getValue() / 2)));
	glVertex2f((getX() + (getValue() / 2)), (getY() - (getValue() / 2)));
	glVertex2f((getX() + (getValue() / 2)), (getY() + (getValue() / 2)));
	glVertex2f((getX() - (getValue() / 2)), (getY() + (getValue() / 2)));
	glEnd();
}