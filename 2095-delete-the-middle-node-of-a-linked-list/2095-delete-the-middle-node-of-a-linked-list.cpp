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
    ListNode* deleteMiddle(ListNode* head) {
        
        ListNode* itr = head;
        ListNode* fastItr = head;

        ListNode* prev;

        while (fastItr != nullptr && fastItr->next != nullptr) {
            prev = itr;
            itr = itr->next;
            fastItr = fastItr->next->next;
        }

        if (itr == head) {
            return nullptr;
        }
        else {
            prev->next = itr->next;
        }

        return head;
    }
};