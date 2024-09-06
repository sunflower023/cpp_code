#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<algorithm>
using namespace std;

//int main()
//{
	//vector<int> v1;//无参构造
	//vector<int> v2(3, 1);//构造并初始化5个1
	//vector<int> v3(v2);//拷贝构造
	//
	//string s("abc");
	//vector<char> v4(s.begin(), s.end());//使用迭代器构造

	//string s1("abcdef");
	//vector<char> v(s1.begin(), s1.end());//使用迭代器构造

	////使用正向迭代器,正向遍历
	//vector<char>::iterator it = v.begin();
	//while (it != v.end())
	//{
	//	cout << *it << " ";
	//	it++;
	//}
	//cout << endl;

	////使用反向迭代器,反向遍历
	//vector<char>::reverse_iterator rit = v.rbegin();
	//while (rit != v.rend())
	//{
	//	cout << *rit << " ";
	//	rit++;//注意使用的是++而不是--
	//}
	////迭代器++都是向前移动，而反向迭代器的“前”指的就是从后向前


	/*vector<int> v(10, 1);
	cout << v.capacity() << endl;
	v.reserve(20);
	cout << v.capacity() << endl;
	v.reserve(5);
	cout << v.capacity() << endl;*/

	/*vector<int> v(10, 1);
	cout << v.capacity() << "/" << v.size() << endl;
	v.resize(5);
	cout << v.capacity() << "/" << v.size() << endl;
	v.resize(20);
	cout << v.capacity() << "/" << v.size() << endl;*/

	/*vector<int> v(5, 0);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	v.push_back(1);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	v.pop_back();
	for (auto e : v)
	{
		cout << e << " ";
	}*/

	//vector<int> v;
	////构造一个0,1,2,3,4的vector容器
	//for (size_t i = 0; i < 5; i++)
	//{
	//	v.push_back(i);
	//}
	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	////找到其中3的位置,在3之前插入0
	////注意：find不在vector类里
	//vector<int>::iterator it = find(v.begin(),v.end(),3);
	//v.insert(it, 0);
	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	////将除了最后一个元素都删除
	//v.erase(v.begin(), v.end() - 1);
	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	//vector<int> a(10, 1);
	//vector<int> b(10, 0);
	//for (auto e : a)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	//for (auto e : b)
	//{
	//	cout << e << " ";
	//}
	//cout << endl << "交换后" << endl;

	////进行交换
	//a.swap(b);
	//for (auto e : a)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	//for (auto e : b)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

//}
//int main(int argc, char* argv[])
//
//{
//
//	string strText = "How are you?";
//
//	string strSeparator = " ";
//
//	string strResult;
//
//	int size_pos = 0;
//
//	int size_prev_pos = 0;
//
//	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)
//
//	{
//
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//
//		cout << strResult << " ";
//
//		size_prev_pos = ++size_pos;
//
//	}
//
//	if (size_prev_pos != strText.size())
//
//	{
//
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//
//		cout << strResult << " ";
//
//	}
//
//	cout << endl;
//
//	return 0;
//
//}

//int main()
//{
	/*vector<int> v;
	for (size_t i = 1; i < 5; i++)
	{
		v.push_back(i);
	}
	auto pos = find(v.begin(), v.end(), 3);
	v.insert(pos, 30);
	v.insert(pos, 40);*/

	//vector<int> v{ 1,2,3,4,5,6 };
	//auto it = v.begin();

	////将有效元素增加到20个，多余的用0填充，操作期间底层扩容
	//v.resize(20, 0);
	////改变容量大小为20，可能会进行扩容而引起底层改变
	//v.reserve(20);

	////插入元素，可能会进行扩容
	//v.push_back(8);
	//v.insert(v.begin(), 0);

	////给vector重新赋值，可能会引起底层容量改变
	//v.assign(20, 9);

	////以上操作都会导致先前的迭代器it失效
	////解决方法就是完成上述操作后更新迭代器it
	////若在此不更新就会出错
	//it = v.begin();
	//while (it != v.end())
	//{
	//	cout << *it << " ";
	//	it++;
	//}
	//cout << endl;

	//vector<int> v{ 1,2,3,4 };
	//auto pos = find(v.begin(), v.end(), 3);//找到3的位置
	//v.erase(pos);//删除3
	//cout << *pos << endl;//再次解引用就会报错

	//vector<int> v{ 1, 2, 3, 4, 4, 6};
	//auto it = v.begin();
	//while (it != v.end())
	//{
	//	if (*it % 2 == 0)
	//	{
	//		//erase返回的是删除位置的下一个元素的位置的迭代器
	//		//这里就直接利用erase的返回值进行更新
	//		it = v.erase(it);
	//	}
	//	else
	//	{
	//		it++;
	//	}
	//}
	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	

	//return 0;
//}

//int main()
//{
	//list<int> l1;//无参构造
	//list<int> l2(10, 1);//用10个1初始化链表

	//vector<int> v{ 1,2,3,4,5 };
	//list<int> l3(v.begin(), v.end());//用迭代器区间初始化

	//head 1 2 3
	/*list<int> l{ 1,2,3};
	auto it1 = l.begin();
	auto it2 = --l.end();
	auto it3 = l.rbegin();
	auto it4 = --l.rend();

	cout << *it1 << endl;
	cout << *it2 << endl;
	cout << *it3 << endl;
	cout << *it4 << endl;*/

	//vector<int> v{ 1,2,3,4,5,6,7,8 };
	//list<int> l(v.begin(), v.end());
	////list<int> l{ 1,2,3,4,5,6,7,8 };

	//for (auto e : l)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	/*list<int> l{ 1,2,3,4,5,6,7,8,9 };
	auto it = l.begin();
	while (it != l.end())
	{
		if (*it % 2 == 0)
		{
			it = l.erase(it);
		}
		else
		{
			++it;
		}
	}
	for (auto e : l)
	{
		cout << e << " ";
	}
	cout << endl;*/


//	return 0;
//}

//namespace zyh
//{
//	//本质是一个类
//	class Person
//	{
//	public:
//		bool operator()(int x, int y)
//		{
//			return x < y;
//		}
//	};
//
//
//
//
//
//	class Student : public Person
//	{
//	public:
//		int _stuid;
//	};
//}
//
//int main()
//{
//	//zyh::less fun;
//	//cout << fun(1, 2) << endl;
//
//	//升序写法
//	vector<int> v{ 1,2,3,4,5 };
//	sort(v.begin(), v.end());
//	sort(v.begin(), v.end(), greater<int>());
//
//
//	priority_queue<int, vector<int>, greater<int>> p;
//	p.push(1);
//	p.push(2);
//	p.push(3);
//	p.push(4);
//	p.push(5);
//	p.push(6);
//
//	while (!p.empty())
//	{
//		cout << p.top() << " ";
//		p.pop();
//	}
//	cout << endl;
//
//	return 0;
//}


//class person
//{
//public:
//	person(const char* name = "Jack")
//		:_name(name)
//	{
//		cout << "person()" << endl;
//	}
//
//	person(const person& p)
//		:_name(p._name)
//	{
//		cout << "person(const person& p)" << endl;
//	}
//
//	person& operator=(const person& p)
//	{
//		cout << "person operator=()" << endl;
//		if (this != &p)
//		{
//			_name = p._name;
//		}
//		return *this;
//	}
//
//	~person()
//	{
//		cout << "~person" << endl;
//	}
//protected:
//	string _name;
//};
//
//class student :public person
//{
//public:
//	student(const char* name,int num)
//		:person(name)
//		,_num(num)
//	{
//		cout << "student()" << endl;
//	}
//
//	student(const student& s)
//		:person(s)
//		,_num(s._num)
//	{
//		cout << "student(const student& s)" << endl;
//	}
//
//	student& operator=(const student& s)
//	{
//		cout << "student operator=()" << endl;
//		if (this != &s)
//		{
//			person::operator=(s);
//			_num = s._num;
//		}
//		return *this;
//	}
//
//	~student()
//	{
//		cout << "~student()" << endl;
//	}
//
//protected:
//	int _num;//学号
//};
//
//int main()
//{
//	student s1("Peter", 18);
//	student s2(s1);
//	s1 = s2;
//	return 0;
//}

class A
{
public:
	int _a1;
	friend void print(B& bb);
protected:
	int _a2;
};

class B:public A
{
public:
	int _b1;
protected:
	int _b2;
};

void print(B& bb)
{
	cout << bb._a1;
	cout << bb._a2;
}