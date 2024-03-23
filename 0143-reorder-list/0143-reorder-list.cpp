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
    void reorderList(ListNode* head) {
        vector<int> nums;

        ListNode* curr = head;

        while (curr != nullptr)
        {
            nums.push_back(curr->val);
            curr = curr->next;
        }

        int j = 0;
        int k = nums.size()-1;

        for (int i = 0; i < nums.size(); i++)
        {
            if ((i+1) % 2 != 0)
            {
                head->val = nums[j];
                j++;
            }
            else
            {
                head->val = nums[k];
                k--;
            }
            head = head->next;
        }

    }
};