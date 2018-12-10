#include "Board.h"
#include "Post.h"
#include "Moderator.h"
#include <iostream>
using namespace std;

Board::Board()
{
}


Board::~Board()
{
}

void Board::DeleteModertor(User* const m){
    for(vector<User*>::iterator it = moderators.begin(); it != moderators.end(); it++)
        if((*it)->GetUserName() == m->GetUserName()){
            moderators.erase(it);
        }
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
	cout << "本版块下不存在该帖子！" << endl;
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

 ofstream& operator <<(ofstream& fout, const Board &board){
     fout << board.name.toStdString()<<"$";
     fout << board.id<<"$";
     for (auto p : board.posts){
         fout << p << endl;
     }
     for (auto m : board.moderators)
         fout << m->GetUserName().toStdString()<<"$";
     return fout;
 }
