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
	
	//ͷ�壬����ʹ��,����Ч������
	//s.insert(0, "nihao,");
	//ĳ��λ��ǰ��
	//s.insert(6, "world ");
	//����n���ַ�
	//s.insert(0, 5, 'z');

	//��ĳ��λ��ɾ��n���ַ�
	//s.erase(0, 2);
	//ͷɾ��βɾ
	//Ĭ��ֵ��npos����-1��Ĭ�ϴ�ĳ��λ�ÿ�ʼ�����涼ɾ��
	//s.erase(s.begin());
	//s.erase(s.size() - 1);
	//s.erase(--s.end());
	//��1��ʼ��ȫ��ɾ��
	//s.erase(1);

	//��ĳ��λ�ã��滻�����ַ����滻Ϊ...
	//s.replace(6, 1, "%%");
	
	//find�Ҳ����ͷ���npos������s.nop/string::npos�ж�
	string s("hello world hello swuer");
	string s2("hello world hello swuer");
	size_t pos = s.find(' ');
	while (pos != s.npos)
	{
		s.replace(pos, 1, "---");
		//���Ч�ʣ���pos+1λ�ÿ�ʼ����
		pos = s.find(' ', pos + 3);
	}
	cout << s << endl;

	//�ÿռ任ʱ�䣬Ч�ʸ���
	string tmp;
	//��ǰ���ռ䣬�������Ч��
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
	//substrȡĳһλ�ú�ļ����ַ���Ĭ��npos
	string suffix = s.substr(pos);
	cout << suffix << endl;

	//find first of����һ���ַ����е��ַ�ƥ����һ���ַ���������һ��
	//find last of������

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