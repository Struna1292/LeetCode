class Solution {
public:

    int isVowel(char letter)
    {
        string vowels = "aeiou";

        for (int i = 0; i < vowels.length(); i++)
        {
            if (letter == vowels[i])
            {
                return 1;
            }
        }
        return 0;
    }

    int maxVowels(string s, int k) {
        
        int counter = 0;
        int length = 0;
        int mostVowels = 0;
        for (int i = 0; i < s.length(); i++)
        {
            
            if (length < k)
            {
                counter += isVowel(s[i]);
                length++;
            }
            else
            {
                counter += isVowel(s[i]);
                counter -= isVowel(s[i-k]);
            }
            
            if (counter > mostVowels)
            {
                mostVowels = counter;
            }
            
        }

        return mostVowels;
    }
};