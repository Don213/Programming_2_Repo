#pragma once
//#include "Prisoner.h"
#include <cstdlib>
#include <string>

class Prisoner {
private:
	int data;
	Prisoner* next;
public:
	Prisoner();

	

	void setData(int data);
	int getData();

	 void setNext(Prisoner* prisoner);
	 Prisoner* getNext();

	 friend int determineSurvivor(Prisoner *n, int words, int prisoners);

	 friend Prisoner* constructCircularLinkedList(int prisoners);
	 //int determineSurvivor(int prisoners, int words);

};