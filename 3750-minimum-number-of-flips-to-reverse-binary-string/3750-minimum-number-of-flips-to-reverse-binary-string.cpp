class Solution {
public:
    int minimumFlips(int n) {
        string s;

        while (n > 0) {
            if ((n & 1) == 1) {
                s.push_back('1');
            }
            else {
                s.push_back('0');
            }

            n >>= 1;
        }

        int output = 0;

        for (int i = 0, j = s.length()-1; i < s.length(); i++, j--) {
            if (s[i] != s[j]) {
                output++;
            }
        }

        return output;
    }
};