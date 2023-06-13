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

    int vowelStrings(vector<string>& words, int left, int right) {
        
        int counter = 0;
        for (int i = left; i <= right; i++)
        {
            if (isVowel(words[i][0]) && isVowel(words[i][words[i].length()-1]))
            {
                counter++;
            }
        }

        return counter;
    }
};