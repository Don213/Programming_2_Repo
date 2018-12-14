#pragma once
#include <vector>
//#include "World.h"
#include "Organism.h"
using namespace std;

class World;


class Organism
{
private:
	static const int SIZE = 20;
	//int breed;
	bool moved;
public:
	Organism();
	//bool breed();
	void move(int i, int j, Organism* grid[][20]);



	bool getMoved();
	void setMoved(bool tf);
};