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
		//Array reactions (To be implemented);
		RStack replyStack;
		

	public:
		Post();
		~Post();
		// Post setters
		void setPDateTime();
		void setPTitle(string);
		void setPContent(string);
		void setLikes(int);

		//Post getters
		string getPTitle();
		string getPContent();
		string getPDateTime();
		RStack getRStack();

		//Add reply to post
		bool addReply(Reply reply);
};

