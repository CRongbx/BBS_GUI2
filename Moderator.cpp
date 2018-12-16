#include "Moderator.h"
#include "Board.h"
#include "Post.h"
#include <iostream>
#include <typeinfo>
using namespace std;

Moderator::Moderator()
{
}


Moderator::~Moderator()
{
}

QString Moderator::Show(){
    QString s = "User Name: "+this->GetUserName()+"\n";
    s = s + "ID: "+QString::number(this->GetId())+"\n";
    s += "Class: "+QString::fromStdString(typeid(*this).name())+"\n";
    s += "Moderate Boards: " + board->GetName() + "\n";
    return s;
}

bool Moderator::DeletePost(Post * post, Board* const board)
{
	//版主可以删除其管理板块下的任一帖子;也可以删除其他版块下自己发布的无人评论的帖子
	if (board->IsPostExist(post)) {
		if (board == this->board) {
			//是版主管理的版块
			board->DeletePost(post);
			if (post)
				delete post;
			return true;
		}
		else {
			//不是版主管理的版块
            if ((post->GetUser() == this->GetUserName()) && (post->GetCommentsSize() == 0)) {
				board->DeletePost(post);
				if (post)
					delete post;
				return true;
			}
			else {
				cout << "该贴不是你发布的未评论的帖子，删除失败！" << endl;
				return false;
			}
		}
	}
	cout << "本版块下无该帖子！" << endl;
	return false;
}
