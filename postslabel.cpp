#include "postslabel.h"
#include "Post.h"
#include <QMouseEvent>

PostsLabel::PostsLabel()
{
    this->installEventFilter(this);     //为自己设置事件过滤器
}

bool PostsLabel::eventFilter(QObject *watched, QEvent *event){
    if(event->type()==QEvent::MouseButtonPress){
        //展示内容和评论
        if(ui->verticalLayout_comments->count()>1){
            QLayoutItem* child;
            while(child = ui->verticalLayout_comments->layout()->takeAt(1)){
                if(child->widget())
                    child->widget()->setParent(NULL);
                delete child;
            }
        }
        if(labels.size()>0){
            //已显示
            for(auto la : labels)
                if(la)
                    delete la;
            labels.clear();
        }

        QLabel* title = new QLabel;
        labels.push_back(title);
        title->setText("Title: "+post->GetTitle());
        ui->verticalLayout_comments->addWidget(title,ui->verticalLayout_comments->count());

        QLabel* content = new QLabel;
        labels.push_back(content);
        content->setText("Content: \n"+post->GetContent());
        ui->verticalLayout_comments->addWidget(content,ui->verticalLayout_comments->count());

        vector<QString> comments = post->ShowComments();
        for(auto c : comments){
            QLabel* label = new QLabel;
            labels.push_back(label);
            label->setText(c);
            ui->verticalLayout_comments->addWidget(label,ui->verticalLayout_comments->count());
        }
    }
    return QWidget::eventFilter(watched,event);
}
