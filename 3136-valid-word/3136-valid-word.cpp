class Solution {
public:
    bool isVowel(char c)
    {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            return true;
        }
        return false;
    }

    bool isValid(string word) {

        if (word.length() < 3)
        {
            return false;
        }


        bool vowel = false;
        bool consonant = false;

        for (int i = 0; i < word.length(); i++)
        {
            if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z'))
            {
                if (isVowel(word[i]))
                {
                    vowel = true;
                }
                else
                {
                    consonant = true;
                }
            }
            else if (word[i] >= '0' && word[i] <= '9')
            {
                continue;
            }
            else
            {
                return false;
            }
        }

        if (!vowel || !consonant)
        {
            return false;
        }

        return true;
    }
};