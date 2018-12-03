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
		//�û�������
//		cout << "�û����������" << endl;
		return false;
	}
	else {
        if (pw != this->password) {
			//��������û�����ȷ��
//			cout << "�������" << endl;
			return false;
		}
		else {
			//������û���������ȷ
//			cout << "��¼�ɹ���" << endl;
			this->online = true;		//��¼�ɹ����û�����
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
		//BBS�����ظ��û������û�������ע��
        this->SetId(bbs->GetUsersSize());	//�����û�����̳ע��������Ϊ�û���Id		
		return true;
	}
	//delete user;
//	cout << "�û����Ѵ��ڡ�ע��ʧ�ܣ�" << endl;
	return false;
}

bool User::Logout(QString name, QString pw, BBS * bbs)
{
	if (this->userName == name && this->password == pw) {
		//�û�����������ȷ
        if (bbs->DeleteUser(this)) {
			//���ڸ��û�������ɾ��
			//if (this)
				//delete this;
			cout << "�û�ע���ɹ���" << endl;
			return true;
		}
		else {
			cout << "���û������ڣ��û�ע��ʧ�ܣ�" << endl;
			return false;
		}
	}
	else {
		cout << "��������û�ע��ʧ��!" << endl;
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


