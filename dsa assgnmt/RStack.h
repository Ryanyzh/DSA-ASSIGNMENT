#pragma once
#include <string>
#include "Reply.h"

using namespace std;


class RStack
{
	typedef Reply ItemType;

	private:
		struct RNode
		{
			ItemType ritem;
			RNode* rnext;
		};

	protected:
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

