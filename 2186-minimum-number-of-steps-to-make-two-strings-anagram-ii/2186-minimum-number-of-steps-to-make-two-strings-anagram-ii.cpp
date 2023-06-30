class Solution {
public:
    int minSteps(string s, string t) {

        if (s.length() < t.length())
        {
            string temp = s;
            s = t;
            t = temp;
        }

        int sLetters[26] = { 0 };

        for (int i = 0; i < s.length(); i++)
        {
            sLetters[s[i]-'a']++;
        }

        int tLetters[26] = { 0 };

        for (int i = 0; i < t.length(); i++)
        {
            tLetters[t[i]-'a']++;
        }

        int counter = 0;

        for (int i = 0; i < 26; i++)
        {
            if (sLetters[i] > tLetters[i])
            {
                counter += sLetters[i] - tLetters[i];
            }
            else
            {
                counter += tLetters[i] - sLetters[i];
            }
        }

        return counter;
    }
};