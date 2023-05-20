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

    int listLength(ListNode* head)
    {
        int length = 0;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            length += 2;
            fast = fast->next->next;
        }

        while (fast != NULL)
        {
            length++;
            fast = fast->next;
        }

        return length;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        int length = listLength(head);

        vector<ListNode*> answer;
        answer.reserve(k);

        int bonusSize = 0;
        if (k < length)
        {
            bonusSize = length % k;
        }

        int groupSize = length / k;

        ListNode* curr = head;
        if (groupSize > 1)
        {
            int i = 0;
            while (curr != NULL)
            {
                if (i == 0)
                {
                    answer.emplace_back(curr);
                    curr = curr->next;
                    i++;
                }
                else if (i >= groupSize-1)
                {
                    if (bonusSize > 0)
                    {
                        curr = curr->next;
                        bonusSize--;
                    }
                    ListNode* temp = curr;
                    curr = curr->next;
                    temp->next = NULL;
                    i = 0;

                }
                else
                {
                    curr = curr->next;
                    i++;
                }
            }
        }
        else if (groupSize == 1 && bonusSize > 0)
        {
            ListNode* curr = head;
            while (curr != NULL)
            {
                answer.emplace_back(curr);
                if (bonusSize > 0)
                {
                    curr = curr->next;
                    bonusSize--;
                }
                ListNode* temp = curr;
                curr = curr->next;
                temp->next = NULL;
            }
        }
        else
        {
            while (curr != NULL)
            {
                answer.emplace_back(curr);
                ListNode* temp = curr;
                curr = curr->next;
                temp->next = NULL;
            }
            ListNode* temp = nullptr;
            for (int i = 0; i < k-length; i++)
            {
                answer.emplace_back(temp);
            }
        }


        return answer;
    }
};