// Doodlebug.cpp
//
// Implementation of the Doodlebug class
//
#include "Doodlebug.h"
#include "gl/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

Doodlebug::Doodlebug()
{
}

// This constructor just invoke the Organism constructor
// but sends in the number of time ticks for a Doodlebug to breed and sets the
// coutndown for starvation
Doodlebug::Doodlebug(World *world, int x, int y) : Organism(world, BREED_TICKS, x, y)
{
	starveCountdown = STARVE_TICKS;
}

Doodlebug::~Doodlebug()
{
}

// Returns the letter representing a Doodlebug
char Doodlebug::getOrganismLetter()
{
	return 'X';
}

// The move priority for a doodelbug
int Doodlebug::movePriority()
{
	return 1;  // First priority
}

// Logic to move a doodlebug;  it first eats a neighboring ant.  If one is not found then
// it moves randomly.
void Doodlebug::move()
{
	moved = true;
	// Check for an ant up, down, left, or right.  If so, eat it.
	if ((y > 0) && (world->getCell(x,y-1)!=nullptr) && (world->getCell(x, y - 1)->getOrganismLetter() == 'o'))
	{
		delete world->getCell(x, y - 1);	// Kill the ant that is at the spot we are moving to
		world->setCell(x, y - 1, this);		// Set the new spot to this doodlebug
		world->setCell(x, y, nullptr);		// Set the old spot to blank
		y--;								// Update y coordinate
		starveCountdown = STARVE_TICKS;		// Reset starvation clock
		deleteCell(x, y);
		setCell(x, y - 1);
		return;
	}
	if ((y < world->SIZE-1) && (world->getCell(x, y + 1) != nullptr) && (world->getCell(x, y + 1)->getOrganismLetter() == 'o'))
	{
		delete world->getCell(x, y + 1);
		world->setCell(x, y + 1, this);
		world->setCell(x, y, nullptr);
		y++;
		starveCountdown = STARVE_TICKS;
		deleteCell(x, y);
		setCell(x, y + 1);
		return;

	}
	if ((x > 0) && (world->getCell(x - 1, y) != nullptr) && (world->getCell(x - 1, y)->getOrganismLetter() == 'o'))
	{
		delete world->getCell(x - 1, y);
		world->setCell(x - 1, y, this);
		world->setCell(x, y, nullptr);
		x--;
		starveCountdown = STARVE_TICKS;
		deleteCell(x, y);
		setCell(x - 1, y);
		return;

	}
	if ((x < world->SIZE-1) && (world->getCell(x + 1, y) != nullptr) && (world->getCell(x + 1, y)->getOrganismLetter() == 'o'))
	{
		delete world->getCell(x + 1, y);
		world->setCell(x + 1, y, this);
		world->setCell(x, y, nullptr);
		x++;
		starveCountdown = STARVE_TICKS;
		deleteCell(x, y);
		setCell(x + 1, y);
		return;

	}
	// If we got here, there was no adjacent ant.  Just move randomly.
	moveRandom(); // Move in a random direction
}

// Check if this doodlebug starves
void Doodlebug::starve()
{
	starveCountdown--;
	if (starveCountdown == 0)
	{
		// We starved
		world->setCell(x, y, nullptr);
		delete this;
	}
}

// Check if this doodlebug should breed
void Doodlebug::breed()
{
	breedCountdown--;
	if (breedCountdown == 0)
	{
		Doodlebug *doodleOffspring = new Doodlebug(world, 0, 0);	// Create new doodlebug
		if (!breedOrganism(x, y, doodleOffspring))					// Attempts to place new bug around x,y
		{
			// No empty neighboring spot, we didn't get to breed
			delete doodleOffspring;
		}
		// Reset counter
		breedCountdown = BREED_TICKS;
	}
}




void Doodlebug::setCell(int x, int y) {


	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);  // Use GL_LINE_LOOP for hollow
	glEnable(GL_BLEND); //Enable blending.
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Set blending function.
	glVertex2f(45 + (x * 40), 45 + (y * 40)); // 
	glVertex2f(75 + (x * 40), 45 + (y * 40)); // 
	glVertex2f(75 + (x * 40), 75 + (y * 40)); // 
	glVertex2f(45 + (x * 40), 75 + (y * 40)); // 
	glVertex2f(45 + (x * 40), 45 + (y * 40)); // 
	glEnd();
}

void Doodlebug::deleteCell(int x, int y)
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);  // Use GL_LINE_LOOP for hollow
	glEnable(GL_BLEND); //Enable blending.
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Set blending function.
	glVertex2f(45 + (x * 40), 45 + (y * 40)); // 
	glVertex2f(75 + (x * 40), 45 + (y * 40)); // 
	glVertex2f(75 + (x * 40), 75 + (y * 40)); // 
	glVertex2f(45 + (x * 40), 75 + (y * 40)); // 
	glVertex2f(45 + (x * 40), 45 + (y * 40)); // 
	glEnd();
}
