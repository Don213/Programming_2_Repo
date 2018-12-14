#pragma once
#include <vector>
#include <cstdlib>
#include "Organism.h"



class Ant: public Organism
{
public:
	Ant(int x, int y);
	virtual std::vector<int> move();
};