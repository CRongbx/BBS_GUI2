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
	//基类OrdinaryUser转化为派生类Moderator
	User* temp = o;
	o = new Moderator;
	//将基类的属性拷贝到派生类中
	o->SetId(temp->GetId());
	o->SetOnline(temp->GetOnline());
	o->SetPassword(temp->GetPassword());
	o->SetPassword(temp->GetUserName());

	return o;
}


bool Administator::RepealModerator(User * m)
{
	//派生类Moderator变成基类OrdinaryUser
	/*运行时类型识别，dynamic_cast用来在运行时转换类型
	*必须在基类指针指向派生类时，dynamic_case才能分配成功；*/
	if (OrdinaryUser* o = dynamic_cast<OrdinaryUser*>(m)) {
		m = o;
		cout << "派生类Moderator变成基类OrdinaryUser:SUCCESS!" << endl;
		return true;
	}
	else {
		cout << "派生类Moderator变成基类OrdinaryUser:FAIL!" << endl;
		return false;
	}
	
}

