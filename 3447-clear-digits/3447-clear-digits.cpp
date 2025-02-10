class Solution {
public:
    string clearDigits(string s) {
        
        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                if (st.empty())
                {
                    st.push(s[i]);
                }
                else
                {
                    st.pop();
                }
            }
            else
            {
                st.push(s[i]);
            }
        }

        string output;

        while (!st.empty())
        {
            output.push_back(st.top());
            st.pop();
        }

        int i = 0;
        int j = output.length()-1;

        while (i < j)
        {
            swap(output[i], output[j]);
            i++;
            j--;
        }

        return output;
    }
};