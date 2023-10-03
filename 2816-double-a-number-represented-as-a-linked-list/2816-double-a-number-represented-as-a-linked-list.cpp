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
    ListNode* doubleIt(ListNode* head) {
        string num;

        while (head != nullptr)
        {
            num.push_back('0'+head->val);
            head = head->next;
        }

        int rest = 0;
        string multiplied;

        for (int i = num.length()-1; i >= 0; i--)
        {
            int curr = (num[i] - '0') * 2;
            if (rest == 1)
            {
                curr++;
                rest = 0;
            }

            if (curr > 10)
            {
                rest = 1;
                curr %= 10;
            }
            else if (curr == 10)
            {
                rest = 1;
                curr = 0;
            }
            multiplied.push_back(curr + '0');
        }

        if (rest == 1)
        {
            multiplied.push_back('1');
        }
        
        ListNode* output = new ListNode;
        ListNode* curr = output;

        for (int i = multiplied.length()-1; i >= 0; i--)
        {
            curr->val = multiplied[i]-'0';
            if (i != 0)
            {
                curr->next = new ListNode;
                curr = curr->next;
            }
        }

        return output;
    }
};