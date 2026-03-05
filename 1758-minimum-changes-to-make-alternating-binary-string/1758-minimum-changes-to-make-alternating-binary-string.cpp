class Solution {
public:
    int minOperations(string s) {
        
        int startsZero = 0;
        int startsOne = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i % 2 == 0) {
                if (s[i] == '0') {
                    startsOne++;
                }
                else {
                    startsZero++;
                }
            }
            else {
                if (s[i] == '0') {
                    startsZero++;
                }
                else {
                    startsOne++;
                }
            }
        }

        return min(startsZero, startsOne);
    }
};