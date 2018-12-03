#ifndef POSTSLABEL_H
#define POSTSLABEL_H
#include <QLabel>
#include "mainwindow.h"
#include "ui_mainwindow.h"

class Post;

class PostsLabel:public QLabel
{
public:
    PostsLabel();
    void ConnectPost(Post* p){post = p;}
    void ConnectUi(Ui::MainWindow *ui){this->ui = ui;}
    Post* GetPost(){return post;}
protected:
    bool eventFilter(QObject *watched, QEvent *event);  //�¼�������

private:
    Post* post;
    Ui::MainWindow *ui;
    vector<QLabel*> labels;
};

#endif // POSTSLABEL_H
