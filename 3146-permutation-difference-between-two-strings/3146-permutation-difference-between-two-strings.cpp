class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int alph[26] = { -1 };

        int output = 0;

        for (int i = 0; i < s.length(); i++)
        {
            alph[s[i]-'a'] = i;
        }

        for (int i = 0; i < t.length(); i++)
        {
            if (i != alph[t[i]-'a'])
            {
                output += abs(i - alph[t[i]-'a']);
            }
        }

        return output;
    }
};