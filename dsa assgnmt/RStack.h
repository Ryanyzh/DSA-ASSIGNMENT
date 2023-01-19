#pragma once
#include <string>
#include "Reply.h"

using namespace std;

typedef Reply ItemType;

struct RNode
{
	ItemType ritem;
	RNode* rnext;
};

class RStack
{
private:
	RNode* rTopNode;

public:
	RStack();
	~RStack();
	bool push(ItemType item);
	ItemType getTop();
	bool isEmpty();
	void displayInOrder();
	void displayInOrderOfInsertion();
};

