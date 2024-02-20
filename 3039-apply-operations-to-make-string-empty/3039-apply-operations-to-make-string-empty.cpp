class Solution {
public:
    string lastNonEmptyString(string s) {
        int alph[26] = { 0 };

        for (char c : s)
        {
            alph[c - 'a']++;
        }

        int biggest = 0;

        for (int i = 0; i < 26; i++)
        {
            if (alph[i] > biggest)
            {
                biggest = alph[i];
            }
        }

        string output;

        for (int i = s.length()-1; i >= 0; i--)
        {
            if (alph[s[i] - 'a'] == biggest)
            {
                output.push_back(s[i]);
                alph[s[i] - 'a']--;
            }
        }

        int i = 0;
        int j = output.length()-1;

        while (i < j)
        {
            swap(output[i], output[j]);
            i++;
            j--;
        }

        return output;
    }
};