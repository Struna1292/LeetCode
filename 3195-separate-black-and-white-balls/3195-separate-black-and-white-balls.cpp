class Solution {
public:
    long long minimumSteps(string s) {
        
        int i = 0;
        int j = s.length()-1;

        long long output = 0;

        while (i < j)
        {
            if (s[i] == '0')
            {
                i++;
                continue;
            }

            if (s[j] == '1')
            {
                j--;
                continue;
            }

            if (s[i] == '1' && s[j] == '0')
            {
                output += j-i;
                i++;
                j--;
            }
        }

        return output;
    }
};