#pragma once


#include <string>

using namespace std;
class User
{
	private:
		string username;
		string password;

	public:
		User();
		~User();
		string getUsername();
		void setUsername(string);
		void setPassword(string);
};

