#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string.h>
using namespace std;

//class person
//{
//public:
//
//	//��ķ�������Ա������
//	void say();
//	void Init(const char* name, int age, const char* sex)
//	{
//		strcpy(_name, name);
//		_age = age;
//		strcpy(_sex,sex);
//	}
//
//private:
//	//������ԣ���Ա������
//	char _name[20];
//	int _age;
//	char _sex[5];
//};
//
//
//void person::say()
//{
//	cout << "����"<<_name << endl;
//	cout << "�ҵ�������"<<_age << endl;
//	cout << "����"<<_sex<<"��" << endl;
//}
//
//
//int main()
//{
//	person p1;
//	p1.Init("����", 18, "��");
//	person p2;
//	p2.Init("����", 20, "��");
//	
//	p1.say();
//	p2.say();
//	return 0;
//}

//class Date
//{
//public:
//	//�޲ι��캯��
//	//Date()
//	//{
//	//	_year = 0;
//	//	_month = 0;
//	//	_day = 0;
//	//}
//
//	//�вι��캯��
//	//Date(int year, int month, int day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	//ȫȱʡ���캯��,����͵�һ���޲ι���ֻ�ܴ���һ��
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
//	//����дΪDate d1();�����������壬�ֲ����ǲ��Ǻ�������
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

////ǰ������������A����ʶ��B�����
//class B;
//
//class A
//{
//	//��Ԫ����
//	friend void func(const A& aa, const B& bb);
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//
//};
//
//class B
//{
//	//��Ԫ����
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
	//return_n()������������
	return_n().ret(10);

	return 0;
}