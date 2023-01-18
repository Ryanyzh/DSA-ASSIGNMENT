#pragma once

#ifndef USER_H //idk what this do
#define USER_H //idk what this do

#include <string>
#include "User.h"

using namespace std;

class Reply
{
	private:
		string Rtitle;
		string Rcontent;
		char* Rdatetime;
		User user;

	public:
		Reply();
		~Reply();

		void setRDateTime();
		void setRTitle(string);
		void setRContent(string);

		string getRTitle();
		string getRContent();
		string getRDateTime(); //not implemented

};
#endif

