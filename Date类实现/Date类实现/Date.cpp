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
		cout << "���ڷǷ�";
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
	//+���ı���������ֻ�ܷ���tmp����tmp������ʱ����
	//ֻ�ܴ�ֵ����
	Date tmp = *this;
	tmp += day;
	return tmp;
}

Date& Date::operator+=(int day)
{
	//+=�ı���Ƕ��������Ҫ���÷��ؼ��ٿ���
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

//��Date���е�һ����������Date��һ���֣�˽�г�Ա���ܷ���
//�����Ǵ�������ʱ����tmpҲ��ֱ�ӷ������е�_year...


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
		//��getmonthdayû��const����Ȩ�޷Ŵ�ᱨ��
		//��Ϊ��ʱ�˺�����const����Ĭ����const Date* const this
		//������tmp����tmp��const Date* ��getmonthday��date*��Ȩ�޷�������
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

// ǰ��++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
// ����++
Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;
	return tmp;
}
// ����--
Date Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;
	return tmp;
}
// ǰ��--
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
		cout << "����������������" << endl;
		in >> d._year >> d._month >> d._day;
		if (!d.CheckDate())
		{
			cout << "�Ƿ�����";
			cout << d;
			cout << "����������" << endl;
		}
		else
		{
			break;
		}
	}

	return in;
}
