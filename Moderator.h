#ifndef  MODERATOR
#define MODERATOR

#include "OrdinaryUser.h"

class Moderator :
	public OrdinaryUser
{
private:
	Board* board;		//����İ��
public:
	Moderator();
    Moderator(Board *const b):board(b){}
	~Moderator();
//	void SetBoard(Board* const b) { board = b; }
//	Board* GetBoard() { return board; }
	virtual bool DeletePost(Post * post, Board* const board) override final;		//��д�����һ����дɾ������
};

#endif // ! MODERATOR
