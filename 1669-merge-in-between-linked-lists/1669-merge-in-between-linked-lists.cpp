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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr = list1;

        ListNode* temp1 = nullptr;

        int counter = 0;

        while (counter != b+1)
        {
            if (counter == a-1)
            {
                temp1 = curr;
            }
            curr = curr->next;
            counter++;
        }

        temp1->next = list2;

        while (list2->next != NULL)
        {
            list2 = list2->next;
        }

        list2->next = curr;

        return list1;
    }
};