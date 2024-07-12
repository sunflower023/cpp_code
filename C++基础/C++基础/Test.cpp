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
int main()
{
    int a;
    double b;
    char c;
    cin >> a;
    cin >> b;
    cin >> c;

    cout << a << "/" << b << "/" << c << endl;

    return 0;
}