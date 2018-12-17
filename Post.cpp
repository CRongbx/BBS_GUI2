#include "Post.h"
#include "MyTime.h"
#include "Comment.h"

Post::Post()
{
    time = GetTime();
}


Post::~Post()
{
    //    for(auto c :comments)
    //        if(c)
    //            delete c;
}

QString Post::Show()
{
    QString s = "id: "+QString::number(id)+"  ";
    s += title + "  ";
    s += "Poster: " + username +"  ";
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
    //打印帖子的基本信息
    fout << "POST:"<<endl;
    fout << "ID:"<<post.id << "$";
    fout << "TITLE:"<<post.title.toStdString()<<"$";        //title里可能有空格，需要添加截断符$处理
    fout << "CONTENT:"<<post.content.toStdString()<<"$";
    fout << "USER:"<<post.username.toStdString();
    fout << "TIME:"<<ShowTime(post.time).toStdString();
    fout << "COMMENTSIZE:"<<post.comments.size()<<endl;
    //打印该post下评论
    for (auto c : post.comments)
        fout << *c << endl;
    return fout;
}

ifstream& operator >> (ifstream& fin, Post& post){
    try{
        string s;
        fin >> s;
        while(s != "POST:"){
            s.clear();
            fin >> s;
        }
        s.clear();
        getline(fin,s,'$');     //id

        int temp = 0;
        for(size_t i = 4; i < s.length(); i++)
            temp = temp*10 + s.at(i) - '0';
        post.id = temp;


        s.clear();
        getline(fin, s, '$');   //title
        string title = "";
        for(size_t i = 6; i < s.length(); i++)
            title += s.at(i);
        post.title = QString::fromStdString(title);

        s.clear();
        getline(fin, s, '$');   //content
        string content = "";
        for(size_t i = 8; i < s.length(); i++)
            content += s.at(i);
        post.content = QString::fromStdString(content);

        s.clear();
        fin >> s;   //username + time
        size_t loc_username = s.find("USER:",0);
        size_t loc_time = s.find("TIME:",loc_username);
        size_t loc_cs = s.find("COMMENTSIZE:",loc_time);

        string username = "";
        for (size_t i = loc_username + 5; i < loc_time; i++)
            username += s.at(i);
        post.username = QString::fromStdString(username);

        string time = "";
        for(size_t i = loc_time + 5; i < loc_cs; i++)
            time += s.at(i);
        SetTime(time, post.time);

        int commentsize = 0;        //commentsize
        for(int i = loc_cs + 12; i < s.length(); i++)
            commentsize = commentsize*10 + s.at(i) - '0';

        for(int i = 0; i < commentsize; i++){       //comments
            Comment* comment = new Comment;
            fin >> *comment;
            post.comments.push_back(comment);
        }

        return fin;
    }
    catch (char const* msg){
        cerr << msg << endl;
    }
}
