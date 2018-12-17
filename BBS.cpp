#include "BBS.h"
#include "Administator.h"
#include "OrdinaryUser.h"
#include "Moderator.h"
#include "MyTime.h"
#include "Post.h"
#include <iostream>
#include <QString>
#include <typeinfo>
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

int BBS::GetOrdinaryUserNum(void){
    int count = 0;
    for(auto u : users){
        if(typeid(OrdinaryUser) == typeid(*u))
            count++;
    }
    return count;
}

int BBS::GetAdministatorNum(void){
    int count = 0;
    for(auto u : users)
        if(typeid(Administator) == typeid(*u))
            count++;
    return count;
}

int BBS::GetModeratorNum(void){
    int count = 0;
    for(auto u : users)
        if(typeid(Moderator) == typeid(*u))
            count++;
    return count;
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
    cout << "board添加成功！" <<endl;
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

ofstream& operator <<(ofstream& fout, BBS &bbs){
    fout << "BBS:" << endl;
    fout << "TITLE:"<<bbs.BBSTitle.toStdString();
    fout << "USERSIZE:"<<bbs.users.size();
    fout << "AdministatorNum:"<<bbs.GetAdministatorNum();
    fout << "OrdinaryUserNum:"<<bbs.GetOrdinaryUserNum();
    fout << "ModeratorNum:"<<bbs.GetModeratorNum();
    fout << "BOARDSIZE:"<<bbs.boards.size()<<endl;
    for(auto u : bbs.users)
        fout << *u<<endl;
    for(auto b : bbs.boards)
        fout << *b<<endl;
    return fout;
}

ifstream& operator >> (ifstream& fin, BBS& bbs){
    try{
        string s;
        fin >> s;
        while(s != "BBS:"){
            s.clear();
            fin >> s;
        }
        s.clear();
        fin >> s;

        size_t loc_title = s.find("TITLE:",0);
        size_t loc_us = s.find("USERSIZE:", loc_title);
        size_t loc_an = s.find("AdministatorNum:", loc_us);    //16
        size_t loc_on = s.find("OrdinaryUserNum:",loc_an);
        size_t loc_mn = s.find("ModeratorNum:", loc_on);    //13
        size_t loc_bs = s.find("BOARDSIZE:",loc_mn);

        //检查是否找到这些关键字
        if (loc_title > s.length()) throw "ERROR: Can't find 'title'! ";
        if (loc_us > s.length()) throw "ERROR: Can't find 'USERSIZE'! ";
        if (loc_an > s.length()) throw "ERROR: Can't find 'AdministatorNum'! ";
        if (loc_on > s.length()) throw "ERROR: Can't find 'OrdinaryUserNum'! ";
        if (loc_mn > s.length()) throw "ERROR: Can't find 'ModeratorNum'! ";
        if (loc_bs > s.length()) throw "ERROR: Can't find 'BOARDSIZE'! ";


        string title;
        for(size_t i = loc_title+6; i < loc_us; i++)
            title += s.at(i);
        bbs.BBSTitle = QString::fromStdString(title);

        int usersize = 0;
        for(size_t i = loc_us + 9; i < loc_an; i++)
            usersize = usersize*10 + s.at(i) - '0';
        int AdministatorNum = 0;
        for(size_t i = loc_an+16; i < loc_on; i++)
            AdministatorNum = AdministatorNum*10 + s.at(i) - '0';
        int OrdinaryUserNum = 0;
        for(size_t i = loc_on+16; i < loc_mn; i++)
            OrdinaryUserNum = OrdinaryUserNum*10 + s.at(i) - '0';
        int ModeratorNum = 0;
        for(size_t i = loc_mn+13; i < loc_bs; i++)
            ModeratorNum = ModeratorNum*10 + s.at(i) - '0';
        int boardsize = 0;
        for(size_t i = loc_bs + 10; i < s.length(); i++)
            boardsize = boardsize*10 + s.at(i) - '0';

        for(int i = 0; i < AdministatorNum; i++){
            User* user = new Administator;
            fin >> *user;
            bbs.users.push_back(user);
        }
        for(int i = 0; i < OrdinaryUserNum; i++){
            User* user = new OrdinaryUser;
            fin >> *user;
            bbs.users.push_back(user);
        }
        for(int i = 0; i < ModeratorNum; i++){
            User* user =  new Moderator;
            fin >> *user;
            bbs.users.push_back(user);
        }

        for(int i = 0; i < boardsize; i++){
            Board* board = new Board;
            fin >> *board;
            bbs.boards.push_back(board);
            for(auto mo : bbs.users)
                for(auto bm : board->GetModerators())
                    if(bm == mo->GetUserName())
                        if(typeid(*mo) == typeid(Moderator)){
                            mo ->SetBoard(board);
                            break;
                        }
                        else
                            throw  "ERROR: Wrong Moderator!";
        }
        return fin;
    }
    catch (char const* msg){
        cerr << msg << endl;
    }
}
