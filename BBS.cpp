#include "BBS.h"
#include <iostream>
#include <QString>
#include "Administator.h"
#include "OrdinaryUser.h"
#include "MyTime.h"
#include "Post.h"
using namespace std;

BBS::BBS()
{
}


BBS::~BBS()
{
    for(vector<Board*>::iterator it = boards.begin();it != boards.end();it++)
        if((*it))
            delete (*it);
    for(vector<User*>::iterator it = users.begin();it != users.end();it++)
        if((*it))
            delete (*it);
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

Board* BBS::GetBoard(QString name){
    for(auto b : boards){
        if (b->GetName()==name)
            return b;
    }
    return nullptr;
}

bool BBS::AddUser(User * const u)
{
    for (auto user : users) {
        if (user->GetUserName() ==u->GetUserName()) {
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

vector<QString> BBS::ShowBoards()
{
//	cout << "当前论坛已有版块如下：" << endl << endl;
    vector<QString> boardinfo;
    for (auto b : boards){
        boardinfo.push_back(b->GetName());
    }
    return boardinfo;
}

void BBS::ShowUsers()
{
	cout << "当前用户已有用户如下：" << endl << endl;
//	for (auto u : users)
//		cout << u->GetUserName() << endl;
}

void BBS::InitBBS(){
   /*论坛板块数不少于 2 个； 管理员数不少于 2 个； 普通用户数不
   *少于 3 个； 每个板块帖子数不少于 2 个，且至少一个帖子的评论数不少于 2 个*/
    MyTime time = GetTime();
   //创建版块
    Board* b1 = new Board("BOARD_ONE");
    Board* b2 = new Board("BOARD_TWO");
    Board* b3 = new Board("BOARD_THREE");
    boards.push_back(b1);boards.push_back(b2);boards.push_back(b3);
    //创建管理员
    User* ad1 = new Administator; ad1->SignUp("AD1","AD1",this);
    User* ad2 = new Administator; ad2->SignUp("AD2","AD2",this);
    //创建普通用户
    User* or1 = new OrdinaryUser; or1->SignUp("OR1","OR1",this);
    User* or2 = new OrdinaryUser; or2->SignUp("OR2","OR2",this);
    User* or3 = new OrdinaryUser; or3->SignUp("OR3","OR3",this);
    //创建版块下的帖子
    Post* p11 = or2->CreatePost("POST1","POST1 CONTENT",b1); Post* p12 = or1->CreatePost("POST2","POST2 CONTENT",b1);p11->SetTime(time); p12->SetTime(time);
    Post* p21 = or1->CreatePost("POST1","POST1 CONTENT",b2); Post* p22 = or1->CreatePost("POST2","POST2 CONTENT",b2);p21->SetTime(time); p22->SetTime(time);
    Post* p31 = or3->CreatePost("POST1","POST1 CONTENT",b3); Post* p32 = or1->CreatePost("POST2","POST2 CONTENT",b3);p31->SetTime(time); p32->SetTime(time);
    //创建帖子下的评论
    or1->CreateComment("Ugly GUI",p11); or2->CreateComment("23333333333333",p11);or1->CreateComment("6666666666",p12);or2->CreateComment("balabala~",p12);
    or2->CreateComment("GUI is so difficult!!!!",p21); or1->CreateComment("23333333333333",p21);or1->CreateComment("6666666666",p22);or2->CreateComment("balabala~",p22);
    or3->CreateComment("hhhhhhhhhhh",p31); or2->CreateComment("23333333333333",p31);or1->CreateComment("6666666666",p32);or2->CreateComment("balabala~",p32);

}
