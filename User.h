#ifndef USER
#define USER
#include <string>
#include <QString>
#include <vector>
#include <iostream>
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
	void Show();
	/* 虚函数 */
	virtual bool DeletePost(Post * post, Board* const board) { return false; }
	virtual Post* CreatePost(string title, string content, Board* const board) { return nullptr; }
	virtual Comment* CreateComment(string content, Post* const post) { return nullptr; }
	virtual void LookBBS(BBS* const bbs) {}
	virtual void LookBoard(Board* const board) {}							
	virtual void LookPost(Post* const post) {}
	virtual User* SetModerator(User* o) {	return nullptr;}
	virtual bool RepealModerator(User* o) { return false; }
};

#endif
