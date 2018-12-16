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
    QString username;		//������
public:
	Comment();
    Comment(QString c) :content(c) { time = GetTime(); }
	~Comment();
    MyTime GetTime() { return time; }
    QString GetContent() { return content; }
    void SetContent(const QString s) { content = s; }
    QString GetUserName() { return username; }
    void SetUserName(QString un) { username = un; }
    QString Show();
    /* ��������� */
    friend ofstream& operator << (ofstream& fout, const Comment& comment);
    friend ifstream& operator >> (ifstream& fin, Comment& comment);
};

#endif // !COMMENT_H
