#include "Comment.h"
#include "OrdinaryUser.h"

Comment::Comment()
{
    time = GetTime();
}


Comment::~Comment()
{
}

QString Comment::Show()
{
    QString s = content+"\n";
    s = s + ShowTime(time)+"\t"+ "Commentator: "+user->GetUserName();
    return s;
}
