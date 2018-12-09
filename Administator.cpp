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

bool Administator::RepealModerator(User * m)
{
    //������Moderator��ɻ���OrdinaryUser
    /*����ʱ����ʶ��dynamic_cast����������ʱת������
    *�����ڻ���ָ��ָ��������ʱ��dynamic_case���ܷ���ɹ���*/
    if (OrdinaryUser* o = dynamic_cast<OrdinaryUser*>(m)) {
        m = o;
        cout << "������Moderator��ɻ���OrdinaryUser:SUCCESS!" << endl;
        return true;
    }
    else {
        cout << "������Moderator��ɻ���OrdinaryUser:FAIL!" << endl;
        return false;
    }
}

