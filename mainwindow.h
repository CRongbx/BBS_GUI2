#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <fstream>
#include "BBS.h"
#include "SocketClient.h"
using namespace std;

namespace Ui {
class MainWindow;
}

class BoardsLabel;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_pushButton_5_clicked();

    void on_Button_signup_clicked();

    void on_username_editingFinished();

    void on_password_editingFinished();

    void on_Button_signin_clicked();

    void on_Button_exit_clicked();

    void on_Button_logout_clicked();

    void on_pushButton_userinfo_clicked();

    void on_lookbullntin_clicked();

    void on_pushButton_createpost_clicked();

    void on_pushButton_deletepost_clicked();

    void on_pushButton_comment_clicked();

    void on_pushButton_setMo_clicked();

    void on_pushButton_CancelMo_clicked();
    void on_checkBox_anonymity_clicked();

private:
    Ui::MainWindow *ui;
    BBS bbs;
    QString username;
    QString password;
    vector<BoardsLabel*> blabels;
    ofstream fout;       //保存BBS数据的输出文件
    ifstream fin;        //保存BBS数据的输入文件
    SocketClient socketClient;
};

#endif // MAINWINDOW_H
