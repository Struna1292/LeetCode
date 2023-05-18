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
    ListNode* sortList(ListNode* head) {
        ListNode* curr = head;
        vector<int> nums;

        while (curr != NULL)
        {
            nums.push_back(curr->val);
            curr = curr->next;
        }

        sort(begin(nums), end(nums));

        curr = head;

        int i = 0;
        while (curr != NULL)
        {
            curr->val = nums[i];
            i++;
            curr = curr->next;
        }

        return head;
    }
};