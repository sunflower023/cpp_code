#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
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
int main(int argc, char* argv[])

{

	string strText = "How are you?";

	string strSeparator = " ";

	string strResult;

	int size_pos = 0;

	int size_prev_pos = 0;

	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)

	{

		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);

		cout << strResult << " ";

		size_prev_pos = ++size_pos;

	}

	if (size_prev_pos != strText.size())

	{

		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);

		cout << strResult << " ";

	}

	cout << endl;

	return 0;

}

