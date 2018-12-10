#include "dialog.h"

Dialog::Dialog(QString title,QWidget *parent):QDialog(parent)
{
    combox = new QComboBox(this);   //������Ͽ�
    combox->setGeometry(20,20,100,30);
    connect(combox,SIGNAL(currentIndexChanged(int)),this,SLOT(onChanged(int)));
    this->resize(200,200);      //�Ի����С
    this->setWindowTitle(title);
}

Dialog::addComBoxItem(QString s){
    combox->addItem(s);
}
