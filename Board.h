#ifndef BOARD_H
#define BOARD_H
//��̳���
#include <QString>
#include <vector>
#include "User.h"
using namespace std;

class Post;
class User;

class Board
{
private:
    QString name;		//�����
	int id;				//���id
	vector<Post*> posts;//����µ�����
    vector<QString> moderators;   //�����Ĺ���Ա������������Ա��
public:
	Board();
    Board(QString name) : name(name) {};
	~Board();
    void SetModerator(QString name){this->moderators.push_back(name);}
    void DeleteModertor(User* const m);
    void SetName(const QString name) { this->name = name; }
    QString GetName() { return name; }
    vector<Post*> GetPostsVector(){return posts;}
    vector<QString> GetModerators(){return moderators;}
	void SetId(const int id) { this->id = id; }
	int GetId() { return id; }
    Post* GetPost(QString name);
	bool AddPost(Post *p);				//��ð���������
	bool DeletePost(Post *p);			//ɾ���ð�������
	bool IsPostExist(Post* const p);	//�ð�����Ƿ���ڸ�����
	int GetPostsSize() { return posts.size(); }  //��ȡ��ǰ�����������Ŀ
    QString ShowBoardInfo();            //��ʾ����Ļ�����Ϣ
    vector<QString> ShowBoardPosts();   //��ʾ���������
    friend ofstream& operator << (ofstream& fout, const Board &board);
    friend ifstream& operator >> (ifstream& fin, Board& board);
};

#endif // !BOARD_H

