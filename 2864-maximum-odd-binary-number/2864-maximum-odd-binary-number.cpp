class Solution {
public:
    string maximumOddBinaryNumber(string s) {

        int j = s.length()-2;

        while (s[s.length()-1] != '1' && j >= 0)
        {
            if (s[j] == '1')
            {
                swap(s[j], s[s.length()-1]);
            }
            else
            {
                j--;
            }
        }

        int i = 0;

        while (i < j)
        {
            if (s[i] == '0')
            {
                while (s[j] != '1' && j > i)
                {
                    j--;
                }

                if (s[j] == '1' && j != i)
                {
                    swap(s[i], s[j]);
                }
            }
            i++;
        }
        
        return s;
    }
};