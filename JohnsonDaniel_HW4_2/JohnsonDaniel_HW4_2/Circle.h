#ifndef CIRCLE
#define CIRCLE
#include "Shape.h"
#pragma once
using namespace std;

class Circle : public Shape
{
public:
	Circle();//default
	Circle(int value);//sets radius (value) of circle
	~Circle();
	void draw();//specific draw function

};
#endif