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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        
        ListNode* curr = head;
        
        while (curr != NULL)
        {
            nums.push_back(curr->val);
            curr = curr->next;
        }

        vector<int> answer(nums.size(), 0);

        stack<int> st;

        int j = 0;
        for (int i = nums.size()-1; i >= 0; i--)
        {
            if (st.empty())
            {
                st.push(nums[i]);
            }
            else
            {
                if (st.top() > nums[i])
                {
                    answer[j] = st.top();
                    st.push(nums[i]);
                }
                else
                {
                    while (!st.empty())
                    {
                        if (st.top() > nums[i])
                        {
                            break;
                        }
                        else
                        {
                            st.pop();
                        }
                    }

                    if (st.empty())
                    {
                        st.push(nums[i]);
                    }
                    else
                    {
                        answer[j] = st.top();
                        st.push(nums[i]);
                    }
                }
            }
            j++;
        }

        reverse(begin(answer), end(answer));

        return answer;
    }
};