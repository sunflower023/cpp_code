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
 

//��һ�γ��ԣ�
//�����m=1��������������⴦�����⴦����������һ������ͷ��㣩������������ֱ��ʹ������ͷ��㣬�����Ͳ��������⴦���ˣ�ֱ�ӽ���һ���ڵ�Ҳ������ͨ�ڵ㣬ֻ����󷵻ص�ʱ�򷵻�����ͷ���_head->next����

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param head ListNode��
     * @param m int����
     * @param n int����
     * @return ListNode��
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        //����ͷ�ڵ�
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
        //ע�����ﲻ��ֱ�ӷ���head,��Ҫ����hhead->next
        //��Ϊԭhead�����Ѿ�����head�ˣ�����{3,5}1,2
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
            //ȥ��
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