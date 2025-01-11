class Solution {
public:
    bool canConstruct(string s, int k) {
        
        if (k > s.length())
        {
            return false;
        }

        int alph[26] = { 0 };

        for (char c : s)
        {
            alph[c-'a']++;
        }


        for (int i = 0; i < 26; i++)
        {
            if (alph[i] > 0 && alph[i] % 2 != 0)
            {
                k--;
            }
        }

        return k >= 0;
    }
};