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
    int length(ListNode* head)
    {
        int counter = 0;
        while (head != NULL)
        {
            counter++;
            head = head->next;
        }
        return counter;
    }

    ListNode* middleNode(ListNode* head) {
        int mid = length(head) / 2;
        int counter = 0;
        while (head != NULL && counter != mid)
        {
            counter++;
            head = head->next;
        }
        return head;
    }
};