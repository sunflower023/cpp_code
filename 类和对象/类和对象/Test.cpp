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

class Date
{
public:
	//�޲ι��캯��
	//Date()
	//{
	//	_year = 0;
	//	_month = 0;
	//	_day = 0;
	//}

	//�вι��캯��
	//Date(int year, int month, int day)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}

	//ȫȱʡ���캯��,����͵�һ���޲ι���ֻ�ܴ���һ��
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
	//����дΪDate d1();�����������壬�ֲ����ǲ��Ǻ�������
	Date d1;
	d1.Print();
	Date d2(2024, 1, 1);
	d2.Print();

	return 0;
}