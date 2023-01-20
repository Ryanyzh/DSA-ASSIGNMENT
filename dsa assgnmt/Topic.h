#pragma once
#include <string>
#include "PLinkedList.h"

using namespace std;

class Topic
{
	private:
		string topicName;
		PLinkedList postList;

	public:
		//PLinkedList::PNode* postPointer;
		Topic();
		~Topic();
		string getTopicName();
		void setTopicName(string);
		
};

