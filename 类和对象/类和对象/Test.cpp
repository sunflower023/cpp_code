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

//class Date
//{
//public:
//	//无参构造函数
//	//Date()
//	//{
//	//	_year = 0;
//	//	_month = 0;
//	//	_day = 0;
//	//}
//
//	//有参构造函数
//	//Date(int year, int month, int day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	//全缺省构造函数,这个和第一个无参构造只能存在一个
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	//不能写为Date d1();这样会有歧义，分不清是不是函数声明
//	Date d1;
//	d1.Print();
//	Date d2(2024, 1, 1);
//	d2.Print();
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 2, int month = 2, int day = 2)
//		:_year(year)
//		, _month(month)
//		,_day(day)
//	{}
//
//	int _year = 1;
//	int _month = 1;
//	int _day = 1;
//};
//int main()
//{
//	Date d1(2024, 7);
//	cout << d1._year << "/" << d1._month << "/" << d1._day << endl;
//	return 0;
//}

////前置声明，否则A不认识有B这个类
//class B;
//
//class A
//{
//	//友元声明
//	friend void func(const A& aa, const B& bb);
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//
//};
//
//class B
//{
//	//友元声明
//	friend void func(const A& aa, const B& bb);
//private:
//	int _b3 = 3;
//	int _b4 = 4;
//};
//
//void func(const A& aa, const B& bb)
//{
//	cout << aa._a1 << endl;
//	cout << bb._b3 << endl;
//}
//
//int main()
//{
//	A aa;
//	B bb;
//	func(aa, bb);
//	return 0;
//}


class return_n
{
public:
	int ret(int n)
	{
		return n;
	}
};

int main()
{
	//return_n()就是匿名对象
	return_n().ret(10);

	return 0;
}