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
	cout << "������²����ڸ����ӣ�" << endl;
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
	cout << "���ƣ�" << name << endl;
	cout << "id: " << id << endl;
	cout << "������Ŀ��" << posts.size() << endl;
	cout << "���ӣ�" << endl;
	for (auto p : posts)
		cout << p->GetTitle() << endl;
}
