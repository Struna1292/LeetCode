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
    ListNode* middleNode(ListNode* head) {
        ListNode* pointer = head;

        ListNode* fastPointer = head;

        int i = 0;

        while (fastPointer->next != nullptr && fastPointer->next->next != nullptr)
        {
            i += 2;
            pointer = pointer->next;
            fastPointer = fastPointer->next->next;
        }

        while (fastPointer != nullptr)
        {
            fastPointer = fastPointer->next;
            i++;
        }

        if (i % 2 == 0)
        {
            pointer = pointer->next;
        }

        return pointer;
    }
};