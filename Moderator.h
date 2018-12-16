#ifndef  MODERATOR
#define MODERATOR

#include "OrdinaryUser.h"

class Moderator :
	public OrdinaryUser
{
private:
	Board* board;		//管理的版块
public:
	Moderator();
    Moderator(Board *const b):board(b){}
	~Moderator();
    virtual Board* GetBoard() override final { return board; }
	virtual bool DeletePost(Post * post, Board* const board) override final;		//重写且最后一次重写删帖函数
    virtual QString Show() override final;
    virtual void SetBoard(Board* const board) override final { this->board = board; }
};

#endif // ! MODERATOR
