#include "Topic.h"
#include <string>

using namespace std;

Topic::Topic() {
	topicName = "";
};

Topic::~Topic() {
	//idk
};

string Topic::getTopicName() {
	return topicName;
};

void Topic::setTopicName(string tn) {
	topicName = tn;
};
