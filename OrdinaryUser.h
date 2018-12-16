#ifndef  ORDINARYUSER_H
#define ORDINARYUSER_H
#include "User.h"
#include <iostream>
#include <QString>
using namespace std;
class Post;
class Board;
class Comment;
class BBS;

class OrdinaryUser :
	public User
{
public:
	OrdinaryUser();
	virtual ~OrdinaryUser();

    virtual Board* GetBoard() override {return nullptr;}
    virtual bool DeletePost(Post * post, Board* const board) override;		//��ͨ�û���ɾ�����ܣ�ɾ���Լ������Ļ�û���۵����ӣ�
    virtual Post* CreatePost(QString title, QString content, Board* const board) override final;	  //����һ������
    virtual Comment* CreateComment(QString content, Post* const post)override final;	//����
    virtual QString Show() override;
};

#endif // ! ORDINARYUSER_H
