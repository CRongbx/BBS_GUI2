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
    QString BBSTitle = "C++_BBS";		//��̳��
	vector<User*> users;			//��ǰBBS��ע����û�
    vector<Board*> boards;			//��̳ӵ�еİ��
public:
    BBS();
	~BBS();
    QString GetBBSTitle(){return BBSTitle;}
    void SetBBSTitle(QString s){BBSTitle = s;}
    vector<QString> ShowBoards();													//չʾ��̳���а��
    vector<Board*> GetBoardsVector(){return boards;}
    void InitBBS();													//��ʼ��BBS�����ð�顢�û�����Ա
	//��������
	User* GetUser(int id);
    User* GetUser(const QString &name);
    Board* GetBoard(QString name);
	int GetUsersSize() { return users.size(); }							//��õ�ǰ��̳ע���û���Ŀ
	int GetBoardSize() { return boards.size(); }						//��õ�ǰ��̳�����Ŀ
	bool AddUser(User* const u);										//����û�
	bool DeleteUser(User* const u);										//ɾ���û�
	bool AddBoard(Board* b);											//��Ӱ��
	bool DeleteBoard(Board* b);											//ɾ�����	
    int GetOrdinaryUserNum (void);  //�����ͨ�û�����
    int GetAdministatorNum (void);  //��ù���Ա����
    int GetModeratorNum(void);      //��ð�������
    /* ��������� */
    friend ofstream& operator <<(ofstream& fout, BBS &bbs);
    friend ifstream& operator >>(ifstream& fin, BBS& bbs);
};

#endif // !BBS_H
