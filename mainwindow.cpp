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
#include <QButtonGroup>     //����ѡ��Ի���
#include <typeinfo>         //�������ͺ���typeid
#include <QComboBox>        //��Ͽ�

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
    //��ʾBBS��Ϣ
    QString str = bbs->GetBBSTitle()+"\nNum of User: "
            +QString::number(bbs->GetUsersSize());
    ui->label->setText(str);
}

void MainWindow::on_Button_signup_clicked()
{
    //ע��
    User* user = new OrdinaryUser;
    if (user->SignUp(username,password,bbs)){
        //ע��ɹ�
        QMessageBox box;
        box.setWindowTitle(tr("Sign Up"));
        box.setText(tr("SUCCESS!"));
        box.exec();     //�����Ի��򣨲���ѡshow()���ֺ�������˳���
    }
    else{
        //ע��ʧ��
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
    //�û���¼
    User * user = bbs->GetUser(username);
    if(user){
        if(user->SignIn(username,password)){
            //success
            QMessageBox box;
            box.setWindowTitle(tr("Sign In"));
            box.setText(tr("SUCCESS!"));
            box.exec();
            //�û���¼������Ĳ������鿴���桢���ӡ������Ȳ���
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
                //�ǹ���Ա����
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
    //�û��˳�
    User * user = bbs->GetUser(username);
    QMessageBox box;
    if(user){
        if(user->GetOnline()){
            //�ɹ��˳�
            user->SignOut();
            box.setWindowTitle(tr("Sign Out"));
            box.setText(tr("SUCCESS!"));
            box.exec();
            //�û��˳�������Ĳ������鿴���桢���ӡ������Ȳ���
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
            //��δ��¼
            box.setWindowTitle(tr("Sign Out"));
            box.setText(tr("FAIL!\nPlease sign in first."));
            box.exec();
        }
    }
    else{
        //��δע��
        box.setWindowTitle(tr("Sign Out"));
        box.setText(tr("FAIL!\nPlease sign up first."));
        box.exec();
    }
}

void MainWindow::on_Button_logout_clicked()
{
    //�û�ע��
    User * user = bbs->GetUser(username);
    QMessageBox box;
    if(user){
        if(user->Logout(username,password,bbs)){
            //ע���ɹ�
            delete user;
            box.setWindowTitle(tr("Logout"));
            box.setText(tr("SUCCESS!"));
            box.exec();
            //�û�ע��������Ĳ������鿴���桢���ӡ������Ȳ���
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
            //�������
            box.setWindowTitle(tr("Logout"));
            box.setText(tr("FAIL!\nWrong Password!"));
            box.exec();
        }
    }
    else{
        //�����ڸ��û�
        box.setWindowTitle(tr("Logout"));
        box.setText(tr("FAIL!\nPlease sign up first."));
        box.exec();
    }
}

void MainWindow::on_pushButton_userinfo_clicked()
{
    //��ʾ�û���Ϣ
    User* user = bbs->GetUser(username);
    ui->label_user->setText(user->Show());
}

void MainWindow::on_lookbullntin_clicked()
{
    vector<Board*> boards = bbs->GetBoardsVector();
    if(blabels.size()>0){
        //����ʾ������
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
    //����
    bool isok;
    QString posttitle,boardname,content;
    boardname = QInputDialog::getText(NULL,"Create Post","Please input the post belonging board:"
                                      ,QLineEdit::Normal,"board name",&isok);
    if(isok){
        if(bbs->GetBoard(boardname)){
            //���ڸð���
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
            //�����ڸð���
            QMessageBox box;
            box.setWindowTitle(tr("Create Post"));
            box.setText(tr("FAIL!\nBoard not exist!"));
            box.exec();
        }
    }
}

void MainWindow::on_pushButton_deletepost_clicked(){
    //ɾ��
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
                    //ɾ���ɹ�
                    box.setText(tr("SUCCESS!"));
                    box.exec();
                }
                else{
                    //ɾ��ʧ��
                    box.setText(tr("FAIL!"));
                    box.exec();
                }
            }
            else{
                //����������
                box.setText(tr("FAIL!\Post not exist!"));
                box.exec();
            }
        }
        else{
            //�����ڸð���
            box.setText(tr("FAIL!\nBoard not exist!"));
            box.exec();
        }
    }
}

void MainWindow::on_pushButton_comment_clicked(){
    //����
    bool isok;
    QMessageBox box;
    box.setWindowTitle(tr("Create Comment"));
    QString posttitle,boardname,content;
    boardname = QInputDialog::getText(NULL,"Create Comment","Please input the post belonging board:"
                                      ,QLineEdit::Normal,"board name",&isok);
    if(isok){
        if(bbs->GetBoard(boardname)){
            //���ڸð���
            Board* board = bbs->GetBoard(boardname);
            posttitle = QInputDialog::getText(NULL,"Create Comment","Please input the post title:"
                                              ,QLineEdit::Normal,"post title",&isok);
            Post * post = board->GetPost(posttitle);
            if(post){
                //���ڸ���
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
                //����������
                box.setText(tr("FAIL\nPost not exist!"));
                box.exec();
            }
        }
        else{
            //�����ڸð���
            box.setText(tr("FAIL!\nBoard not exist!"));
            box.exec();
        }
    }
}

void MainWindow::on_pushButton_setMo_clicked(){
    //���ð���
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
            //���ڸð��
            orname = QInputDialog::getText(NULL,"Set Moderator","Please input the user name"
                                           ,QLineEdit::Normal,"user name",&isok);
            User* ordinary = bbs->GetUser(orname);
            if(ordinary){
                if(isok){
                    User* o = new Moderator;
                    o = ad->SetModerator(ordinary,board,bbs);
                    cout << typeid(*o).name()<<endl;
                    //���óɹ�
                    box.setText(tr("SUCCESS!"));
                    box.exec();
                }
            }
            else{
                //�����ڸ��û�
                box.setText(tr("FAIL!\nUser not exist!"));
                box.exec();
            }
        }
        else{
            //�����ڸð���
            box.setText(tr("FAIL!\nBoard not exist!"));
            box.exec();
        }
    }
}

void MainWindow::on_pushButton_CancelMo_clicked(){
    //��������
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
            //���ڸ��û�
            if(typeid(*mo).name()==typeid(Moderator).name()){
                //�ǰ���
                mo = ad->RepealModerator(mo,bbs);
                if(mo){
                    //ת���ɹ�                    
                    cout <<typeid(*mo).name()<<endl;
                    box.setText(tr("SUCCESS!"));
                    box.exec();
                }else{
                    //ת��ʧ��
                    box.setText(tr("FAIL!"));
                    box.exec();
                }
            }else{
                //���ǰ���
                box.setText(tr("FAIL!\nNOT Moderator!"));
                box.exec();
            }
        }else{
            //���û�������
            box.setText(tr("FAIL!\nUser not exist!"));
            box.exec();
        }
    }
}
