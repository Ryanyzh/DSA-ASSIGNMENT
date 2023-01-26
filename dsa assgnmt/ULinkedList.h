#pragma once
#include <string>
#include "User.h"

using namespace std;





class ULinkedList
{
	typedef User ItemType;

	private:
		struct UNode {
			ItemType uitem;
			UNode* unext;
		};

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

		//check if user input correspond to the saved credentials
		bool checkCredentials(string u, string p);

		//search user with username
		User searchUser(string username);
		//recursive function for the above search function
		User searchUser(string username, UNode* userNode);
};



