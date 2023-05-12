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

        ListNode* curr = head;
        vector<int> nums;
        while (curr != NULL)
        {
            nums.push_back(curr->val);
            curr = curr->next;
        }

        int i = 0;
        int j = nums.size()-1;
        int counter = 1;
        curr = head;
        while (curr != NULL)
        {
            if (counter % 2 != 0)
            {
                curr->val = nums[i];
                i++;
            }
            else
            {
                curr->val = nums[j];
                j--;
            }
            counter++;
            curr = curr->next;
        }

    }
};