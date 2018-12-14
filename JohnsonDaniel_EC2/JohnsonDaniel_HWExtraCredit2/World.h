#pragma once
#include <vector>
#include <cstdlib>
#include "Organism.h"
//#include "Ant.h"
//#include "DoodleBug.h"


#include "gl/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;




class World
{
private:
	static const int SIZE = 20;
	Organism* grid[SIZE][SIZE];


public:
	World();
	Organism* getGridPanel(int x, int y);
	void displayGrid();
	void updateGrid(World world);
	bool isOccupied(int x, int y);

};