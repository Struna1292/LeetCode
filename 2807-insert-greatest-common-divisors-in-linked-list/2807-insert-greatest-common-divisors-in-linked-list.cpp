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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        ListNode* curr = head;

        while (curr->next != nullptr)
        {
            ListNode* prev = curr;
            curr = curr->next;
            prev->next = new ListNode;
            ListNode* temp = prev->next;
            temp->val = gcd(prev->val, curr->val);
            temp->next = curr;
        }

        return head;
    }
};