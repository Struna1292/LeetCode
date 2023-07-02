class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<int> st;

        vector<int> output(temperatures.size(), 0);
        
        for (int i = temperatures.size()-1; i >= 0; i--)
        {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                output[i] = st.top() - i;
            }
            st.push(i);
        }

        return output;
    }
};