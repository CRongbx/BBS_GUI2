#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>      //对话框
#include <QComboBox>    //组合框
//自己实现了个附带组合框的对话框
class Dialog : public QDialog
{
    Q_OBJECT
public:
    Dialog(QString title,QWidget *p = 0);
    ~Dialog();
    void addComBoxItem(QString s);  //添加组合框选项
public slots:
    void onChanged(int index);
private:
    QComboBox* combox;      //组合框指针
};

#endif // DIALOG_H
