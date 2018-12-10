#ifndef BOARD_H
#define BOARD_H
//论坛版块
#include <QString>
#include <vector>
using namespace std;

class Post;
class User;

class Board
{
private:
    QString name;		//版块名
	int id;				//版块id
	vector<Post*> posts;//版块下的帖子
    vector<User*> moderators;   //本版块的管理员（允许多个管理员）
public:
	Board();
    Board(QString name) : name(name) {};
	~Board();
    void SetModerator(User* const m){moderators.push_back(m);}
    void DeleteModertor(User* const m);
    void SetName(const QString name) { this->name = name; }
    QString GetName() { return name; }
    vector<Post*> GetPostsVector(){return posts;}
	void SetId(const int id) { this->id = id; }
	int GetId() { return id; }
    Post* GetPost(QString name);
	bool AddPost(Post *p);				//向该板块添加帖子
	bool DeletePost(Post *p);			//删除该版块的帖子
	bool IsPostExist(Post* const p);	//该板块下是否存在该帖子
	int GetPostsSize() { return posts.size(); }  //获取当前板块下帖子数目
    QString ShowBoardInfo();            //显示版面的基本信息
    vector<QString> ShowBoardPosts();   //显示版面的帖子
    friend ofstream& operator <<(ofstream& fout, const Board &board);
};

#endif // !BOARD_H

