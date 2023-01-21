#include "ULinkedList.h"
#include <string>
#include <iostream>

using namespace std;

// constructor
ULinkedList::ULinkedList() { size = 0; }

ULinkedList::~ULinkedList()
{

}



// add an item to the back of the list
bool ULinkedList::add(ItemType item)
{
	UNode* newNode = new UNode;
	newNode->uitem = item;
	newNode->unext = NULL;
	UNode* current = uFirstNode;

	if (size == 0) {
		uFirstNode = newNode;
	}
	else {
		while (current->unext != NULL) {
			current = current->unext;
		}
		current->unext = newNode;
	}
	size++;
	return true;
}

// add an item at a specified position in the list
bool ULinkedList::add(int index, ItemType item)
{
	if (index <= size) {
		UNode* newNode = new UNode;
		newNode->uitem = item;
		newNode->unext = NULL;

		if (index == 0) {
			newNode->unext = uFirstNode;
			uFirstNode = newNode;
		}
		else {
			UNode* current = uFirstNode;
			for (index; index - 1 > 0; index--) {
				current = current->unext;
			}
			newNode->unext = current->unext;
			current->unext = newNode;
		}
		size++;
		return true;
	}
	else {
		return false;
	}
}

// remove an item at a specified position in the list
void ULinkedList::remove(int index)
{
	if (index <= size) {
		if (index == 0) {
			uFirstNode = uFirstNode->unext;
		}
		else {
			UNode* current = uFirstNode;
			UNode* previous = current;
			for (index; index > 0; index--) {
				previous = current;
				current = current->unext;
			}
			previous->unext = current->unext;
		}
	}

}

// get an item at a specified position of the list
ULinkedList::ItemType ULinkedList::get(int index)
{
	UNode* current = new UNode;
	if (index <= size) {
		for (index; index > 0; index--) {
			current = current->unext;
		}
		return current->uitem;
	}
	else {
		return ItemType();
	}

}

// check if the list is empty
bool ULinkedList::isEmpty() { return size == 0; }

// check the size of the list
int ULinkedList::getLength() { return size; }

// display the items in the list
void ULinkedList::print()
{
	UNode* tempPointer;
	tempPointer = uFirstNode;

	while (tempPointer != NULL) {
		cout << "The item is " << tempPointer->uitem.getUsername() << "." << endl;
		tempPointer = tempPointer->unext;
	}
}


bool ULinkedList::checkCredentials(string u, string p) {
	UNode* tempPointer;
	tempPointer = uFirstNode;

	while (tempPointer != NULL) {
		if (u == tempPointer->uitem.getUsername() && p == tempPointer->uitem.getPassword()) {
			return true;
			break;
		}
		tempPointer = tempPointer->unext;
	}
	return false;
}
