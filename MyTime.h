/*
* ʱ����Ϣ
*/
#ifndef MYTIME_H
#define MYTIME_H

/*��struct��װ������class��װ��ԭ��struct��Ĭ�Ϸ���Ȩ����public��
class��private�����������ϣ����������г�Ա��public��*/
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
