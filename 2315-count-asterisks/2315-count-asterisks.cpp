class Solution {
public:
    int countAsterisks(string s) {

        stack<char> st;
        int counter = 0;
        int longest = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '*' && st.empty())
            {
                counter++;
                if (counter > longest)
                {
                    longest = counter;
                }
            }
            else if (s[i] == '|')
            {
                if (st.empty())
                {
                    st.push('|');
                }
                else
                {
                    st.pop();
                }
            } 
        }

        return longest;
    }
};