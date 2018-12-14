// World class
//
// The world class stores information about the world!
// It contains a 20x20 grid of pointers to Organism objects.
// 
#pragma once
#include "Organism.h"

// This is a forward reference, like a function header for a class.
// It says the Organism class is defined somewhere else.
class Organism;

class World
{
public:
	static const int SIZE = 20;
	World();
	~World();	
	void print();				// Prints the grid of organisms
	void simulateTick();		// Simulates one time step
	Organism* getCell(int x, int y);		// Used to retrieve a grid entry
	void setCell(int x, int y, Organism *o);	// Used to set a grid entry to a new Organism object (or nullptr)
private:
	Organism* grid[SIZE][SIZE];
};

