class Solution {
public:
    bool isVowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            return true;
        }
        else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            return true;
        }
        return false;
    }

    bool halvesAreAlike(string s) {
        
        int counter1 = 0;
        int counter2 = 0;

        int i = 0;
        int j = s.length()-1;
        while (i < j)
        {
            if (isVowel(s[i]))
            {
                counter1++;
            }

            if (isVowel(s[j]))
            {
                counter2++;
            }

            i++;
            j--;
        }

        if (counter1 == counter2)
        {
            return true;
        }
        return false;
    }
};