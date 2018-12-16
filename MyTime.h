/*
* 时间信息
*/
#ifndef MYTIME_H
#define MYTIME_H
#include <QString>
#include <fstream>
using namespace std;

/*用struct封装而不用class封装的原因：struct的默认访问权限是public，
class是private，在这里，我们希望定义的所有成员是public的*/
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
