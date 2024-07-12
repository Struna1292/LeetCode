class Solution {
public:

    stack<char> helper(int& score, string s, char a, char b, int value)
    {
        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            if (st.empty())
            {   
                st.push(s[i]);
            }
            else
            {
                if (st.top() == a && s[i] == b)
                {
                    st.pop();
                    score += value;
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }

        return st;
    }

    string stackToString(stack<char> st)
    {
        string curr = "";

        while (!st.empty())
        {
            curr.push_back(st.top());
            st.pop();
        }

        int i = 0;
        int j = curr.length()-1;

        while (i < j)
        {
            swap(curr[i], curr[j]);
            i++;
            j--;
        }

        return curr;
    }

    int maximumGain(string s, int x, int y) {
        
        int score = 0;

        if (x > y)
        {
            stack<char> st = helper(score, s, 'a', 'b', x);

            string curr = stackToString(st);

            st = helper(score, curr, 'b', 'a', y);
        }
        else
        {
            stack<char> st = helper(score, s, 'b', 'a', y);

            string curr = stackToString(st);

            st = helper(score, curr, 'a', 'b', x);
        }

        return score;
    }
};