#pragma once

#include "Reply.h"
#include "RStack.h"
#include <string>
#include <ctime>

using namespace std;

class Post
{
	private:
		string Ptitle;
		string Pcontent;
		char* Pdatetime;
		User user;
		int likes;
		//Array reactions;
		RNode* replypointer;
		

	public:
		Post();
		~Post();

		void setPDateTime();
		void setPTitle(string);
		void setPContent(string);
		void setLikes(int);


		string getPTitle();
		string getPContent();
		string getPDateTime();
};

