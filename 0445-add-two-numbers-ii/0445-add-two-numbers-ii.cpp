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

    string add(string &num1, string &num2)
{
    string sum;

    if (num1.length() > num2.length())
    {
        string temp = num1;
        num1 = num2;
        num2 = temp;
    }

    bool one = false;
    int j = num1.length()-1;
    for (int i = num2.length()-1; i >= 0; i--)
    {
        int num = 0;
        if (j >= 0)
        {
            num = (num2[i] - '0') + (num1[j] - '0');
        }
        else
        {
            num = num2[i] - '0';
        }

        if (one)
        {
            num++;
            one = false;
        }
        if (num > 9)
        {
            num -= 10;
            one = true;
        }

        sum.append(to_string(num));

        j--;
    }

    if (one)
    {
        sum.push_back('1');
    }

    int i = 0;
    j = sum.length()-1;
    while (i < j)
    {
        swap(sum[i], sum[j]);
        i++;
        j--;
    }

    return sum;
}

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* curr1 = l1;
        string num1;
        while (curr1 != NULL)
        {
            num1.push_back(curr1->val + '0');
            curr1 = curr1->next;
        }
        

        ListNode* curr2 = l2;
        string num2;
        while (curr2 != NULL)
        {
            num2.push_back(curr2->val + '0');
            curr2 = curr2->next;
        }

        string sum1 = add(num1, num2);

        
        ListNode* head = new ListNode;
        ListNode* curr = head;
        for (int i = 0; i < sum1.length(); i++)
        {
            curr->val = sum1[i] - '0';
            if (i+1 != sum1.length())
            {
                curr->next = new ListNode;
                curr = curr->next;
            }
        }

        return head;
    }
};