class Solution {
public:
    int minimumLength(string s) {
        
        int alph[26] = { 0 };

        for (char c : s)
        {
            alph[c-'a']++;
        }

        int output = 0;

        for (int i = 0; i < 26; i++)
        {
            while (alph[i] >= 3)
            {
                int rest = alph[i] % 3;

                alph[i] /= 3;

                alph[i] += rest;
            }

            output += alph[i];
        }

        return output;
    }
};