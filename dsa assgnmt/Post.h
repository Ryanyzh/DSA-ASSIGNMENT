#pragma once

#include "Reply.h"
#include "RStack.h"
#include "User.h"
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
		RStack replyStack;
		

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
		RStack getRStack();

		bool isRStackEmpty();

		bool addReply(Reply reply);
};

