#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[128] = { 0 };
        int n = s.size(), ret = 0;
        for (int left = 0, right = 0; right < n; right++)
        {
            hash[s[right]]++;//enter window
            while (hash[s[right]] > 1)//judge
                hash[s[left++]]--;//quit window
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};


int main()
{

}