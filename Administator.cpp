#include "Administator.h"
#include "Moderator.h"
#include "OrdinaryUser.h"
#include "Board.h"
#include "BBS.h"
#include <iostream>
#include <typeinfo>

Administator::Administator()
{
}


Administator::~Administator()
{
}


User* Administator::SetModerator(User* o,Board* const b,BBS* bbs)
{
    //基类OrdinaryUser转化为派生类Moderator
    User* temp = o;
    bbs->DeleteUser(o);
    o = new Moderator(b);
    b->SetModerator(temp->GetUserName());
    o->SetId(temp->GetId());
    o->SetOnline(temp->GetOnline());
    o->SetPassword(temp->GetPassword());
    o->SetUserName(temp->GetUserName());
//    cout << typeid(*o).name()<<endl;
//    cout << QString::toStdString(o->GetUserName())<<endl;
    bbs->AddUser(o);
    //将基类的属性拷贝到派生类中
    return o;
}

OrdinaryUser* Administator::RepealModerator(User * m,BBS* bbs)
{
    OrdinaryUser* o = new OrdinaryUser;
    User *tmp = m;
    Board* board = m->GetBoard();
    bbs->DeleteUser(m);
    if(board)
        board->DeleteModertor(tmp);
    o->SetId(tmp->GetId());
    o->SetOnline(tmp->GetOnline());
    o->SetPassword(tmp->GetPassword());
    o->SetUserName(tmp->GetUserName());
    bbs->AddUser(o);
    return o;
}

