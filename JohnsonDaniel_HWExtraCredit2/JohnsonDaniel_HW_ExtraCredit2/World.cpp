// World.cpp
// 
// Implementation of the World class
//
#include "World.h"
#include "Ant.h"
#include "Doodlebug.h"
#include <iostream>
#include <cstdlib>


using std::cout;
using std::endl;
using std::rand;

// The World constructor initializes doodlebugs and ants
World::World()
{
	// Initialize world to empty
	for (int x = 0; x < SIZE; x++)
		for (int y = 0; y< SIZE; y++)
			grid[x][y] = nullptr;

	// Populate with random doodlebugs and ants
	int numDoodle = 5;
	int numAnts = 100;

	while (numDoodle > 0)
	{
		int x = rand() % SIZE;
		int y = rand() % SIZE;
		if (grid[x][y] == nullptr)
		{
			grid[x][y] = new Doodlebug(this, x, y); // Each bug saves a reference to this world object and its coordinates
			numDoodle--;
		}
	}
	while (numAnts > 0)
	{
		int x = rand() % SIZE;
		int y = rand() % SIZE;
		if (grid[x][y] == nullptr)
		{
			grid[x][y] = new Ant(this, x, y);	// Each ant has a reference to this world object and its coordinates
			numAnts--;
		}
	}
}

// The destructor loops through and deletes any Organisms that are left in the world
World::~World()
{
	// Delete any organisms in the world
	for (int x = 0; x < SIZE; x++)
		for (int y = 0; y < SIZE; y++)
			if (grid[x][y] != nullptr)
				delete grid[x][y];
}

// This is a "getter" to retrieve the Organism at coordinate x,y in the grid
Organism* World::getCell(int x, int y)
{
	return grid[x][y];
}

// This is a "setter" to set the x,y entry in the grid to organism o
// It is up to the caller to avoid any memory leaks (e.g. delete any
// reference before setting it to something else)
void World::setCell(int x, int y, Organism *o)
{
	grid[x][y] = o;
}

// Prints the world out
void World::print()
{
	int numDoodle = 0;	// Not required, but counts up how many ants and doodlebugs there are
	int numAnts = 0;

	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			if (grid[x][y] == nullptr)
				cout << '.';		// Print . for an empty space
			else
			{
				cout << grid[x][y]->getOrganismLetter();		// Use virtual function for child to print out whatever its letter is
				if (grid[x][y]->getOrganismLetter() == 'o')		// This is to count how many ants/doodles
					numAnts++;
				else
					numDoodle++;
			}

		}
		cout << endl;
	}
	cout << "Doodlebugs: " << numDoodle << " Ants: " << numAnts << endl;
	cout << endl;
}

// This simulates one time tick. It makes two passes through the organisms so the Doodlebugs can move first
// and then the ants can move second. Finally,
void World::simulateTick()
{
	// Clear the moved flag for all organisms
	for (int x = 0; x < SIZE; x++)
		for (int y = 0; y < SIZE; y++)
			if (grid[x][y] != nullptr)
				grid[x][y]->setMoved(false);

	// Move, breed, then starve any organism with priority 1; right now this is just the Doodlebug but this way we could easily expand it to others	
	for (int x = 0; x < SIZE; x++)
		for (int y = 0; y < SIZE; y++)
			if (grid[x][y] != nullptr)
				if ((grid[x][y]->movePriority() == 1) && (!grid[x][y]->getMoved())) // Only move those that haven't moved yet
					grid[x][y]->move();		// Thanks to virtual functions, calls the move() function for either Ant or Doodlebug

	for (int x = 0; x < SIZE; x++)
		for (int y = 0; y < SIZE; y++)
			if (grid[x][y] != nullptr)
				if (grid[x][y]->movePriority() == 1) 
					grid[x][y]->breed();	// Thanks to virtual functions, calls the breed() function for either Ant or Doodlebug

	for (int x = 0; x < SIZE; x++)
		for (int y = 0; y < SIZE; y++)
			if (grid[x][y] != nullptr)
				if ((grid[x][y]->movePriority() == 1) && (grid[x][y]->getMoved())) // Only starve if moved
					grid[x][y]->starve();	// Thanks to virtual functions, calls the starve() function for either Ant or Doodlebug






	// Repeat for priority 2 organisms; right now this is just the Ants but this way we could easily expand it to others
	// Could combine with the above in a for loop above but thought this is a little clearer to show what the priority is for
	for (int x = 0; x < SIZE; x++)
		for (int y = 0; y < SIZE; y++)
			if (grid[x][y] != nullptr)
				if ((grid[x][y]->movePriority() == 2) && (!grid[x][y]->getMoved()))	// Only move those that haven't moved yet
					grid[x][y]->move();				
	for (int x = 0; x < SIZE; x++)
		for (int y = 0; y < SIZE; y++)
			if (grid[x][y] != nullptr)
				if (grid[x][y]->movePriority() == 2) 
					grid[x][y]->breed();
	for (int x = 0; x < SIZE; x++)
		for (int y = 0; y < SIZE; y++)
			if (grid[x][y] != nullptr)
				if ((grid[x][y]->movePriority() == 2) && (grid[x][y]->getMoved())) // Only starve if moved
					grid[x][y]->starve();
				
}
