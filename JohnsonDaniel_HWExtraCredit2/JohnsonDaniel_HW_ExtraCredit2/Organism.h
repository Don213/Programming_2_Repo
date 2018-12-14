// Organism class
//
// The class stores information about an Organism in the simulation.
// It holds material that is common to both Ants and Doodlebugs.
// This has variables for:
//	  x,y coordinates
//	  A pointer to the world object so we can get to the grid of cells
//    A flag if this organism has moved in a simulation step
//	  A countdown to reproduce
//	Abstract virtual methods are:
//		move, starve, breed, movePriority, getOrganismLetter
//    These all must be implemented in a child class (Ant or Doodlebug)
// 
#pragma once
#include "World.h"

// This is a forward reference, like a function header for a class.
// It says the World class is defined somewhere else.
class World;

class Organism
{
public:
	Organism();
	Organism(World *world, int breedCountdown, int x, int y);
	~Organism();

	// The following group are all virtual functions; they must be implemented in a derived class (Ant or Doodlebug)
	virtual char getOrganismLetter() = 0;		// Abstract function; should return the character representing the Organism
	virtual int movePriority() = 0;				// Abstract function; return move priority for organism (1 for doodlebug, 2 for ant)
	virtual void move() = 0;					// Abstract function to move the organism
	virtual void starve() = 0;					// Abstract function for this organism to starve
	virtual void breed() = 0;						// Handle breeding this organism
	virtual void setCell(int x, int y);
	virtual void deleteCell(int x, int y);

	// These are implemented in the Organism class
	void moveRandom();							// Move in a random direction
	bool breedOrganism(int x, int y, Organism *o);	// Breed organism o around cell x,y; returns false if breed failed
	void setMoved(bool moved);					// Getter and setter for whether this organism moved
	bool getMoved();
protected:
	int x, y;				// Coordinates in the world
	World* world;   		// Reference to the world this organism is in
	int breedCountdown;		// How many ticks until this organism breeds	
	bool moved;				// boolean if this organism has moved
};

