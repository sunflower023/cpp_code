#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

void test01()
{
	Date d1(2024, 7, 12);
	d1.Print();
	//d1.operator+=(100);
	d1 += 100;
	d1.Print();

	Date d2;
	d2 = d1 + 1400;
	d2.Print();
}

void test02()
{
	Date d1(2024, 7, 31);
	Date d2(2024, 7, 1);
	Date d3;
	d1 -= 30;
	d1.Print();
}

void test03()
{
	Date d1(2024, 7, 16);
	Date d2(2024, 7, 14);
	cout << (d1 >= d2) << endl;
	cout << (d1 <= d2) << endl;
}

void test04()
{
	Date d1(2024, 8, 6);
	Date d2(2024, 7, 14);
	//cout << (d1 - d2) << endl;
	cout << d1;
	cout << d1 << d2;
}

void test05()
{
	Date d1, d2;
	cin >> d1 >> d2;
	cout << d1 << d2;
	cout << d1 - d2 << endl;
}
int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	test05();
	return 0;
}