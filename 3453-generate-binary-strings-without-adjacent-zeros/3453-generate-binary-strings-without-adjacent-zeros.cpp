class Solution {
public:
    void helper(string curr, int i, vector<string>& output)
    {
        if (i == curr.length())
        {
            output.push_back(curr);
            return;
        }

        if (i > 0 && curr[i-1] == '0')
        {

        }
        else
        {
            helper(curr, i+1, output);
        }
        
        curr[i] = '1';

        helper(curr, i+1, output);
    }

    vector<string> validStrings(int n) {
        
        string curr(n, '0');

        vector<string> output;

        helper(curr, 0, output);

        return output;
    }
};