#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//Ĭ�ϲ���д��������
int mul(int n1, int n2 = 2);

int mul(int n1, int n2)
{
	return n1 * n2;
}

//��������ʵ��swap
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

//��������
inline int Getmax(int a, int b, int c)
{
	return a > b ? (a > c ? a : c) : (b > c ? b : c);
}


int main()
{
	//���
	//cout << "hello world!" <<endl;

	//����
	//int a, b;
	//cin >> a >> b;
	//cout << a << endl << b << endl << a + b << endl;
	//cout << a << " + " << b << " = " << a + b << endl;

	//�ࣺ�ַ���
	//string s = "hello world";
	//cout << s << endl;
	//cout << s.length() << endl;
	//s[0] = 'H'; s[6] = 'W';
	//cout << s << endl;

	//����Ĭ�ϲ���
	//cout << mul(4) << endl;
	//cout << mul(4, 5) << endl;

	////���ã��������
	//int a = 10;
	//int& b = a, & c = b;
	//cout << a << " " << b << " " << c << endl;
	//c++; b++;
	//cout << a << endl;

	//int d = 88;
	//swap(a, d);
	//cout << "a = " << a << " d = " << d << endl;

	////��������
	//cout << myadd(520, 1314) << endl;
	//cout << myadd("i love", 1) << endl;
	//cout << myadd("i love", "you") << endl;

	//cout << "max = " << Getmax(1, 2, 3) << endl;
	//cout << "max = " << Getmax(55, 33, 11) << endl;


	return 0;
}