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
    //����OrdinaryUserת��Ϊ������Moderator
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
    //����������Կ�������������
    return o;
}

OrdinaryUser* Administator::RepealModerator(User * m,BBS* bbs)
{
    //������Moderator��ɻ���OrdinaryUser
    /*����ʱ����ʶ��dynamic_cast����������ʱת������
    *�����ڻ���ָ��ָ��������ʱ��dynamic_case���ܷ���ɹ���*/
//    if (OrdinaryUser* o = dynamic_cast<OrdinaryUser*>(m)) {
////        m = o;
//        cout << "������Moderator��ɻ���OrdinaryUser:SUCCESS!" << endl;
//        return o;
//    }
//    else {
//        cout << "������Moderator��ɻ���OrdinaryUser:FAIL!" << endl;
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

