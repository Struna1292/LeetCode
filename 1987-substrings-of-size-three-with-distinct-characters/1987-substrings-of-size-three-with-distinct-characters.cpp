class Solution {
public:
    bool isDistinct(int *alph)
    {
        for (int i = 0; i < 26; i++)
        {
            if (alph[i] > 1)
            {
                return false;
            }
        }

        return true;
    }

    int countGoodSubstrings(string s) {
        if (s.length() < 3)
        {
            return 0;
        }
        
        int curr[26] = { 0 };

        for (int i = 0; i < 3; i++)
        {
            curr[s[i]-'a']++;
        }

        int output = 0;

        if (isDistinct(curr))
        {
            output++;
        }

        for (int i = 3; i < s.length(); i++)
        {
            curr[s[i-3]-'a']--;
            curr[s[i]-'a']++;
            if (isDistinct(curr))
            {
                output++;
            }
        }

        return output;
    }
};