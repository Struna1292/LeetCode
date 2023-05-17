/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        
        vector<int> nums;
        while (head != NULL)
        {
            nums.push_back(head->val);
            head = head->next;
        }

        int i = 0;
        int j = nums.size()-1;
        int output = 0;
        while (i < j)
        {
            if (nums[i] + nums[j] > output)
            {
                output = nums[i] + nums[j];
            }
            i++;
            j--;
        }

        return output;
    }
};