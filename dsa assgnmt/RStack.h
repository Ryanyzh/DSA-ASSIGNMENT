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

		RNode* rTopNode;
		

	public:
		//Constructor
		RStack();

		//Deconstructor
		~RStack();

		//Add a reply to the stack
		bool push(ItemType item);

		//Delete a reply from stack (Used for deconstructor)
		bool pop();

		//Get reply at top of stack
		ItemType getTop();

		//Check for empty stack
		bool isEmpty();

		//Display replies in order
		void displayInOrder();

		//Display replies in order of insertion
		void displayInOrderOfInsertion();
};

