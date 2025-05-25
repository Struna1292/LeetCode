class Solution {
public:
    bool isVowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u')
        {
            return true;
        }
        return false;
    }

    int maxFreqSum(string s) {
        
        int alph[26] = { 0 };

        for (char c : s)
        {
            alph[c-'a']++;
        }

        int mostFrequentConsonant = 0;
        int mostFrequentVowel = 0;

        for (int i = 0; i < 26; i++)
        {
            if (isVowel(i+'a'))
            {
                if (alph[i] > mostFrequentVowel)
                {
                    mostFrequentVowel = alph[i];
                }
            }
            else
            {
                if (alph[i] > mostFrequentConsonant)
                {
                    mostFrequentConsonant = alph[i];
                }
            }
        }

        return mostFrequentConsonant + mostFrequentVowel;
    }
};