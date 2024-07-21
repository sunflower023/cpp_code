#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1("hello world          ");
	cout << s1.size() << "/" << s1.capacity() << endl;
	return 0;
}