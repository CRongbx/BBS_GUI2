#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include "BBS.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//    Ui::MainWindow* GetUi(){return ui;}
private slots:
    void on_pushButton_5_clicked();

    void on_Button_signup_clicked();

    void on_username_editingFinished();

    void on_password_editingFinished();

    void on_Button_signin_clicked();

    void on_Button_exit_clicked();

    void on_Button_logout_clicked();

private:
    Ui::MainWindow *ui;
    BBS* bbs;
    QString username;
    QString password;
};

#endif // MAINWINDOW_H
