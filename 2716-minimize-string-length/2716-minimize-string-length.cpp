class Solution {
public:
    int minimizedStringLength(string s) {

        int alphabet[26] = { 0 };

        for (int i = 0; i < s.length(); i++)
        {
            alphabet[s[i] - 'a']++;
        }

        int counter = 0;

        for (int i = 0; i < 26; i++)
        {
            if (alphabet[i] != 0)
            {
                counter++;
            }
        }

        return counter;
    }
};