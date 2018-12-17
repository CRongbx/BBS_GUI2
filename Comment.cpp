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
    s = s + ShowTime(time)+"\t"+ "Commentator: "+username;
    return s;
}

ofstream& operator <<(ofstream& fout, const Comment& comment){
    fout << "COMMENT:"<<endl;
    fout << "CONTENT:"<<comment.content.toStdString();
    fout << "TIME:"<< ShowTime(comment.time).toStdString();
    fout << "USER:"<<comment.username.toStdString();
    fout << "$";    //�ض��ַ�"$"
    return fout;
}

ifstream& operator >>(ifstream& fin, Comment& comment){
    try{
        string s;
        fin >> s;
        while(s != "COMMENT:"){
            s.clear();
            fin >> s;
        }
        s.clear();
        getline(fin,s,'$');     //�������ݣ�ֱ������$ֹͣ��\n�Ϳհ׷�����ֹͣ��
        //    cout <<s <<endl;

        size_t loc_content = s.find("CONTENT",0);
        size_t loc_time = s.find("TIME:",loc_content);
        size_t loc_user = s.find("USER:",loc_time);

        if (loc_content > s.length()) throw "ERROR: Can't find 'CONTENT'! ";
        if (loc_time > s.length()) throw "ERROR: Can't find 'TIME'! ";
        if (loc_user > s.length()) throw "ERROR: Can't find 'USER'! ";

        string content = "";
        for(size_t i = loc_content+8; i < loc_time; i++)
            content += s.at(i);
        comment.content = QString::fromStdString(content);

        string time = "";
        for(size_t i = loc_time + 5; i < loc_user; i++)
            time += s.at(i);
        SetTime(time,comment.time);

        string user = "";
        for(size_t i = loc_user + 5; i < s.length(); i++)
            user += s.at(i);
        comment.username = QString::fromStdString(user);

        fin.get();      //�����ض��ַ�$
        return fin;
    }
    catch (char const* msg){
        cerr << msg << endl;
    }
}
