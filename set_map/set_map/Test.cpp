#define _CRT_SECURE_NO_WARNINGS 1
#include<utility>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
	auto p1 = pair<int, string>(1, "ysh");
	auto p2 = make_pair(2, "zyh");
	auto p3 = pair<int, string>{ 3,"xx" };

	map<int, string> m;
	m.insert(pair<int, string>(1, "ysh"));
	m.insert(make_pair(2, "zyh"));
	m.insert({ 3,"xx" });

	/*vector<int> v{ 5,3,4,6,1,2,2,2,2 };
	set<int> s(v.begin(), v.end());
	for (auto e : s)
	{
		cout << e << " ";
	}*/

	//cout << endl;

	//�㷨��Ĳ���O(N)
	//auto pos1 = find(s.begin(), s.end(), 1);
	//set����Ĳ���O(logN)
	//auto pos2 = s.find(1);

	//cout << *s.begin() << endl;
	//cout << *(--s.end()) << endl;

	/*vector<int> v{ 10,20,30,40,50,60,70,80,90,100,100,100,100 };
	multiset<int> s(v.begin(), v.end());
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	s.erase(100);
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;*/
	/*int input;
	cin >> input;
	if (s.count(input))
	{
		cout << "����" << endl;
	}
	else
	{
		cout << "������" << endl;
	}*/


	map<string, string> m1;//�յ�

	m1.insert(pair<string, string>("sort", "����"));
	m1.insert(make_pair("apple", "ƻ��"));
	m1.insert({ "left", "���" });
	for (auto& kv : m1)
	{
		cout << kv.first << ":" << kv.second << " ";
	}
	cout << endl;

	m1["right"];//right�����ڣ����ǲ���һ��right��key��
	m1["apple"] = "��ƻ��";//����apple�Ѿ����ڣ������ǽ����޸�

	for (auto& kv : m1)
	{
		cout << kv.first << ":" << kv.second << " ";
	}
	cout << endl;
	
	return 0;
}