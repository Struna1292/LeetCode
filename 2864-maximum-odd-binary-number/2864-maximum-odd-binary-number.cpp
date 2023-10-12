class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        if (s.length() == 1)
        {
            return s;
        }
        
        int i = s.length()-2;

        while (s[s.length()-1] != '1' && i >= 0)
        {
            if (s[i] == '1')
            {
                s[s.length()-1] = '1';
                s[i] = '0';
                break;
            }
            i--;
        }

        int j = 1;
        for (i = 0; i < s.length()-2; i++)
        {
            if (j == s.length()-1)
            {
                break;
            }
            if (s[i] == '0')
            {
                j = i+1;
                while (s[j] != '1' && j < s.length()-2)
                {
                    j++;
                }
                if (s[j] == '1')
                {
                    s[i] = '1';
                    s[j] = '0';
                }
            }
        }
        
        return s;
    }
};