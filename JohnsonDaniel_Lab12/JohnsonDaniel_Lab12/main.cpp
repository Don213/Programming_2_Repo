#include "LinkedList.h"
#include <iostream>

using namespace std;

int main()
{
	LinkedList mylist;

	mylist.add("Armando");
	mylist.add("Bobo");
	mylist.add("Carlo");
	mylist.add("Drogo");
	mylist.add("Cyrano");
	mylist.add("Frodo");

	cout << "Output entire list" << endl;
	mylist.output();

	cout << "Output after removing Carlo" << endl;
	mylist.remove("Carlo");
	mylist.output();

	cout << "Output after removing Frodo" << endl;
	mylist.remove("Frodo");
	mylist.output();

	cout << "Output after removing Armando" << endl;
	mylist.remove("Armando");
	mylist.output();

	cout << mylist.contains("Bobo")->getName() << endl;
	mylist.addTail("Steven");
	cout << mylist.contains("Steven")->getName() << endl;


	cin.get();// Pauses the system
	return 0;
}