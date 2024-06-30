#include<iostream>
#include<string> 
using namespace std;

class time
{
	private:
		int year;
		int month;
		int day;
	public:
		time(int x,int y,int z) 
		{
			year = x;
			month = y;
			day = z;
			}	
		void print()
		{
			cout<<"year = "<<year<<endl;
			cout<<"month = "<<month<<endl;
			cout<<"day = "<<day<<endl;
			}	
};

template<typename T>
T add(T a,T b)
{
	return a+b;
} 

//多态
	class human
	{
	public:
	virtual void say() = 0;	
	}; 
	 
	 class student:public human
	 {
	 	public:
	 		void say()
	 		{
	 			cout<<"student!"<<endl;
			 }
	 };
	
	class man:public human
	{
		public:
			void say()
			{
				cout<<"man!"<<endl;
			}
	};
	
	void func(human* h)
	{
		h->say();
	}


void test01()
{
	//human a;
	student b;
	man c;
	
	func(&b);
	func(&c);
}

class num{
	public:
		int a,b;
		num(int x,int y)
		{
			a = x;
			b = y;
		}
		
	//用到了this,要在类中声明实现	
	num& operator=(num& o)
	{
	this->a = o.a;
	this->b = o.b;
	return *this;
	}
};

num operator+(num& p1,num& p2)
{
	num p3(0,0);
	p3.a = p1.a + p2.a;
	p3.b = p1.b + p2.b;
	return p3;
}

ostream& operator<<(ostream& o,num& p)
{
	cout<<"a = "<<p.a<<endl;
	cout<<"b = "<<p.b<<endl;
	return o;
 } 

void test02()
{
	num a(1,1);
	num b(2,2);
	num c = a + b;
	
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;
}

class ren
{
public:
string name;
int age;

ren(string n,int a):name(n),age(a)
{
	
}	


};


void test03()
{
	ren r1("zyh",18);
	cout<<"name:"<<r1.name<<endl<<"age:"<<r1.age<<endl;
}

int main()
{
	//string s = "hello";
	//cout<<s.length()<<endl;
	//std::cout<<"hello world"<<std::endl;
	
	//time a(2024,6,18);
	//a.print();
	
	//模版 
	//cout<<add<string>("hello","world")<<endl;
	
	//多态 
	//test01();
	
	//运算符重载
	test02();
	 
	 //test03();
	 
	return 0;
}
