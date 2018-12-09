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
    virtual User* SetModerator(User* o,Board* const b,BBS* bbs)override final;	//将普通用户设置为版主
    virtual OrdinaryUser* RepealModerator(User* o,BBS* bbs)override final;		//将版主撤销为管理员
};

#endif // !ADMINISTATOR_H
/*公有继承，派生类对象可以访问基类的公有成员及保护成员
*私有继承，派生类对象不可以访问基类的任何成员
*两种继承，派生类的成员函数，都可以访问基类的公有成员和保护成员*/
