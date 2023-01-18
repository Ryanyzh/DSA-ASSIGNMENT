#pragma once
#include <string>
#include "Reply.h"

using namespace std;

typedef Reply ItemType;

struct Node
{
	ItemType item;
	Node* next;
};

class RStack
{
private:
	Node* topNode;

public:
	RStack();
	~RStack();
	bool push(ItemType item);
	ItemType getTop();
	bool isEmpty();
	void displayInOrder();
	void displayInOrderOfInsertion();
};

