#define _CRT_SECURE_NO_WARNINGS 1
#include"RBTree.h"

void test1()
{
	RBTree<int, int> t;
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	//常规的测试用例
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };

	for (auto e : a)
	{
		t.insert({e,e});
	}

	t.InOrder();
	cout << t.IsBalance() << endl;
}


int main()
{

	test1();
	return 0;
}