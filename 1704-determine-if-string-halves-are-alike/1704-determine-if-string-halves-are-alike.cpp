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

    bool halvesAreAlike(string s) {
        
        int i = 0;
        int j = s.length()-1;

        int c1 = 0;
        int c2 = 0;

        while (i < j)
        {
            if (isVowel(s[i]))
            {
                c1++;
            }
            if (isVowel(s[j]))
            {
                c2++;
            }
            i++;
            j--;
        }

        if (c1 != c2)
        {
            return false;
        }

        return true;
    }
};