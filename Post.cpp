#include "Post.h"
#include "MyTime.h"


Post::Post()
{
	time = GetTime();
}


Post::~Post()
{
}

void Post::Show()
{
	cout << "Infomation of Post:" << endl;
	cout << "创建时间：" << endl;
	ShowTime(time);
	cout << "Id:" << id << endl;
	cout << "Title:" << title << endl;
	cout << "Content:" << content << endl;
//	cout << "发帖人：" << user->GetUserName() << endl;
	cout << "评论：" << endl;
	for (auto c : comments)
		c->Show();
}

bool Post::AddComment(Comment * c)
{
	comments.push_back(c);
	return true;
}

bool Post::DeleteComment(Comment * c)
{
	for (vector<Comment*>::iterator it = comments.begin();it != comments.end();it++) {
		if (c == (*it)) {
			comments.erase(it);
			return true;
		}
	}
	return false;
}
