/*
* 时间信息
*/
#ifndef MYTIME_H
#define MYTIME_H

/*用struct封装而不用class封装的原因：struct的默认访问权限是public，
class是private，在这里，我们希望定义的所有成员是public的*/
typedef struct MyTime {
	unsigned int year;
	unsigned int mouth;
	unsigned int day;
	unsigned int hour;
	unsigned int minute;
	unsigned int second;
}MyTime;
MyTime GetTime();
void DeleteTime(MyTime* time);
void ShowTime(MyTime const time);
#endif // !MYTIME_H
