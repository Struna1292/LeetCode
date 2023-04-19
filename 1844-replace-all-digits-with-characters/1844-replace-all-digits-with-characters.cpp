class Solution {
public:
    char shift(char a, int b)
    {
        return a + b;
    }
    string replaceDigits(string s) {
        char prev;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                s[i] = shift(prev, s[i] - '0');
            }
            prev = s[i];
        }
        return s;
    }
};