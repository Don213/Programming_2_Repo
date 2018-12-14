#pragma once
#include <vector>
#include <cstdlib>
#include "Organism.h"


class DoodleBug: public Organism 
{
private:
	int hunger;
public:
	virtual std::vector<int> move();
	void starve();
};

