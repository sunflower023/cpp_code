#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string.h>
using namespace std;

class person
{
public:

	//��ķ�������Ա������
	void say();
	void Init(const char* name, int age, const char* sex)
	{
		strcpy(_name, name);
		_age = age;
		strcpy(_sex,sex);
	}

private:
	//������ԣ���Ա������
	char _name[20];
	int _age;
	char _sex[5];
};


void person::say()
{
	cout << "����"<<_name << endl;
	cout << "�ҵ�������"<<_age << endl;
	cout << "����"<<_sex<<"��" << endl;
}


int main()
{
	person p1;
	p1.Init("����", 18, "��");
	person p2;
	p2.Init("����", 20, "��");
	
	p1.say();
	p2.say();
	return 0;
}