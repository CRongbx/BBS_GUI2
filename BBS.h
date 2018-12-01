#ifndef BBS_H
#define BBS_H
#include <vector>
#include "User.h"
#include "Board.h"
#include <QString>

class BBS
{
private:
    QString BBSTitle = "MY BBS";		//��̳��
	vector<User*> users;			//��ǰBBS��ע����û�
	vector<Board*> boards;			//��̳ӵ�еİ��
public:
    BBS();
	~BBS();
    QString GetBBSTitle(){return BBSTitle;}
    void SetBBSTitle(QString s){BBSTitle = s;}
    void ShowBoards();													//չʾ��̳���а��
    void ShowUsers();													//չʾ��̳�����û���Ϣ
    //void InitBBS();													//��ʼ��BBS�����ð�顢�û�����Ա
	//��������
	User* GetUser(int id);
    User* GetUser(const QString &name);
	int GetUsersSize() { return users.size(); }							//��õ�ǰ��̳ע���û���Ŀ
	int GetBoardSize() { return boards.size(); }						//��õ�ǰ��̳�����Ŀ
	bool AddUser(User* const u);										//����û�
	bool DeleteUser(User* const u);										//ɾ���û�
	bool AddBoard(Board* b);											//��Ӱ��
	bool DeleteBoard(Board* b);											//ɾ�����	
};

#endif // !BBS_H
