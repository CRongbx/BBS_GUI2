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
//	cout << "Time: " << t.year << "-" << t.mouth << "-" << t.day << "-";
//	cout << t.hour << "-" << t.minute << "-" << t.second << endl;
    QString s = "Time: "+QString::number(t.year)+"-"+QString::number(t.mouth);
    s += "-"+QString::number(t.day)+" "+QString::number(t.hour)+":"+QString::number(t.minute);
    s += ":"+QString::number(t.second);
    return s;
}
