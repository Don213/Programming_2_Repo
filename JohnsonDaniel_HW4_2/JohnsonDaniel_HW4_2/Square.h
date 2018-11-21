#ifndef SQUARE
#define SQUARE
#include "Shape.h"
#pragma once
using namespace std;

class Square : public Shape
{
public:
	Square();//defualt
	Square(int value); //sets diameter (value) of square
	~Square();
	void draw();//specific draw function

};
#endif