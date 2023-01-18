#pragma warning(disable : 4996)
#include "Reply.h"
#include <string>
#include <ctime>

using namespace std;

Reply::Reply() {
	Rtitle = "";
	Rcontent = "";
	Rdatetime = { nullptr };
	//user = NULL;  HOW TO SET THE USER TO NULL?
};

Reply::~Reply() {
	//idk
};

string Reply::getRTitle() {
	return Rtitle;
};

string Reply::getRContent() {
	return Rcontent;
};

void Reply::setRDateTime() {
	time_t ttime = time(0);
	char* dt = ctime(&ttime);
	Rdatetime = dt; // check this again cause this is a pointer
};

void Reply::setRTitle(string rt) {
	Rtitle = rt;
};

void Reply::setRContent(string rc) {
	Rcontent = rc;
};