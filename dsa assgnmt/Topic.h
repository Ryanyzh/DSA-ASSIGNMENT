#pragma once
#include <string>
#include "PLinkedList.h"

using namespace std;

class Topic
{
	private:
		string topicName;
		PNode* postPointer;

	public:
		Topic();
		~Topic();
		string getTopicName();
		void setTopicName(string);
		
};

