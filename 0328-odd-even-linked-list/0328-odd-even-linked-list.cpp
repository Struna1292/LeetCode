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
    ListNode* oddEvenList(ListNode* head) {

        if (head == NULL || head->next == NULL)
        {
            return head;
        }


        ListNode* odd = new ListNode;
        ListNode* temp1;
        ListNode* curr1 = odd;

        ListNode* even = new ListNode;
        ListNode* temp2;
        ListNode* curr2 = even;

        ListNode* curr = head;
        int i = 1;
        while (curr != NULL)
        {
            if (i % 2 != 0)
            {
                curr1->val = curr->val;
                curr1->next = new ListNode;
                temp1 = curr1;
                curr1 = curr1->next;
            }
            else
            {
                curr2->val = curr->val;
                curr2->next = new ListNode;
                temp2 = curr2;
                curr2 = curr2->next;
            }
            i++;
            curr = curr->next;
        }

        head = odd;
        temp1->next = even;
        temp2->next = NULL;


        return head;
    }
};