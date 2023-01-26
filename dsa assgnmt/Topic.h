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
		
		//Topic Setter 
		void setTopicName(string);

		//Topic getter
		string getTopicName();
		
		//Add post to topic
		bool addPost(Post post);

		//Remove post from topic
		void removePost(int index);

		//Display topic details?
		void displayTopicDetails();
};

