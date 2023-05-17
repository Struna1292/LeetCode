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
    ListNode* removeNodes(ListNode* head) {
        
        vector<int> nums;
        ListNode* curr1 = head;
        while (curr1 != NULL)
        {
            nums.push_back(curr1->val);
            curr1 = curr1->next;
        }

        int biggest = nums[nums.size()-1];
        vector<int> curr = {biggest};
        for (int i = nums.size()-2; i >= 0; i--)
        {
            if (nums[i] >= biggest)
            {
                biggest = nums[i];
                curr.push_back(biggest);
            }
        }

        int i = 0;
        int j = curr.size()-1;

        while (i < j)
        {
            swap(curr[i], curr[j]);
            i++;
            j--;
        }

        ListNode* curr2 = head;

        for (int i = 0; i < curr.size(); i++)
        {
            curr2->val = curr[i];
            if (i+1 != curr.size())
            {
                curr2 = curr2->next;
            }
            else
            {
                curr2->next = NULL;
            }
        }

        return head;
    }
};