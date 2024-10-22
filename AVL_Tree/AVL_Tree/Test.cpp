#define _CRT_SECURE_NO_WARNINGS 1
#include"AVLTree.h"

void test01()
{
	AVLTree<int, int> t;
	// ����Ĳ�������
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	// ����Ĵ���˫�������Ĳ�������
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };

	for (auto e : a)
	{
		t.Insert({ e, e });
	}

	t.InOrder();
	cout << t.IsBalanceTree() << endl;
}

int main()
{
	test01();

	return 0;
}