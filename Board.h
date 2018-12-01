#ifndef BOARD_H
#define BOARD_H
//论坛版块
#include <string>
#include <vector>
using namespace std;

class Post;

class Board
{
private:
	string name;		//版块名
	int id;				//版块id
	vector<Post*> posts;//版块下的帖子
public:
	Board();
	Board(string name) : name(name) {};
	~Board();
	void SetName(const string name) { this->name = name; }
	string GetName() { return name; }
	void SetId(const int id) { this->id = id; }
	int GetId() { return id; }
	bool AddPost(Post *p);				//向该板块添加帖子
	bool DeletePost(Post *p);			//删除该版块的帖子
	bool IsPostExist(Post* const p);	//该板块下是否存在该帖子
	int GetPostsSize() { return posts.size(); }  //获取当前板块下帖子数目
	void Show();
};

#endif // !BOARD_H

