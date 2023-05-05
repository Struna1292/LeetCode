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

    int maxVowels(string s, int k) {
        
        int counter = 0;
        int mostVowels = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (isVowel(s[i]))
            {
                counter++;
            }

            if (i+1 >= k)
            {
                mostVowels = max(mostVowels, counter);

                if (isVowel(s[i+1-k]))
                {
                    counter--;
                }
            }

        }

        return mostVowels;
    }
};