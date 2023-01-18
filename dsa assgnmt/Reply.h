#pragma once

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

