class Solution {
public:
    bool isVowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            return true;
        }
        return false;
    }


    int beautifulSubstrings(string s, int k) {
        
        int output = 0;

        for (int i = 0; i < s.length(); i++)
        {
            int currVowels = 0;
            int currConsonants = 0;

            for (int j = i; j < s.length(); j++)
            {
                if (isVowel(s[j]))
                {
                    currVowels++;
                }
                else
                {
                    currConsonants++;
                }

                if ((currVowels * currConsonants) % k == 0 && currVowels == currConsonants)
                {
                    output++;
                }
            }
        }

        return output;
    }
};