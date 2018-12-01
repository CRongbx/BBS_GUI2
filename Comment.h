#ifndef COMMENT_H
#define COMMENT_H

#include <string>
#include "MyTime.h"
using namespace std;

class OrdinaryUser;

class Comment
{
private:
	string content;
    MyTime time;
	OrdinaryUser* user;		//∆¿¬€»À
public:
	Comment();
	Comment(string c) :content(c) { time = GetTime(); }
	~Comment();
    MyTime GetTime() { return time; }
	string GetContent() { return content; }
	void SetContent(const string s) { content = s; }
	OrdinaryUser* GetOrdinaryUser() { return user; }
	void SetOrdinaryUser(OrdinaryUser* u) { user = u; }
	void Show();
};

#endif // !COMMENT_H
