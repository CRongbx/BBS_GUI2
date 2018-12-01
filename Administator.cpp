#include "Administator.h"
#include "Moderator.h"
#include "OrdinaryUser.h"
#include <iostream>

Administator::Administator()
{
}


Administator::~Administator()
{
}


User* Administator::SetModerator(User* o)
{
	//����OrdinaryUserת��Ϊ������Moderator
	User* temp = o;
	o = new Moderator;
	//����������Կ�������������
	o->SetId(temp->GetId());
	o->SetOnline(temp->GetOnline());
	o->SetPassword(temp->GetPassword());
	o->SetPassword(temp->GetUserName());

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

