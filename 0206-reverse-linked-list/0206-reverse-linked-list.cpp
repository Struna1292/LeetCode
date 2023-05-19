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
    ListNode* reverseList(ListNode* head) {

        ListNode* temp1 = nullptr;
        ListNode* temp2 = nullptr;
        while (head != NULL)
        {
            temp2 = head->next;
            head->next = temp1;
            temp1 = head;
            head = temp2;
        }
        head = temp1;

        return head;
    }
};