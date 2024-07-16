#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string.h>
using namespace std;

class person
{
public:

	//类的方法（成员函数）
	void say();
	void Init(const char* name, int age, const char* sex)
	{
		strcpy(_name, name);
		_age = age;
		strcpy(_sex,sex);
	}

private:
	//类的属性（成员变量）
	char _name[20];
	int _age;
	char _sex[5];
};


void person::say()
{
	cout << "我是"<<_name << endl;
	cout << "我的年龄是"<<_age << endl;
	cout << "我是"<<_sex<<"的" << endl;
}


int main()
{
	person p1;
	p1.Init("张三", 18, "男");
	person p2;
	p2.Init("李四", 20, "男");
	
	p1.say();
	p2.say();
	return 0;
}