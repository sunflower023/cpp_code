#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<list>
using namespace std;

namespace zyh
{
	/*class person
	{
	public:
		void print()
		{
			cout << "void print()" << endl;
		}

	protected:
		string name;
		int age = 1;
	private:
		int middle = 0;
	};

	class student :private person
	{
	public:
		void get_age()
		{
			cout << "get age:" << age << endl;
		}
	protected:

	private:

	};*/

	/*template<class T>
	class stack :public vector<T>
	{
	public:
		void push(const T& x)
		{
			vector<T>::push_back(x);
		}



	};*/


	class person
	{
	public:
		person(const char* name = "нч")
			:_name(name)
		{
			cout << "person()" << endl;
		}

		person& operator=(const person& p)
		{
			if (this != &p)
			{
				_name = p._name;
			}
			return *this;
		}

		~person()
		{
			cout << "~person" << endl;
		}


	protected:
		string _name;
	};

	class student :public person
	{
	public:
		student(const char* name = "нч", int num = 0)
			:_num(num)
			,person(name)
		{
			cout << "student()" << endl;
		}
		
		student(const student& s)
			:person(s)
			,_num(s._num)
		{
			cout << "student(const student& s)" << endl;
		}

		student& operator=(const student& s)
		{
			if (this != &s)
			{
				person::operator=(s);
				_num = s._num;
			}
			return *this;
		}

		~student()
		{
			cout << "~student" << endl;
		}

		void print()
		{
			cout << "name:" << _name << endl;
			cout << "num:" << _num << endl;
		}

	protected:
		int _num;
	};

}


void test02()
{
	zyh::student s1("peter", 17);
	s1.print();

	zyh::student s2;
	s2 = s1;
	s2.print();
}

//void test01()
//{
//	zyh::stack<int> s1;
//	s1.push(1);
//	s1.push(2);
//	s1.push(3);
//}

int main()
{
	//zyh::student s1;
	//s1.print();
	//s1.get_age();
	//test01();
	test02();

	return 0;
}