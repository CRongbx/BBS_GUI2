#ifndef ADMINISTATOR_H
#define ADMINISTATOR_H
#include "User.h"

class Moderator;
class Board;

class Administator :
	public User
{
private:

public:
	Administator();
	~Administator();
    virtual User* SetModerator(User* o,Board* const b,BBS* bbs)override final;	//����ͨ�û�����Ϊ����
    virtual OrdinaryUser* RepealModerator(User* o,BBS* bbs)override final;		//����������Ϊ����Ա
};

#endif // !ADMINISTATOR_H
/*���м̳У������������Է��ʻ���Ĺ��г�Ա��������Ա
*˽�м̳У���������󲻿��Է��ʻ�����κγ�Ա
*���ּ̳У�������ĳ�Ա�����������Է��ʻ���Ĺ��г�Ա�ͱ�����Ա*/
