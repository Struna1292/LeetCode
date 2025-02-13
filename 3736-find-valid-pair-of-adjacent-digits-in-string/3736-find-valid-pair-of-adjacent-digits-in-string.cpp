class Solution {
public:
    string findValidPair(string s) {
        
        int nums[10] = { 0 };

        for (char c : s)
        {
            nums[c-'0']++;
        }

        string output;

        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] != s[i-1] && s[i]-'0' == nums[s[i]-'0'] && s[i-1]-'0' == nums[s[i-1]-'0'])
            {
                output.push_back(s[i-1]);
                output.push_back(s[i]);
                break;
            }
        }

        return output;
    }
};