#include "BBS.h"
#include <iostream>
#include <QString>
using namespace std;
BBS::BBS()
{
}


BBS::~BBS()
{
	
}

User * BBS::GetUser(int id)
{
	for (auto u : users) {
		if (u->GetId() == id)
			return u;
	}
	return nullptr;
}

User * BBS::GetUser(const QString &name)
{
	for (auto u : users) {
		if (u->GetUserName() == name)
			return u;
	}
	return nullptr;
}

bool BBS::AddUser(User * const u)
{
	for (auto u : users) {
		if (u->GetUserName() ==u->GetUserName()) {
			cout << "该用户名已存在，无法注册！" << endl;
			return false;
		}
	}
	users.push_back(u);
	return true;
}

bool BBS::DeleteUser(User * const u)
{
	for (vector<User*>::iterator it = users.begin();it != users.end();it++) {
		if (u == (*it)) {
			users.erase(it);
			return true;
		}
	}
	return false;
}

bool BBS::AddBoard(Board * b)
{
	for (auto bo : boards) {
		if (bo->GetName() == b->GetName()) {
			cout << "该版块以存在，添加失败！" << endl;
			return false;
		}
	}
	boards.push_back(b);
	return true;
}

bool BBS::DeleteBoard(Board * b)
{
	for (vector<Board*>::iterator it = boards.begin();it != boards.end();it++) {
		if (b == (*it)) {
			boards.erase(it);
			return true;
		}
	}
	return false;
}

void BBS::ShowBoards()
{
	cout << "当前论坛已有版块如下：" << endl << endl;
	for (auto b : boards)
		b->Show();
}

void BBS::ShowUsers()
{
	cout << "当前用户已有用户如下：" << endl << endl;
//	for (auto u : users)
//		cout << u->GetUserName() << endl;
}

