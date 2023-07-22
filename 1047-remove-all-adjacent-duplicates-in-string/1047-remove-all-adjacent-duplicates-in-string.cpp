class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            if (st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                if (st.top() == s[i])
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }

        string output;

        while (!st.empty())
        {
            output.push_back(st.top());
            st.pop();
        }

        int i = 0;
        int j = output.size()-1;
        while (i < j)
        {
            swap(output[i], output[j]);
            i++;
            j--;
        }

        return output;
    }
};