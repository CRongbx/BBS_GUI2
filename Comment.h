#ifndef COMMENT_H
#define COMMENT_H

#include <QString>
#include "MyTime.h"
using namespace std;

class OrdinaryUser;

class Comment
{
private:
    QString content;
    MyTime time ;
	OrdinaryUser* user;		//∆¿¬€»À
public:
	Comment();
    Comment(QString c) :content(c) { time = GetTime(); }
	~Comment();
    MyTime GetTime() { return time; }
    QString GetContent() { return content; }
    void SetContent(const QString s) { content = s; }
	OrdinaryUser* GetOrdinaryUser() { return user; }
	void SetOrdinaryUser(OrdinaryUser* u) { user = u; }
    QString Show();
};

#endif // !COMMENT_H
