class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int output = 0;

        int x = n-k;
        if (x <= 0) {
            x = 1;
        }

        for (; x <= n+k; x++) {
            if ((n & x) == 0) {
                output += x;
            }
        }

        return output;
    }
};