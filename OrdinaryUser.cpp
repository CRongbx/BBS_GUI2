#include "OrdinaryUser.h"
#include "Board.h"
#include "Post.h"
#include "BBS.h"
#include <iostream>
#include <typeinfo>
using namespace std;

OrdinaryUser::OrdinaryUser()
{
}


OrdinaryUser::~OrdinaryUser()
{
}

QString OrdinaryUser::Show(){
    QString s = "User Name: "+this->GetUserName()+"\n";
    s = s + "ID: "+QString::number(this->GetId())+"\n";
    s += "Class: "+QString::fromStdString(typeid(*this).name())+"\n";

    return s;
}

bool OrdinaryUser::DeletePost(Post * post,Board* const board)
{
    if ((post->GetUser() == this->GetUserName()) && (post->GetCommentsSize() == 0)) {
		//自己发布、评论数为0
		if (board->IsPostExist(post)) {
			board->DeletePost(post);  //从该板块下删除
			if (post)	//删除堆中空间
				delete post;
			return true;
		}
		else {
			cout << "本板块下无该贴！" << endl;
			return false;
		}
	}
	return false;
}

Post * OrdinaryUser::CreatePost(QString title, QString content, Board * const board)
{
	Post* post = new Post();
	board->AddPost(post);

	post->SetContent(content);
	post->SetId(board->GetPostsSize());
	post->SetTitle(title);
    post->SetUser(this->GetUserName());
	post->SetTime(GetTime());

	return post;
}

Comment * OrdinaryUser::CreateComment(QString content, Post * const post)
{
	Comment* com = new Comment(content);
	post->AddComment(com);
    com->SetUserName(this->GetUserName());
	return com;
}
