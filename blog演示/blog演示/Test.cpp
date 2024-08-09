#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//template<class T>
//T Add(const T& x, const T& y)
//{
//	return x + y;
//}
//
//int Add(const int& x, const int& y)
//{
//	return x + y;
//}

//int main()
//{
//	int a1 = 10, a2 = 20;
//	double b1 = 10.11, b2 = 20.11;
//
//	int c1 = 10;
//	double c2 = 20.11;
//
//	cout << Add(a1, a2) << endl;
//	cout << Add(b1, b2) << endl;
//	cout << Add<int>(c1, c2) << endl;
//	cout << Add<double>(c1, c2) << endl;
//}

//int main()
//{
//	cout << Add<int>(1, 2) << endl;
//	return 0;
//}

//template<typename Type>
//
//Type Max(const Type& a, const Type& b)
//
//{
//
//	cout << "This is Max<Type>" << endl;
//
//	return a > b ? a : b;
//
//}
//
//template<>
//
//int Max<int>(const int& a, const int& b)
//
//{
//
//	cout << "This is Max<int>" << endl;
//
//	return a > b ? a : b;
//
//}
//
//template<>
//
//char Max<char>(const char& a, const char& b)
//
//{
//
//	cout << "This is Max<char>" << endl;
//
//	return a > b ? a : b;
//
//}
//
//int Max(const int& a, const int& b)
//
//{
//
//	cout << "This is Max" << endl;
//
//	return a > b ? a : b;
//
//}
//
//int main()
//
//{
//
//	Max(10, 20);
//
//	Max(12.34, 23.45);
//
//	Max('A', 'B');
//
//	Max<int>(20, 30);
//
//	return 0;
//
//}

//int globalVar = 1;
//static int staticGlobalVar = 1;
//void Test()
//{
//    static int staticVar = 1;
//    int localVar = 1;
//    int num1[10] = { 1, 2, 3, 4 };
//    char char2[] = "abcd";
//    const char* pChar3 = "abcd";
//    int* ptr1 = (int*)malloc(sizeof(int) * 4);
//    int* ptr2 = (int*)calloc(4, sizeof(int));
//    int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//    free(ptr1);
//    free(ptr3);
//}

//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p1 = new A;
//	delete(p1);
//	cout << "-------------------------" << endl;
//	A* p2 = new A[5];
//	delete[](p2);
//
//	return 0;
//}

class A
{
public:
	A(int a = 0)
		: _a(a)
	{}
	~A()
	{}

private:
	int _a = 1;
};
class B
{
private:
	int _b = 2;
};
int main()
{
	A* p1 = new A[10];
	B* p2 = new B[10];
	delete[] p1;
	delete p2;
}
