#include <iostream>
#include "Pair.h"

using namespace std;


/*
// Return a new pair that adds otherNum to the pair.
Pair operator+(int otherNum, Pair &other)
{
	Pair newPair(other.num1, other.num2);
	newPair.num1 += otherNum;
	newPair.num2 += otherNum;
	return newPair;
}
*/


// Return a new pair that adds otherNum to the pair.
Pair operator+(int otherNum, Pair &other)
{
	Pair newPair((other.get1() + otherNum),(other.get2() + otherNum));
	return newPair;
}



int main()
{
	Pair p1(5, 10);
	Pair p2(1, 2);

	// Outputs 5 and 10
	cout << p1.get1() << " " << p1.get2() << endl;
	// Outputs 1 and 2
	cout << p2.get1() << " " << p2.get2() << endl;

	Pair p3 = p1 + p2;
	// Outputs 6 and 12
	cout << p3.get1() << " " << p3.get2() << endl;

	p3 = 2 + p3;
	// Outputs 8 and 14
	cout << p3.get1() << " " << p3.get2() << endl;
	cout << "Please press enter to exit the program." << endl << endl;
	cin.get();
}


//1. Put the original code into separate files, compile, and run it.You can use the programming environment of your choice.If you're using Linux and compiling from the command line, don't forget you need to compile main.cpp and Pair.cpp together unless you create a Makefile or do separate compilation.
//   Done
//
//2. Change the line p3 = p3 + 2; to p3 = 2 + p3; and explain why it doesn't work.
//   This did not work because the overloaded operator only allows one more argument because the object is implicity called to also be added.
//
//3. Overload the + operator as a global friend function / operator so that all of these work : 2 + p3 or p3 + 2 or p1 + p2 or p2 + p1(the last two already work in the original code, but you should rewrite them as friends also to be consistent and for a little extra practice).The best place to put the global friend function(s) is in main.cpp(don't put it in Pair.cpp).
//	 Done. I also made a free function to demonstrate + could be overloaded without being a friend.
//
//4. Does the overloaded + operator even need to be a friend in this program ? Tell the TA or instructor why or why not.
//	 The + operator does not need to be a friend in this program. I implemented a free function at the top next to the commented out friend function to demonstrate this.
//	 Since there is public access to get functions and needed constructors there is no need to have specific access within the function for the + operator to be overloaded


