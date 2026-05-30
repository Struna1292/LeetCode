class Solution {
public:
    int minFlips(string s) {
        if (s.length() == 1) {
            return 0;
        }

        int ones = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                ones++;
            }
        }

        // all zeros scenario
        int output = ones;

        // all ones scenario
        output = min(output, (int)(s.length() - ones));

        // only one 1 scenario
        if (ones > 0) {
            output = min(output, ones-1);
        }

        // start with one and end with one scenario
        if (s[0] == '1') {
            ones--;
        }
        else {
            ones++;
        }

        if (s[s.length()-1] == '1') {
            ones--;
        }
        else {
            ones++;
        }

        output = min(output, ones);

        return output;
    }
};