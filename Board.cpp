#include "Board.h"
#include "Post.h"
#include <iostream>
using namespace std;

Board::Board()
{
}


Board::~Board()
{
}

Post* Board::GetPost(QString name){
    for (auto p : posts){
        if (name == p->GetTitle())
            return p;
    }
    return nullptr;
}

bool Board::AddPost(Post * p)
{
	posts.push_back(p);
    p->SetBoard(this);
	return true;
}

bool Board::DeletePost(Post * p)
{
	for (vector<Post*>::iterator it = posts.begin();it != posts.end();++it) {
		if ((*it) == p) {
			posts.erase(it);
			return true;
		}
	}
	cout << "������²����ڸ����ӣ�" << endl;
	return false;
}

bool Board::IsPostExist(Post * const p)
{
	for (auto post : posts) {
		if (p == post)
			return true;
	}
	return false;
}

QString Board::ShowBoardInfo()
{
//    QString s = "id: "+QString::number(id)+" ";
    QString s = name+" ";
    s += "Num of Post: "+ QString::number(posts.size());
    return s;
}

 vector<QString> Board::ShowBoardPosts(){
     vector<QString> postinfo;
     for(auto p : posts){
        postinfo.push_back(p->Show());
     }
     return postinfo;
 }
