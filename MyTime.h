/*
* ʱ����Ϣ
*/
#ifndef MYTIME_H
#define MYTIME_H
#include <QString>
#include <fstream>
using namespace std;

/*��struct��װ������class��װ��ԭ��struct��Ĭ�Ϸ���Ȩ����public��
class��private�����������ϣ����������г�Ա��public��*/
typedef struct MyTime {
    int year = 2018;
    int mouth = 12;
    int day = 03;
    int hour = 22;
    int minute =44;
    int second = 00;
}MyTime;
MyTime GetTime();
void DeleteTime(MyTime* time);
QString ShowTime(MyTime const time);
void SetTime (string s, MyTime& time);
#endif // !MYTIME_H
