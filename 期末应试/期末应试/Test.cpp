#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//默认参数写函数定义
int mul(int n1, int n2 = 2);

int mul(int n1, int n2)
{
	return n1 * n2;
}

//利用引用实现swap
void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

string myadd(string a, string b)
{
	return a + b;
}

string myadd(string a, int b)
{
	return a + to_string(b);
}

string myadd(int a, int b)
{
	return to_string(a) + to_string(b);
}

//内联函数
inline int Getmax(int a, int b, int c)
{
	return a > b ? (a > c ? a : c) : (b > c ? b : c);
}


int main()
{
	//输出
	//cout << "hello world!" <<endl;

	//输入
	//int a, b;
	//cin >> a >> b;
	//cout << a << endl << b << endl << a + b << endl;
	//cout << a << " + " << b << " = " << a + b << endl;

	//类：字符串
	//string s = "hello world";
	//cout << s << endl;
	//cout << s.length() << endl;
	//s[0] = 'H'; s[6] = 'W';
	//cout << s << endl;

	//函数默认参数
	//cout << mul(4) << endl;
	//cout << mul(4, 5) << endl;

	////引用（起别名）
	//int a = 10;
	//int& b = a, & c = b;
	//cout << a << " " << b << " " << c << endl;
	//c++; b++;
	//cout << a << endl;

	//int d = 88;
	//swap(a, d);
	//cout << "a = " << a << " d = " << d << endl;

	////函数重载
	//cout << myadd(520, 1314) << endl;
	//cout << myadd("i love", 1) << endl;
	//cout << myadd("i love", "you") << endl;

	//cout << "max = " << Getmax(1, 2, 3) << endl;
	//cout << "max = " << Getmax(55, 33, 11) << endl;


	return 0;
}