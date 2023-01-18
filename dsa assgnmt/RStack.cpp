#include "RStack.h"

#include <iostream>

using namespace std;

RStack::RStack() {
	topNode = NULL;
};

RStack::~RStack() {
	Node* current = NULL;
	while (topNode->next != NULL) {
		current = topNode;
		topNode = topNode->next;
		current->next = NULL;
		delete current;
	}
}

bool RStack::isEmpty() {
	if (topNode == NULL) {
		return true;
	}
	else {
		return false;
	}
}

bool RStack::push(ItemType item) {
	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;

	newNode->next = topNode; //set new node's pointer to point to node pointed to by topNode
	topNode = newNode; //set topNode(pointer) to point to new Node

	return true;
}


ItemType RStack::getTop() {
	if (!isEmpty()) {
		return topNode->item;
	}
	return ItemType();
}

void RStack::displayInOrder() {
	Node* currentNode = new Node;
	currentNode = topNode;
	do {
		cout << "Item is: " << currentNode->item.getRContent() << endl;
		currentNode = currentNode->next;
	} while (currentNode != NULL);
}

void RStack::displayInOrderOfInsertion() {
	RStack newStack;
	Node* current = new Node;
	current = topNode;
	while (current != NULL) {
		newStack.push(current->item);
		current = current->next;
	}
	newStack.displayInOrder();
}

