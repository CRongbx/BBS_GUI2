#include "Comment.h"
#include "OrdinaryUser.h"

Comment::Comment()
{
	time = GetTime();
}


Comment::~Comment()
{
}

void Comment::Show()
{
//	cout << "Comment:" << endl;
//	cout << "�����ڣ�" << endl;
	ShowTime(time);
//	cout << "���ݣ�" << content << endl;
//	cout << "�����ˣ�" << user->GetUserName() << endl;
}
