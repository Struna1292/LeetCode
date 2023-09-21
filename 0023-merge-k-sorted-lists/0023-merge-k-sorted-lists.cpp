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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> nums;

        for (int i = 0; i < lists.size(); i++)
        {
            ListNode* curr = lists[i];
            while (curr != nullptr)
            {
                nums.push_back(curr->val);
                curr = curr->next;
            }
        }

        sort(begin(nums), end(nums));

        if (nums.size() == 0)
        {
            return nullptr;
        }

        ListNode* head = new ListNode;
        ListNode* curr = head;

        for (int i = 0; i < nums.size(); i++)
        {
            curr->val = nums[i];
            if (i+1 != nums.size())
            {
                curr->next = new ListNode;
                curr = curr->next;
            }
        }

        return head;
    }
};