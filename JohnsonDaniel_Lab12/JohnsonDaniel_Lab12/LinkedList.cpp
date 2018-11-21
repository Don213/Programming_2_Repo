#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList()
{
	head = nullptr;
}
LinkedList::~LinkedList()
{
	Node *temp = head;
	while (temp != nullptr)
	{
		Node *next = temp->getNext();
		delete temp;
		temp = next;
	}
}

// Output everything in the list
void LinkedList::output()
{
	Node *temp = head;
	while (temp != nullptr)
	{
		cout << temp->getName() << endl;
		temp = temp->getNext();
	}
	cout << endl;
}

// Adds a new node with this string to the front of the linked list
void LinkedList::add(string s)
{
	if (head == nullptr)
	{
		// New list, make head point to it
		head = new Node(s, nullptr);
	}
	else
	{
		// Make a new node that points to head
		Node *temp = new Node(s, head);
		// Set head to the new node
		head = temp;
	}
}

// Deletes first occurrence of s in the list
void LinkedList::remove(string s)
{
	Node *temp = head;
	Node *previous = nullptr;  // You might want to use this variable
	while (temp != nullptr)
	{
		if (temp->getName() == s)
		{
			// If we are deleting the head of the list
			if (temp == head)
			{
				head = head->getNext();
				delete temp;
			}
			else
				// We are deleting something that is not the head
			{
				previous->setNext(temp->getNext());
			}

			break;
		}
		previous = temp;
		temp = temp->getNext();
	}
}

Node* LinkedList::contains(string target)
{
	Node *temp = head;
	Node *previous = nullptr;  // You might want to use this variable
	while (temp != nullptr)
	{
		if (temp->getName() == target)
		{
			return temp;
		}
		previous = temp;
		temp = temp->getNext();
	}
	return nullptr;
}

void LinkedList::addTail(string s)
{
	Node *temp = head;
	Node *previous = nullptr;  // You might want to use this variable
	while (temp != nullptr)
	{
		previous = temp;
		temp = temp->getNext();
	}

	temp = new Node(s, nullptr);
	previous->setNext(temp);
}
