class Solution {
public:
    bool validDigit(int n, int x) {
        
        string s = to_string(n);
        char digit = x + '0';

        if (s[0] == digit) {
            return false;
        }

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == digit) {
                return true;
            }
        }

        return false;
    }
};