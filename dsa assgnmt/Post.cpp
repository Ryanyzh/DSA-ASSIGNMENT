#pragma warning(disable : 4996)
#include "Post.h"
#include <string>
#include <ctime>

using namespace std;

Post::Post() {
	Ptitle = "";
	Pcontent = "";
	Pdatetime = { nullptr };
	user = User();  //HOW TO SET THE USER TO NULL?
	replyStack = RStack() ;
	reactions = ReactionList();
};

Post::~Post() {
	// Deconstruct replyStack
	replyStack.~RStack();
};

string Post::getPTitle() {
	return Ptitle;
};

string Post::getPContent() {
	return Pcontent;
};

RStack Post::getRStack() {
	return replyStack;
}

void Post::setPDateTime() {
	time_t ttime = time(0);
	char* dt = ctime(&ttime);
	Pdatetime = dt; // check this again cause this is a pointer
};

void Post::setPTitle(string pt) {
	Ptitle = pt;
};

void Post::setPContent(string pc) {
	Pcontent = pc;
};

bool Post::addReply(Reply reply) {
	return replyStack.push(reply);
}


