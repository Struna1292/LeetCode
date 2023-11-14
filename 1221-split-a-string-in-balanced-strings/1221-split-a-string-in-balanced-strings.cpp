class Solution {
public:
    int balancedStringSplit(string s) {
        
        int output = 0;
        int curr = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'R')
            {
                curr++;
            }
            else
            {
                curr--;
            }
            
            if (curr == 0)
            {
                output ++;
            }
        }

        return output;
    }
};