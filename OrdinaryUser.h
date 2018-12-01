#ifndef  ORDINARYUSER_H
#define ORDINARYUSER_H
#include "User.h"
#include <iostream>
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

	virtual void Show() { cout << "Ordinary user!" << endl; }
	virtual bool DeletePost(Post * post, Board* const board);		//普通用户的删帖功能（删除自己发布的还没评论的帖子）
	virtual Post* CreatePost(string title, string content, Board* const board) override final;	  //创建一个帖子
	virtual Comment* CreateComment(string content, Post* const post)override final;	//评论
	void LookBBS(BBS* const bbs) override final;								//查看论坛已有版块
	void LookBoard(Board* const board) override final;							//查看当前版块及版块下的帖子
	void LookPost(Post* const post)override final;							//查看当前帖子及其评论
};

#endif // ! ORDINARYUSER_H