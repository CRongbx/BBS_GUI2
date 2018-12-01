#ifndef POST_H
#define POST_H
//帖子
#include <string>
#include <vector>
#include "OrdinaryUser.h"
#include "Comment.h"

using namespace std;

class Post
{
private:
	int id;				//帖子id
	string title;		//帖子标题
	string content;		//帖子内容
	OrdinaryUser* user;	//发帖人
    MyTime time;			//创建时间
	vector<Comment*> comments;	//帖子下的评论
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
	int GetCommentsSize() { return comments.size(); }		//获得该帖子下的评论数量
};

#endif // !POST_H

