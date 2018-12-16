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
    virtual bool DeletePost(Post * post, Board* const board) override;		//普通用户的删帖功能（删除自己发布的还没评论的帖子）
    virtual Post* CreatePost(QString title, QString content, Board* const board) override final;	  //创建一个帖子
    virtual Comment* CreateComment(QString content, Post* const post)override final;	//评论
    virtual QString Show() override;
};

#endif // ! ORDINARYUSER_H
