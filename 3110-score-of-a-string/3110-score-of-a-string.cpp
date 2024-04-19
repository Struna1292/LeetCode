class Solution {
public:
    int scoreOfString(string s) {
        
        int output = 0;

        for (int i = 1; i < s.length(); i++)
        {
            output += abs(s[i] - s[i-1]);
        }

        return output;
    }
};