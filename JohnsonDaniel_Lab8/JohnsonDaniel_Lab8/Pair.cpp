#include "Pair.h"

Pair::Pair() : num1(0), num2(0)
{
}

Pair::Pair(int num1, int num2) : num1(num1), num2(num2)
{
}

int Pair::get1()
{
	return num1;
}

int Pair::get2()
{
	return num2;
}

// Return a new pair that adds the corresponding numbers
Pair Pair::operator+(const Pair &other)
{
	Pair newPair(this->num1, this->num2);
	newPair.num1 += other.num1;
	newPair.num2 += other.num2;
	return newPair;
}

// Return a new pair that adds otherNum to num1 and num2
Pair Pair::operator+(int otherNum)
{
	Pair newPair(this->num1, this->num2);
	newPair.num1 += otherNum;
	newPair.num2 += otherNum;
	return newPair;
}



