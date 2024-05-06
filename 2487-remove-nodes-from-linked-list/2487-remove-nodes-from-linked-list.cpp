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
    ListNode* removeNodes(ListNode* head) {
        
        vector<int> nums;

        ListNode* curr = head;

        while (curr != nullptr)
        {
            nums.push_back(curr->val);
            ListNode* temp = curr;
            curr = curr->next;
            delete temp;
        }

        stack<int> st;

        st.push(nums[nums.size()-1]);

        for (int i = nums.size()-2; i >= 0; i--)
        {
            if (nums[i] >= st.top())
            {
                st.push(nums[i]);
            }
        }

        head = new ListNode;

        curr = head;

        while(!st.empty())
        {
            curr->val = st.top();
            st.pop();
            if (!st.empty())
            {
                curr->next = new ListNode;
                curr = curr->next;
            }
        }

        return head;
    }
};