class Solution {
public:
    int partitionString(string s) {
        int alph[26] = { 0 };

        int output = 1;

        for (int i = 0; i < s.length(); i++)
        {
            if (alph[s[i]-'a'] == 1)
            {
                for (int j = 0; j < 26; j++)
                {
                    alph[j] = 0;
                }
                output++;
            }
            alph[s[i]-'a']++;
        }

        return output;
    }
};