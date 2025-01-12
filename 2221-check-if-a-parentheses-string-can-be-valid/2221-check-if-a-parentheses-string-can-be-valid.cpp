class Solution {
public:
    bool canBeValid(string s, string locked) {

        if (s.length() % 2 != 0)
        {
            return false;
        }

        stack<pair<char,int>> st;

        for (int i = 0; i < s.length(); i++)
        {
            if (locked[i] == '1')
            {
                if (s[i] == '(')
                {
                    st.push({'(',i});
                }
                else
                {
                    if (!st.empty())
                    {
                        s[st.top().second] = 'x';
                        st.pop();
                        s[i] = 'x';
                    }
                }
            }
        }

        int zeros = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != 'x')
            {
                if (locked[i] == '0')
                {
                    zeros++;
                }
                else if (s[i] == ')')
                {
                    if (zeros == 0)
                    {
                        return false;
                    }
                    zeros--;
                }
                else
                {
                    break;
                }
            }
        }

        zeros = 0;
        for (int i = s.length()-1; i >= 0; i--)
        {
            if (s[i] != 'x')
            {
                if (locked[i] == '0')
                {
                    zeros++;
                }
                else if (s[i] == '(')
                {
                    if (zeros == 0)
                    {
                        return false;
                    }
                    zeros--;
                }
                else
                {
                    break;
                }
            }
        }

        return true;
    }
};