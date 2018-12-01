#ifndef USER
#define USER
#include <string>
#include <QString>
#include <vector>
#include <iostream>
using namespace std;

//ǰ������
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
    QString password;									//�û�����
    QString userName;									//�û���
	bool online = false;								//��ǰ���û��Ƿ�����
public:
	User();
	//��ʼ���б�
    User(QString name, QString password) :userName(name), password(password) {};
	//������������User��Ϊ����Ӧ�ö���һ����������������̬����̳���ϵ�еĶ���
	virtual ~User();
	int GetId() { return id; }
	void SetId(const int id) { this->id = id; }
    QString GetPassword() { return password; }
    void SetPassword(const QString pw) { password = pw; }
    QString GetUserName() { return userName; }
    void SetUserName(const QString un) { userName = un; }
	bool GetOnline() { return online; }
	void SetOnline(const bool online) { this->online = online; }
	//�û���¼�������Ƿ��¼�ɹ�  /*���볣������Ҫ�õ���������*/
    bool SignIn(QString name, QString pw);
    //�û��˳�
    void SignOut();
	//�û�ע��
    bool SignUp(QString name, QString pw, BBS * bbs);
	//�û�ע��
    bool Logout(QString name, QString pw, BBS * bbs);
	//�鿴�û���Ϣ
	void Show();
	/* �麯�� */
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
