#ifndef BBS_H
#define BBS_H
#include <vector>
#include "User.h"
#include "Board.h"
#include <QString>
#include <fstream>
using namespace std;

class BBS
{
private:
    QString BBSTitle = "C++_BBS";		//论坛名
	vector<User*> users;			//当前BBS下注册的用户
    vector<Board*> boards;			//论坛拥有的版块
public:
    BBS();
	~BBS();
    QString GetBBSTitle(){return BBSTitle;}
    void SetBBSTitle(QString s){BBSTitle = s;}
    vector<QString> ShowBoards();													//展示论坛已有版块
    vector<Board*> GetBoardsVector(){return boards;}
    void InitBBS();													//初始化BBS，设置版块、用户管理员
	//函数重载
	User* GetUser(int id);
    User* GetUser(const QString &name);
    Board* GetBoard(QString name);
	int GetUsersSize() { return users.size(); }							//获得当前论坛注册用户数目
	int GetBoardSize() { return boards.size(); }						//获得当前论坛版块数目
	bool AddUser(User* const u);										//添加用户
	bool DeleteUser(User* const u);										//删除用户
	bool AddBoard(Board* b);											//添加版块
	bool DeleteBoard(Board* b);											//删除版块	
    int GetOrdinaryUserNum (void);  //获得普通用户人数
    int GetAdministatorNum (void);  //获得管理员人数
    int GetModeratorNum(void);      //获得版主人数
    /* 运算符重载 */
    friend ofstream& operator <<(ofstream& fout, BBS &bbs);
    friend ifstream& operator >>(ifstream& fin, BBS& bbs);
};

#endif // !BBS_H
