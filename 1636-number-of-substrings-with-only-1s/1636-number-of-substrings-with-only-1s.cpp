class Solution {
public:
    int numSub(string s) {
        long long output = 0;
        int ones = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                ones++;
            }
            else {
                for (; ones > 0; ones--) {
                    output += ones;
                }
            }
        }
        for (; ones > 0; ones--) {
            output += ones;
        }        

        return output % 1000000007;
    }
};