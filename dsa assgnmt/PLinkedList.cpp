#include "PLinkedList.h"
#include <string>
#include <iostream>

using namespace std;

// constructor
PLinkedList::PLinkedList() { size = 0; pFirstNode = NULL; }

PLinkedList::~PLinkedList()
{
}



// add an item to the back of the list
bool PLinkedList::add(ItemType item)
{
	PNode* newNode = new PNode;
	newNode->pitem = item;
	newNode->pnext = NULL;
	PNode* current = pFirstNode;

	if (size == 0) {
		pFirstNode = newNode;
	}
	else {
		while (current->pnext != NULL) {
			current = current->pnext;
		}
		current->pnext = newNode;
	}
	size++;
	return true;
}

// add an item at a specified position in the list
bool PLinkedList::add(int index, ItemType item)
{
	if (index <= size) {
		PNode* newNode = new PNode;
		newNode->pitem = item;
		newNode->pnext = NULL;

		if (index == 0) {
			newNode->pnext = pFirstNode;
			pFirstNode = newNode;
		}
		else {
			PNode* current = pFirstNode;
			for (index; index - 1 > 0; index--) {
				current = current->pnext;
			}
			newNode->pnext = current->pnext;
			current->pnext = newNode;
		}
		size++;
		return true;
	}
	else {
		return false;
	}
}

// remove an item at a specified position in the list
void PLinkedList::remove(int index)
{
	if (index <= size) {
		if (index == 0) {
			pFirstNode = pFirstNode->pnext;
		}
		else {
			PNode* current = pFirstNode;
			PNode* previous = current;
			for (index; index > 0; index--) {
				previous = current;
				current = current->pnext;
			}
			previous->pnext = current->pnext;
		}
	}

}

// get an item at a specified position of the list
PLinkedList::ItemType PLinkedList::get(int index)
{
	PNode* current = new PNode;
	if (index <= size) {
		for (index; index > 0; index--) {
			current = current->pnext;
		}
		return current->pitem;
	}
	else {
		return ItemType();
	}

}

// check if the list is empty
bool PLinkedList::isEmpty() { return size == 0; }

// check the size of the list
int PLinkedList::getLength() { return size; }

// display the items in the list
void PLinkedList::print()
{
	PNode* tempPointer;
	tempPointer = pFirstNode;

	while (tempPointer != NULL) {
		cout << "The item is " << tempPointer->pitem.getPContent() << "." << endl;
		tempPointer = tempPointer->pnext;
	}
}

