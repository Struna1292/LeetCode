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
    ListNode* swapPairs(ListNode* head) {
        ListNode* curr = head;

        bool first = true;
        while (curr != NULL)
        {
            if (curr->next != NULL)
            {
                if (first)
                {
                    ListNode* temp1 = curr;
                    curr = curr->next;
                    ListNode* temp2 = curr->next;
                    curr->next = temp1;
                    head = curr;
                    first = false;
                    temp1->next = temp2;
                }
                else
                {
                    ListNode* temp1 = curr->next;
                    if (temp1->next != NULL)
                    {
                        curr->next = temp1->next;
                        curr = curr->next;
                        ListNode* temp2 = curr->next;
                        curr->next = temp1;
                        temp1->next = temp2;
                    }
                }
            }
            curr = curr->next;
        }

        return head;
    }
};