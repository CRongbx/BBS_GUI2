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
    o->SetId(temp->GetId());
    o->SetOnline(temp->GetOnline());
    o->SetPassword(temp->GetPassword());
    o->SetUserName(temp->GetUserName());
    cout << typeid(*o).name()<<endl;
//    cout << QString::toStdString(o->GetUserName())<<endl;
    bbs->AddUser(o);
    //将基类的属性拷贝到派生类中
    return o;
}

OrdinaryUser* Administator::RepealModerator(User * m,BBS* bbs)
{
    //派生类Moderator变成基类OrdinaryUser
    /*运行时类型识别，dynamic_cast用来在运行时转换类型
    *必须在基类指针指向派生类时，dynamic_case才能分配成功；*/
//    if (OrdinaryUser* o = dynamic_cast<OrdinaryUser*>(m)) {
////        m = o;
//        cout << "派生类Moderator变成基类OrdinaryUser:SUCCESS!" << endl;
//        return o;
//    }
//    else {
//        cout << "派生类Moderator变成基类OrdinaryUser:FAIL!" << endl;
//        return nullptr;
//    }
    OrdinaryUser* o = new OrdinaryUser;
    User *tmp = m;
    bbs->DeleteUser(m);
    o->SetId(tmp->GetId());
    o->SetOnline(tmp->GetOnline());
    o->SetPassword(tmp->GetPassword());
    o->SetUserName(tmp->GetUserName());
    bbs->AddUser(o);
    return o;
}

