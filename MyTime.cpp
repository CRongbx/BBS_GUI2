#include "MyTime.h"
#include <Windows.h>
#include <iostream>
using namespace std;

MyTime GetTime() {
    MyTime *time = new MyTime;
    //获取系统当前时间
    SYSTEMTIME sys;
    GetLocalTime(&sys);

    time->year = (int)sys.wYear;
    time->mouth = (int)sys.wMonth;
    time->day = (int)sys.wDay;
    time->hour = (int)sys.wHour;
    time->minute = (int)sys.wMinute;
    time->second = (int)sys.wSecond;

    return *time;
}
void DeleteTime(MyTime* time) {
    if (!time) delete time;
}

QString ShowTime(MyTime const t) {
    QString s = QString::number(t.year)+"-"+QString::number(t.mouth);
    s += "-"+QString::number(t.day)+"-"+QString::number(t.hour)+":"+QString::number(t.minute);
    s += ":"+QString::number(t.second);
    return s;
}

void SetTime (string s, MyTime& time){
    try{
        MyTime thistime = GetTime();
        size_t ly = s.find("-",0);  size_t lm = s.find("-",ly+1);
        size_t ld = s.find("-",lm+1); size_t lh = s.find(":",ld);
        size_t lminute = s.find(":",lh+1);

        int temp = 0;
        for(size_t i = 0; i < ly; i++)
            temp = temp*10 + s.at(i)-'0';
        if (temp <= thistime.year)  time.year = temp;
        else throw "ERROR: Wrong Time of Year!";

        temp = 0;
        for (size_t i = ly+1; i < lm; i++)
            temp = temp*10 + s.at(i)-'0';
        if(temp <= thistime.mouth || time.year < thistime.year)  time.mouth = temp;
        else throw "ERROR: Wrong Time of Mouth!";


        temp = 0;
        for(size_t i = lm+1; i < ld; i++)
            temp = temp*10 + s.at(i)-'0';
        if(temp <= thistime.day || time.year < thistime.year || time.mouth < thistime.mouth )  time.day = temp;
        else throw "ERROR: Wrong Time of Day!";

        temp = 0;
        for(size_t i = ld+1;  i < lh; i++)
            temp = temp*10 + s.at(i)-'0';
        if(temp <= thistime.hour|| time.year < thistime.year || time.mouth < thistime.mouth
                || time.day < thistime.day)  time.hour = temp;
        else throw "ERROR: Wrong Time of Hour!";

        temp = 0;
        for(size_t i = lh+1; i < lminute; i++)
            temp = temp*10 + s.at(i)-'0';
        if(temp <= thistime.minute || time.year < thistime.year || time.mouth < thistime.mouth
                || time.day < thistime.day || time.hour < thistime.hour)  time.minute = temp;
        else throw "ERROR: Wrong Time of Minute!";

        temp = 0;
        for(size_t i = lminute+1; i < s.length(); i++)
            temp = temp*10 + s.at(i) - '0';
        if(temp <= thistime.second|| time.year < thistime.year || time.mouth < thistime.mouth
                || time.day < thistime.day || time.hour < thistime.hour || time.minute < thistime.minute)  time.second = temp;
        else throw "ERROR: Wrong Time of Second!";
    }
    catch (char const* msg){
        cerr << msg << endl;
    }
}
