#include "OrdinaryUser.h"
#include "Board.h"
#include "Post.h"
#include "BBS.h"
#include <iostream>
using namespace std;

OrdinaryUser::OrdinaryUser()
{
}


OrdinaryUser::~OrdinaryUser()
{
}

bool OrdinaryUser::DeletePost(Post * post,Board* const board)
{
	if ((post->GetUser() == this) && (post->GetCommentsSize() == 0)) {
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

Post * OrdinaryUser::CreatePost(string title, string content, Board * const board)
{
	Post* post = new Post();
	board->AddPost(post);

	post->SetContent(content);
	post->SetId(board->GetPostsSize());
	post->SetTitle(title);
	post->SetUser(this);
	post->SetTime(GetTime());

	return post;
}

Comment * OrdinaryUser::CreateComment(string content, Post * const post)
{
	Comment* com = new Comment(content);
	post->AddComment(com);
	com->SetOrdinaryUser(this);
	return com;
}

void OrdinaryUser::LookBBS(BBS* const bbs)
{
//	bbs->ShowBBS();
	bbs->ShowBoards();
}

void OrdinaryUser::LookBoard(Board * const board)
{
	board->Show();
}

void OrdinaryUser::LookPost(Post * const post)
{
	post->Show();
}
