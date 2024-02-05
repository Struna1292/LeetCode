class Solution {
public:
    int firstUniqChar(string s) {
        int alph[26] = { 0 };

        for (int i = 0; i < s.length(); i++)
        {
            alph[s[i]-'a']++;
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (alph[s[i]-'a'] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};