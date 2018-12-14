#pragma once
#include <vector>
#include <iostream>
#include <cstdlib>
#include "Organism.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
//#include "World.h"
using namespace std;











Organism::Organism()
{
	//this->breed = 0;
}

/*
bool Organism::breed()
{
	if (breed == 0) {
		return true;
	}
	return false;
}
*/


void Organism::move(int j, int i, Organism* grid[20][20])
{
	int random;
	bool m1 = grid[i - 1][j];
	bool m2 = grid[i + 1][j];
	bool m3 = grid[i][j + 1];
	bool m4 = grid[i][j - 1];


	//Organism* tempGrid = new Organism;
	int signal = 0;
	srand(time(NULL));



	if (/*((m1 || m2 || m3 || m4)) && */(grid[i][j] != nullptr)) {
		while (signal == 0) {
			
			random = rand() % 4;


			if (random == 0 && !((i - 1) < 0)) {
				grid[i - 1][j] = new Organism;
				
				grid[i][j] = nullptr;
				signal = 1;
			}
			else if (random == 1 && !((i + 1) > 20)) {
				grid[i + 1][j] = new Organism;
				
				grid[i][j] = nullptr;
				signal = 1;
			}
			else if (random == 2 && !((j + 1) > 20)) {
				grid[i][j + 1] = new Organism;
				
				grid[i][j] = nullptr;
				signal = 1;
			}
			else if (random == 3 && !((j - 1) < 0)) {
				grid[i][j - 1] = new Organism;
				
				grid[i][j] = nullptr;
				signal = 1;
			}
			
		}
		signal = 0;
	}
	this->moved = true;
}









bool Organism::getMoved()
{
	return moved;
}
void Organism::setMoved(bool tf)
{
	this->moved = tf;
}

