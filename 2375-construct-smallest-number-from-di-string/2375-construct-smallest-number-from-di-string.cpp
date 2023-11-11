class Solution {
public:
    void helper(string& pattern, int i, string curr, char c, string& output)
    {
        if (output.length() != 0)
        {
            return;
        }

        if (c != '0')
        {
            curr.push_back(c);
        }

        if (curr.length() == 0)
        {
            for (int j = 1; j < 10; j++)
            {
                helper(pattern, i, curr, '0'+j, output);
            }
        }
        else
        {
            if (i == pattern.length())
            {
                output = curr;
                return;
            }
            
            if (pattern[i] == 'I')
            {
                for (int j = c - '0' + 1; j <= 9; j++)
                {
                    bool appear = false;
                    for (int k = 0; k < curr.length(); k++)
                    {
                        if (curr[k] == j+'0')
                        {
                            appear = true;
                            break;
                        }
                    }

                    if (appear == false)
                        helper(pattern, i+1, curr, '0'+j, output);
                }
            }
            else
            {
                for (int j = 1; j < c - '0'; j++)
                {
                    bool appear = false;
                    for (int k = 0; k < curr.length(); k++)
                    {
                        if (curr[k] == j+'0')
                        {
                            appear = true;
                            break;
                        }
                    }

                    if (appear == false)
                        helper(pattern, i+1, curr, '0'+j, output);
                }
            }
        }
    }

    string smallestNumber(string pattern) { 

        string output;

        helper(pattern, 0, "", '0', output);

        return output;
    }
};