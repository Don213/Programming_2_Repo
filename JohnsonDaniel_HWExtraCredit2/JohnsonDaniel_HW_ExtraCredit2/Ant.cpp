//
// Ant.cpp
// 
// Implementation of the Ant class
//
#include "Ant.h"
#include "gl/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"
#include <stdio.h>
#include <string.h>
#include <math.h>


Ant::Ant()
{
}

// This constructor just invoke the Organism constructor
// but sends in the number of time ticks for an Ant to breed
Ant::Ant(World *world, int x, int y) : Organism(world, BREED_TICKS, x, y) 
{
}


Ant::~Ant()
{
}

// Returns the letter representing an ant
char Ant::getOrganismLetter()
{
	return 'o';
}

// Returns the move priority
int Ant::movePriority()
{
	return 2;   // Second priority after doodlebugs
}

// Moves an ant on the grid; just invokes the random move function defined in Organism
void Ant::move()
{
	moveRandom(); // Move in a random direction
	moved = true;
}

// Starve an ant
void Ant::starve()
{
	// Nothing happens here, an ant never starves.
	// But we must implement it since it's an abstract function in Organism
}

// Breed an ant if it its breed countdown reaches zero
void Ant::breed()
{
	breedCountdown--;
	if (breedCountdown == 0)
	{
		Ant *antOffspring = new Ant(world, 0, 0);		// Create new Ant
		if (!breedOrganism(x, y, antOffspring))			// This function tries to place it in the grid
		{
			// No empty neighboring spot, we didn't get to breed so delete the object we made
			delete antOffspring;  
		}
		// Reset counter
		breedCountdown = BREED_TICKS;
	}
}






void Ant::setCell(int x, int y) {


	glColor3f(1.0f, 0.0f, 0.0f);
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

void Ant::deleteCell(int x, int y)
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
