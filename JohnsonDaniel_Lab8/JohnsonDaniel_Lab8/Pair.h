#pragma once
class Pair
{
private:
	int num1, num2;
public:
	Pair();
	Pair(int num1, int num2);
	int get1();
	int get2();
	Pair operator+(const Pair &other);
	Pair operator+(int otherNum);

	//friend Pair operator+(int otherNum, Pair &other);

	//friend Pair operator+(int otherNum, Pair &other);
};