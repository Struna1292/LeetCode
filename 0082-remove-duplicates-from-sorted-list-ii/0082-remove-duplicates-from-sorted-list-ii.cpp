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
    ListNode* removeByVal(ListNode* head, int val)
{
    ListNode* curr = head;

    curr = curr->next;

    while (curr != NULL)
    {
        if (curr->val == val)
        {
            ListNode* temp = curr;
            head->next = curr->next;
            curr = curr->next;
            delete temp;
        }
        else
        {
            break;
        }
    }

    return curr;
}

    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* curr = head;

        ListNode* prev = nullptr;
        while (curr != NULL)
        {
            if (curr->next != NULL && curr->val == curr->next->val)
            {
                if (head->val == curr->val)
                {
                    head = removeByVal(head, curr->val);
                }
                else
                {
                    removeByVal(prev, curr->val);
                    curr = prev;
                }
            }
            prev = curr;

            curr = curr->next;
        }

        return head;
    }
};