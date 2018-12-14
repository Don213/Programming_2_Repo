// Ant class
//
// This class defines an Ant, which is derived from Organism.
//
#pragma once
#include "Organism.h"
class Ant :
	public Organism
{
public:
	Ant();
	Ant(World *world, int x, int y);
	~Ant();
	char getOrganismLetter();			// Returns letter representing an ant
	int movePriority();					// Returns whether this moves first or second
	void move();						// Moves the an
	void starve();						// Starves the ant (does nothing but must override it)
	void breed();						// Breed the ant
	virtual void setCell(int x, int y);
	virtual void deleteCell(int x, int y);
private:
	static const int BREED_TICKS = 3;
};

