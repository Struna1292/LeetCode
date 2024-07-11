class Solution {
public:
    string reverseParentheses(string s) {

        while (true)
        {

            int startIndex = -1;
            int endIndex = -1;

            string curr = "";

            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == '(')
                {
                    startIndex = i;
                }
                else if (s[i] == ')')
                {
                    endIndex = i;

                    for (int j = 0; j < startIndex; j++)
                    {
                        curr.push_back(s[j]);
                    }

                    for (int j = endIndex-1; j > startIndex; j--)
                    {
                        curr.push_back(s[j]);
                    }

                    for (int j = endIndex+1; j < s.length(); j++)
                    {
                        curr.push_back(s[j]);
                    }

                    break;
                }
            }

            if (startIndex == -1)
            {
                break;
            }

            s = curr;
        }

        return s;
    }
};