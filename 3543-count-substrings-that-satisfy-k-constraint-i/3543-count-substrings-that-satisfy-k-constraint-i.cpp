class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        
        int output = 0;

        for (int i = 0; i < s.length(); i++)
        {
            int zeros = 0;
            int ones = 0;
            
            for (int j = i; j < s.length(); j++)
            {
                if (s[j] == '0')
                {
                    zeros++;
                }
                else
                {
                    ones++;
                }
                if (zeros > k && ones > k)
                {
                    break;
                }
                else
                {
                    output++;
                }
            }
        }

        return output;
    }
};