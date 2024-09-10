#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

struct ListNode {
    int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
 

//第一次尝试：
//针对于m=1的情况进行了特殊处理（特殊处理就是添加了一个虚拟头结点），不过更建议直接使用虚拟头结点，这样就不用做特殊处理了，直接将第一个节点也当做普通节点，只在最后返回的时候返回虚拟头结点_head->next即可

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        //虚拟头节点
        ListNode* hhead = new ListNode(0);
        hhead->next = head;
        ListNode* prev = hhead, * next = hhead->next;
        while (--m)
        {
            prev = prev->next;
        }
        while (n--)
        {
            next = next->next;
        }

        ListNode* n1 = next, * n2 = prev->next, * n3 = n2->next;
        while (n2 != next)
        {
            n2->next = n1;
            n1 = n2;
            n2 = n3;
            if (n3 != nullptr)
                n3 = n2->next;
        }
        prev->next = n1;
        //注意这里不能直接返回head,而要返回hhead->next
        //因为原head可能已经不是head了，例：{3,5}1,2
        return hhead->next;
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for (int i = 0; i < nums.size(); i++)
        {
            //去重
            while (i > 0 && i < nums.size() && nums[i] == nums[i - 1])
            {
                i++;
            }
            //cout<<"nums[i]:"<<nums[i]<<endl;

            int left = i + 1, right = nums.size() - 1;
            while (left < right)
            {
                //cout<<"left:"<<left<<" nums[left]:"<<nums[left]<<endl;
                //cout<<"right:"<<right<<" nums[right]:"<<nums[right]<<endl;
                if (nums[left] + nums[right] == -nums[i])
                {
                    ret.push_back({ nums[i],nums[left],nums[right] });
                    left++;
                    right--;
                }
                else if (nums[left] + nums[right] > -nums[i])
                {
                    right--;
                    //if(right < nums.size()-1 && nums[right] == nums[right+1]) right--;
                }
                else
                {
                    left++;
                    //if(nums[left] == nums[left-1]) left++;
                }
                while (right < nums.size() - 1 && nums[right] == nums[right + 1]) right--;
                while (left < nums.size() - 1 && nums[left] == nums[left - 1] && left != i + 1) left++;
            }
        }
        return ret;
    }
};

int main()
{
    stack<int>* s1 = new stack<int>();
    s1->push(1);
    cout << s1->top() << endl;

	return 0;
}