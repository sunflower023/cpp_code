#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//����ͳ��
int force_cnt = 0;
int kmp_cnt = 0;

//����ƥ��
int force_match(const string& s, const string& t)
{
	force_cnt = 0;
	int m = s.size(), n = t.size();
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			//����ƥ�����ͳ��
			force_cnt++;
			if (s[i + j] != t[j])break;
		}
		if (j == n)return i;
	}
	return -1;
}

//����next
void Get_next(int* next, const string& s)
{
	int m = s.size();
	int i = 0, j = -1;
	next[0] = -1;
	while (i < m)
	{
		if (j == -1 || s[i] == s[j])
			next[++i] = ++j;
		else
			j = next[j];
	}
}

//KMP�㷨
int kmp_match(const string& s, const string& t)
{
	kmp_cnt = 0;
	int* next = new int[s.size()];
	Get_next(next, s);

	int i = 0, j = 0;
	int m = s.size(), n = t.size();
	while (i< m && j < n)
	{
		//kmp����ͳ��
		kmp_cnt++;
		if (s[i] == t[j])
		{
			i++;
			j++;
		}
		else
		{
			if (next[j] == -1)
			{
				j = 0;
				i++;
			}
			else if(next[j] >= 0)
			{
				j = next[j];
			}
		}
		if (j == n) return i - j;
	}
	return -1;
}

int main()
{
	string s("abacabcdefff");
	string t("abce");
	while (1)
	{
		cout << "����Ŀ�괮:";
		cin >> s;
		cout << "����ģʽ��:";
		cin >> t;
		cout << "force���Ϊ:" << force_match(s,t) << endl;
		cout << "force����Ϊ��" << force_cnt << endl;
		cout << "kmp���Ϊ:" << kmp_match(s, t) << endl;
		cout << "kmp����Ϊ��" << kmp_cnt << endl;
	}
	
	return 0;
}