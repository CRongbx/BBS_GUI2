#ifndef BBS_H
#define BBS_H
#include <vector>
#include "User.h"
#include "Board.h"
#include <QString>

class BBS
{
private:
    QString BBSTitle = "MY BBS";		//论坛名
	vector<User*> users;			//当前BBS下注册的用户
	vector<Board*> boards;			//论坛拥有的版块
public:
    BBS();
	~BBS();
    QString GetBBSTitle(){return BBSTitle;}
    void SetBBSTitle(QString s){BBSTitle = s;}
    void ShowBoards();													//展示论坛已有版块
    void ShowUsers();													//展示论坛已有用户信息
    //void InitBBS();													//初始化BBS，设置版块、用户管理员
	//函数重载
	User* GetUser(int id);
    User* GetUser(const QString &name);
	int GetUsersSize() { return users.size(); }							//获得当前论坛注册用户数目
	int GetBoardSize() { return boards.size(); }						//获得当前论坛版块数目
	bool AddUser(User* const u);										//添加用户
	bool DeleteUser(User* const u);										//删除用户
	bool AddBoard(Board* b);											//添加版块
	bool DeleteBoard(Board* b);											//删除版块	
};

#endif // !BBS_H
