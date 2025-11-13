class Solution {
public:
    int maxOperations(string s) {
        int ones = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                ones++;
            }
        }

        int output = 0;
        char prev = '1';
        for (int i = s.length()-1; i >= 0; i--) {
            if (s[i] == '0' && prev == '1') {
                output += ones;
            }
            else if (s[i] == '1') {
                ones--;
            }

            prev = s[i];
        }

        return output;
    }
};