#pragma once
#include "Prisoner.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;







Prisoner* constructCircularLinkedList(int prisoners)
{
	Prisoner* n;
	Prisoner* t;
	Prisoner* h;

	n = new Prisoner();
	n->data = 1;
	h = n;
	t = n;


	for (int i = 1; i < prisoners; i++) {
		n = new Prisoner();
		n->data = (i + 1);
		t->next = n;
		t = t->next;
	}
	t = n;
	t->next = h;
	return h;
}


Prisoner::Prisoner()
{}


void Prisoner::setData(int data) {
	this->data = data;
}
int Prisoner::getData() {
	return this->data;
}

void Prisoner::setNext(Prisoner* prisoner) {

}
Prisoner* Prisoner::getNext() {
	return this->next;
}

int determineSurvivor(Prisoner *n, int words, int prisoners) {



	// When not first node, follow the normal deletion process 

	// find the previous node
	Prisoner* tempLink = n;
	if (tempLink == tempLink->next)
	{
	return (tempLink->data);
	}


	//finds node to delete
	for (int i = 1; i < words; i++) {
	tempLink = tempLink->next;
	}

	//iterates until behind found node
	for (int i = 1; i < prisoners; i++)
	{
	tempLink = tempLink->next;
	}
	Prisoner *prev = tempLink;
	// Remove node from Linked List 
	prev->next = prev->next->next;
	prev = prev->next;
	
	prisoners = prisoners - 1;
	return determineSurvivor((prev), words, prisoners);
	free(n);
}





int main()
{
	int prisoners = 10;
	int words = 1;

	Prisoner peep = Prisoner();

	Prisoner* person = constructCircularLinkedList(prisoners);

	//I created some functions as a friend functions because I liked the access better :D
	cout << endl << "With " << prisoners << " prisoners and " << words << " many words, the survivor will be number " << determineSurvivor(person, words, prisoners) << endl;
	prisoners = 22;
	words = 10;

	cout << endl << "With " << prisoners << " prisoners and " << words << " many words, the survivor will be number " << determineSurvivor(person, words, prisoners) << endl;
	prisoners = 3;
	words = 3;

	cout << endl << "With " << prisoners << " prisoners and " << words << " many words, the survivor will be number " << determineSurvivor(person, words, prisoners) << endl;
	prisoners = 6;
	words = 3;

	cout << endl << "With " << prisoners << " prisoners and " << words << " many words, the survivor will be number " << determineSurvivor(person, words, prisoners) << endl;
	cin.get();//pauses the console for viewing


}