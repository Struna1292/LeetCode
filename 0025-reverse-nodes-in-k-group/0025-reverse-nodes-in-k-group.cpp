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

    ListNode* reverseList(ListNode* head, int k, ListNode* &curr) {

        ListNode* temp1 = nullptr;
        ListNode* temp2 = nullptr;
        ListNode* firstEl = nullptr;
        bool first = true;
        while (k > 0)
        {
            if (first)
            {
                firstEl = head;
                first = false;
            }
            temp2 = head->next;
            head->next = temp1;
            temp1 = head;
            head = temp2;
            k--;
        }
        firstEl->next = head;
        head = temp1;
        curr = firstEl;
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* temp;
        int i = 0;
        bool first = true;
        while (curr != NULL)
        {
            i++;

            if (i == k)
            {
                if (first)
                {
                    head = reverseList(head, k, curr);
                    first = false;
                }
                else
                {
                    temp->next = reverseList(temp->next, k, curr);
                }
                temp = curr;
                i = 0;
            }

            curr = curr->next;
        }

        return head;
    }
};