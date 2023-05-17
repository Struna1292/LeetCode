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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        ListNode* curr = head;
        ListNode* head1;
        vector<int> nums;
        int i = 1;
        while (curr != NULL)
        {
            if (i >= left && i <= right)
            {
                nums.push_back(curr->val);
            }
            else if (i > right)
            {
                break;
            }
            if (i == left)
            {
                head1 = curr;
            }
            i++;
            curr = curr->next;    
        }

        for (i = nums.size()-1; i >= 0; i--)
        {
            head1->val = nums[i];
            head1 = head1->next;
        }

        return head;
    }
};