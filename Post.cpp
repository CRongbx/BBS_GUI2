#include "Post.h"
#include "MyTime.h"
#include "Comment.h"

Post::Post()
{
	time = GetTime();
}


Post::~Post()
{
}

QString Post::Show()
{
  QString s = "id: "+QString::number(id)+"  ";
  s += title + "  ";
  s += "Poster: " + user->GetUserName()+"  ";
  s += "Creating Time: "+ShowTime(time)+"  ";
  s += "Num of Comment: " + QString::number(comments.size());
  return s;
}

 vector<QString> Post::ShowComments(){
    vector<QString> com;
     for (auto c : comments)
        com.push_back(c->Show());
     return com;
 }

bool Post::AddComment(Comment * c)
{
	comments.push_back(c);
	return true;
}

bool Post::DeleteComment(Comment * c)
{
	for (vector<Comment*>::iterator it = comments.begin();it != comments.end();it++) {
		if (c == (*it)) {
			comments.erase(it);
			return true;
		}
	}
	return false;
}

Comment* Post::GetComment(QString name){
    for(auto c : comments){
        if(c->GetContent() == name)
            return c;
    }
    return nullptr;
}

ofstream& operator <<(ofstream& fout,const Post &post){
    //用“$”分隔变量
    fout << post.id<<"$"<<post.title.toStdString();
    fout <<"$"<<post.content.toStdString()<< "$";
    fout <<post.user->GetUserName().toStdString()<<"$";
    fout <<ShowTime(post.time).toStdString()<<"$$";
    //保存该post下评论
    for (auto c : post.comments){
        fout << c->GetContent().toStdString()<<"$";
        fout << ShowTime(c->GetTime()).toStdString()<<"$";
        fout << c->GetOrdinaryUser()->GetUserName().toStdString()<<"$$";
    }
    return fout;
}
