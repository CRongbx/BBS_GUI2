#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bbs = new BBS;
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
    User* user = new User;
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
    //��¼
    User * user = bbs->GetUser(username);
    if(user){
        if(user->SignIn(username,password)){
            //success
            QMessageBox box;
            box.setWindowTitle(tr("Sign In"));
            box.setText(tr("SUCCESS!"));
            box.exec();
            //���Բ鿴���桢���ӡ������Ȳ���
            ui->lookbullntin->setEnabled(true);
            ui->label_user->setEnabled(true);
        }
        else{
            //fail
            QMessageBox box;
            box.setWindowTitle(tr("Sign In"));
            box.setText(tr("FAIL!"));
            box.exec();
        }
    }
    else{
        //fail
        QMessageBox box;
        box.setWindowTitle(tr("Sign In"));
        box.setText(tr("FAIL!"));
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
