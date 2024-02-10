class Solution {
public:
    string greatestLetter(string s) {
        int lowerCase[26] = { 0 };
        int upperCase[26] = { 0 };

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] <= 'Z' && s[i] >= 'A')
            {
                upperCase[s[i]-'A']++;
            }
            else
            {
                lowerCase[s[i]-'a']++;
            }
        }

        for (int i = 25; i >= 0; i--)
        {
            if (lowerCase[i] > 0 && upperCase[i] > 0)
            {
                char c = 'A'+i;
                string output;
                output += c;
                return output;
            }
        }

        return "";
    }
};