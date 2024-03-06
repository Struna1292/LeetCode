/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> pointers;
        while (head != NULL)
        {
            if (pointers.find(head) != pointers.end())
            {
                return true;
            }
            else
            {
                pointers.insert(head);
            }
            head = head->next;
        }
        return false;
    }
};