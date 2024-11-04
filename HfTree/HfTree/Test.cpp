#include"HfTree.h"
#include"ref.h"

void test1()
{
	char c[] = "aeistdn";
	int w[] = { 10,15,12,3,4,13,1 };
	HfTree<char> t(c, w, 7);
	HfTree<char>::HfCode* result = new HfTree<char>::HfCode[7];
	t.GetCode(result);
	for (int i = 0; i < 7; i++)
	{
		cout << result[i].data << ":" << result[i].code << endl;
	}
}

void test2()
{
	char c[] = { "abcdefghij" };
	int w[] = { 1,6,8,3,2,13,4,15,16,7 };
	HfTree<char> t(c, w, 10);
	HfTree<char>::HfCode* result = new HfTree<char>::HfCode[10];
	t.GetCode(result);
	for (int i = 0; i < 10; i++)
	{
		cout << result[i].data << ":" << result[i].code << endl;
	}
}

void test3()
{
	char c[] = { "abcdefghijklmnopq" };
	int w[] = { 1,6,8,3,2,13,4,15,16,7,11,22,21,23,24,41,9 };
	HfTree<char> t(c, w, 17);
	HfTree<char>::HfCode* result = new HfTree<char>::HfCode[17];
	t.GetCode(result);
	for (int i = 0; i < 17; i++)
	{
		cout << result[i].data << ":" << result[i].code << endl;
	}
}

int main()
{

	test1();
	cout<<endl;
	test2();
	cout << endl;
	test3();
	return 0;
}