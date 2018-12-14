#pragma once
//#include "Ant.h"
//#include "DoodleBug.h"
#include <vector>
#include <cstdlib>
//#include "Organism.h"
#include "World.h"
#include <iostream>

#include "gl/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

class Organism;

World::World()
{


	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			grid[j][i] = nullptr;
		}
	}


	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (i % 2 == 0) {
				//grid[j][i] = new Organism;
			}
		}
	}
	grid[1][1] = new Organism;
	grid[1][0] = new Organism;
	grid[0][1] = new Organism;
}

bool World::isOccupied(int x, int y)
{
	if (grid[x][y] == nullptr){
		return false;
	}
	else { return true; }
}

void World::updateGrid(World world)
{

	Organism* grid = getGridPanel(0, 0);
	Organism* tempGrid = getGridPanel(0, 0);



	for (int i = 0; i < 20; i++) {

		for (int j = 0; j < 20; j++) {
			grid = getGridPanel(j, i);

			//grid->move(j, i, world);




		}
	}

}








void World::displayGrid()
{

	



	
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (grid[j][i] != nullptr) {

				grid[j][i]->move(j,i,*grid);

					glBegin(GL_QUADS);  // Use GL_LINE_LOOP for hollow
					glEnable(GL_BLEND); //Enable blending.
					glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Set blending function.
					glVertex2f(45 + (i * 40), 45 + (j * 40)); // 
					glVertex2f(75 + (i * 40), 45 + (j * 40)); // 
					glVertex2f(75 + (i * 40), 75 + (j * 40)); // 
					glVertex2f(45 + (i * 40), 75 + (j * 40)); // 
					glVertex2f(45 + (i * 40), 45 + (j * 40)); // 
					glEnd();
				
			}
		}
	}
	

	cout << "hello there" << endl;



	





	/*
	// Draw a rectangle given the four corners
	glBegin(GL_QUADS);  // Use GL_LINE_LOOP for hollow
	glColor3f(0, 0, 1); // Change to Blue
	glVertex2f(50, 200); // x1,y1
	glVertex2f(200, 200); // x2, y1
	glVertex2f(200, 50); // x2, y2
	glVertex2f(50, 50); // x1, y2
	glEnd();



	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0); // Change to yellow
	glVertex2f(50, 200);
	glVertex2f(200, 200);
	glVertex2f(125, 50);
	glEnd();
	//
	*/






	//cin.get();
}








Organism* World::getGridPanel(int x, int y)
{
	return grid[y][x];
}


