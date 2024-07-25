#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
                continue;
            }
            // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
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