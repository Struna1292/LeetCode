class Solution {
public:
    bool isSubstringPresent(string s) {
        
        string reversed = s;

        int i = 0;
        int j = s.length()-1;

        while (i < j)
        {
            swap(reversed[i], reversed[j]);
            i++;
            j--;
        }


        for (i = 0; i < s.length()-1; i++)
        {
            for (j = 0; j < reversed.length()-1; j++)
            {
                if (s[i] == reversed[j] && s[i+1] == reversed[j+1])
                {
                    return true;
                }
            }
        }

        return false;
    }
};