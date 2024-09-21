#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//class Person
//{
//public:
//	//虚函数
//	virtual void BuyTicket() { cout << "买票-全价"; }
//};
//
//
//int main()
//{
//
//
//	return 0;
//}

//class A
//{
//public:
//	virtual ~A()
//	{
//		cout << "~A()" << endl;
//	}
//};
//
//class B :public A
//{
//public:
//	//不加virtual也依旧构成重写
//	~B()
//	{
//		cout << "~B()" << endl;
//		delete _p;
//	}
//protected:
//	int* _p = new int[10];
//};
//
//int main()
//{
//	A* p1 = new A;
//	A* p2 = new B;
//	delete p1;
//	delete p2;
//}

//class Base
//{
//public:
//    virtual void Func1()
//    {
//        cout << "Func1()" << endl;
//    }
//
//    virtual void Func2()
//    {
//        cout << "Func2()" << endl;
//    }
//private:
//    int _base = 1;
//};
//
//class Derive :public Base
//{
//public:
//    virtual void Func1()
//    {
//        cout << "Func111()" << endl;
//    }
//
//    //virtual void Func2()
//    //{
//    //    cout << "Func222()" << endl;
//    //}
//protected:
//    int _derive = 2;
//};
//
//int main()
//{
//    Base b;
//    Derive d;
//
//    return 0;
//}

//class Person {
//public:
//    virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//
//class Student : public Person {
//public:
//    virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//
//void Func(Person& p)
//{
//    p.BuyTicket();
//}
//
//int main()
//{
//    Person man;
//    Func(man);
//
//    Student Jack;
//    Func(Jack);
//
//    return 0;
//}

//class A
//{
//public:
//	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
//	virtual void test() { func(); }
//};
//
//class B : public A
//{
//public:
//	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
//	//继承了父类A的test函数
//	//void test() { func(); }
//};
//
//int main(int argc, char* argv[])
//{
//	B* p = new B;
//	p->test();
//
//	return 0;
//}

//class A
//
//{
//
//public:
//
//    virtual void f()
//
//    {
//
//        cout << "A::f()" << endl;
//
//    }
//
//};
//
//
//
//class B : public A
//
//{
//
//private:
//
//    virtual void f()
//
//    {
//
//        cout << "B::f()" << endl;
//
//    }
//
//};
//
//int main()
//{
//    A* tp = (A*)new B;
//    tp->f();
//
//    return 0;
//}

//class A
//
//{
//
//public:
//
//    A() :m_iVal(0) { test(); }
//
//    virtual void func() { std::cout << m_iVal << " "; }
//
//    void test() { func(); }
//
//public:
//
//    int m_iVal;
//
//};
//
//
//
//class B : public A
//
//{
//
//public:
//
//    B() { test(); }
//
//    virtual void func()
//
//    {
//
//        ++m_iVal;
//
//        std::cout << m_iVal << " ";
//
//    }
//
//};
//
//
//
//int main(int argc, char* argv[])
//
//{
//
//    A* p = new B;
//
//    p->test();
//
//    return 0;
//
//}

//class A { public: void test(float a) { cout << a; } }; 
//class B :public A { public: void test(int b) { cout << b; } }; 
//void main() { A* a = new A; B* b = new B; a = b; a->test(1.1); }

//class A
//{
//public:
//    virtual void f()
//    {
//        cout << "A::f()" << endl;
//    }
//};
//
//class B : public A
//{
//private:
//    virtual void f()
//    {
//        cout << "B::f()" << endl;
//    }
//};
//
//int main()
//{
//    A* pa = (A*)new B;
//    pa->f();
//}

class A
{
public:
	A() :m_iVal(0) { test(); }
	virtual void func() { std::cout << m_iVal << " "; }
	void test() { func(); }
public:
	int m_iVal;
};

class B : public A
{
public:
	B() { test(); }
	virtual void func()
	{
		++m_iVal;
		std::cout << m_iVal << " ";
	}
};

int main(int argc, char* argv[])
{
	A* p = new B;
	p->test();
	return 0;
}