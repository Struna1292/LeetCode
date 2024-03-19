class Solution {
public:
    long long countSubstrings(string s, char c) {
        
        int counter = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == c)
            {
                counter++;
            }
        }

        long long output = 0;

        for (int i = 1; i <= counter; i++)
        {
            output += i;
        }

        return output;
    }
};