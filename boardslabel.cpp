#include "boardslabel.h"
#include "postslabel.h"
#include "Post.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>

BoardsLabel::BoardsLabel()
{

}

BoardsLabel::~BoardsLabel(){
    for(auto pl : plabes)
        if(pl)
            delete pl;
    //    delete this;
}

void BoardsLabel::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton){
        //չʾ������Ϣ
        //ԭ��������Ϣչʾ
        if(ui->verticalLayout_posts->count()){
            QLayoutItem* child;
            while(child = ui->verticalLayout_posts->layout()->takeAt(0)){
                if(child->widget())
                    child->widget()->setParent(NULL);
                delete child;
            }
        }
        vector<Post*> posts = board->GetPostsVector();
        if(plabes.size()>0){
            //����ʾ�ð���
            for(auto pl : plabes)
                if(pl)
                    delete pl;
            plabes.clear();
        }
        for(auto p : posts){
            PostsLabel* plabel = new PostsLabel;
            plabes.push_back(plabel);
            plabel->setText(p->Show());
            plabel->ConnectPost(p);
            plabel->ConnectUi(ui);
            ui->verticalLayout_posts->addWidget(plabel,ui->verticalLayout_posts->count());
        }
    }
}

