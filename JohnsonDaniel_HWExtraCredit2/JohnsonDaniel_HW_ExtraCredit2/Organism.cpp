// Organism.cpp
//
// Implementation of the Organism class
//
#include <cstdlib>
#include "Organism.h"
#include "gl/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

using std::rand;

// This default constructor shouldn't be used, the simulation won't work properly
// without a world object set to something
Organism::Organism()
{
	breedCountdown = 0;
	world = nullptr;
	moved = false;
}

// This constructor saves a pointer reference to the world, a variable for how many
// time ticks until the organism can breed, and the organism's x,y coordinates in the world
Organism::Organism(World *world, int breedCountdown, int x, int y)
{
	this->world = world;
	this->breedCountdown = breedCountdown;
	this->x = x;
	this->y = y;
	moved = false;
}

// Nothing to destroy in destructor
Organism::~Organism()
{
}

// Getter and setter for whether this organism moved
void Organism::setMoved(bool moved)
{
	this->moved = moved;
}
bool Organism::getMoved()
{
	return moved;
}

// This function moves the organism in a random direction, if it is open.
// If the selected direction isn't open then the organism doesn't move at all.
void Organism::moveRandom()
{
	int direction = rand() % 4;

	switch (direction)
	{
		case 0: 
			// up
			if ((y > 0) && (world->getCell(x,y-1) == nullptr))
			{
				world->setCell(x, y - 1, this);	// New grid cell points to this organism
				world->setCell(x, y, nullptr);	// Old grid cell is empty
				y--;

				deleteCell(x, y);
				setCell(x, y - 1);
			}
			break;
		case 1:
			// Down
			if ((y < world->SIZE-1) && (world->getCell(x, y + 1) == nullptr))
			{				
				world->setCell(x, y + 1, this);
				world->setCell(x, y, nullptr);
				y++;

				deleteCell(x, y);
				setCell(x, y + 1);

			}
			break;
		case 2:
			// Left
			if ((x > 0) && (world->getCell(x - 1, y) == nullptr))
			{				
				world->setCell(x - 1, y, this);
				world->setCell(x, y, nullptr);
				x--;


				deleteCell(x, y);
				setCell(x - 1, y);
			}
			break;
		case 3:
			// Right
			if ((x < world->SIZE-1) && (world->getCell(x + 1, y) == nullptr))
			{				
				world->setCell(x + 1, y, this);
				world->setCell(x, y, nullptr);
				x++;


				deleteCell(x, y);
				setCell(x + 1, y);
			}
			break;
	}
	// Mark that we moved
	this->moved = true;
}

// This function implements the breeding logic for the Organism o centered around
// cell x,y.   It checks for an open neighboring position.  If one is found, the
// organism is placed there and true is returned.  If one can't be found then the
// organism isn't placed and false is returned.
bool Organism::breedOrganism(int x, int y, Organism *o)
{ 
	// Try placing offspring in up, down, left, right order	
	if ((y > 0) && (world->getCell(x, y - 1) == nullptr))
	{
		world->setCell(x, y - 1, o);
		o->x = x;
		o->y = y - 1;
		deleteCell(x, y);
		setCell(x, y - 1);
		return true;
	}
	if ((y < world->SIZE-1) && (world->getCell(x, y + 1) == nullptr))
	{
		world->setCell(x, y + 1, o);
		o->x = x;
		o->y = y + 1;
		deleteCell(x, y);
		setCell(x, y + 1);
		return true;
	}
	if ((x < 0) && (world->getCell(x - 1, y) == nullptr))
	{
		world->setCell(x - 1, y, o);
		o->x = x - 1;
		o->y = y;
		deleteCell(x, y);
		setCell(x - 1, y);
		return true;
	}
	if ((x < world->SIZE-1) && (world->getCell(x + 1, y) == nullptr))
	{
		world->setCell(x + 1, y, o);
		o->x = x + 1;
		o->y = y;
		deleteCell(x, y);
		setCell(x + 1, y);
		return true;
	}
	// If we got here, we couldn't find an empty slot next to us.
	// So we don't get to breed. 
	return false;
}





void Organism::setCell(int x, int y)
{

}
void Organism::deleteCell(int x, int y)
{

}







