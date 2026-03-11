class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) { 
            return 1;
        }
        
        int currN = n;
        int ones = 0;
        while (currN > 0) {
            ones <<= 1;
            ones |= 1;

            currN >>= 1;
        }

        return ones - n;
    }
};