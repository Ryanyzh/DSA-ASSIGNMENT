#pragma once
#include <string>
#include "User.h"

using namespace std;

typedef User ItemType;

struct UNode {
	ItemType uitem;
	UNode* unext;
};

class ULinkedList
{
private:
	UNode* uFirstNode;
	int size;

public:
	//constructor
	ULinkedList();

	//destrcutor
	~ULinkedList();

	//add an item to the back of the list
	bool add(ItemType item);

	//add an item at a specified position in the list
	bool add(int index, ItemType item);

	//remove an item at a specified position of the list
	void remove(int index);

	//get an item at a specified position of the list
	ItemType get(int index);

	//check if the size of the list is empty
	bool isEmpty();

	//check the size of the list
	int getLength();

	//display all the items in the list
	void print();

};



