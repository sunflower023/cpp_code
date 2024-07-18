#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<string>
using namespace std;

class Date
{
public:
    Date(string d)
    {
        _year = (d[0] - '0') * 1000 + (d[1] - '0') * 100 + (d[2] - '0') * 10 + (d[3] - '0');
        _month = (d[4] - '0') * 10 + (d[5] - '0');
        _day = (d[6] - '0') * 10 + (d[7] - '0');
    }

    int Getmonthday(int year, int month)
    {
        static int days[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        {
            return 29;
        }
        return days[month];
    }

    void Print()
    {
        cout << _year << "/" << _month << "/" << _day << endl;
    }

    Date& operator++()
    {
        ++_day;
        if (_day > Getmonthday(_year, _month))
        {
            ++_month;
            _day = 1;
            if (_month == 13)
            {
                _month = 1;
                ++_year;
            }
        }
        return *this;
    }

    bool operator==(const Date& d)const
    {
        if (_year == d._year && _month == d._month && _day == d._day)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator>(const Date& d)const
    {
        if (_year > d._year)
        {
            return true;
        }
        else if (_year == d._year)
        {
            if (_month > d._month)
            {
                return true;
            }
            else if (_month == d._month)
            {
                if (_day > d._day)
                {
                    return true;
                }
            }
        }
        return false;
    }

    int operator-(Date& d)
    {
        Date max = *this;
        Date min = d;

        if (d > *this)
        {
            max = d;
            min = *this;
        }

        int sum = 1;
        while (!(max == min))
        {
            ++min;
            ++sum;
        }

        return sum;
    }

private:
    int _year;
    int _month;
    int _day;
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    Date d1(s1);
    Date d2(s2);

    cout << d1 - d2 << endl;
    return 0;
}