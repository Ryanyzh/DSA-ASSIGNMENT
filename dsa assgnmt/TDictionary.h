#pragma once
#include <string>
#include <iostream>
#include "Topic.h"

using namespace std;

const int MAX_SIZE = 101; //this one need to change
typedef Topic ItemType;
typedef string KeyType;

struct Node 
{
	KeyType key;
	ItemType item;
	Node* next; //or use hashnext;
};

class TDictionary
{
	private:
		Node* items[MAX_SIZE];
		int size;
	public:
		//constructor
		TDictionary();

		//destructor
		~TDictionary();

		//get hash value from key
		int hash(KeyType key);

		//add a new item with the specified key in the Dictionary
		bool add(KeyType newKey, ItemType item);

		//remove an item with the specified key in the Dictionary
		void remove(KeyType key);

		//get an item with the specified key in the Dictionary
		ItemType get(KeyType key);

		//check if the Dictionary is empty
		bool isEmpty();

		//check the size of the Dictionary
		int getLength();

		//display the topics in the Dictionary
		void printAllTopics();

};

