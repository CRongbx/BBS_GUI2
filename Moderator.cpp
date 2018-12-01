#include "Moderator.h"
#include "Board.h"
#include "Post.h"
#include <iostream>
using namespace std;

Moderator::Moderator()
{
}


Moderator::~Moderator()
{
}

bool Moderator::DeletePost(Post * post, Board* const board)
{
	//��������ɾ�����������µ���һ����;Ҳ����ɾ������������Լ��������������۵�����
	if (board->IsPostExist(post)) {
		if (board == this->board) {
			//�ǰ��������İ��
			board->DeletePost(post);
			if (post)
				delete post;
			return true;
		}
		else {
			//���ǰ��������İ��
			if ((post->GetUser() == dynamic_cast<OrdinaryUser*>(this))
				&& (post->GetCommentsSize() == 0)) {
				board->DeletePost(post);
				if (post)
					delete post;
				return true;
			}
			else {
				cout << "���������㷢����δ���۵����ӣ�ɾ��ʧ�ܣ�" << endl;
				return false;
			}
		}
	}
	cout << "��������޸����ӣ�" << endl;
	return false;
}