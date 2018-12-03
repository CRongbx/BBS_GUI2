#include "User.h"
#include "BBS.h"
#include <iostream>
#include <typeinfo>

User::User()
{
}


User::~User()
{
}

bool User::SignIn(QString name, QString pw)
{
    if (name != userName) {
		//用户名错误
//		cout << "用户名输入错误！" << endl;
		return false;
	}
	else {
        if (pw != this->password) {
			//密码错误（用户名正确）
//			cout << "密码错误！" << endl;
			return false;
		}
		else {
			//密码和用户名输入正确
//			cout << "登录成功！" << endl;
			this->online = true;		//登录成功，用户在线
			return true;
		}
	}

}

void User::SignOut()
{
		this->online = false;
}

bool User::SignUp(QString name, QString pw, BBS * bbs)
{
	//User *user = new User(name, pw);
	userName = name;
	password = pw;
    if (bbs->AddUser(this)) {
		//BBS中无重复用户名的用户，可以注册
        this->SetId(bbs->GetUsersSize());	//将该用户在论坛注册的序号作为用户的Id		
		return true;
	}
	//delete user;
//	cout << "用户名已存在。注册失败！" << endl;
	return false;
}

bool User::Logout(QString name, QString pw, BBS * bbs)
{
	if (this->userName == name && this->password == pw) {
		//用户名、密码正确
        if (bbs->DeleteUser(this)) {
			//存在该用户，可以删除
			//if (this)
				//delete this;
			cout << "用户注销成功！" << endl;
			return true;
		}
		else {
			cout << "该用户不存在，用户注销失败！" << endl;
			return false;
		}
	}
	else {
		cout << "密码错误，用户注销失败!" << endl;
		return false;
	}
}

QString User::Show()
{
    QString s = "User Name: "+userName+"\n";
    s = s + "ID: "+QString::number(id)+"\n";
    s += "Class: "+QString::fromStdString(typeid(*this).name())+"\n";

    return s;
}


