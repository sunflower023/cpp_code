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


//类
class book
{
private:
	string name;
	int count = 0;
public:
	//构造函数的重载
	book()
	{
		name = "NULL";
	}

	book(string name)
	{
		this->name = name;
	}
	~book() {}

	string get_name()
	{
		return name;
	}

	int get_count()
	{
		return count;
	}

	void set_count(const int x)
	{
		count = x;
	}

};

//class human
//{
//private:
//public:
//	human() {};
//	~human() {};
//	virtual void say() { cout << "i am human" << endl; }
//};

//class student :public human
//{
//private:
//public:
//	virtual void say() { cout << "i am student" << endl; }
//};
//
//class college :public student
//{
//private:
//public:
//	void say() { cout << "i am college" << endl; }
//};
//
//
//void test01()
//{
//	human man;
//	man.say();
//	student s;
//	s.say();
//	college c;
//	c.say();
//}


class shape
{
public:
	//纯虚函数声明
	virtual float getC() = 0;
	virtual float getS() = 0;
};

class circle :public shape
{
private:
	float r;
public:
	circle(float x)
	{
		r = x;
	}

	float getC()
	{
		return 2 * 3.14 * r;
	}
	float getS()
	{
		return 3.14 * r * r;
	}
};

void test02()
{
	circle c1(3.0f);
	cout << c1.getC() << endl;
	cout << c1.getS() << endl;
}

class human
{
public:
	virtual void say() = 0;
};


//多态的实现
class man :public human
{
public:
	void say() { cout << "man!" << endl; }
};

class woman :public human
{
public:
	void say() { cout << "woman!" << endl; }
};

void func(human* h)
{
	h->say();
}

void test03()
{
	man m1, m2;
	woman w1, w2;
	func(&m1);
	func(&w2);
}


//模版
template<typename T>
T add(T a, T b)
{
	return a + b;
}


void test04()
{
	cout << add<int>(5, 6) << endl;
	cout << add<float>(4.5f, 8.8f) << endl;
	cout << add<string>("hello ", "world") << endl;
}


class student
{
private:
	string name;
	int score;
public:
	student(string n, int s) { name = n, score = s; }

	friend ostream& operator << (ostream& o, student s);

};

ostream& operator << (ostream& o, student s)
{
	cout << s.name << " " << s.score << endl;
	return o;
}

void test05()
{
	student s("zyh", 100);
	cout << s << endl;
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

	/*book book1("c++");
	cout << book1.get_name() << endl;
	book1.set_count(55);
	cout << book1.get_count() << endl;*/

	//test01();
	//test02();
	//test03();
	//test04();
	test05();
	return 0;
}