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