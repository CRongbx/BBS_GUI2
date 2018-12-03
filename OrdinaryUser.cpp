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
		//�Լ�������������Ϊ0
		if (board->IsPostExist(post)) {
			board->DeletePost(post);  //�Ӹð����ɾ��
			if (post)	//ɾ�����пռ�
				delete post;
			return true;
		}
		else {
			cout << "��������޸�����" << endl;
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
	post->SetUser(this);
	post->SetTime(GetTime());

	return post;
}

Comment * OrdinaryUser::CreateComment(QString content, Post * const post)
{
	Comment* com = new Comment(content);
	post->AddComment(com);
	com->SetOrdinaryUser(this);
	return com;
}
