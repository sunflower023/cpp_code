#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<vector>
//using namespace std;


//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param numRows int整型 numRows表示行数
//     * @return int整型vector<vector<>>
//     */
//    vector<vector<int> > generate(int numRows) {
//        // write code here
//        
//        vector < vector<int>> ret;
//        for (int i = 0; i < numRows; i++)
//        {
//            vector<int> r(i + 1, 0);
//            ret.push_back(r);
//        }
//        
//        for (int i = 0; i < numRows; i++)
//        {
//            ret[i][0] = 1;
//            ret[i][i] = 1;
//        }
//        for (int i = 2; i < numRows; i++)
//        {
//            for (int j = 1; j < i; j++)
//            {
//                ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
//            }
//        }
//
//        for (int i = 0; i < numRows; i++)
//        {
//            for (int j = 0; j < numRows; j++)
//            {
//                cout << ret[i][j] << endl;
//            }
//        }
//        return ret;
//    }
//};
//
//int main()
//{
//
//    Solution s;
//    s.generate(1);
//    return 0;
//}

//class Date
//{
//public:
//	int GetMonthDay(int year, int month)
//	{
//		int _month[13] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
//		if (month == 2 && ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
//		{
//			return (_month[2] + 1);
//		}
//		else
//		{
//			return _month[month];
//		}
//	}
//
//	Date(int year = 1900, int month = 1, int day = 1)
//		:_year(year) 
//		,_month(month) 
//		,_day(day)
//	{}
//
//	Date(const Date& d)
//		:_year(d._year)
//		,_month(d._month)
//		,_day(d._day)
//	{}
//
//	Date& operator=(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		return *this;
//	}
//
//	Date& operator+=(int day)
//	{
//		_day += day;
//		while (_day > GetMonthDay(_year,_month))
//		{
//			_day -= GetMonthDay(_year, _month);
//			_month++;
//			if (_month == 13)
//			{
//				_month = 1;
//				_year++;
//			}
//		}
//		return *this;
//	}
//
//	Date operator+(int day)
//	{
//		Date tmp(*this);
//		tmp._day += day;
//		while (tmp._day > GetMonthDay(tmp._year, tmp._month))
//		{
//			tmp._day -= GetMonthDay(tmp._year, tmp._month);
//			tmp._month++;
//			if (tmp._month == 13)
//			{
//				tmp._month = 1;
//				tmp._year++;
//			}
//		}
//		return tmp;
//	}
//
//	Date operator-(int day)
//	{
//		Date tmp(*this);
//		tmp._day -= day;
//		while (tmp._day <= 0)
//		{
//			tmp._day += GetMonthDay(tmp._year, tmp._month);
//			tmp._month--;
//			if (tmp._month == 0)
//			{
//				tmp._month = 12;
//				tmp._year--;
//			}
//		}
//		return tmp;
//	}
//
//	Date& operator-=(int day)
//	{
//		_day -= day;
//		while (_day <= 0)
//		{
//			_day += GetMonthDay(_year, _month);
//			_month--;
//			if (_month == 0)
//			{
//				_month = 12;
//				_year--;
//			}
//		}
//		return *this;
//	}
//
//	bool operator==(const Date& d)
//	{
//		return ((_year == d._year) && (_month == d._month)
//			&& (_day == d._day));
//	}
//
//	friend ostream& operator<<(ostream& out, const Date& d);
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//};
//
//ostream& operator<<(ostream& out, const Date& d)
//{
//	cout << d._year << "-" << d._month << "-" << d._day << endl;
//	return out;
//}
//
//
//int main()
//{
//	Date d1(2020, 2, 20);
//	d1 += (-10);
//	Date d2(d1 + 100);
//	cout << d1 << d2;
//	cout << (d1 == d2) << endl;
//	return 0;
//}

#include<iostream>
#include<cstring>
#include<vector>
#include<functional>
using namespace std;

template<class T,class Container = std::vector<int>,class Compare = less<T>>
class priority_queue
{
public:
	priority_queue() = default;
	template<class InputIterator>
	priority_queue(InputIterator first, InputIterator last)
	{
		while (first != last)
		{
			push(*first);
			++first;
		}
	}
	bool empty() const
	{
		return c.size() == 0;
	}
	size_t size()const
	{
		return c.size();
	}
	const T& top()const
	{
		return c[0];
	}
	void push(const T& x)
	{
		c.push_back(x);
		
	}
	void pop()
	{

	}

private:
	void AdjustUp(int child)
	{
		int parent = (child - 1) / 2;
		while (child >= 0)
		{
			if (Com(c[parent], c[child]))
			{
				swap(c[parent], c[child]);
			}
			child = parent;
			parent = (parent - 1) / 2;
		}
	}
	void AdjustDown(int child)
	{

	}
private:
	Container c;
	Compare Com;
};