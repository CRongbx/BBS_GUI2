#ifndef ADMINISTATOR_H
#define ADMINISTATOR_H
#include "User.h"

class OrdinaryUser;
class Moderator;

class Administator :
	public User
{
private:

public:
	Administator();
	~Administator();
	virtual User* SetModerator(User* o)override final;	//����ͨ�û�����Ϊ����
	virtual bool RepealModerator(User* o)override final;		//����������Ϊ����Ա
};

#endif // !ADMINISTATOR_H
/*���м̳У������������Է��ʻ���Ĺ��г�Ա��������Ա
*˽�м̳У���������󲻿��Է��ʻ�����κγ�Ա
*���ּ̳У�������ĳ�Ա�����������Է��ʻ���Ĺ��г�Ա�ͱ�����Ա*/