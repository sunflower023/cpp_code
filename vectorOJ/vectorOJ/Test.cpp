#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<vector>
#include<string>
#include<list>
#include<stack>
#include<queue>
using namespace std;


//class Solution {
//public:
//    vector<string> letterCombinations(string digits) {
//        vector<string> a({ "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" });
//        int size = digits.size();
//        int r_size = pow(3, size);
//        vector<string> ret(r_size);
//        int cnt = 0;
//        int p1 = 0;
//        int j = 0;
//        while (r_size > 1)
//        {
//            for (int i = 0; i < pow(3, size); i++)
//            {
//                if (cnt == (r_size / 3))
//                {
//                    p1++;
//                    cnt = 0;
//                }
//                if (p1 == 3)
//                {
//                    p1 = 0;
//                }
//                ret[i].push_back(a[digits[j] - '0'][p1]);
//                cnt++;
//            }
//            r_size /= 3;
//            j++;
//            p1 = 0;
//            cnt = 0;
//        }
//        return ret;
//    }
//};




//int main()
//{
//	//cout << pow(2,3) << endl;
//    //vector<string> v(10);
//    //v[0].push_back('a');
//    /*Solution s;
//    s.letterCombinations("23");*/
//	int ar[] = { 1,2,3,4,0,5,6,7,8,9 };
//
//	int n = sizeof(ar) / sizeof(int);
//
//	vector<int> v(ar, ar + n);
//
//	vector<int>::iterator it = v.begin();
//
//	while (it != v.end())
//
//	{
//
//		if (*it != 0)
//
//			cout << *it;
//
//		else
//
//			v.erase(it);
//
//		it++;
//
//	}
//
//	return 0;
//}

//template<typename T>
//void removeDuplicates(list<T>& aList)
//{
//	T curValue;
//	typename list<T>::iterator cur, p;
//	cur = aList.begin();
//	while (cur != aList.end())
//	{
//		curValue = *cur;
//		p = ++cur;
//		while (p != aList.end())
//		{
//			if (*p == curValue)
//			{
//				p == cur ? cur = p = aList.erase(p) : p = aList.erase(p);
//			}
//			else
//			{
//				p++;
//			}
//		}
//	}
//};
//
//int main()
//{
//	list<int>l = { 1, 1, 5, 5, 6, 7, 8, 9, 7 };
//	removeDuplicates<int>(l);
//	for (auto e : l)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//}



  /*struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
  class Solution {
  public:
      vector<vector<int>> levelOrder(TreeNode* root) {
          vector<vector<int>> v;
          stack<TreeNode*> s;
          if (root)
              s.push(root);

          int levelsize = s.size();
          int level = 0;
          while (!s.empty())
          {
              while (levelsize--)
              {
                  TreeNode* top = s.top();
                  if (top->left)
                  {
                      s.push(top->left);
                  }
                  if (top->right)
                  {
                      s.push(top->right);
                  }
                  v[level].push_back(top->val);
                  s.pop();
              }
              levelsize = s.size();
              level++;
          }
          return v;
      }
  };*/

bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
    // write code here
    int i = 0, j = 0;
    stack<int> s;
    s.push(pushV[i++]);
    while (1)
    {
        while((i < pushV.size() && s.empty()) || (i < pushV.size() && s.top() != popV[j]))
        {
            s.push(pushV[i++]);
        }
        while (j < popV.size() && !s.empty() && s.top() == popV[j])
        {
            s.pop();
            j++;
        }
        if (i == pushV.size() && (!s.empty()))
        {
            return false;
        }
        if (i == pushV.size() && (s.empty()))
        {
            return true;
        }
    }
}

int main()
{

    vector<int> v1 = { 2,1,0 };
    vector<int> v2= { 1,2,0};
    IsPopOrder(v1, v2);
    return 0;
}
