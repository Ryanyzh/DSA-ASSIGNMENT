#include "Topic.h"
#include <string>

using namespace std;

Topic::Topic() {
	topicName = "";
	postList = PLinkedList();
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

bool Topic::addPost(Post post) {
	return postList.add(post);
}

void Topic::removePost(int index) {
	postList.remove(index);
}

void Topic::displayTopicDetails() {
	// Insert code here
}
