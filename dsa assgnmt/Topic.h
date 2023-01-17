#pragma once
#include <string>

using namespace std;

class Topic
{
	private:
		string topicName;

	public:
		Topic();
		~Topic();
		string getTopicName();
		void setTopicName(string);
		
};

