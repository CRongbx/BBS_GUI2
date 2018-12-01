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
//	cout << "创建于：" << endl;
	ShowTime(time);
//	cout << "内容：" << content << endl;
//	cout << "评论人：" << user->GetUserName() << endl;
}
