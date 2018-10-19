////////////////////////////////
//
// Daniel Johnson
// Assignment 3.1
// 10/19/2018
//
////////////////////////////////


////////////////////////////////
//
// DESCRIPTION: This program makes a dynamic array go from 5 ints long to 10 ints long.
// The code was fixed to allow this to happen in the main function.
//
//
//
// 1. Everything looks fine in the function because the dynamic array is passed by value (passes the value pointed to by the pointer.) so
// all the variables look the same and behave normally. It looks like garbage in the main because
// the variable needs to be passed by reference instead.
//
// 2. The program is fixed.
//
//
////////////////////////////////





#include <iostream>
using namespace std;



//The following function has a parameter that is a pointer to ints. It outputs the 5 integers 
//in the array then allocates a new dynamic array of size 10 and sets the input parameter to 
//point to this new array. Finally, it sets the 10 integers to all 999's and outputs them.

void ptrChange(int *&p)
{
	// Output original array data
	cout << "Original data with 5 ints" << endl;
	for (int i = 0; i < 5; i++)
		cout << p[i] << " ";
	cout << endl;

	// Allocate new array of 10 ints and make p point to it
	int *p2 = new int[10];
	// Free memory allocated to old array
	delete [] p;
	// Set pointer to new array
	p = p2;

	// Store 10 ints in the new array
	for (int i = 0; i < 10; i++)
		p[i] = 999;
	// Output new array data
	cout << "Data now with 10 ints" << endl;
	for (int i = 0; i < 10; i++)
		cout << p[i] << " ";
	cout << endl;
}



int main()
{
	int *p = new int[5];

	p[0] = 10;
	p[1] = 20;
	p[2] = 30;
	p[3] = 40;
	p[4] = 50;
	ptrChange(p);
	cout << "After calling ptrChange:" << endl;
	for (int i = 0; i < 10; i++)
		cout << p[i] << " ";
	cout << endl;

	delete[] p;
	cin.get();




}