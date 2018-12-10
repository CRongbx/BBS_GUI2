#ifndef POST_H
#define POST_H
//����
#include <QString>
#include <vector>
#include "OrdinaryUser.h"
#include "Comment.h"

using namespace std;

class Post
{
private:
	int id;				//����id
    QString title;		//���ӱ���
    QString content;		//��������
	OrdinaryUser* user;	//������
    MyTime time;			//����ʱ��
	vector<Comment*> comments;	//�����µ�����
    Board* board;           //��������
public:
	Post();
    Post(int id, QString title, QString content) :id(id), title(title), content(content) { time = GetTime(); };
	~Post();
    void SetBoard(Board* const b){board = b;}
    QString Show();
    vector<QString> ShowComments();
	int GetId() { return id; }
	void SetId(const int id) { this->id = id; }
    QString GetTitle() { return title; }
    void SetTitle(const QString t) { title = t; }
    QString GetContent() { return content; }
    void SetContent(const QString c) { content = c; }
	OrdinaryUser* GetUser() { return user; }
	void SetUser(OrdinaryUser* const ou) { user = ou; }
    void SetTime(MyTime t) { time = t; }
    MyTime GetTime() { return time; }
	bool AddComment(Comment* c);
	bool DeleteComment(Comment* c);
	int GetCommentsSize() { return comments.size(); }		//��ø������µ���������
    Comment* GetComment(QString name);
    friend ofstream& operator <<(ofstream& fout,const Post &post);
};

#endif // !POST_H

