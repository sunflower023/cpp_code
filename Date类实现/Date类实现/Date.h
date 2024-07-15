#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

class Date
{
public:
	bool CheckDate()const;

	Date(int year = 1900, int month = 1, int day = 1);
	~Date();
	Date(const Date& d);

	void Print();

	//在类中定义的默认是Inline
	int Getmonthday(int year, int month)const
	{
		//频繁调用该数组，避免频繁创建，直接设置为静态区
		static int monthday[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			return 29;
		}
		return monthday[month];
	}

	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;

	// 前置++
	Date& operator++();
	// 后置++
	Date operator++(int);
	// 后置--
	Date operator--(int);
	// 前置--
	Date& operator--();

	// d1 += 天数
	Date& operator+=(int day);
	Date operator+(int day)const;
	// d1 -= 天数
	Date& operator-=(int day);
	Date operator-(int day)const;
	//d1 - d2
	int operator-(const Date& d)const;

	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

private:
	int _year;
	int _month;
	int _day;
};