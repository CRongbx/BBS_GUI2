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
    //显示BBS信息
    QString str = bbs->GetBBSTitle()+"\nNum of User: "
            +QString::number(bbs->GetUsersSize());
    ui->label->setText(str);
}

void MainWindow::on_Button_signup_clicked()
{
    //注册
    User* user = new User;
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
    //登录
    User * user = bbs->GetUser(username);
    if(user){
        if(user->SignIn(username,password)){
            //success
            QMessageBox box;
            box.setWindowTitle(tr("Sign In"));
            box.setText(tr("SUCCESS!"));
            box.exec();
            //可以查看版面、帖子、发帖等操作
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
