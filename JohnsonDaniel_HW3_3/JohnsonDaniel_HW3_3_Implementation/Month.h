////////////////////////////////
//
// Daniel Johnson
// Assignment 3.3 (Class)
// 10/19/2018
//
////////////////////////////////


////////////////////////////////
//
// DESCRIPTION: This is a month class with one private 
// variable (month) and some functions that return the month
// as an int, string, and also a new month object (the next month)
//
// The functions are defined in Month.cpp
////////////////////////////////
#pragma once
#include <iostream>
#include <algorithm>
using namespace std;



class Month
{
private:
	int month;

public:
	Month();
	Month(int m);
	Month(string m);
	int getMonth();
	string getMonthString();
	Month getNextMonth();
};

