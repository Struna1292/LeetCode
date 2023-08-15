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
    ListNode* partition(ListNode* head, int x) {
        ListNode* curr = head;

        ListNode* last = nullptr;

        ListNode* prev = nullptr;

        while (curr != NULL && curr->val < x)
        {
            last = curr;
            curr = curr->next;
        }

        while (curr != NULL)
        {
            if (curr->val < x && last == nullptr)
            {
                prev->next = curr->next;
                curr->next = head;
                head = curr;
                last = head;
                curr = prev->next;
            }
            else if (curr->val < x) 
            {
                prev->next = curr->next;

                curr->next = last->next;
                last->next = curr;
                last = last->next;

                curr = prev->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};