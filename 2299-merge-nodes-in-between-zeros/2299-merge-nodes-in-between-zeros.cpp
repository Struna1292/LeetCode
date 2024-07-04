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
    ListNode* mergeNodes(ListNode* head) {
        head = head->next;
        
        ListNode* outputHead = new ListNode;

        ListNode* currOutput = outputHead;

        int currValue = 0;

        while (head != nullptr)
        {
            if (head->val == 0)
            {
                currOutput->val = currValue;

                if (head->next != nullptr)
                {
                    currOutput->next = new ListNode;
                    currOutput = currOutput->next;
                }

                currValue = 0;
            }
            else
            {
                currValue += head->val;
            }


            head = head->next;
        }


        return outputHead;
    }
};