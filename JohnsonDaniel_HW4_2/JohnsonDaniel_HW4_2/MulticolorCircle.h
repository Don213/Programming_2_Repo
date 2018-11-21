#ifndef MULTICOLORCIRCLE
#define MULTICOLORCIRCLE
#include "Shape.h"
#pragma once
using namespace std;

class MulticolorCircle : public Shape
{
public:
	MulticolorCircle();//default
	MulticolorCircle(int value);//sets radius (value) of circle
	~MulticolorCircle();
	void draw();//specific draw function
};
#endif