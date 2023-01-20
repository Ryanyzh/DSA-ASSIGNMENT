#include "RStack.h"

#include <iostream>

using namespace std;

RStack::RStack() {
	rTopNode = NULL;
};

RStack::~RStack() {
	RNode* current = NULL;
	while (rTopNode->rnext != NULL) {
		current = rTopNode;
		rTopNode = rTopNode->rnext;
		current->rnext = NULL;
		delete current;
	}
}

bool RStack::isEmpty() {
	if (rTopNode == NULL) {
		return true;
	}
	else {
		return false;
	}
}

bool RStack::push(ItemType item) {
	RNode* newNode = new RNode;
	newNode->ritem = item;
	newNode->rnext = NULL;

	newNode->rnext = rTopNode; //set new node's pointer to point to node pointed to by topNode
	rTopNode = newNode; //set topNode(pointer) to point to new Node

	return true;
}


RStack::ItemType RStack::getTop() {
	if (!isEmpty()) {
		return rTopNode->ritem;
	}
	return ItemType();
}

void RStack::displayInOrder() {
	RNode* currentNode = new RNode;
	currentNode = rTopNode;
	do {
		cout << "Item is: " << currentNode->ritem.getRContent() << endl;
		currentNode = currentNode->rnext;
	} while (currentNode != NULL);
}

void RStack::displayInOrderOfInsertion() {
	RStack newStack;
	RNode* current = new RNode;
	current = rTopNode;
	while (current != NULL) {
		newStack.push(current->ritem);
		current = current->rnext;
	}
	newStack.displayInOrder();
}

