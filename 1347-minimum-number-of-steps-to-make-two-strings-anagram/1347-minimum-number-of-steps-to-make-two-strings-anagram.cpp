class Solution {
public:
    int minSteps(string s, string t) {

        int sLetters[26] = { 0 };
        int tLetters[26] = { 0 };
        
        for (int i = 0; i < s.length(); i++)
        {
            sLetters[s[i]-'a']++;
            tLetters[t[i]-'a']++;
        }
        
        int counter = 0;
        for (int i = 0; i < 26; i++)
        {
            if (sLetters[i] > tLetters[i])
            {
                counter += sLetters[i] - tLetters[i];
            }
        }

        return counter;
    }
};