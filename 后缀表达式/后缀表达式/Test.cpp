#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<stack>
using namespace std;

//judge用于判断负数是否成立
bool judge(string str,int i,stack<char>& st)
{
	if (str[i] == '-' && st.top() == '(')
	{
		i++;
		while (str[i] != ')')
		{
			if (str[i] > '9' || str[i] < '0')
			{
				return false;
			}
			i++;
		}
		return true;
	}
	return false;
}


void convert(string str)
{
	stack<char> st;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			cout << str[i];
			while (str[++i] >= '0' && str[i] <= '9')
			{
				cout << str[i];
			}
			i--;
			cout << " ";
		}
		else if (str[i] == '(')
		{
			st.push(str[i]);
		}
		else if (str[i] == ')')
		{
			while (st.top() != '(')
			{
				cout << st.top() << " ";
				st.pop();
			}
			st.pop();
		}
		else if (judge(str,i,st))
		{
			//负数的情况，把负数当做一个数
			st.pop();
			cout << str[i];
			while (str[++i] >= '0' && str[i] <= '9')
			{
				cout << str[i];
			}
			cout << " ";
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			while ((!st.empty()) && (st.top() == '*' || st.top() == '/'))
			{
				cout << st.top() << " ";
				st.pop();
			}
			while ((!st.empty()) && (st.top() == '+' || st.top() == '-'))
			{
				cout << st.top() << " ";
				st.pop();
			}
			st.push(str[i]);
		}
		else if (str[i] == '*' || str[i] == '/')
		{
			while ((!st.empty()) && (st.top() == '*' || st.top() == '/'))
			{
				cout << st.top() << " ";
				st.pop();
			}
			st.push(str[i]);
		}
	}
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

int main()
{
	string str;
	cout << "请输入表达式：" << endl;
	while (cin >> str)
	{
		convert(str);
		cout << endl;
		cout << "请输入表达式：" << endl;
	}

	return 0;
}