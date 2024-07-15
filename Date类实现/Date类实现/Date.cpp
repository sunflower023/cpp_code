#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"
bool Date::CheckDate()const
{
	if (_month < 1 || _month>13 || _day<1 || _day>Getmonthday(_year, _month))
	{
		return false;
	}
	else
	{
		return true;
	}
}

Date::Date(int year, int month, int day)
	:_year(year), _month(month), _day(day) 
{
	if (!(CheckDate()))
	{
		cout << "日期非法";
		cout << *this;
	}
}

Date::~Date()
{
	_year = _month = _day = 0;
}

void Date::Print()
{
	cout << _year << "/" << _month << "/" << _day << endl;
}

Date::Date(const Date& d)
{
	this->_year = d._year;
	this->_month = d._month;
	this->_day = d._day;
}

Date Date::operator+(int day)const
{
	//+不改变对象本身，因此只能返回tmp，而tmp又是临时变量
	//只能传值返回
	Date tmp = *this;
	tmp += day;
	return tmp;
}

Date& Date::operator+=(int day)
{
	//+=改变的是对象本身，因此要引用返回减少拷贝
	_day += day;
	while (_day > Getmonthday(_year, _month))
	{
		_day -= Getmonthday(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}

//在Date类中的一个函数，是Date的一部分，私有成员都能访问
//哪怕是创建的临时对象tmp也能直接访问其中的_year...


Date Date::operator-(int day)const
{
	Date tmp = *this;
	tmp._day -= day;
	while (tmp._day <= 0)
	{
		--tmp._month;
		if (tmp._month == 0)
		{
			tmp._month = 12;
			--tmp._year;
		}
		//若getmonthday没加const就是权限放大会报错
		//因为此时此函数有const，则默认是const Date* const this
		//拷贝给tmp，但tmp是const Date* ，getmonthday是date*，权限方法报错
		tmp._day += Getmonthday(tmp._year, tmp._month);
	}
	return tmp;
}

Date& Date::operator-=(int day)
{
	*this = *this - day;
	return *this;
}

bool Date::operator<(const Date& d) const
{
	if (this->_year < d._year)
	{
		return true;
	}
	else if (this->_year == d._year)
	{
		if (this->_month < d._month)
		{
			return true;
		}
		else if (this->_month == d._month)
		{
			if (this->_day < d._day)
			{
				return true;
			}
		}
	}
	return false;
}
bool Date::operator<=(const Date& d) const
{
	return ((*this < d) || (*this == d));
}
bool Date::operator>(const Date& d) const
{
	return !(*this <= d);
}
bool Date::operator>=(const Date& d) const
{
	return !(*this < d);
}
bool Date::operator==(const Date& d) const
{
	if ((this->_year == d._year) && (this->_month == d._month) && (this->_day == d._day))
	{
		return true;
	}

	return false;
}
bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

// 前置++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
// 后置++
Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;
	return tmp;
}
// 后置--
Date Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;
	return tmp;
}
// 前置--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

int Date::operator-(const Date& d)const
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int cnt = 0;
	while (min < max)
	{
		++min;
		++cnt;
	}

	return cnt;
}

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "/" << d._month << "/" << d._day << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	while (1)
	{
		cout << "请依次输入年月日" << endl;
		in >> d._year >> d._month >> d._day;
		if (!d.CheckDate())
		{
			cout << "非法日期";
			cout << d;
			cout << "请重新输入" << endl;
		}
		else
		{
			break;
		}
	}

	return in;
}
