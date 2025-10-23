class Solution {
public:
    bool hasSameDigits(string s) {
        
        while (s.length() > 2) {
            string curr;

            for (int i = 1; i < s.length(); i++) {
                char digit = (((s[i-1]-'0') + (s[i]-'0')) % 10) + '0';
                curr.push_back(digit);
            }
            
            s = curr;
        }   

        return s[0] == s[1];
    }
};