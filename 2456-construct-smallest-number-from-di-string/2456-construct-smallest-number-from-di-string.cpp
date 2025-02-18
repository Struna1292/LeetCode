class Solution {
public:
    void helper(string& pattern, int index, vector<bool>& used, string& output, string curr)
    {
        if (output != "")
        {
            return;
        }

        for (int i = '1'; i <= '9'; i++)
        {
            if (!used[i-'1'] && ((pattern[index] == 'I' && curr[index] < i) || (pattern[index] == 'D' && curr[index] > i)))
            {
                string cp = curr;
                cp.push_back(i);
                if (cp.length() == pattern.length()+1)
                {
                    output = cp;
                    return;
                }
                used[i-'1'] = true;
                helper(pattern, index+1, used, output, cp);
                used[i-'1'] = false;
            }
        }
    }

    string smallestNumber(string pattern) {
        string output;

        for (int i = '1'; i <= '9'; i++)
        {
            string curr;
            curr.push_back(i);
            vector<bool> used(9, false);
            used[i-'1'] = true;
            helper(pattern, 0, used, output, curr);
        }

        return output;
    }
};