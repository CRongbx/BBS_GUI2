#include "User.h"
#include "BBS.h"
#include <iostream>
#include <typeinfo>
#include <string>

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

ofstream& operator << (ofstream& fout,const User &user){
    /*��������<<������Ӧ�����ڲ�������������ʽ�Ĵ����ʾ�����Ҫ��endl*/
    fout << "USER:"<<endl;
    fout << "ID:"<<user.id;
    fout << "USERNAME:"<<user.userName.toStdString();
    fout << "PASSWORD:"<<user.password.toStdString();
    return fout;
}

ifstream& operator >> (ifstream& fin, User &user){
    try{
        string s;
        fin >> s;
        while(s != "USER:"){
            s.clear();
            fin >> s;
        }
        s.clear();
        fin >> s;

        size_t loc_id = s.find("ID:",0);
        size_t loc_username = s.find("USERNAME:",loc_id);
        size_t loc_password = s.find("PASSWORD:",loc_username);

        if (loc_id > s.length()) throw "ERROR: Can't find 'ID'! ";
        if (loc_username > s.length()) throw "ERROR: Can't find 'USERNAME'! ";
        if (loc_password > s.length()) throw "ERROR: Can't find 'PASSWORD'! ";

        int id = 0;
        for(size_t i = loc_id+3; i < loc_username; i++)
            id = id*10 + s.at(i) - '0';
        user.id = id;

        string username = "";
        for(size_t i = loc_username+9; i < loc_password ; i++)
            username += s.at(i);
        user.userName = QString::fromStdString(username);

        string password = "";
        for(size_t i = loc_password+9; i < s.length(); i++)
            password += s.at(i);
        user.password = QString::fromStdString(password);

        return fin;
    }
    catch (char const* msg){
        cerr << msg << endl;
    }
}
