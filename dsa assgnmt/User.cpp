#include "User.h"
#include <string>

using namespace std;

User::User() {
	username = "";
	password = "";
};

User::~User() {
	//idk
};

string User::getUsername() {
	return username;
};

void User::setUsername(string u) {
	username = u;
};

void User::setPassword(string p) {
	password = p;
};