#ifndef POST_H
#define POST_H
//����
#include <string>
#include <vector>
#include "OrdinaryUser.h"
#include "Comment.h"

using namespace std;

class Post
{
private:
	int id;				//����id
	string title;		//���ӱ���
	string content;		//��������
	OrdinaryUser* user;	//������
    MyTime time;			//����ʱ��
	vector<Comment*> comments;	//�����µ�����
public:
	Post();
	Post(int id, string title, string content) :id(id), title(title), content(content) { time = GetTime(); };
	~Post();
	void Show();
	int GetId() { return id; }
	void SetId(const int id) { this->id = id; }
	string GetTitle() { return title; }
	void SetTitle(const string t) { title = t; }
	string GetContent() { return content; }
	void SetContent(const string c) { content = c; }
	OrdinaryUser* GetUser() { return user; }
	void SetUser(OrdinaryUser* const ou) { user = ou; }
    void SetTime(MyTime t) { time = t; }
    MyTime GetTime() { return time; }
	bool AddComment(Comment* c);
	bool DeleteComment(Comment* c);
	int GetCommentsSize() { return comments.size(); }		//��ø������µ���������
};

#endif // !POST_H

