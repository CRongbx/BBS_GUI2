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
	cout << "����ʱ�䣺" << endl;
	ShowTime(time);
	cout << "Id:" << id << endl;
	cout << "Title:" << title << endl;
	cout << "Content:" << content << endl;
//	cout << "�����ˣ�" << user->GetUserName() << endl;
	cout << "���ۣ�" << endl;
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
