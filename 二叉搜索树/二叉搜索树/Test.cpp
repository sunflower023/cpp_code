#define _CRT_SECURE_NO_WARNINGS 1
#include"Binary_Search_Tree.h"

int main()
{
	/*zyh::BSTree<int> s;

	int a[] = { 7,5,3,6,9,8,1,2 };
	for (auto e : a)
	{
		s.insert(e);
	}
	s._InOrder();*/

	//if (s.find(11)) cout << "yes" << endl;
	//else cout << "no" << endl;
	
	/*for (auto e : a)
	{
		s.erase(e);
	}
	s._InOrder();*/

	/*zyh::BSTree<int> s2(s);
	s2._InOrder();*/
	
	zyh::BSTree<string, string> dict;
	dict.insert("insert", "����");
	dict.insert("erase", "ɾ��");
	dict.insert("left", "���");
	dict.insert("string", "�ַ���");

	string str;
	while (cin >> str)
	{
		auto ret = dict.find(str);
		if (ret)
		{
			cout << str << ":" << ret->_value << endl;
		}
		else
		{
			cout << "����ƴд����" << endl;
		}
	}

	//string strs[] = { "ƻ��", "����", "ƻ��", "ӣ��", "ƻ��", "ӣ��", "ƻ��", "ӣ��", "ƻ��" };
	//// ͳ��ˮ�����ֵĴ�
	//zyh::BSTree<string, int> countTree;
	//for (auto str : strs)
	//{
	//	auto ret = countTree.find(str);
	//	if (ret == NULL)
	//	{
	//		countTree.insert(str, 1);
	//	}
	//	else
	//	{
	//		ret->_value++;
	//	}
	//}
	//countTree._InOrder();
	return 0;
}