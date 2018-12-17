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
    for(vector<QString>::iterator it = moderators.begin(); it != moderators.end(); it++)
        if((*it) == m->GetUserName()){
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
    fout << "BOARD:"<<endl;
    fout << "NAME:"<<board.name.toStdString();
    fout << "ID:"<<board.id;
    fout << "MODERSIZE:"<<board.moderators.size();
    fout <<"POSTSIZE:"<<board.posts.size();
    fout << "MODERATORS:";
    for (auto m : board.moderators){
        fout<<m.toStdString()<< "$";
    }
    fout <<endl;
    for (auto p : board.posts)
        fout << *p << endl;
    return fout;
}

ifstream& operator >> (ifstream& fin, Board& board){
    try{
        string s;
        fin >> s;
        while(s != "BOARD:"){
            s.clear();
            fin >> s;
        }
        s.clear();
        fin.get();     //endl
        fin >> s;

        size_t loc_name = s.find("NAME:",0);
        size_t loc_id = s.find("ID:", loc_name);
        size_t loc_mos = s.find("MODERSIZE:",loc_id);
        size_t loc_ps = s.find("POSTSIZE:",loc_mos);
        size_t loc_mo = s.find("MODERATORS:",loc_ps);

        if (loc_name > s.length()) throw "ERROR: Can't find 'NAME'! ";
        if (loc_id > s.length()) throw "ERROR: Can't find 'ID'! ";
        if (loc_mos > s.length()) throw "ERROR: Can't find 'MODERSIZE'! ";
        if (loc_ps > s.length()) throw "ERROR: Can't find 'POSTSIZE'! ";
        if (loc_mo > s.length()) throw "ERROR: Can't find 'MODERATORS'! ";

        string name;
        for(size_t i = loc_name + 5; i < loc_id; i++)
            name += s.at(i);
        board.name = QString::fromStdString(name);

        int id = 0;
        for(size_t i = loc_id + 3; i < loc_mos; i++)
            id = id*10 + s.at(i) - '0';
        board.id = id;

        int modersize = 0;
        for(size_t i = loc_mos + 10; i < loc_ps; i++)
            modersize = modersize*10 + s.at(i) - '0';

        int postsize = 0;
        for(size_t i = loc_ps + 9; i < loc_mo; i++)
            postsize = postsize*10 + s.at(i) - '0';

        string m;
        for(size_t i = loc_mo + 11; i < s.length(); i++){
            if(s.at(i) == '$'){
                board.moderators.push_back(QString::fromStdString(m));
                m.clear();
            }
            else
                m += s.at(i);
        }

        for(int i = 0; i < postsize; i++){
            Post* post = new Post;
            fin >> *post;
            board.posts.push_back(post);
        }

        return fin;
    }
    catch (char const* msg){
        cerr << msg << endl;
    }
}
