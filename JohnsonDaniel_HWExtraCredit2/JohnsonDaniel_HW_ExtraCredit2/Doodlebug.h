// Doodlebug class
//
// This class defines a Doodlebug, which is derived from Organism.
//
#pragma once
#include "Organism.h"
class Doodlebug :
	public Organism
{
public:
	Doodlebug();
	Doodlebug(World *w, int x, int y);
	~Doodlebug();
	char getOrganismLetter();				// Returns letter representing a doodlebug
	int movePriority();						// The priority of moving (1 for a Doodlebug)
	void move();							// Moves the doodlebug
	void starve();							// Check to see if bug starves
	void breed();							// Check to see if bug should breed
	virtual void setCell(int x, int y);
	virtual void deleteCell(int x, int y);
private:
	static const int BREED_TICKS = 8;		// time steps to breed
	static const int STARVE_TICKS = 3;		// time steps to starve
	int starveCountdown = 0;				// countdown until starvation hits
};

