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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int length = 0;

        while (curr != NULL)
        {
            length++;
            curr = curr->next;
        }

        if (length-n == 0)
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        curr = head;
        int i = 1;
        while (curr != NULL)
        {
            if (i == length-n)
            {
                ListNode* temp = curr;
                curr = curr->next;
                if (curr != NULL)
                {
                    temp->next = curr->next;
                }
                else
                {
                    temp->next = nullptr;
                }
                delete curr;
                break;
            }
            i++;
            curr = curr->next;
        }

        return head;
    }
};