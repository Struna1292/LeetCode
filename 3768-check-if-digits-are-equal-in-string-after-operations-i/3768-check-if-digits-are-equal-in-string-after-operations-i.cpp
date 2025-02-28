class Solution {
public:
    bool hasSameDigits(string s) {
        
        while (s.length() > 2)
        {
            string curr;

            for (int i = 1; i < s.length(); i++)
            {
                int modulo = ((s[i-1]-'0') + (s[i]-'0')) % 10; 
                curr.push_back(modulo + '0');
            }
            s = curr;
        }

        return s[0] == s[1];
    }
};