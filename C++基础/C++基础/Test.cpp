#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stdlib.h>
//using namespace std;
//
////Ƕ�׶���
//namespace zyh
//{
//	int a = 10;
//	int b = 20;
//}
//
//int main()
//{
//	////Ĭ����std::rand
//	////��׼����rand��һ����ַ
//	//cout << rand << endl;
//	////�����ռ�zyh��rand��һ��Int����
//	//cout << zyh::rand << endl;
//
//	cout << zyh::a << endl;
//	cout << zyh::b << endl;
//
//	return 0;
//}

using std::cout;
using std::endl;
using std::cin;

//int main()
//{
//    int a;
//    double b;
//    char c;
//    cin >> a;
//    cin >> b;
//    cin >> c;
//
//    cout << a << "/" << b << "/" << c << endl;
//
//    return 0;
//}

////ȫȱʡ
//void func1(int a = 10, int b = 20, int c = 30)
//{
//	cout << a << "/" << b << "/" << c << endl;
//}
//
////��ȱʡ
//void func2(int a, int b = 0, int c = 0)
//{
//	cout << a << "/" << b << "/" << c << endl;
//}
//
//int main()
//{
//	func1();
//	func1(666);
//	func1(1, 2, 3);
//
//	func2(6);
//	func2(6, 7, 8);
//	return 0;
//}

int Add(int a, int b)
{
	return a + b;
}

int Add(int a, int b, int c)
{
	return a + b + c;
}
double Add(double a, double b)
{
	return a + b;
}

void f(int a, double b)
{
	cout << "f1" << endl;
}

void f(double b, int a)
{
	cout << "f2" << endl;
}

int main()
{
	f(1, 1.2);
	f(2.2, 4);

	return 0;
}