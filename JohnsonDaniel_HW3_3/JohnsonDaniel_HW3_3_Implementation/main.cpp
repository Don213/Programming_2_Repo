////////////////////////////////
//
// Daniel Johnson
// Assignment 3.3 (Using class)
// 10/19/2018
//
////////////////////////////////


////////////////////////////////
//
// DESCRIPTION: This program uses the month class and 
// demonstrates its abilities and that it works.
//
//
//
////////////////////////////////
#include <iostream>
#include <string>
#include "Month.h"
using namespace std;




int main()
{
	//Makes three Month objects to test the Month class with
	Month month1 = Month();
	Month month2 = Month(2);
	Month month3 = Month("Mar");

	//Every month class is tested with getMonth(),



	cout << "Test Section one: " << endl;
	cout << "This is the number of the month: " << month1.getMonth() << endl;//Should print 1
	cout << "This is the month represented by a string " << month1.getMonthString() << endl;//Should print Jan
	cout << "This is the next month's number and string representation: ";
	Month month4 = month1.getNextMonth();//makes new month object
	cout << month4.getMonth() << " and " << month4.getMonthString() << endl << endl;

	cout << "Test Section two: " << endl;
	cout << "This is the number of the month: " << month2.getMonth() << endl;//Should print 2
	cout << "This is the month represented by a string " << month2.getMonthString() << endl;//Should print Feb
	cout << "This is the next month's number and string representation: ";
	Month month5 = month2.getNextMonth();//makes new month object
	cout << month5.getMonth() << " and " << month5.getMonthString() << endl << endl;

	cout << "Test Section one: " << endl;
	cout << "This is the number of the month: " << month3.getMonth() << endl;//Should print 1
	cout << "This is the month represented by a string " << month3.getMonthString() << endl;//Should print Jan
	cout << "This is the next month's number and string representation: ";
	Month month6 = month3.getNextMonth();//makes new month object
	cout << month6.getMonth() << " and " << month6.getMonthString() << endl << endl;

	cin.get();
	cout << "Press enter to end the program" << endl;

}