#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stdlib.h>
//using namespace std;
//
////嵌套定义
//namespace zyh
//{
//	int a = 10;
//	int b = 20;
//}
//
//int main()
//{
//	////默认是std::rand
//	////标准库中rand是一个地址
//	//cout << rand << endl;
//	////命名空间zyh中rand是一个Int变量
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

////全缺省
//void func1(int a = 10, int b = 20, int c = 30)
//{
//	cout << a << "/" << b << "/" << c << endl;
//}
//
////半缺省
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

//int Add(int a, int b)
//{
//	return a + b;
//}
//
//int Add(int a, int b, int c)
//{
//	return a + b + c;
//}
//double Add(double a, double b)
//{
//	return a + b;
//}
//
//void f(int a, double b)
//{
//	cout << "f1" << endl;
//}
//
//void f(double b, int a)
//{
//	cout << "f2" << endl;
//}
//
//int main()
//{
//	f(1, 1.2);
//	f(2.2, 4);
//
//	return 0;
//}


//void Swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//
//int main()
//{
//
//	int a = 0;
//	int& b = a;
//	int c = 20;
//	//b已经引用a的情况下，不能更改为引用c
//	//以下直接看作赋值
//	b = c;
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//
//
//	/*cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;*/
//
//	return 0;
//}


//typedef int STDatatype;
//typedef struct Stack
//{
//	int* a;
//	int capacity;
//	int top;
//}ST;
//
////直接引用传参
//void STInit(ST& rs, int n = 4)
//{
//	rs.a = (STDatatype*)malloc(sizeof(STDatatype) * n);
//	rs.capacity = n;
//	rs.top = 0;
//}
//
//void STPush(ST& rs, STDatatype x)
//{
//	rs.a[rs.top] = x;
//	rs.top++;
//}
//
////int STTop(ST& rs)
////{
////	return rs.a[rs.top - 1];
////}
//
//int& STTop(ST& rs)
//{
//	return rs.a[rs.top - 1];
//}
//int main()
//{
//	ST s;
//	STInit(s,4);
//	STPush(s, 1);
//	STPush(s, 2);
//
//	STTop(s) = 4;
//
//
//	const int a = 4;
//	const int& b = a;
//
//	return 0;
//}

void f(int x)
{
	cout << "f(int x)" << endl;
}
void f(int* x)
{
	cout << "f(int* x)" << endl;
}
int main()
{
	f(0);
	f(NULL);
	f(nullptr);
	return 0;
}