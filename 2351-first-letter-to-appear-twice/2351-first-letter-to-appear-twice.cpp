class Solution {
public:
    char repeatedCharacter(string s) {
        int alphabet[26] = { 0 };

        for (int i = 0; i < s.length(); i++)
        {
            alphabet[s[i]-'a']++;
            if (alphabet[s[i]-'a'] > 1)
            {
                return s[i];
            }
        }
        return 'a';
    }
};