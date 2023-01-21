#include "TDictionary.h"
#include <string>

using namespace std;

TDictionary::TDictionary() {
	size = 0;
	for (int i = 0; i < HT_MAX_SIZE; i++) {
		items[i] = NULL;
	}
}

TDictionary::~TDictionary() {
	for (int i = 0; i < size; i++) {
		while (items[i] != NULL) {
			remove(items[i]->tkey);
		}
	}
}

int TDictionary::hash(KeyType key) { //use string or int
	//https://dev.to/muiz6/string-hashing-in-c-1np3
	size_t hashCode = 0;
	for (int i = 0; i < key.length(); i++) {
		hashCode += (key[i] * (int)pow(31, i)) % HT_MAX_SIZE;
	}
	return hashCode % HT_MAX_SIZE;
}

bool TDictionary::add(KeyType newKey, ItemType newItem) {
	int index = hash(newKey);
	if (items[index] == NULL) {
		TNode* newNode = new TNode;
		newNode->tkey = newKey;
		newNode->titem = newItem;
		newNode->tnext = NULL;
		items[index] = newNode;
	}
	else {
		TNode* current = items[index];
		if (current->tkey == newKey) {
			cout << newKey << " already exists." << endl;
			return false;
		}
		while (current->tnext != NULL) {
			current = current->tnext;
			if (current->tkey == newKey) {
				cout << newKey << " already exists." << endl;
				return false;
			}
		}
		TNode* newNode2 = new TNode;
		newNode2->tkey = newKey;
		newNode2->titem = newItem;
		newNode2->tnext = NULL;
		current->tnext = newNode2;
	}
	size++;
	return true;
}

void TDictionary::remove(KeyType key) {
	int index = hash(key);
	if (items[index] != NULL) {
		TNode* removal = new TNode;
		TNode* current = new TNode;
		current = items[index];
		if (current->tkey == key) {
			items[index] = current->tnext;
			current->tnext = NULL;
			delete current;
		}
		else {
			while (current->tnext != NULL) {
				removal = current->tnext;
				if (removal->tkey == key) {
					current->tnext = removal->tnext;
					removal->tnext = NULL;
					delete removal;
				}
				else {
					current = current->tnext;
				}
			}
		}

	}
	size--;
}

TDictionary::ItemType TDictionary::get(KeyType key) {
	int index = hash(key);
	if (items[index] != NULL) {
		TNode* current = new TNode;
		current = items[index];
		while (current->tnext != NULL) {
			if (current->tkey == key) {
				return current->titem;
			}
			current = current->tnext;
		}
	}
	//need to return here?
	return ItemType();
}

bool TDictionary::isEmpty() { return size == 0; }

int TDictionary::getLength() { return size; }

void TDictionary::printAllPost() {
	for (int i = 0; i < HT_MAX_SIZE; i++) {
		TNode* current = new TNode;
		current = items[i];
		if (current != NULL) {
			cout << current->tkey << " : " << current->titem.getTopicName() << endl;
			while (current->tnext != NULL) {
				cout << current->tnext->tkey << " : " << current->tnext->titem.getTopicName() << endl;
				current = current->tnext;
			}
		}
	}
	cout << "\n\n" << endl;
}
