class Solution {
public:
    int minOperations(string s) {
        
        int output = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a') {
                continue;
            }
            else {
                if (output < (26 - (s[i] - 'a'))) {
                    output = 26 - (s[i] - 'a');
                }
            }
        }

        return output;
    }
};