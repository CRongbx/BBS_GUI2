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
	virtual bool DeletePost(Post * post, Board* const board);		//��ͨ�û���ɾ�����ܣ�ɾ���Լ������Ļ�û���۵����ӣ�
	virtual Post* CreatePost(string title, string content, Board* const board) override final;	  //����һ������
	virtual Comment* CreateComment(string content, Post* const post)override final;	//����
	void LookBBS(BBS* const bbs) override final;								//�鿴��̳���а��
	void LookBoard(Board* const board) override final;							//�鿴��ǰ��鼰����µ�����
	void LookPost(Post* const post)override final;							//�鿴��ǰ���Ӽ�������
};

#endif // ! ORDINARYUSER_H