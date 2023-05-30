class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        
        int j = 0;
        for (int i = 0; i < pushed.size(); i++)
        {
            if (pushed[i] == popped[j])
            {
                j++;
                while (j < popped.size() && !st.empty() && st.top() == popped[j])
                {
                    st.pop();
                    j++;
                }
            }
            else
            {
                st.push(pushed[i]);
            }
        }

        for (int i = j; i < popped.size(); i++)
        {
            if (st.top() == popped[i])
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};