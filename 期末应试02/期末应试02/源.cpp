#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class person
{
public:
	int a = 10, b = 20;

	person(int x, int y)
	{
		a = x, b = y;
	}

	//ͨ����Ա��������
	//person operator+(person& o)
	//{
	//	person p3(0,0);
	//	p3.a = this->a + o.a;
	//	p3.b = this->b + o.b;
	//	return p3;
	//}

	//��Ԫ
	//friend ostream& operator<<(ostream& o, person& p);

};

//ͨ��ȫ�ֺ�������
person operator+(person& p1, person& p2)
{
	person p3(0,0);
	p3.a = p1.a + p2.a;
	p3.b = p1.b + p2.b;
	return p3;
}

//����<<ֻ����ȫ��
ostream& operator<<(ostream& o, person& p)
{
	cout << "a = " << p.a << " b = " << p.b << endl;
	return o;
}

void test01()
{
	person p1(11,11), p2(22,22);
	person p3 = p1 + p2;
	std::cout << p3.a << " " << p3.b << std::endl;

	cout << p3 << endl;
}

int main()
{
	test01();
}