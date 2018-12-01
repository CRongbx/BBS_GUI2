#include "MyTime.h"
#include <Windows.h>
#include <iostream>
using namespace std;

MyTime GetTime() {
    MyTime *time = new MyTime;
	//获取系统当前时间
	SYSTEMTIME sys;
	GetLocalTime(&sys);

	time->year = (unsigned int)sys.wYear;
	time->mouth = (unsigned int)sys.wMonth;
	time->day = (unsigned int)sys.wDay;
	time->hour = (unsigned int)sys.wHour;
	time->minute = (unsigned int)sys.wMinute;
	time->second = (unsigned int)sys.wSecond;

	return *time;
}
void DeleteTime(MyTime* time) {
	if (!time) delete time;
}

void ShowTime(MyTime const t) {
	cout << "Time: " << t.year << "-" << t.mouth << "-" << t.day << "-";
	cout << t.hour << "-" << t.minute << "-" << t.second << endl;
}
