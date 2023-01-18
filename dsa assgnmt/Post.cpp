#pragma warning(disable : 4996)
#include "Post.h"
#include <string>
#include <ctime>

using namespace std;

Post::Post() {
	Ptitle = "";
	Pcontent = "";
	Pdatetime = { nullptr };
	likes = 0;
	//user = NULL;  HOW TO SET THE USER TO NULL?
};

Post::~Post() {
	//idk
};

string Post::getPTitle() {
	return Ptitle;
};

string Post::getPContent() {
	return Pcontent;
};


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
