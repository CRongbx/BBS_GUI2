#include "Board.h"
#include "Post.h"
#include <iostream>
using namespace std;

Board::Board()
{
}


Board::~Board()
{
}

bool Board::AddPost(Post * p)
{
	posts.push_back(p);
	return true;
}

bool Board::DeletePost(Post * p)
{
	for (vector<Post*>::iterator it = posts.begin();it != posts.end();++it) {
		if ((*it) == p) {
			posts.erase(it);
			return true;
		}
	}
	cout << "本版块下不存在该帖子！" << endl;
	return false;
}

bool Board::IsPostExist(Post * const p)
{
	for (auto post : posts) {
		if (p == post)
			return true;
	}
	return false;
}

void Board::Show()
{
	cout << "Board:" << endl;
	cout << "名称：" << name << endl;
	cout << "id: " << id << endl;
	cout << "帖子数目：" << posts.size() << endl;
	cout << "帖子：" << endl;
	for (auto p : posts)
		cout << p->GetTitle() << endl;
}
