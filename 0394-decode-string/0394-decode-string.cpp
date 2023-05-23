class Solution {
public:

    string helper(string s)
    {
        string answer;
        string curr;
        string num;
        stack<char> parentheses;
        string empty;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                if (parentheses.empty())
                {
                    answer.push_back(s[i]);
                }
                else
                {
                    curr.push_back(s[i]);
                }
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                if (parentheses.empty())
                {
                    num.push_back(s[i]);
                }
                else
                {
                    curr.push_back(s[i]);
                }
            }
            else
            {
                if (s[i] == '[')
                {
                    if (!parentheses.empty())
                    {
                        curr.push_back(s[i]);
                    }
                    parentheses.push('[');
                }
                else
                {
                    parentheses.pop();
                    if (parentheses.empty())
                    {
                        curr = helper(curr);
                        for (int j = 0; j < stoi(num); j++)
                        {
                            answer.append(curr);
                        }
                        curr = empty;
                        num = empty;
                    }
                    else
                    {
                        curr.push_back(s[i]);
                    }
                }
            }

        }
        return answer;
    }

    string decodeString(string s) {
        return helper(s);
    }
};