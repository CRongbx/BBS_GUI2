#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "boardslabel.h"
#include "Board.h"
#include "Moderator.h"
#include "Administator.h"
#include <QMessageBox>
#include <QLineEdit>
#include <QLabel>
#include <QInputDialog>
#include <QButtonGroup>     //单项选择对话框
#include <typeinfo>         //返回类型函数typeid
#include <QComboBox>        //组合框

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bbs = new BBS;
    bbs->InitBBS();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete bbs;
}

void MainWindow::on_pushButton_5_clicked()
{
    //显示BBS信息
    QString str = bbs->GetBBSTitle()+"\nNum of User: "
            +QString::number(bbs->GetUsersSize());
    ui->label->setText(str);
}

void MainWindow::on_Button_signup_clicked()
{
    //注册
    User* user = new OrdinaryUser;
    if (user->SignUp(username,password,bbs)){
        //注册成功
        QMessageBox box;
        box.setWindowTitle(tr("Sign Up"));
        box.setText(tr("SUCCESS!"));
        box.exec();     //弹出对话框（不能选show()出现后会马上退出）
    }
    else{
        //注册失败
        QMessageBox box;
        box.setWindowTitle(tr("Sign Up"));
        box.setText(tr("FAIL!"));
        box.exec();
    }

}

void MainWindow::on_username_editingFinished()
{
    username = ui->username->text();
}

void MainWindow::on_password_editingFinished()
{
    password = ui->password->text();
}

void MainWindow::on_Button_signin_clicked()
{
    //用户登录
    User * user = bbs->GetUser(username);
    if(user){
        if(user->SignIn(username,password)){
            //success
            QMessageBox box;
            box.setWindowTitle(tr("Sign In"));
            box.setText(tr("SUCCESS!"));
            box.exec();
            //用户登录后允许的操作：查看版面、帖子、发帖等操作
            ui->pushButton_createpost->setEnabled(true);
            ui->pushButton_deletepost->setEnabled(true);
            ui->pushButton_comment->setEnabled(true);
            ui->lookbullntin->setEnabled(true);
            ui->label_user->setEnabled(true);
            ui->pushButton_userinfo->setEnabled(true);
            ui->Button_logout->setEnabled(true);
            ui->Button_exit->setEnabled(true);
            ui->Button_signin->setEnabled(false);
            ui->Button_signup->setEnabled(false);
            if(typeid(*user) == typeid(Administator)){
                //是管理员类型
                ui->pushButton_setMo->setEnabled(true);
                ui->pushButton_CancelMo->setEnabled(true);
            }
        }
        else{
            //fail
            QMessageBox box;
            box.setWindowTitle(tr("Sign In"));
            box.setText(tr("FAIL!\nWrong Password!"));
            box.exec();
        }
    }
    else{
        //fail
        QMessageBox box;
        box.setWindowTitle(tr("Sign In"));
        box.setText(tr("FAIL!\nPlease Sign Up first!"));
        box.exec();
    }

}

void MainWindow::on_Button_exit_clicked()
{
    //用户退出
    User * user = bbs->GetUser(username);
    QMessageBox box;
    if(user){
        if(user->GetOnline()){
            //成功退出
            user->SignOut();
            box.setWindowTitle(tr("Sign Out"));
            box.setText(tr("SUCCESS!"));
            box.exec();
            //用户退出后不允许的操作：查看版面、帖子、发帖等操作
            ui->pushButton_createpost->setEnabled(false);
            ui->pushButton_deletepost->setEnabled(false);
            ui->pushButton_comment->setEnabled(false);
            ui->lookbullntin->setEnabled(false);
            ui->label_user->setEnabled(false);
            ui->pushButton_userinfo->setEnabled(false);
            ui->pushButton_setMo->setEnabled(false);
            ui->pushButton_CancelMo->setEnabled(false);
            ui->Button_logout->setEnabled(false);
            ui->Button_exit->setEnabled(false);
            ui->Button_signin->setEnabled(true);
            ui->Button_signup->setEnabled(true);
        }
        else{
            //还未登录
            box.setWindowTitle(tr("Sign Out"));
            box.setText(tr("FAIL!\nPlease sign in first."));
            box.exec();
        }
    }
    else{
        //还未注册
        box.setWindowTitle(tr("Sign Out"));
        box.setText(tr("FAIL!\nPlease sign up first."));
        box.exec();
    }
}

void MainWindow::on_Button_logout_clicked()
{
    //用户注销
    User * user = bbs->GetUser(username);
    QMessageBox box;
    if(user){
        if(user->Logout(username,password,bbs)){
            //注销成功
            delete user;
            box.setWindowTitle(tr("Logout"));
            box.setText(tr("SUCCESS!"));
            box.exec();
            //用户注销后不允许的操作：查看版面、帖子、发帖等操作
            ui->pushButton_createpost->setEnabled(false);
            ui->pushButton_deletepost->setEnabled(false);
            ui->pushButton_comment->setEnabled(false);
            ui->lookbullntin->setEnabled(false);
            ui->label_user->setEnabled(false);
            ui->pushButton_userinfo->setEnabled(false);
            ui->pushButton_setMo->setEnabled(false);
            ui->pushButton_CancelMo->setEnabled(false);
            ui->Button_logout->setEnabled(false);
            ui->Button_exit->setEnabled(false);
            ui->Button_signin->setEnabled(true);
            ui->Button_signup->setEnabled(true);
        }
        else{
            //密码错误
            box.setWindowTitle(tr("Logout"));
            box.setText(tr("FAIL!\nWrong Password!"));
            box.exec();
        }
    }
    else{
        //不存在该用户
        box.setWindowTitle(tr("Logout"));
        box.setText(tr("FAIL!\nPlease sign up first."));
        box.exec();
    }
}

void MainWindow::on_pushButton_userinfo_clicked()
{
    //显示用户信息
    User* user = bbs->GetUser(username);
    ui->label_user->setText(user->Show());
}

void MainWindow::on_lookbullntin_clicked()
{
    vector<Board*> boards = bbs->GetBoardsVector();
    if(blabels.size()>0){
        //已显示版面了
        for(vector<BoardsLabel*>::iterator it = blabels.begin();it != blabels.end();it++){
            if((*it))
                delete (*it);
        }
        blabels.clear();
    }
    for(auto b : boards){
        BoardsLabel * blabel = new BoardsLabel;
        blabels.push_back(blabel);
        blabel->setText(b->ShowBoardInfo());
        blabel->ConnectUi(ui);
        blabel->ConnectBoard(b);
        ui->bullutin->addWidget(blabel,ui->bullutin->count());
    }
}

void MainWindow::on_pushButton_createpost_clicked(){
    //发帖
    bool isok;
    QString posttitle,boardname,content;
    boardname = QInputDialog::getText(NULL,"Create Post","Please input the post belonging board:"
                                      ,QLineEdit::Normal,"board name",&isok);
    if(isok){
        if(bbs->GetBoard(boardname)){
            //存在该版面
            posttitle = QInputDialog::getText(NULL,"Create Post","Please input the post title:"
                                              ,QLineEdit::Normal,"post title",&isok);
            if(isok){
                content = QInputDialog::getText(NULL,"Create Post","Please input the post content:"
                                                ,QLineEdit::Normal,"post content",&isok);
                if (isok){
                    User * user = bbs->GetUser(username);
                    user->CreatePost(posttitle,content,bbs->GetBoard(boardname));
                    QMessageBox box;
                    box.setWindowTitle(tr("Create Post"));
                    box.setText(tr("SUCCESS!"));
                    box.exec();
                }
            }
        }
        else{
            //不存在该版面
            QMessageBox box;
            box.setWindowTitle(tr("Create Post"));
            box.setText(tr("FAIL!\nBoard not exist!"));
            box.exec();
        }
    }
}

void MainWindow::on_pushButton_deletepost_clicked(){
    //删帖
    bool isok;
    QString boardname,postname;
    QMessageBox box;
    box.setWindowTitle(tr("Delete Post"));
    boardname = QInputDialog::getText(NULL,"Delete Post","Please input the post belonging board:"
                                      ,QLineEdit::Normal,"board name",&isok);
    if(isok){
        Board* board = bbs->GetBoard(boardname);
        if(board){
            postname = QInputDialog::getText(NULL,"Delete Post","Please input the post title:"
                                             ,QLineEdit::Normal,"post title",&isok);
            Post* post = board->GetPost(postname);
            if(post){
                User* user = bbs->GetUser(username);
                cout << typeid(*user).name()<<endl;
                if(user->DeletePost(post,board)){
                    //删帖成功
                    box.setText(tr("SUCCESS!"));
                    box.exec();
                }
                else{
                    //删帖失败
                    box.setText(tr("FAIL!"));
                    box.exec();
                }
            }
            else{
                //该贴不存在
                box.setText(tr("FAIL!\Post not exist!"));
                box.exec();
            }
        }
        else{
            //不存在该版面
            box.setText(tr("FAIL!\nBoard not exist!"));
            box.exec();
        }
    }
}

void MainWindow::on_pushButton_comment_clicked(){
    //评论
    bool isok;
    QMessageBox box;
    box.setWindowTitle(tr("Create Comment"));
    QString posttitle,boardname,content;
    boardname = QInputDialog::getText(NULL,"Create Comment","Please input the post belonging board:"
                                      ,QLineEdit::Normal,"board name",&isok);
    if(isok){
        if(bbs->GetBoard(boardname)){
            //存在该版面
            Board* board = bbs->GetBoard(boardname);
            posttitle = QInputDialog::getText(NULL,"Create Comment","Please input the post title:"
                                              ,QLineEdit::Normal,"post title",&isok);
            Post * post = board->GetPost(posttitle);
            if(post){
                //存在该贴
                content = QInputDialog::getText(NULL,"Create Comment","Please input the post title:"
                                                ,QLineEdit::Normal,"post title",&isok);
                if(isok){
                    User *user = bbs->GetUser(username);
                    user->CreateComment(content,post);
                    box.setText("SUCCESS!");
                    box.exec();
                }
            }
            else{
                //该贴不存在
                box.setText(tr("FAIL\nPost not exist!"));
                box.exec();
            }
        }
        else{
            //不存在该版面
            box.setText(tr("FAIL!\nBoard not exist!"));
            box.exec();
        }
    }
}

void MainWindow::on_pushButton_setMo_clicked(){
    //设置版主
    User* ad = bbs->GetUser(username);
    bool isok;
    QString boardname, orname;
    QMessageBox box;
    box.setWindowTitle(tr("Set Moderator"));
    boardname = QInputDialog::getText(NULL,"Set Moderator","Please input the board name"
                                      ,QLineEdit::Normal,"board name",&isok);
    if(isok){
        Board* board = bbs->GetBoard(boardname);
        if(board){
            //存在该板块
            orname = QInputDialog::getText(NULL,"Set Moderator","Please input the user name"
                                           ,QLineEdit::Normal,"user name",&isok);
            User* ordinary = bbs->GetUser(orname);
            if(ordinary){
                if(isok){
                    User* o = new Moderator;
                    o = ad->SetModerator(ordinary,board,bbs);
                    cout << typeid(*o).name()<<endl;
                    //设置成功
                    box.setText(tr("SUCCESS!"));
                    box.exec();
                }
            }
            else{
                //不存在该用户
                box.setText(tr("FAIL!\nUser not exist!"));
                box.exec();
            }
        }
        else{
            //不存在该版面
            box.setText(tr("FAIL!\nBoard not exist!"));
            box.exec();
        }
    }
}

void MainWindow::on_pushButton_CancelMo_clicked(){
    //撤销版主
    User* ad = bbs->GetUser(username);
    bool isok;
    QString name;
    QMessageBox box;
    box.setWindowTitle(tr("Repeal Moderator"));
    name = QInputDialog::getText(NULL,"Repeal Moderator","Please input the moderator name"
                                 ,QLineEdit::Normal,"moderator name",&isok);
    if(isok){
        User* mo = bbs->GetUser(name);
        if(mo){
            //存在该用户
            if(typeid(*mo).name()==typeid(Moderator).name()){
                //是版主
                mo = ad->RepealModerator(mo,bbs);
                if(mo){
                    //转换成功                    
                    cout <<typeid(*mo).name()<<endl;
                    box.setText(tr("SUCCESS!"));
                    box.exec();
                }else{
                    //转换失败
                    box.setText(tr("FAIL!"));
                    box.exec();
                }
            }else{
                //不是版主
                box.setText(tr("FAIL!\nNOT Moderator!"));
                box.exec();
            }
        }else{
            //该用户不存在
            box.setText(tr("FAIL!\nUser not exist!"));
            box.exec();
        }
    }
}
