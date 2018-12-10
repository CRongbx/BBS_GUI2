#ifndef USER
#define USER
#include <string>
#include <QString>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

//前置声明
class BBS;
class Comment;
class Post;
class Board;
class Moderator;
class OrdinaryUser;

class User
{
private:
	int id;
    QString password;									//用户密码
    QString userName;									//用户名
	bool online = false;								//当前该用户是否在线
//    ofstream fuser_out("user_out.txt",ios::trunc);       //输出用户信息
public:
	User();
	//初始化列表
    User(QString name, QString password) :userName(name), password(password) {};
	//虚析构函数，User作为基类应该定义一个虚析构函数来动态分配继承体系中的对象
	virtual ~User();
	int GetId() { return id; }
	void SetId(const int id) { this->id = id; }
    QString GetPassword() { return password; }
    void SetPassword(const QString pw) { password = pw; }
    QString GetUserName() { return userName; }
    void SetUserName(const QString un) { userName = un; }
	bool GetOnline() { return online; }
	void SetOnline(const bool online) { this->online = online; }
	//用户登录，返回是否登录成功  /*传入常量，需要用到常量引用*/
    bool SignIn(QString name, QString pw);
    //用户退出
    void SignOut();
	//用户注册
    bool SignUp(QString name, QString pw, BBS * bbs);
	//用户注销
    bool Logout(QString name, QString pw, BBS * bbs);
	//查看用户信息
    QString Show();
	/* 虚函数 */
	virtual bool DeletePost(Post * post, Board* const board) { return false; }
    virtual Post* CreatePost(QString title, QString content, Board* const board) { return nullptr; }
    virtual Comment* CreateComment(QString content, Post* const post) { return nullptr; }
    virtual User* SetModerator(User* o,Board* const b,BBS* bbs) {	return nullptr;}
    virtual OrdinaryUser* RepealModerator(User* o,BBS* bbs) { return false; }
    /*运算符重载*/
    friend ostream& operator << (ostream & output, const User &user);
    //设置为友元函数，可以访问类的私有数据;可以使用标准库fstream中的成员
    friend ofstream& operator << (ofstream& fout,const User &user);         //常量引用，保证可以传入User类型的常量
};

#endif
