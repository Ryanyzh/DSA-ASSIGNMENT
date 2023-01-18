#include "TDictionary.h"
#include <string>

using namespace std;

TDictionary::TDictionary() {
	size = 0;
	for (int i = 0; i < MAX_SIZE; i++) {
		items[i] = NULL;
	}
}

TDictionary::~TDictionary() {
	for (int i = 0; i < size; i++) {
		while (items[i] != NULL) {
			remove(items[i]->key);
		}
	}
}

int TDictionary::hash(KeyType key) { //use string or int
	//https://dev.to/muiz6/string-hashing-in-c-1np3
	int hashValue = 0;  
	int totalHashValue = 0;
	//cout << "\n" << endl;
	for (int pos = 0; pos < key.length(); pos++) {
		if (isalpha(key[pos]))
		{
			if (isupper(key[pos])) {
				hashValue = (int)key[pos] - (int)'A';
			}
			else {
				hashValue = (int)key[pos] - (int)'a' + 26;
			}
		}
		else {
			return 0;
		}
		totalHashValue = totalHashValue * 52 + hashValue;
		totalHashValue %= MAX_SIZE;
		//totalHashValue = hashValue * (pos + 1) + totalHashValue;
	}
	//cout << totalHashValue << endl;
	//cout << totalHashValue % MAX_SIZE << endl;

	return totalHashValue;
}

bool TDictionary::add(KeyType newKey, ItemType newItem) {
	int index = hash(newKey);
	if (items[index] == NULL) {
		Node* newNode = new Node;
		newNode->key = newKey;
		newNode->item = newItem;
		newNode->next = NULL;
		items[index] = newNode;
	}
	else {
		Node* current = items[index];
		if (current->key == newKey) {
			cout << newKey << " already exists." << endl;
			return false;
		}
		while (current->next != NULL) {
			current = current->next;
			if (current->key == newKey) {
				cout << newKey << " already exists." << endl;
				return false;
			}
		}
		Node* newNode2 = new Node;
		newNode2->key = newKey;
		newNode2->item = newItem;
		newNode2->next = NULL;
		current->next = newNode2;
	}
	size++;
	return true;
}

void TDictionary::remove(KeyType key) {
	int index = hash(key);
	if (items[index] != NULL) {
		Node* removal = new Node;
		Node* current = new Node;
		current = items[index];
		if (current->key == key) {
			items[index] = current->next;
			current->next = NULL;
			delete current;
		}
		else {
			while (current->next != NULL) {
				removal = current->next;
				if (removal->key == key) {
					current->next = removal->next;
					removal->next = NULL;
					delete removal;
				}
				else {
					current = current->next;
				}
			}
		}

	}
	size--;
}

ItemType TDictionary::get(KeyType key) {
	int index = hash(key);
	if (items[index] != NULL) {
		Node* current = new Node;
		current = items[index];
		while (current->next != NULL) {
			if (current->key == key) {
				return current->item;
			}
			current = current->next;
		}
	}
	//need to return here?
	return ItemType();
}

bool TDictionary::isEmpty() { return size == 0; }

int TDictionary::getLength() { return size; }

void TDictionary::printAllPost() {
	for (int i = 0; i < MAX_SIZE; i++) {
		Node* current = new Node;
		current = items[i];
		if (current != NULL) {
			cout << current->key << " : " << current->item.getPContent() << endl;
			while (current->next != NULL) {
				cout << current->next->key << " : " << current->next->item.getPContent() << endl;
				current = current->next;
			}
		}
	}
	cout << "\n\n" << endl;
}
