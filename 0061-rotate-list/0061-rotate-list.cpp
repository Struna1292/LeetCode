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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
        {
            return head;
        }
        ListNode* curr = head;

        int length = 0;
        while (curr != NULL)
        {
            length++;
            curr = curr->next;
        }

        for (int i = k % length; i > 0; i--)
        {
            ListNode* prev = nullptr;
            curr = head;
            while (curr != NULL && curr->next != NULL)
            {
                prev = curr;
                curr = curr->next;
            }

            curr->next = head;
            prev->next = NULL;
            head = curr;
        }

        return head;
    }
};