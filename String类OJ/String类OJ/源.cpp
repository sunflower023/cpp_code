#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            // 1. ÿ�� 2k ���ַ���ǰ k ���ַ����з�ת
            // 2. ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ�
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
                continue;
            }
            // 3. ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��
            reverse(s.begin() + i, s.begin() + s.size());
        }
        return s;
    }
};

class Solution2 {
public:
    int firstUniqChar(string s) {
        char a[26];
        for (int i = 0; i < 26; i++)
        {
            a[i] = 0;
        }
        for (int i = 0; i < s.size(); i++)
        {
            a[s[i] - '0' - 49]++;
        }
        for (int i = 0; i < 26; i++)
        {
            cout << a[i] << " ";
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (a[s[i] - '0' - 49] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    //string s("abcd");
    //Solution2 so;
    //cout << so.firstUniqChar(s) << endl;

    string s("abcdefg");
    //cout << s.find('b',1) << endl;
    reverse(s.begin(), s.end());
    cout << s << endl;

    //cout << 'a'-'0'-49 << endl;
    //cout << 'n'-'0'-49 << endl;

    return 0;
}