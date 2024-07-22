#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

void test01()
{
	//string s("hello world");
	//s.push_back(' ');
	//s.push_back('!');
	//s.append("!!!!!");
	//s += "!!!";
	//s.assign("xxx");
	
	//头插，谨慎使用,存在效率问题
	//s.insert(0, "nihao,");
	//某个位置前插
	//s.insert(6, "world ");
	//插入n个字符
	//s.insert(0, 5, 'z');

	//从某个位置删除n个字符
	//s.erase(0, 2);
	//头删、尾删
	//默认值是npos，即-1，默认从某个位置开始，后面都删除
	//s.erase(s.begin());
	//s.erase(s.size() - 1);
	//s.erase(--s.end());
	//从1开始，全部删除
	//s.erase(1);

	//从某个位置，替换几个字符，替换为...
	//s.replace(6, 1, "%%");
	
	//find找不到就返回npos，则用s.nop/string::npos判断
	string s("hello world hello swuer");
	string s2("hello world hello swuer");
	size_t pos = s.find(' ');
	while (pos != s.npos)
	{
		s.replace(pos, 1, "---");
		//提高效率，从pos+1位置开始查找
		pos = s.find(' ', pos + 3);
	}
	cout << s << endl;

	//用空间换时间，效率更高
	string tmp;
	//提前开空间，更能提高效率
	tmp.reserve(s2.size());
	for (auto ch : s2)
	{
		if (ch == ' ')
			tmp += "---";
		else
			tmp += ch;
	}
	//s2 = tmp;
	//swap(s2, tmp);
	s2.swap(tmp);
	cout << s2 << endl;

}

void test02()
{
	string s("/c.desk./test.cpp");
	size_t pos = s.rfind('.');
	//substr取某一位置后的几个字符，默认npos
	string suffix = s.substr(pos);
	cout << suffix << endl;

	//find first of是找一个字符串中的字符匹配另一个字符串中任意一个
	//find last of倒着找

}

void test03()
{
	string s1("hello");
	cout << s1 + " world" << endl;
	cout << "world " + s1 << endl;
	cout << s1 + ' ' + 'b' + 'i' + 't' << endl;
}

void test04()
{
	string s1("hello");
	string s2;
	s2 = s1.substr(0, 3);
	cout << s2 << endl;
}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
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

	size_t t1 = -1;
	size_t t2 = 0;
	cout << (t1 > t2) << endl;
	cout << INT_MAX << endl;
	return 0;
}