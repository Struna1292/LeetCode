class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        int curr = n & 1;
        n >>= 1;
        while (n > 0) {
            int digit = n & 1;
            if (curr == digit) {
                return false;
            }
            curr = digit;
            n >>= 1;
        }

        return true;
    }
};