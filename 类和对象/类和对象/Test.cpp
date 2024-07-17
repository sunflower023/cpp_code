#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string.h>
using namespace std;

//class person
//{
//public:
//
//	//类的方法（成员函数）
//	void say();
//	void Init(const char* name, int age, const char* sex)
//	{
//		strcpy(_name, name);
//		_age = age;
//		strcpy(_sex,sex);
//	}
//
//private:
//	//类的属性（成员变量）
//	char _name[20];
//	int _age;
//	char _sex[5];
//};
//
//
//void person::say()
//{
//	cout << "我是"<<_name << endl;
//	cout << "我的年龄是"<<_age << endl;
//	cout << "我是"<<_sex<<"的" << endl;
//}
//
//
//int main()
//{
//	person p1;
//	p1.Init("张三", 18, "男");
//	person p2;
//	p2.Init("李四", 20, "男");
//	
//	p1.say();
//	p2.say();
//	return 0;
//}

class Date
{
public:
	//无参构造函数
	//Date()
	//{
	//	_year = 0;
	//	_month = 0;
	//	_day = 0;
	//}

	//有参构造函数
	//Date(int year, int month, int day)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}

	//全缺省构造函数,这个和第一个无参构造只能存在一个
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	//不能写为Date d1();这样会有歧义，分不清是不是函数声明
	Date d1;
	d1.Print();
	Date d2(2024, 1, 1);
	d2.Print();

	return 0;
}