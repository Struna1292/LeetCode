class Solution {
public:
    int reverseBits(int n) {
        
        int curr = 0;

        for (int i = 0; i < 32; i++) {
            curr <<= 1;
            int digit = n & 1;
            curr |= digit;

            n >>= 1;
        }

        return curr;
    }
};