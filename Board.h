#ifndef BOARD_H
#define BOARD_H
//��̳���
#include <string>
#include <vector>
using namespace std;

class Post;

class Board
{
private:
	string name;		//�����
	int id;				//���id
	vector<Post*> posts;//����µ�����
public:
	Board();
	Board(string name) : name(name) {};
	~Board();
	void SetName(const string name) { this->name = name; }
	string GetName() { return name; }
	void SetId(const int id) { this->id = id; }
	int GetId() { return id; }
	bool AddPost(Post *p);				//��ð���������
	bool DeletePost(Post *p);			//ɾ���ð�������
	bool IsPostExist(Post* const p);	//�ð�����Ƿ���ڸ�����
	int GetPostsSize() { return posts.size(); }  //��ȡ��ǰ�����������Ŀ
	void Show();
};

#endif // !BOARD_H

