#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>      //�Ի���
#include <QComboBox>    //��Ͽ�
//�Լ�ʵ���˸�������Ͽ�ĶԻ���
class Dialog : public QDialog
{
    Q_OBJECT
public:
    Dialog(QString title,QWidget *p = 0);
    ~Dialog();
    void addComBoxItem(QString s);  //�����Ͽ�ѡ��
public slots:
    void onChanged(int index);
private:
    QComboBox* combox;      //��Ͽ�ָ��
};

#endif // DIALOG_H
